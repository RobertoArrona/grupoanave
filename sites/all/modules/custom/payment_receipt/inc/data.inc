<?php

/**
 * Returns the Contract Folio.
 * @return INT The contract folio.
 */
function payment_receipt_receipt_number_folio_get() {
  $i = 1;
  $payment_receipt_number = (variable_get('payment_receipt_receipt_number', 0) + $i);
  $payment_receipt_number_string = sprintf("%'.07d", $payment_receipt_number);
  $payment_receipt_folio = "{$payment_receipt_number_string}";
  return $payment_receipt_folio;
}

/**
 * Increases the Payment Receipt Number by 1.
 */
function payment_receipt_receipt_number_increase() {
  if (!($payment_receipt_number = variable_get('payment_receipt_receipt_number', false))) {
    return false;
  }

  $payment_receipt_number = intval($payment_receipt_number) + 1;
//   print_r($payment_receipt_number);exit;
  if ($payment_receipt_number > 9999999) {
    $payment_receipt_number = 1000000;
  }

  variable_set('payment_receipt_receipt_number', $payment_receipt_number);
  return $payment_receipt_number;
}

function payment_receipt_receipt_number_folio_exists($payment_receipt_folio) {
  $type = 'recibo_contrato';
  $result = db_query("SELECT title FROM {node} WHERE type = :type AND title = :title",
  array(
  ':type' => $type, ':title' => $payment_receipt_folio,
  ));
  foreach ($result as $row) {
    return $row->title;
  }
  return false;
}

function payment_receipt_receipt_new_folio() {
  $type = 'recibo_contrato';
  $result = db_query("SELECT MAX(title) + 1 AS newfolio FROM {node} WHERE type = :type ORDER BY title ASC;",
  array(
  ':type' => $type,
  ));
  foreach ($result as $row) {
    print_r($row->newfolio);exit;
    return $row->newfolio;
  }
}