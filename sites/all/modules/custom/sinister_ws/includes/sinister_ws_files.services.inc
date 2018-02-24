<?php

/**
 * @file
 * Retrieve file info from nid.
 */

/**
 * Return file data from sinister.
 */
function sinister_ws_archivos_resource_retrieve($nid) {
  $node = node_load($nid);
  // Get field collection field_siniestro_archivo item from node.
  $fc_archivo = field_collection_item_load($node->field_siniestro_archivo[LANGUAGE_NONE][0]['value'], $reset = FALSE);
  $result = get_image($fc_archivo);
  return $result;
}

/**
 * Returns value from field_siniestros_archivo.
 */
function get_image($fc_archivo) {
  $base_url = $GLOBALS['base_root'];
  $pathImages = array();
  // Get value from field_visualizador.
  $field_image = $fc_archivo->field_visualizador;
  // Get number of images from field_visualizador.
  $items = count($field_image[LANGUAGE_NONE]);
  for ($i = 0; $i < $items; $i++) {
    $images = array();
    $images[$i] = $field_image[LANGUAGE_NONE][$i]['uri'];
    $path = $base_url . drupal_realpath($images[$i]);
    $pathImages[$i] = $path;
  }
  return $pathImages;
}
