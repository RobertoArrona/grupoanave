<?php

/**
 * Form builder; The contract number form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function insurance_contract_form_settings() {
  $form['contract_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contract'),
  );
  $form['contract_information']['insurance_contract_contract_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#default_value' => variable_get('insurance_contract_contract_number', '1001'),
    '#required' => TRUE,
  );


  return system_settings_form($form);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function insurance_contract_form_poliza_node_form_alter(&$form, &$form_state, $form_id) {
  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    if (($contract_folio = insurance_contract_contract_folio_get())) {
      $form['title']['#default_value'] = $contract_folio;
    }
  }
	
  $form['title']['#attributes']['readonly'] = 'readonly';
  $userld= insurance_contract_contract_load_oficina_get();
  
  $form['field_poliza_oficina'][LANGUAGE_NONE][0]['value']['#default_value'] = $userld;
  $form['field_poliza_oficina'][LANGUAGE_NONE][0]['value']['#attributes']['style'] = 'display: none;';
  $form['field_poliza_emision']['#attributes']['style'] = 'display: none;';

  // field title(numero de contrato)
  $form['title']['#attributes']['style']  = 'display: none;';
  // field_asegurado_domicilio
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['street_block']['thoroughfare']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['street_block']['premise']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['locality']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['postal_code']['#required'] = 'true';
  //$form Validate
  $form['#validate'][] = 'insurance_contract_form_poliza_node_validate';

  //$form attached JS
  drupal_add_js(drupal_get_path('module', 'insurance_contract') . '/js/contratos.pagos.js');
}

/**
 *
 */
function insurance_contract_form_poliza_node_validate(&$form, &$form_state) {
  $issuedate = strtotime($form_state['values']['field_poliza_emision'][LANGUAGE_NONE][0]['value']);
  $validity = strtotime($form_state['values']['field_poliza_vigencia'][LANGUAGE_NONE][0]['value']);
  if ($validity < $issuedate) {
    form_set_error('field_poliza_emision', '');
    form_set_error('field_poliza_vigencia', t('The validity start date cannot be earlier than the issue date.'));
  }


/*
  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    if (($contract_folio = insurance_contract_contract_folio_get())) {
      if ($contract_folio != $form_state['values']['title']) {
        form_set_error('title', t('Is forbidden to modify the Contract folio, please contact the administers of the site if you really need this.'));
      }
    }
  
  }
*/
}

function insurance_contract_form_recibo_contrato_node_form_alter(&$form, &$form_state, $form_id) {

  if ((isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    $child_nid = $form['nid']['#value'];
    $parent_data = node_collection_api_get_parent_node_instance($child_nid);
    $nids_childs = node_collection_api_get_child_node_instances($parent_data->nid);
    $payments = $parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
    //print_r($form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']); exit;
    $serie = getSerie($payments);
  // define when is the first payemnt or not and assign data.
    if (empty($nids_childs) || $nids_childs[0] == $child_nid) {
     print_r("Es el primer pago");
     $form['field_primer_pago'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value'];
     $form['field_serie'][LANGUAGE_NONE][0]['value']['#default_value'] = "1$serie";
     $form['field_importe_letra'][LANGUAGE_NONE][0]['value']['#default_value'] = strtoupper(num2letras($parent_data->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value']));
     $form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']['value2'] = getCoverage($payments, $form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']['value']);
   }else {
     print_r("Es pago subsecuente");
     $form['field_pago_subsecuente'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value'];
     $paymentKey = array_search($child_nid, $nids_childs) +1;
     $form['field_serie'][LANGUAGE_NONE][0]['value']['#default_value'] = "$paymentKey$serie";
     $form['field_importe_letra'][LANGUAGE_NONE][0]['value']['#default_value'] = strtoupper(num2letras($parent_data->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value']));
     $form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']['value2'] = getCoverage($payments, $form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']['value']);
    }
  }else {
  // ---- Get parent data when a invoice is created. ---
  // get string that contains parent node id  
     $actionString = $form['#action'];
     $child_nid = $form['nid']['#value'];
  // get parent nid using string replace and then load the parent data
     $parent_nid = str_replace('/node/add/recibo-contrato?parent_node_id=','',$actionString);
     $parent_data = node_load($parent_nid);
     $nids_childs = node_collection_api_get_child_node_instances($parent_data->nid);
     // get serie from payment type
     $payments = $parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
     $serie = getSerie($payments);
     // count array to get new payment key
     $paymentKey = count($nids_childs) +1;
   // add from poliza to recibo
     $payments = $parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];  
     $form['field_primer_pago'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value'];
     $form['field_serie'][LANGUAGE_NONE][0]['value']['#default_value'] = "$paymentKey$serie";
     $form['field_importe_letra'][LANGUAGE_NONE][0]['value']['#default_value'] = strtoupper(num2letras($parent_data->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value']));
     $form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']['value2'] = getCoverage($payments, $form['field_periodo_cobertura'][LANGUAGE_NONE][0]['#default_value']['value']);
   }
   // add fields from poliza to recibo
}

// get series data for payments
    function getSerie($payment_type){
      if ($payment_type == 'mensual'){
        return $serie = '/12';
      }
      if ($payment_type == '3meses'){
        return $serie = '/3';
      }
      if ($payment_type == 'trimestral'){
        return $serie = '/4';
      }
      if ($payment_type == 'cuatrimestral'){
        return $serie = '/3';
      }
      if ($payment_type == 'semestral'){
        return $serie = '/2';
      }
      if ($payment_type == 'anual'){
        return $serie = '/1';
      }
    }
    
// get series data for payments
    function getCoverage($payment_type, $date){
      if ($payment_type == 'mensual'){
        $dateAumented = date('Y-m-d', strtotime("$date +1 month"));
        return $dateAumented;
      }
      if ($payment_type == '3meses'){
        $dateAumented = date('Y-m-d', strtotime("$date +1 month"));
        return $dateAumented;
      }
      if ($payment_type == 'trimestral'){
        $dateAumented = date('Y-m-d', strtotime("$date +3 month"));
        return $dateAumented;
      }
      if ($payment_type == 'cuatrimestral'){
        $dateAumented = date('Y-m-d', strtotime("$date +4 month"));
        return $dateAumented;
      }
      if ($payment_type == 'semestral'){
        $dateAumented = date('Y-m-d', strtotime("$date +6 month"));
       return $dateAumented;
      }
      if ($payment_type == 'anual'){
        $dateAumented = date('Y-m-d', strtotime("$date +1 year"));
        return $dateAumented;
      }
    }

function num2letras($num, $fem = false, $dec = true) { 
   $matuni[2]  = "dos"; 
   $matuni[3]  = "tres"; 
   $matuni[4]  = "cuatro"; 
   $matuni[5]  = "cinco"; 
   $matuni[6]  = "seis"; 
   $matuni[7]  = "siete"; 
   $matuni[8]  = "ocho"; 
   $matuni[9]  = "nueve"; 
   $matuni[10] = "diez"; 
   $matuni[11] = "once"; 
   $matuni[12] = "doce"; 
   $matuni[13] = "trece"; 
   $matuni[14] = "catorce"; 
   $matuni[15] = "quince"; 
   $matuni[16] = "dieciseis"; 
   $matuni[17] = "diecisiete"; 
   $matuni[18] = "dieciocho"; 
   $matuni[19] = "diecinueve"; 
   $matuni[20] = "veinte"; 
   $matunisub[2] = "dos"; 
   $matunisub[3] = "tres"; 
   $matunisub[4] = "cuatro"; 
   $matunisub[5] = "quin"; 
   $matunisub[6] = "seis"; 
   $matunisub[7] = "sete"; 
   $matunisub[8] = "ocho"; 
   $matunisub[9] = "nove"; 

   $matdec[2] = "veint"; 
   $matdec[3] = "treinta"; 
   $matdec[4] = "cuarenta"; 
   $matdec[5] = "cincuenta"; 
   $matdec[6] = "sesenta"; 
   $matdec[7] = "setenta"; 
   $matdec[8] = "ochenta"; 
   $matdec[9] = "noventa"; 
   $matsub[3]  = 'mill'; 
   $matsub[5]  = 'bill'; 
   $matsub[7]  = 'mill'; 
   $matsub[9]  = 'trill'; 
   $matsub[11] = 'mill'; 
   $matsub[13] = 'bill'; 
   $matsub[15] = 'mill'; 
   $matmil[4]  = 'millones'; 
   $matmil[6]  = 'billones'; 
   $matmil[7]  = 'de billones'; 
   $matmil[8]  = 'millones de billones'; 
   $matmil[10] = 'trillones'; 
   $matmil[11] = 'de trillones'; 
   $matmil[12] = 'millones de trillones'; 
   $matmil[13] = 'de trillones'; 
   $matmil[14] = 'billones de trillones'; 
   $matmil[15] = 'de billones de trillones'; 
   $matmil[16] = 'millones de billones de trillones'; 
   
   //Zi hack
   $float=explode('.',$num);
   $num=$float[0];

   $num = trim((string)@$num); 
   if ($num[0] == '-') { 
      $neg = 'menos '; 
      $num = substr($num, 1); 
   }else 
      $neg = ''; 
   while ($num[0] == '0') $num = substr($num, 1); 
   if ($num[0] < '1' or $num[0] > 9) $num = '0' . $num; 
   $zeros = true; 
   $punt = false; 
   $ent = ''; 
   $fra = ''; 
   for ($c = 0; $c < strlen($num); $c++) { 
      $n = $num[$c]; 
      if (! (strpos(".,'''", $n) === false)) { 
         if ($punt) break; 
         else{ 
            $punt = true; 
            continue; 
         } 

      }elseif (! (strpos('0123456789', $n) === false)) { 
         if ($punt) { 
            if ($n != '0') $zeros = false; 
            $fra .= $n; 
         }else 

            $ent .= $n; 
      }else 

         break; 

   } 
   $ent = '     ' . $ent; 
   if ($dec and $fra and ! $zeros) { 
      $fin = ' coma'; 
      for ($n = 0; $n < strlen($fra); $n++) { 
         if (($s = $fra[$n]) == '0') 
            $fin .= ' cero'; 
         elseif ($s == '1') 
            $fin .= $fem ? ' una' : ' un'; 
         else 
            $fin .= ' ' . $matuni[$s]; 
      } 
   }else 
      $fin = ''; 
   if ((int)$ent === 0) return 'Cero ' . $fin; 
   $tex = ''; 
   $sub = 0; 
   $mils = 0; 
   $neutro = false; 
   while ( ($num = substr($ent, -3)) != '   ') { 
      $ent = substr($ent, 0, -3); 
      if (++$sub < 3 and $fem) { 
         $matuni[1] = 'una'; 
         $subcent = 'as'; 
      }else{ 
         $matuni[1] = $neutro ? 'un' : 'uno'; 
         $subcent = 'os'; 
      } 
      $t = ''; 
      $n2 = substr($num, 1); 
      if ($n2 == '00') { 
      }elseif ($n2 < 21) 
         $t = ' ' . $matuni[(int)$n2]; 
      elseif ($n2 < 30) { 
         $n3 = $num[2]; 
         if ($n3 != 0) $t = 'i' . $matuni[$n3]; 
         $n2 = $num[1]; 
         $t = ' ' . $matdec[$n2] . $t; 
      }else{ 
         $n3 = $num[2]; 
         if ($n3 != 0) $t = ' y ' . $matuni[$n3]; 
         $n2 = $num[1]; 
         $t = ' ' . $matdec[$n2] . $t; 
      } 
      $n = $num[0]; 
      if ($n == 1) { 
         $t = ' ciento' . $t; 
      }elseif ($n == 5){ 
         $t = ' ' . $matunisub[$n] . 'ient' . $subcent . $t; 
      }elseif ($n != 0){ 
         $t = ' ' . $matunisub[$n] . 'cient' . $subcent . $t; 
      } 
      if ($sub == 1) { 
      }elseif (! isset($matsub[$sub])) { 
         if ($num == 1) { 
            $t = ' mil'; 
         }elseif ($num > 1){ 
            $t .= ' mil'; 
         } 
      }elseif ($num == 1) { 
         $t .= ' ' . $matsub[$sub] . '?n'; 
      }elseif ($num > 1){ 
         $t .= ' ' . $matsub[$sub] . 'ones'; 
      }   
      if ($num == '000') $mils ++; 
      elseif ($mils != 0) { 
         if (isset($matmil[$sub])) $t .= ' ' . $matmil[$sub]; 
         $mils = 0; 
      } 
      $neutro = true; 
      $tex = $t . $tex; 
   } 
   $tex = $neg . substr($tex, 1) . $fin; 
   //Zi hack --> return ucfirst($tex);
   $end_num=ucfirst($tex).' pesos '.$float[1].'/100 M.N.';
   return $end_num; 
} 
