<?php

/**
 * @file
 * This files manipulates contract title.
 */

/**
 * Implements hook_node_insert().
 */
/*
function insurance_contract_node_insert($node) {
  switch ($node->type) {
    case 'poliza':
      insurance_contract_node_insert_poliza($node);
      break;
  }
}*/

/**
 * Implements hook_node_submit().
 */
function insurance_contract_node_submit($node) {
  if (empty($node->nid)) {
    switch ($node->type) {
      case 'poliza':
        insurance_contract_node_insert_poliza($node);
        watchdog('insurance_contract', '<pre>' . print_r('insurance_contract_node_submit', TRUE) . '</pre>');
        break;
    }
  }
}

/**
 * Implements hook_node_insert().
 */
function insurance_contract_node_insert($node) {
  if ($node->type != 'poliza' && empty($node->nid)) {
    return false;
  }

  // Create payment receipts for contract.
  $contract = $node;
  for ($i = 0; $i < 3; $i++) {
    $entity_type = 'node';
    $entity = entity_create($entity_type, array('type' => 'recibo_contrato'));
    $payment_receipt = entity_metadata_wrapper($entity_type, $entity);
    $payment_receipt->title = 'title' . ($i + 2);
    //node_collection_api_add_relationship_instance($contract, $payment_receipt);
    $payment_receipt->save();

    watchdog('insurance_contract', '<pre>' . print_r($parent_instance, TRUE) . '</pre>');
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
