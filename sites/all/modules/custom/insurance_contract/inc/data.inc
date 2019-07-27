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
  $result = db_query("{SELECT MAX($field) + 1 AS $field FROM {$table} ORDER BY $field ASC}");

  foreach ($result as $row) {
    return $row->$field;
  }
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
 * Returns payment type on readable format or returns payments number.
 */
function insurance_contract_get_payment_type_value($payment_type, $request = 'payments_number') {
  switch ($payment_type) {
    case 'mensual':
      $payment_type_value = $request == 'format' ? 'Mensual' : 12;
      break;

    case '3meses':
      $payment_type_value = $request == 'format' ? '3 Meses' : 3;
      break;

    case 'trimestral':
      $payment_type_value = $request == 'format' ? 'Trimestral' : 4;
      break;

    case 'cuatrimestral':
      $payment_type_value = $request == 'format' ? 'Cuatrimestral' : 3;
      break;

    case 'semestral':
      $payment_type_value = $request == 'format' ? 'Semestral' : 2;
      break;

    case 'anual':
      $payment_type_value = $request == 'format' ? 'Anual' : 1;
      break;

    default:
      $payment_type_value = $request == 'format' ? '' : 0;
  }

  return $payment_type_value;
}
