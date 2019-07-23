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
 * Returns payment type on readable format.
 */
function get_payment_type_format($payment_type) {
  $payment_type_format = '';

  switch ($payment_type) {
    case 'mensual':
      $payment_type_format = 'Mensual';
      break;

    case '3meses':
      $payment_type_format = '3 Meses';
      break;

    case 'trimestral':
      $payment_type_format = 'Trimestral';
      break;

    case 'cuatrimestral':
      $payment_type_format = 'Cuatrimestral';
      break;

    case 'semestral':
      $payment_type_format = 'Semestral';
      break;

    case 'anual':
      $payment_type_format = 'Anual';
      break;

    default:
      $payment_type_format = '';
  }

  return $payment_type_format;
}
