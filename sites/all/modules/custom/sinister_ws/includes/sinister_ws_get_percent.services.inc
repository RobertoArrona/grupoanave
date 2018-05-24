<?php

/**
 * @file
 * Retrieve sinister percent and arrival data from nid.
 */

/**
 * Return sinister percent and arrival data.
 */
function sinister_ws_percent_resource_retrieve($nid) {

  $node = node_load($nid);

  $sinister = array();
  $percent = array();

  // Declare array index.
  $percent['files'] = 0;
  $percent['driver'] = 0;
  $percent['injuries'] = 0;
  $percent['term'] = 0;
  $percent['total'] = 0;

  if (!empty($node->field_siniestro_archivo[LANGUAGE_NONE][0]['value'])) {
    $percent['files'] = get_files_percent($node);
  }

  if (!empty($node->field_conductor[LANGUAGE_NONE][0]['value'])) {
    $percent['driver'] = get_driver_percent($node);
  }

  if (!empty($node->field_lesionado[LANGUAGE_NONE][0]['value'])) {
    $percent['injuries'] = get_injuries_percent($node);
  }

  if (!empty($nid)) {
    $percent['term'] = get_term_percent($node);
  }

  // Sum all percents.
  $percent['total'] = intval($percent['files'], 10) + intval($percent['driver'], 10) + intval($percent['injuries'], 10) + intval($percent['term'], 10);

  // Add arrival data.
  $arrival = sinister_ws_arrival_resource_retrieve($node);

  $sinister['percent'] = $percent;
  $sinister['arrival'] = $arrival;

  return $sinister;
}

/**
 * Returns percent from field_siniestros_archivo.
 */
function get_files_percent($node) {
  $count = 0;
  $percent = 0;
  $fc_count = count($node->field_siniestro_archivo[LANGUAGE_NONE]);

  for ($i = 0; $i < $fc_count; $i++) {

    // Get field collection id.
    $fc_id = $node->field_siniestro_archivo[LANGUAGE_NONE][$i]['value'];
    // Get field collection field_siniestro_archivo item from node.
    $fc_archivo[$i] = field_collection_item_load($fc_id, $reset = FALSE);

    if (!empty($fc_archivo[$i]->field_visualizador)) {
      // Get value from field_visualizador.
      $field_image = $fc_archivo[$i]->field_visualizador;
    }

    if (!empty($fc_archivo[$i]->field_documentos)) {
      // Get value from field_documentos.
      $field_document = $fc_archivo[$i]->field_documentos;
    }

    $images = array();

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

    if (!empty($field_document[LANGUAGE_NONE][0]['filename'])) {
      $count++;
    }

  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}

/**
 * Returns percent from field_conductor.
 */
function get_driver_percent($node) {
  $count = 0;
  $percent = 0;

  // Get field collection id.
  $fc_id = $node->field_conductor[LANGUAGE_NONE][0]['value'];
  // Get field collection field_conductor item from node.
  $driver_data = entity_load_single('field_collection_item', $fc_id);

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
function get_injuries_percent($node) {
  $count = 0;
  $percent = 0;
  $fc_count = count($node->field_lesionado[LANGUAGE_NONE]);

  for ($i = 0; $i < $fc_count; $i++) {

    // Get field collection id.
    $fc_id = $node->field_lesionado[LANGUAGE_NONE][$i]['value'];
    // Get field collection field_lesionado item from node.
    $fc_injuries[$i] = field_collection_item_load($fc_id, $reset = FALSE);

    if (!empty($fc_injuries[$i]->field_lesionado_nombre[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_edad[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_telefono[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (isset($fc_injuries[$i]->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'])) {
      $count++;
    }

    if (!empty($fc_injuries[$i]->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
      $count++;
    }

  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}

/**
 * Returns percent from term fields.
 */
function get_term_percent($node) {
  $count = 0;
  $percent = 0;

  if (!empty($node->field_informe[LANGUAGE_NONE][0]['value'])) {
    $count++;
  }

  if (!empty($node->field_danos_materiales[LANGUAGE_NONE][0]['value']) && $node->field_danos_materiales[LANGUAGE_NONE][0]['value'] != '0.00') {
    $count++;
    $damages = $node->field_danos_materiales[LANGUAGE_NONE][0]['value'];
  }

  if (!empty($node->field_robo[LANGUAGE_NONE][0]['value']) && $node->field_robo[LANGUAGE_NONE][0]['value'] != '0.00') {
    $count++;
  }

  if (!empty($node->field_resp_civil[LANGUAGE_NONE][0]['value']) && $node->field_resp_civil[LANGUAGE_NONE][0]['value'] != '0.00') {
    $count++;
  }

  if (!empty($node->field_gastos_medicos[LANGUAGE_NONE][0]['value']) && $node->field_gastos_medicos[LANGUAGE_NONE][0]['value'] != '0.00') {
    $count++;
  }

  if (!empty($node->field_rc_viajero[LANGUAGE_NONE][0]['value']) && $node->field_rc_viajero[LANGUAGE_NONE][0]['value'] != '0.00') {
    $count++;
  }

  if (!empty($node->field_reserva_total[LANGUAGE_NONE][0]['value']) && $node->field_reserva_total[LANGUAGE_NONE][0]['value'] != '0.00') {
    $count++;
  }

  if ($count > 0) {
    $percent = 25;
  }

  return $percent;
}

/**
 * Return data from sinister arrival.
 */
function sinister_ws_arrival_resource_retrieve($node) {
  $arrival = array();
  $count = 0;

  if (!empty($node->field_fecha_arribo[LANGUAGE_NONE][0]['value'])) {
    // Get date arribal.
    $date = $node->field_fecha_arribo[LANGUAGE_NONE][0]['value'];
    $arrival['date'] = $date;
    $count++;
  }
  else {
    $arrival['date'] = NULL;
  }
  if (!empty($node->field_mapa_arribo[LANGUAGE_NONE][0]['lat'])) {
    // Get latitude from arribal map.
    $lat = $node->field_mapa_arribo[LANGUAGE_NONE][0]['lat'];
    // Get longitude from arribal map.
    $lng = $node->field_mapa_arribo[LANGUAGE_NONE][0]['lng'];
    // Add values to array.
    $arrival['latitude'] = $lat;
    $arrival['longitude'] = $lng;
    $count++;
  }
  else {
    $arrival['latitude'] = NULL;
    $arrival['longitude'] = NULL;
  }

  if ($count >= 1) {
    $arrival['checked-arrival'] = TRUE;
  }
  else {
    $arrival['checked-arrival'] = FALSE;
  }

  return $arrival;
}
