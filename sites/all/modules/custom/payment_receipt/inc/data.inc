<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Returns the Contract payment receip folio.
 *
 * @return INT
 *   The contract payment receip folio.
 */
function payment_receipt_receipt_number_folio_get() {
  $payment_receipt_number = (variable_get('payment_receipt_receipt_number', 0));
  $payment_receipt_number_string = sprintf("%'.07d", $payment_receipt_number);
  $payment_receipt_folio = "{$payment_receipt_number_string}";
  return $payment_receipt_folio;
}

/**
 * Increases the Payment Receipt Number by 1.
 */
function payment_receipt_receipt_number_increase() {
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
 * Returns TRUE if the Payment Receipt folio exists.
 */
function payment_receipt_receipt_number_folio_exists($payment_receipt_folio) {
  $type = 'recibo_contrato';
  $result = db_query("SELECT title FROM {node} WHERE type = :type AND title = :title",
    array(
      ':type' => $type,
      ':title' => $payment_receipt_folio,
    ));
  foreach ($result as $row) {
    return $row->title;
  }
  return FALSE;
}

/**
 * Increases the Payment Receipt new folio.
 */
function payment_receipt_receipt_new_folio() {
  $type = 'recibo_contrato';
  $result = db_query("SELECT MAX(title) + 1 AS newfolio FROM {node} WHERE type = :type ORDER BY title ASC;",
  array(
    ':type' => $type,
  ));
  foreach ($result as $row) {
    return $row->newfolio;
  }
}

/**
 * Returns contract nid.
 */
function payment_receipt_get_contract_nid($contract_folio) {
  $type = 'poliza';

  $result = db_query("SELECT nid FROM node  WHERE type = :type AND title = :title",
    array(
      ':type' => $type,
      ':title' => $contract_folio,
    ));

  foreach ($result as $row) {
    return $row->nid;
  }

  return FALSE;
}

/**
 * Returns all recibo_contrato and poliza node having a node relationship.
 */
function payment_receipt_get_all_payment_receipt_contract_nids() {
  $result = db_query("SELECT NCD.nc_parent_nid AS nc_parent_nid, NCD.nc_child_nid AS nc_child_nid FROM node AS N INNER JOIN node_collection_data AS NCD ON N.nid = NCD.nc_child_nid WHERE N.type = 'recibo_contrato' ORDER BY NCD.nc_child_nid ASC");

  foreach ($result as $key => $row) {
    $payment_receipt_nids[$key]['nc_parent_nid'] = $row->nc_parent_nid;
    $payment_receipt_nids[$key]['nc_child_nid'] = $row->nc_child_nid;
  }

  if ($payment_receipt_nids) {
    return $payment_receipt_nids;
  }
  else {
    return FALSE;
  }
}

/**
 * Returns contract data.
 */
function payment_receipt_get_contract_data($field_name, $contract_folio) {
  $type = 'poliza';

  $result = db_query("{SELECT IFN.{$field_name}_value FROM {node} AS N INNER JOIN {field_data_{$field_name}} AS IFN ON N.nid = IFN.entity_id WHERE N.type = :type AND N.title = :title}",
    array(
      ':type' => $type,
      ':title' => $contract_folio,
    ));

  foreach ($result as $row) {
    return $row->{"{$field_name}_value"};
  }

  return FALSE;
}

/**
 * Returns spanish date format (dd/Month/yyyy).
 */
function payment_receipt_get_spanish_date_format($date) {
  $date = new DateTime($date);

  $day = $date->format('d');
  $month = $date->format('n');
  $year = $date->format('Y');

  switch ($month) {
    case 1:
      $spanishMonth = "Enero";
      break;

    case 2:
      $spanishMonth = "Febrero";
      break;

    case 3:
      $spanishMonth = "Marzo";
      break;

    case 4:
      $spanishMonth = "Abril";
      break;

    case 5:
      $spanishMonth = "Mayo";
      break;

    case 6:
      $spanishMonth = "Junio";
      break;

    case 7:
      $spanishMonth = "Julio";
      break;

    case 8:
      $spanishMonth = "Agosto";
      break;

    case 9:
      $spanishMonth = "Septiembre";
      break;

    case 10:
      $spanishMonth = "Octubre";
      break;

    case 11:
      $spanishMonth = "Noviembre";
      break;

    case 12:
      $spanishMonth = "Diciembre";
      break;
  }

  return "{$day}/{$spanishMonth}/{$year}";
}
