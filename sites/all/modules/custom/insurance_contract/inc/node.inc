<?php

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

}
*/


/**
 * Implements hook_node_submit().
 */
function insurance_contract_node_submit($node){
	if(empty($node ->nid)) {
		switch ($node ->type){
			case 'poliza':
				insurance_contract_node_insert_poliza($node);
				break;
		  }
	}
} 
 
	

/**
 * Helper function for insurance_contract_node_insert when the node type is poliza.
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
  $node->title = $contract_folio;
  insurance_contract_contract_number_increase($i);
}
