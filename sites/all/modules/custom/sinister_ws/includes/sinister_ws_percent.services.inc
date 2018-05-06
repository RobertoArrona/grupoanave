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

  // Get field collection field_siniestro_archivo item from node.
  $fc_archivo[0] = field_collection_item_load($node->field_siniestro_archivo[LANGUAGE_NONE][0]['value'], $reset = FALSE);
  $percent['images'] = get_image($fc_archivo[0]);

  // Get driver information.
  $driver_data = entity_load_single('field_collection_item', $node->field_conductor[LANGUAGE_NONE][0]['value']);
  $percent['driver'] = get_driver($driver_data);

//   return $percent;
  return $percent['driver'];
}

/**
 * Returns percent from field_siniestros_archivo.
 */
function get_image($fc_archivo) {
  $count = 0;
  $percent = 0;

  if (!empty($fc_archivo->field_visualizador)) {
    // Get value from field_visualizador.
    $field_image = $fc_archivo->field_visualizador;
  }

  $images = array();

  if (!empty($fc_archivo->field_fecha[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

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
function get_driver($driver_data) {
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

  if ($driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'] == '1' || $driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'] == '0') {
    $count++;
    $valueReport = $driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'];
  }

  if ($count > 0) {
    $percent = 25;
  }

//   return $percent;
  return $valueReport;
}
