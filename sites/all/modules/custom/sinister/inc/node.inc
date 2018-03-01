<?php

/**
 * @file
 * Increments sinister folio.
 */

/**
 * Implements hook_node_submit().
 */
function sinister_node_submit($node) {
  if (empty($node->nid)) {
    switch ($node->type) {
      case 'siniestro':
        sinister_node_insert_siniestro($node);
        break;
    }
  }
}

/**
 * Helper function for sinister_node_insert when the node type is siniestro.
 */
function sinister_node_insert_siniestro($node) {
  $i = $j = 0;
  while ($j == 0) {
    $sinister_folio = sinister_number_folio_get($i);
    if (sinister_number_folio_exists($sinister_folio, $node->nid)) {
      $i++;
    }
    else {
      $j = 1;
    }
  }
  $node->title = $sinister_folio;
  sinister_number_increase($i);
}
