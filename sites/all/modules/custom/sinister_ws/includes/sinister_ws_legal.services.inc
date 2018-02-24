<?php

/**
 * [sinister_ws_resource_retrieve] definition.
 * Returns the information about a sinister
 * @param $nid The nid of the housing_scheme node.
 * @return array The node processed information array.
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


