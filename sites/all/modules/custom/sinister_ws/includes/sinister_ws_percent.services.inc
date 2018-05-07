<?php

/**
 * @file
 * Retrieve a filling percent of sinister fields from nid.
 */

/**
 * Return data from sinister arrival.
 */
function sinister_ws_percent_resource_retrieve($nid) {

  $node = node_load($nid);

  $percent = array();

  // Declare array index.
  $percent['images'] = 0;
  $percent['driver'] = 0;
  $percent['injuries'] = 0;
  $percent['term'] = 0;
  $percent['total'] = 0;

  if (!empty($node->field_siniestro_archivo[LANGUAGE_NONE][0]['value'])) {
    // Get field collection id.
    $fc_id = $node->field_siniestro_archivo[LANGUAGE_NONE][0]['value'];
    // Get field collection field_siniestro_archivo item from node.
    $fc_archivo[0] = field_collection_item_load($fc_id, $reset = FALSE);
    $percent['images'] = get_image_percent($fc_archivo[0]);
  }

  if (!empty($node->field_conductor[LANGUAGE_NONE][0]['value'])) {
    // Get field collection id.
    $fc_id = $node->field_conductor[LANGUAGE_NONE][0]['value'];
    // Get field collection field_conductor item from node.
    $driver_data = entity_load_single('field_collection_item', $fc_id);
    $percent['driver'] = get_driver_percent($driver_data);
  }

  if (!empty($node->field_lesionado[LANGUAGE_NONE][0]['value'])) {
    // Get field collection id.
    $fc_id = $node->field_lesionado[LANGUAGE_NONE][0]['value'];
    // Get field collection field_lesionado item from node.
    $fc_injuries[0] = field_collection_item_load($fc_id, $reset = FALSE);
    $percent['injuried'] = get_injuried_percent($fc_injuries[0]);
  }

  if (!empty($nid)) {
    $percent['term'] = get_term_percent();
  }

  return $percent;
}

/**
 * Returns percent from field_siniestros_archivo.
 */
function get_image_percent($fc_archivo) {
  $count = 0;
  $percent = 0;

  if (!empty($fc_archivo->field_visualizador)) {
    // Get value from field_visualizador.
    $field_image = $fc_archivo->field_visualizador;
  }

  $images = array();

  if (!empty($fc_archivo->field_archivo_comentario[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['uri'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['metadata']['width'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['metadata']['height'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['filename'])) {
    $count++;
  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}

/**
 * Returns percent from field_conductor.
 */
function get_driver_percent($driver_data) {
  $count = 0;
  $percent = 0;

  if (!empty($driver_data->field_nombre[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $count++;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $count++;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $count++;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $count++;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $count++;
  }

  if (!empty($driver_data->field_rfc[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($driver_data->field_licencia_numero[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($driver_data->field_licencia_tipo[LANGUAGE_NONE][0]['tid'])) {
    $count++;
  }

  if (!empty($driver_data->field_licencia_alta_lugar[LANGUAGE_NONE][0]['tid'])) {
    $count++;
  }

  if (!empty($driver_data->field_licencia_alta_fecha[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($driver_data->field_telefono[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if ($driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'] == '0') {
    $count++;
  }

  if (!empty($driver_data->field_nombre_quien_reporta[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($driver_data->field_telefono_quien_reporta[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}

/**
 * Returns percent from field_lesionado.
 */
function get_injuried_percent($fc_injuries) {
  $count = 0;
  $percent = 0;

  if (!empty($fc_injuries->field_lesionado_nombre[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_edad[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_telefono[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (isset($fc_injuries->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($fc_injuries->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
    $count++;
  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}

/**
 * Returns percent from term fields.
 */
function get_term_percent() {
  $count = 0;
  $percent = 0;

  if (!empty($fc_archivo->field_visualizador)) {
    // Get value from field_visualizador.
    $field_image = $fc_archivo->field_visualizador;
  }

  $images = array();

  if (!empty($fc_archivo->field_archivo_comentario[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['uri'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['metadata']['width'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['metadata']['height'])) {
    $count++;
  }

  if (!empty($field_image[LANGUAGE_NONE][0]['filename'])) {
    $count++;
  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}
