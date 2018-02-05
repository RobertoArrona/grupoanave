<?php
  
/**
 * Implements hook_form_alter().
 */
function payment_receipt_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'recibo_contrato_node_form':
      $pathCSS = drupal_get_path('module', 'payment_receipt') . '/css/payment_receipt.admin.css';
      drupal_add_css($pathCSS);
      $pathJS = drupal_get_path('module', 'payment_receipt') . '/js/payment_receipt.js';
      drupal_add_js($pathJS);
      break;
  }
}

/**
 * Form builder; The contract number form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function payment_receipt_form_settings() {
  
  if (empty(variable_get('payment_receipt_receipt_number'))) {
    variable_set('payment_receipt_receipt_number', '1000001');
  } else if (!empty(variable_get('payment_receipt_receipt_number'))) {
    $payment_receipt_folio = variable_get('payment_receipt_receipt_number');
    if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio)) {
      $newfolio = payment_receipt_receipt_new_folio();
      variable_set('payment_receipt_receipt_number', $newfolio);
    }
  }
  
  $form['contract_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contract'),
  );
  $form['payment_receipt_information']['payment_receipt_receipt_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#default_value' => variable_get('payment_receipt_receipt_number'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function payment_receipt_form_recibo_contrato_node_form_alter(&$form, &$form_state, $form_id) {
    
    
  
  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    $payment_receipt_folio = payment_receipt_receipt_number_folio_get();
    if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio)) {
      $payment_receipt_folio = payment_receipt_receipt_new_folio();
    }
    $form['title']['#default_value'] = $payment_receipt_folio;
  }
  
  $form['title']['#attributes']['readonly'] = 'readonly';
  $form['title']['#attributes']['style']  = 'display: none;';
  $form['#validate'][] = 'payment_receipt_node_form_validate';
  $node = menu_get_object();

  if(empty($node ->nid)) {
    $actionString = $form['#action'];
    $split = preg_split('[=]', $actionString);
    $parent_node_id = $split[1];
    $parent_nid = str_replace('/node/add/recibo-contrato?parent_node_id=','',$actionString);
  } else if (!empty($node ->nid)) {
    $parentInstance = node_collection_api_get_parent_node_instance($node ->nid);
    $parent_node_id = $parentInstance ->nid;
  }
  
  /**
   * logic to fill payment receipt fields
   */
   
  // ---- Get parent data when a invoice is created. ---
  // get string that contains parent node id  
  
  $child_nid = $form['nid']['#value'];
  // get parent nid using string replace and then load the parent data
  
  $parent_data = node_load($parent_node_id);
  
  
  $nids_childs = node_collection_api_get_child_node_instances($parent_node_id);
  // get serie from payment type
  $payments = $parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
  $serie = getSerie($payments);
  $serieNumber = substr($serie,1);
  
  // count array to get new payment key
  $paymentKey = count($nids_childs) +1;
  $childsNumber = count($nids_childs);
  $receiptSerie = $paymentKey.$serie;
  // add from poliza to recibo
  $payments = $parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
/*
  $form['field_referencia_contrato'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->title;
  $form['field_referencia_contrato']['#attributes']['readonly'] = 'readonly';
  $form['field_referencia_contrato']['#attributes']['style']  = 'display: none;';
*/
//   print_r($parent_data->title);exit;
    
  
  
  // define when is the first payemnt or not and assign data.
  if (empty($nids_childs) || $nids_childs[0] == $child_nid) {
    print ("<h1>Es el primer pago</h1>");
    $form['field_primer_pago_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value'];
    $form['field_serie_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = "1$serie";
    $form['field_importe_con_letra_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = strtoupper(num2letras($parent_data->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value']));
    $form['field_periodo_cobertura_rc'][LANGUAGE_NONE][0]['#default_value']['value2'] = getCoverage($payments, $form['field_periodo_cobertura_rc'][LANGUAGE_NONE][0]['#default_value']['value']);
    $form['field_vencimiento_rc'][LANGUAGE_NONE][0]['#default_value']['value'] = getGracePeriod($parent_data->field_periodo_de_gracia[LANGUAGE_NONE][0]['value']);
    $form['field_emision_recibo_ref_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->field_derecho_de_poliza2[LANGUAGE_NONE][0]['value'];
    $form['field_pago_subsecuente_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = 0;
  } else {
    print ("<h1>Es pago subsecuente</h1>");
    $form['field_pago_subsecuente_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = $parent_data->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value'];
    if ($childsNumber != $serieNumber) {
      $form['field_serie_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = $receiptSerie;
    }
    $form['field_importe_con_letra_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = strtoupper(num2letras($parent_data->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value']));
    $form['field_periodo_cobertura_rc'][LANGUAGE_NONE][0]['#default_value']['value2'] = getCoverage($payments, $form['field_periodo_cobertura_rc'][LANGUAGE_NONE][0]['#default_value']['value']);
    $form['field_vencimiento_rc'][LANGUAGE_NONE][0]['#default_value']['value'] = getGracePeriod($parent_data->field_periodo_de_gracia[LANGUAGE_NONE][0]['value']);
    $form['field_emision_recibo_ref_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = 0;
    $form['field_primer_pago_rc'][LANGUAGE_NONE][0]['value']['#default_value'] = 0;
  }
  
/*
  $form['field_primer_pago_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_serie_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_importe_con_letra_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_periodo_cobertura_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_vencimiento_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_emision_recibo_ref_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_pago_subsecuente_rc'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
*/
  
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

// Get grace period 
function getGracePeriod($grace_day) {
    $due_date = "";
    $due_date = date('Y-m-d', strtotime("$due_date +$grace_day day" )); 
    return $due_date;
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

function payment_receipt_node_form_validate($form, &$form_state) {
  $node = menu_get_object();
  
  
  
  if(empty($node ->nid)) {
    $actionString = $form['#action'];
    $split = preg_split('[=]', $actionString);
    $parent_node_id = $split[1];
    $parent_nid = str_replace('/node/add/recibo-contrato?parent_node_id=','',$actionString);
    
    $parent_data = node_load($parent_node_id);
    $payments = $parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
    $serie = getSerie($payments);
    $serieNumber = substr($serie,1);
    $nids_childs = node_collection_api_get_child_node_instances($parent_node_id);
    $childsNumber = count($nids_childs);
    
    // get serie     
    $serie = getSerie($payments);
    // count array to get new payment key
    $paymentKey = count($nids_childs) +1;
    $receiptSerie = $paymentKey.$serie;
    $form_state['values']['field_serie_rc'][LANGUAGE_NONE][0]['value'] = $receiptSerie;
    
    //validating for folio receipt     
    $payment_receipt_folio = $form_state['values']['title'];
    if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio)) {
      $newfolio = payment_receipt_receipt_new_folio();
      $form_state['values']['title'] = $newfolio;
    }
    
    //validating for serie receipt 
    if ($childsNumber == $serieNumber){
       form_set_error('title', t('No se puede crear otro recibo, porque ya se supero el límite para este contrato, en base al método de pago.'));
    }
    
    //validating for subpayments receipt
    if (count($nids_childs) >= 1) {
      $form_state['values']['field_primer_pago_rc'][LANGUAGE_NONE][0]['value'] = 0;
      $form_state['values']['field_pago_subsecuente_rc'][LANGUAGE_NONE][0]['value'] = $parent_data->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value'];
    }
    
  } else if (!empty($node ->nid)) {
    $parentInstance = node_collection_api_get_parent_node_instance($node ->nid);
    $parent_node_id = $parentInstance ->nid;
  }
}
