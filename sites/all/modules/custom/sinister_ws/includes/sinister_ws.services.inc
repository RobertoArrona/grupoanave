<?php

/**
 * [sinister_ws_resource_retrieve] definition.
 * Returns the information about a sinister
 * @param $nid The nid of the housing_scheme node.
 * @return array The node processed information array.
 */
function sinister_ws_resource_retrieve($uid) {
  $sinisters = sinister_get_ajustador_sinisters($uid, 1);
  $objects = array();
  foreach ($sinisters as $nid => $sinister) {
    if (!($node = node_load($nid))) {
      continue;
    }

    // Create return object.
    $return_obj = array(
      'id' => $node->nid,
      'title' => $node->title,      
      'created' => date('Y/m/d H:s A', $node->created),
    );

    if (isset($node->field_poblacion[LANGUAGE_NONE][0]['value'])) {
      $return_obj['city'] = $node->field_poblacion[LANGUAGE_NONE][0]['value'];
    }

    if (isset($node->field_lugar_referencias[LANGUAGE_NONE][0]['value'])) {
      $return_obj['address_references'] = $node->field_lugar_referencias[LANGUAGE_NONE][0]['value'];
    }

    $objects[$nid] = $return_obj;
  }

  return $objects;
}

