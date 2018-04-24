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
  $count = count($node->field_siniestro_archivo[LANGUAGE_NONE]);

  $results = array();

  // Get field collection field_siniestro_archivo item from node.
  for ($i = 0; $i < $count; $i++) {
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

  if (!empty($fc_archivo->field_visualizador)) {
    // Get value from field_visualizador.
    $field_image = $fc_archivo->field_visualizador;
    // Get number of images from field_visualizador.
    $items = count($field_image[LANGUAGE_NONE]);
  }
  else {
    $items = 0;
  }

  $images = array();

  for ($i = 0; $i < $items; $i++) {

    $j = $i + 1;

    if (!empty($field_image[LANGUAGE_NONE][$i]['uri'])) {
      $uri = $field_image[LANGUAGE_NONE][$i]['uri'];
      $path = file_create_url($uri);
      $images["image_$j"]['url'] = $path;
      $percent = 1.538461538461538;
    }

    if (!empty($field_image[LANGUAGE_NONE][$i]['metadata']['width'])) {
      $width = $field_image[LANGUAGE_NONE][$i]['metadata']['width'];
      $images["image_$j"]['width'] = $width;
    }

    if (!empty($field_image[LANGUAGE_NONE][$i]['metadata']['height'])) {
      $height = $field_image[LANGUAGE_NONE][$i]['metadata']['height'];
      $images["image_$j"]['height'] = $height;
    }

    if (!empty($field_image[LANGUAGE_NONE][$i]['filename'])) {
      $filename = $field_image[LANGUAGE_NONE][$i]['filename'];
      $images["image_$j"]['filename'] = $filename;
    }

    if (!empty($fc_archivo->field_fecha[LANGUAGE_NONE][$i]['value'])) {
      $date = $fc_archivo->field_fecha[LANGUAGE_NONE][$i]['value'];
      $images["image_$j"]['date'] = date('Y/m/d h:i a', $date);
    }

    if (!empty($fc_archivo->field_archivo_comentario[LANGUAGE_NONE][$i]['value'])) {
      $comment_files = $fc_archivo->field_archivo_comentario[LANGUAGE_NONE][$i]['value'];
      $images["image_$j"]['comment'] = $comment_files;
    }
  }

  $images['percent'] = $percent;
  return $images;
}
