<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_views_pre_render().
 */
function payment_receipt_views_pre_render(&$view) {
  if ($view->name == 'contract_receipts' && $view->current_display == 'page') {
    foreach ($view->result as $key => $result) {
      if (empty($result->field_field_codigo_de_barras_rc)) {
        $payment_type = NULL;
        $total_premium = NULL;

        // Set default payment type and total premium values.
        $result->field_field_serie_rc[0]['rendered']['#markup'] = $payment_type;
        $result->field_field_importe_con_letra_rc[0]['rendered']['#markup'] = $total_premium;
      }
      else {
        // Get contract folio.
        $contract_folio = $result->field_field_codigo_de_barras_rc[0]['rendered']['#markup'];
        // Convert contract folio to lower case.
        $contract_folio_lower = strtolower($contract_folio);

        // Set contract link.
        $contract_nid = payment_receipt_get_contract_nid($contract_folio);
        // Create a link directly to contract node.
        $result->field_field_codigo_de_barras_rc[0]['rendered']['#markup'] = "<a href=\"/polizas/$contract_folio_lower-$contract_nid\">$contract_folio</a>";

        // Set payment type.
        $payment_type = payment_receipt_get_contract_data('field_poliza_forma_pago', $contract_folio);
        // Get payment type on readable format.
        $payment_type = get_payment_type_format($payment_type);
        // On this case, field_serie is not important,
        // is just used to store payment type value.
        $result->field_field_serie_rc[0]['rendered']['#markup'] = $payment_type;

        // Set total premium.
        $total_premium = payment_receipt_get_contract_data('field_poliza_prima_total', $contract_folio);
        // On this case, field_importe_con_letra is not important,
        // is just used to store total premium value.
        $result->field_field_importe_con_letra_rc[0]['rendered']['#markup'] = '$' . number_format($total_premium, 2);
      }
    }
  }
}
