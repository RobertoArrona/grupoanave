<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Returns the Contract Folio.
 *
 * @return INT
 *   The contract folio.
 */
function insurance_contract_contract_folio_get($i = 0) {
  $month_digit = intval(date('n'));
  $months = array(
    0 => 'None',
    1 => 'A',
    2 => 'B',
    3 => 'C',
    4 => 'D',
    5 => 'E',
    6 => 'F',
    7 => 'G',
    8 => 'H',
    9 => 'I',
    10 => 'J',
    11 => 'K',
    12 => 'L',
  );
  $month = $months[$month_digit];
  $year = date('y');
  $contract_number = (variable_get('insurance_contract_contract_number', 1001) + $i);
  $contract_number_string = sprintf("%'.06d", $contract_number);
  $contract_folio = "{$month}{$year}{$contract_number_string}";
  return $contract_folio;
}

/**
 * Increases the Contract Number by 1.
 */
function insurance_contract_contract_number_increase($i = 0) {
  if (!($contract_number = variable_get('insurance_contract_contract_number', FALSE))) {
    return FALSE;
  }

  $contract_number = intval($contract_number) + 1 + $i;
  if ($contract_number > 999999) {
    $contract_number = 0;
  }

  variable_set('insurance_contract_contract_number', $contract_number);
  return TRUE;
}

/**
 * Returns TRUE if a given contract is found at the database.
 */
function insurance_contract_contract_folio_exists($contract_folio, $nid) {
  if (isset($nid)) {
    $nid = explode('', $nid);
    $contract_folio = explode('', $contract_folio);
    if ($nid) {
      $query = db_query("SELECT nid FROM {nodes} WHERE title = '%s' AND nid != %d", $contract_folio, $nid);
      if ($item = $query->fetchArray()) {
        return $item['nid'];
      }
    }

    return FALSE;
  }
}

/**
 * Increases the Payment Receipt Number by 1.
 */
function insurance_contract_payment_get_receipt_number() {
  if (!($payment_receipt_number = variable_get('payment_receipt_receipt_number', FALSE))) {
    return FALSE;
  }

  $payment_receipt_number = intval($payment_receipt_number) + 1;
  if ($payment_receipt_number > 9999999) {
    $payment_receipt_number = 1000000;
  }

  variable_set('payment_receipt_receipt_number', $payment_receipt_number);
  return $payment_receipt_number;
}

/**
 * Returns the next id to be inserted.
 */
function insurance_contract_get_insert_id($table, $field) {
  $sql = sprintf('SELECT MAX(%s) + 1 AS %s FROM %s ORDER BY %s', $field, $field, $table, $field);
  $result = db_query($sql);

  foreach ($result as $row) {
    return $row->$field;
  }

  return FALSE;
}

/**
 * Creates node collection relationship.
 */
function insurance_contract_create_node_collection_relationship($nid) {
  // Get ids to be inserted.
  $insert_nc_data_id = insurance_contract_get_insert_id('node_collection_data', 'nc_data_id');
  $insert_nc_child_nid = insurance_contract_get_insert_id('node', 'nid');

  // Insert values to create node collection relationship.
  $last_insert_nc_data_id = db_insert('node_collection_data')
    ->fields(array(
      'nc_data_id' => $insert_nc_data_id,
      'nc_parent_nid' => $nid,
      'nc_child_nid' => $insert_nc_child_nid,
    ))
    ->execute();

  if ($last_insert_nc_data_id) {
    return $last_insert_nc_data_id;
  }
  else {
    return FALSE;
  }
}

/**
 * Returns coverage_period_end_date from last payment receipt.
 */
function insurance_contract_get_coverage_period_start_date_from_last_payment_receipt($nid, $offset) {
  $result = db_query("SELECT field_periodo_cobertura_rc_value2 AS coverage_period_start_date FROM field_data_field_periodo_cobertura_rc WHERE entity_id = (SELECT nc_child_nid FROM node_collection_data WHERE nc_parent_nid = $nid LIMIT $offset, 1)",
    array(
      ':nid' => $nid,
      ':offset' => $offset,
    ));

  foreach ($result as $key => $row) {
    return $row->coverage_period_start_date;
  }

  return FALSE;
}

/**
 * Returns payment type on readable format or returns payments number.
 */
function insurance_contract_get_payment_type_value($payment_type, $request = 'payments_number', $date = NULL) {
  // Get date and time.
  if ($request == 'coverage') {
    $dt = new DateTime($date);
  }

  switch ($payment_type) {
    case 'mensual':
      if ($request == 'format') {
        // Set month on letters.
        $payment_type_value = 'Mensual';
      }
      elseif ($request == 'coverage') {
        // Set date coverage.
        $dt->modify('+1 month');
        $payment_type_value = $dt->format('Y-m-d');
      }
      else {
        // Set payments number.
        $payment_type_value = 12;
      }
      break;

    case '3meses':
      if ($request == 'format') {
        // Set month on letters.
        $payment_type_value = '3 Meses';
      }
      elseif ($request == 'coverage') {
        // Set date coverage.
        $dt->modify('+1 month');
        $payment_type_value = $dt->format('Y-m-d');
      }
      else {
        // Set payments number.
        $payment_type_value = 3;
      }
      break;

    case 'trimestral':
      if ($request == 'format') {
        // Set month on letters.
        $payment_type_value = 'Trimestral';
      }
      elseif ($request == 'coverage') {
        // Set date coverage.
        $dt->modify('+3 month');
        $payment_type_value = $dt->format('Y-m-d');
      }
      else {
        // Set payments number.
        $payment_type_value = 4;
      }
      break;

    case 'cuatrimestral':
      if ($request == 'format') {
        // Set month on letters.
        $payment_type_value = 'Cuatrimestral';
      }
      elseif ($request == 'coverage') {
        // Set date coverage.
        $dt->modify('+4 month');
        $payment_type_value = $dt->format('Y-m-d');
      }
      else {
        // Set payments number.
        $payment_type_value = 3;
      }
      break;

    case 'semestral':
      if ($request == 'format') {
        // Set month on letters.
        $payment_type_value = 'Semestral';
      }
      elseif ($request == 'coverage') {
        // Set date coverage.
        $dt->modify('+6 month');
        $payment_type_value = $dt->format('Y-m-d');
      }
      else {
        // Set payments number.
        $payment_type_value = 2;
      }
      break;

    case 'anual':
      if ($request == 'format') {
        // Set month on letters.
        $payment_type_value = 'Anual';
      }
      elseif ($request == 'coverage') {
        // Set date coverage.
        $dt->modify('+1 year');
        $payment_type_value = $dt->format('Y-m-d');
      }
      else {
        // Set payments number.
        $payment_type_value = 1;
      }
      break;

    default:
      $payment_type_value = NULL;
  }

  return $payment_type_value;
}

/**
 * Converts decimal number to letters.
 */
function convert_number_to_letters($num, $fem = FALSE, $dec = TRUE) {
  $matuni[2] = "dos";
  $matuni[3] = "tres";
  $matuni[4] = "cuatro";
  $matuni[5] = "cinco";
  $matuni[6] = "seis";
  $matuni[7] = "siete";
  $matuni[8] = "ocho";
  $matuni[9] = "nueve";
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
  $matsub[3] = 'mill';
  $matsub[5] = 'bill';
  $matsub[7] = 'mill';
  $matsub[9] = 'trill';
  $matsub[11] = 'mill';
  $matsub[13] = 'bill';
  $matsub[15] = 'mill';
  $matmil[4] = 'millones';
  $matmil[6] = 'billones';
  $matmil[7] = 'de billones';
  $matmil[8] = 'millones de billones';
  $matmil[10] = 'trillones';
  $matmil[11] = 'de trillones';
  $matmil[12] = 'millones de trillones';
  $matmil[13] = 'de trillones';
  $matmil[14] = 'billones de trillones';
  $matmil[15] = 'de billones de trillones';
  $matmil[16] = 'millones de billones de trillones';

  // Zi hack.
  $float = explode('.', $num);
  $num = $float[0];
  $num = trim((string) @$num);

  if ($num[0] == '-') {
    $neg = 'menos ';
    $num = substr($num, 1);
  }
  else {
    $neg = '';
  }

  while (isset($num[0]) && $num[0] == '0') {
    $num = substr($num, 1);
  }

  if ($num[0] < '1' or $num[0] > 9) {
    $num = '0' . $num;
  }

  $zeros = TRUE;
  $punt = FALSE;
  $ent = '';
  $fra = '';

  for ($c = 0; $c < strlen($num); $c++) {
    $n = $num[$c];
    if (!(strpos(".,'''", $n) === FALSE)) {
      if ($punt) {
        break;
      }
      else {
        $punt = TRUE;
        continue;
      }
    }
    elseif (!(strpos('0123456789', $n) === FALSE)) {
      if ($punt) {
        if ($n != '0') {
          $zeros = FALSE;
        }

        $fra .= $n;
      }
      else {
        $ent .= $n;
      }
    }
    else {
      break;
    }
  }

  $ent = '     ' . $ent;

  if ($dec and $fra and !$zeros) {
    $fin = ' coma';

    for ($n = 0; $n < strlen($fra); $n++) {
      if (($s = $fra[$n]) == '0') {
        $fin .= ' cero';
      }
      elseif ($s == '1') {
        $fin .= $fem ? ' una' : ' un';
      }
      else {
        $fin .= ' ' . $matuni[$s];
      }
    }
  }
  else {
    $fin = '';
  }

  if ((int) $ent === 0) {
    return 'Cero ' . $fin;
  }

  $tex = '';
  $sub = 0;
  $mils = 0;
  $neutro = FALSE;

  while (($num = substr($ent, -3)) != '   ') {
    $ent = substr($ent, 0, -3);

    if (++$sub < 3 and $fem) {
      $matuni[1] = 'una';
      $subcent = 'as';
    }
    else {
      $matuni[1] = $neutro ? 'un' : 'uno';
      $subcent = 'os';
    }

    $t = '';
    $n2 = substr($num, 1);

    if ($n2 == '00') {
    }
    elseif ($n2 < 21) {
      $t = ' ' . $matuni[(int) $n2];
    }
    elseif ($n2 < 30) {
      $n3 = $num[2];

      if ($n3 != 0) {
        $t = 'i' . $matuni[$n3];
      }

      $n2 = $num[1];
      $t = ' ' . $matdec[$n2] . $t;
    }
    else {
      $n3 = $num[2];

      if ($n3 != 0) {
        $t = ' y ' . $matuni[$n3];
      }

      $n2 = $num[1];
      $t = ' ' . $matdec[$n2] . $t;
    }

    $n = $num[0];

    if ($n == 1) {
      $t = ' ciento' . $t;
    }
    elseif ($n == 5) {
      $t = ' ' . $matunisub[$n] . 'ient' . $subcent . $t;
    }
    elseif ($n != 0) {
      $t = ' ' . $matunisub[$n] . 'cient' . $subcent . $t;
    }

    if ($sub == 1) {
    }
    elseif (!isset($matsub[$sub])) {
      if ($num == 1) {
        $t = ' mil';
      }
      elseif ($num > 1) {
        $t .= ' mil';
      }
    }
    elseif ($num == 1) {
      $t .= ' ' . $matsub[$sub] . '?n';
    }
    elseif ($num > 1) {
      $t .= ' ' . $matsub[$sub] . 'ones';
    }

    if ($num == '000') {
      $mils++;
    }
    elseif ($mils != 0) {
      if (isset($matmil[$sub])) {
        $t .= ' ' . $matmil[$sub];
      }

      $mils = 0;
    }

    $neutro = TRUE;
    $tex = $t . $tex;
  }

  if (!isset($float[1])) {
    $float[1] = '00';
  }

  $tex = $neg . substr($tex, 1) . $fin;
  $end_num = ucfirst($tex) . ' pesos ' . $float[1] . '/100 M.N.';

  return $end_num;
}

/**
 * Returns grace period date.
 */
function insurance_contract_get_grace_period_date($grace_period, $validity_contract_start_date) {
  // Create new date and time object based on validity contract start date.
  $due_date = new DateTime($validity_contract_start_date);
  // Increase day on date based on grace period.
  $due_date->modify("+$grace_period day");
  // Format date.
  $due_date->format('Y-m-d H:i:s');

  return $due_date->getTimestamp();
}
