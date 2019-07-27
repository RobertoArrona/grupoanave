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

  // Get next node id to be inserted.
  $nid = $node->nid;

  for ($i = 1; $i <= $payment_receipts_number; $i++) {
    // Create payment receipt node.
    $entity = entity_create('node', $values);
    $payment_receipt = entity_metadata_wrapper('node', $entity);

    // Prepare payment receipt values.
    $payment_receipt_values = insurance_contract_prepare_payment_receipt_values($node, $nid, $i);

    // Add payment receipt values and save payment receipt node.
    insurance_contract_save_payment_receipt_node($payment_receipt, $payment_receipt_values);
  }
}

/**
 * Prepares payment receipt values and returns array with values.
 */
function insurance_contract_prepare_payment_receipt_values($node, $nid, $i) {
  // Add nid value.
  $payment_receipt_values['nid'] = $nid;
  // Get payment receipt folio.
  $payment_receipt_values['payment_receipt_folio'] = insurance_contract_payment_get_receipt_number();
  // Get contract folio.
  $payment_receipt_values['contrac_folio'] = $node->title;

  return $payment_receipt_values;
}

/**
 * Adds payment receipt values and saves payment receipt node.
 */
function insurance_contract_save_payment_receipt_node(&$payment_receipt, $payment_receipt_values) {
  // Validate if node collection relationship is created.
  if (!insurance_contract_create_node_collection_relationship($payment_receipt_values['nid'])) {
    return FALSE;
  }

  /*if (isset($payment_receipt_values['payment_receipt_folio'])) {
  if (!empty($payment_receipt_values['payment_receipt_folio']) {
  $payment_receipt->field_codigo_de_barras_rc->set($contrac_folio);
  }
  }*/

  // Create node collection relationship.
  $node_collection_relationship = insurance_contract_create_node_collection_relationship($payment_receipt_values['nid']);

  // Set payment receipt folio.
  $payment_receipt->title->set($payment_receipt_values['payment_receipt_folio']);

  // Set contract folio.
  $payment_receipt->field_codigo_de_barras_rc->set($payment_receipt_values['contrac_folio']);

  // Save payment receipt node.
  $payment_receipt->save();
}
