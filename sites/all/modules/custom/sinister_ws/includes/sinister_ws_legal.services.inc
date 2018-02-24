<?php

/**
 * @file
 * Retrieve legal info from nid.
 */

/**
 * Return data legal from sinister.
 */
function sinister_ws_legal_resource_retrieve($nid) {
  $objects = array();
  if (($node = node_load($nid))) {
    // Create return object.
    $return_obj = array(
      'id' => $node->nid,
      'titulo' => $node->title,
      'created' => date('Y/m/d H:s A', $node->created),
      'texto' => $node->body[LANGUAGE_NONE][0]['value'],
    );
    $objects[$nid] = $return_obj;
  }
  return $objects;
}
