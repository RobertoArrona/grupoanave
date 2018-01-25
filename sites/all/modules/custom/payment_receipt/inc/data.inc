<?php

/**
 * Returns the Contract Folio.
 * @return INT The contract folio.
 */
function payment_receipt_receipt_number_folio_get($i = 1) {
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
    $payment_receipt_number = 0;
  }

  variable_set('payment_receipt_receipt_number', $payment_receipt_number);
  return true;
}
