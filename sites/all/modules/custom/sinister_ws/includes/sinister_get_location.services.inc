<?php

/**
 * @file
 * Retrieve a map location sinister.
 */

/**
 * Return data from map location sinister.
 */
function sinister_ws_location_resource_retrieve($nid) {
  $node = node_load($nid);
  $map = array();

  if (!empty($node->field_mapa_siniestro[LANGUAGE_NONE][0]['lat'])) {
    // Get latitude from sinister map.
    $lat = $node->field_mapa_siniestro[LANGUAGE_NONE][0]['lat'];
    // Get longitude from sinister map.
    $lng = $node->field_mapa_siniestro[LANGUAGE_NONE][0]['lng'];
    // Add values to array.
    $map['latitude'] = $lat;
    $map['longitude'] = $lng;
  }
  else {
    $map['latitude'] = NULL;
    $map['longitude'] = NULL;
  }

  return $map;
}
