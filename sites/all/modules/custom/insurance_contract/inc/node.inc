<?php

/**
 * Implements hook_node_insert().
 */
function insurance_contract_node_insert($node) {
  switch ($node->type) {
    case 'poliza':
      insurance_contract_node_insert_poliza($node);
      break;
  }

}

/**
 * Helper function for insurance_contract_node_insert when the node type is poliza.
 */
function insurance_contract_node_insert_poliza($node) {
  $contract_folio = insurance_contract_contract_folio_get();

  if ($contract_folio == $node->title) {
    insurance_contract_contract_number_increase();
  }
}
