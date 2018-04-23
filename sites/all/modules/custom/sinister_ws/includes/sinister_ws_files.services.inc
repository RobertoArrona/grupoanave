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
  for ($i = 0; $i < count($node->field_siniestro_archivo[LANGUAGE_NONE]); $i++) {
    $fc_archivo[$i] = field_collection_item_load($node->field_siniestro_archivo[LANGUAGE_NONE][$i]['value'], $reset = FALSE);
    $results[] = get_image($fc_archivo[$i]);
  }
  return $results;
}

/**
 * Returns value from field_siniestros_archivo.
 */
function get_image($fc_archivo) {
  $percent = 0;
  $pathImages = array();
  // Get value from field_visualizador.
  $field_image = $fc_archivo->field_visualizador;
  // Get number of images from field_visualizador.
  $items = count($field_image[LANGUAGE_NONE]);
  for ($i = 0; $i < $items; $i++) {
    $images = array();
    $images[$i] = $field_image[LANGUAGE_NONE][$i]['uri'];
    $filename = $field_image[LANGUAGE_NONE][$i]['filename'];
    $comment_files = $fc_archivo->field_archivo_comentario[LANGUAGE_NONE][$i]['value'];
    $path = file_create_url($images[$i]);
    $width = $field_image[LANGUAGE_NONE][$i]['metadata']['width'];
    $height = $field_image[LANGUAGE_NONE][$i]['metadata']['height'];
    $date = $fc_archivo->field_fecha[LANGUAGE_NONE][$i]['value'];
    $images['url'][$i] = $path;
    $images['width'][$i] = $width;
    $images['height'][$i] = $height;
    $images['filename'][$i] = $filename;
    $images['date'][$i] = date('Y/m/d h:i a', $date);
    $images['comment'][$i] = $comment_files;
    if (isset($field_image[LANGUAGE_NONE][$i]['uri'])) {
      $percent = 1.538461538461538;
    }
  }
  $images['percent'] = $percent;
  return $images;
}
