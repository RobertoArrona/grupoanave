<?php

/**
 * @file
 * This files manipulates contract title.
 */

/**
 * Implements hook_node_submit().
 */
function insurance_contract_node_submit($node) {
  if (empty($node->nid)) {
    switch ($node->type) {
      case 'poliza':
        insurance_contract_node_insert_poliza($node);
        break;
    }
  }
}

/**
 * Implements hook_node_insert().
 */
function insurance_contract_node_insert($node) {
  if (!empty($node->nid)) {
    // Create payment receipts.
    insurance_contract_create_payment_receipts($node);
  }
}

/**
 * Helper for insurance_contract_node_insert when the node type is poliza.
 */
function insurance_contract_node_insert_poliza($node) {
  $i = $j = 0;
  while ($j == 0) {
    $contract_folio = insurance_contract_contract_folio_get($i);
    if (insurance_contract_contract_folio_exists($contract_folio, $node->nid)) {
      $i++;
    }
    else {
      $j = 1;
    }
  }

  // Set contract filio.
  $node->title = $contract_folio;

  // Increase contract number.
  insurance_contract_contract_number_increase($i);
}

/**
 * Creates payment receipts.
 */
function insurance_contract_create_payment_receipts($node) {
  if (!isset($node->field_poliza_forma_pago)) {
    return FALSE;
  }

  // Prepare entity values.
  $values = array(
    'type' => 'recibo_contrato',
    'status' => 0,
    'comment' => 0,
    'promote' => 0,
  );

  // Get payment receipts number, based on payment type.
  $payment_type = $node->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
  $payment_receipts_number = insurance_contract_get_payment_type_value($payment_type);

  // Get validity contract start date.
  $validity_contract_start_date = $node->field_poliza_vigencia[LANGUAGE_NONE][0]['value'];

  // Get grace period.
  $grace_period = $node->field_periodo_de_gracia[LANGUAGE_NONE][0]['value'];

  // Create parameters array.
  $parameters = [
    'nid' => $node->nid,
    'node_title' => $node->title,
    'payment_type' => $payment_type,
    'payment_receipts_number' => $payment_receipts_number,
    'first_payment' => $node->field_poliza_prima_1er_recibo[LANGUAGE_NONE][0]['value'],
    'subsequent_payment' => $node->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value'],
    'validity_contract_start_date' => $validity_contract_start_date,
    'due_date' => insurance_contract_get_grace_period_date($grace_period),
    'issuance' => $node->field_derecho_de_poliza2[LANGUAGE_NONE][0]['value'],
  ];

  for ($i = 1; $i <= $payment_receipts_number; $i++) {
    // Create payment receipt node.
    $entity = entity_create('node', $values);
    $payment_receipt = entity_metadata_wrapper('node', $entity);

    // Add payment receipt values and save payment receipt node.
    insurance_contract_save_payment_receipt_node($parameters, $i, $payment_receipt);
  }
}

/**
 * Adds payment receipt values and saves payment receipt node.
 */
function insurance_contract_save_payment_receipt_node($parameters, $i, &$payment_receipt) {
  // Validate if node collection relationship is created.
  if (!insurance_contract_create_node_collection_relationship($parameters['nid'])) {
    return FALSE;
  }

  // Validate first payment receipt.
  if ($i == 1) {
    // Set first payment.
    $payment_receipt->field_primer_pago_rc->set($parameters['first_payment']);
    // Set subsequent payment.
    $payment_receipt->field_pago_subsecuente_rc->set(0);
    // Set amount with letter.
    $payment_receipt->field_importe_con_letra_rc->set(strtoupper(convert_number_to_letters($parameters['first_payment'])));
    // Set coverage period start and end date,
    // based on validity contract start date.
    $payment_receipt->field_periodo_cobertura_rc->set(array(
      'value' => $parameters['validity_contract_start_date'],
      'value2' => insurance_contract_get_payment_type_value($parameters['payment_type'], 'coverage', $parameters['validity_contract_start_date']),
      'timezone' => 'America/Mazatlan',
      'timezone_db' => 'America/Mazatlan',
    ));
  }
  else {
    // Set subsequent payment.
    $payment_receipt->field_pago_subsecuente_rc->set($parameters['subsequent_payment']);
    // Set first payment.
    $payment_receipt->field_primer_pago_rc->set(0);
    // Set amount with letter.
    $payment_receipt->field_importe_con_letra_rc->set(strtoupper(convert_number_to_letters($parameters['subsequent_payment'])));
    // Set coverage period start and end date.
    if ($coverage_period_start_date = insurance_contract_get_coverage_period_start_date_from_last_payment_receipt($parameters['nid'], ($i - 2))) {
      $payment_receipt->field_periodo_cobertura_rc->set(array(
        'value' => $coverage_period_start_date,
        'value2' => insurance_contract_get_payment_type_value($parameters['payment_type'], 'coverage', $coverage_period_start_date),
        'timezone' => 'America/Mazatlan',
        'timezone_db' => 'America/Mazatlan',
      ));
    }
  }

  // Get and set payment receipt folio.
  $payment_receipt_folio = insurance_contract_payment_get_receipt_number();
  $payment_receipt->title->set($payment_receipt_folio);

  // Set contract node id on contract field.
  $payment_receipt->field_poliza->set($parameters['nid']);

  // Set contract folio on bars code field.
  $payment_receipt->field_codigo_de_barras_rc->set($parameters['node_title']);

  // Set receipt serie.
  $payment_receipt->field_serie_rc->set($i . '/' . $parameters['payment_receipts_number']);

  // Set receipt due date.
  $payment_receipt->field_vencimiento_rc->set($parameters['due_date']);

  // Set receipt issuance.
  $payment_receipt->field_emision_recibo_ref_rc->set($parameters['issuance']);

  // Set expedition date based on current date.
  $date_time = new DateTime(date('Y-m-d 00:00:00'));
  $payment_receipt->field_fecha_de_expedicion_rc->set($date_time->getTimestamp());

  // Save payment receipt node.
  $payment_receipt->save();
}
