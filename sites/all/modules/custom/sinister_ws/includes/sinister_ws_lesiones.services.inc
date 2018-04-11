<?php

/**
 * @file
 * Retrieve injury info from nid.
 */

/**
 * Return data from sinister injuries and damages.
 */
function sinister_ws_lesiones_resource_retrieve($nid) {
  $node = node_load($nid);
  $count = count($node->field_lesionado[LANGUAGE_NONE]);

  // Get field collection field_vehiculo item from node.
  $results = array();

  for ($i=0; $i < $count; $i++) {
    $injured_data[$i] = field_collection_item_load($node->field_lesionado[LANGUAGE_NONE][$i]['value'], $reset = FALSE);
    $results[] = get_injured($injured_data[$i], $count);
  }
  
  return $results;
}

 /**
 * Returns array from field_lesionado.
 *
 * @params $fc_injured The id item of field_siniestro_archivo field.
 */
function get_injured($injured_data, $count) {
  $objects = array();
  $percent = 0;
  $number = (1.538461538461538 / $count);
  // Get riesgo b field value.
  $key_riesgo = $injured_data->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'];
  $field_info = field_info_field('field_lesionado_riesgo_b');
  $risk_b = $field_info['settings']['allowed_values'][$key_riesgo];
  // Get administrative area field value.
  $key_admin_area = $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area'];
  $country = 'MX';
  module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
  $administrative_areas = addressfield_get_administrative_areas($country);
  $admin_area = $administrative_areas[$key_admin_area];
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_nombre[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_edad[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($admin_area)) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_telefono[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($risk_b)) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if ($injured_data->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'] == '0') {
    $percent = $percent + $number;
  }
  else {
    // Add value to $percent variable.
    if (isset($injured_data->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + $number;
    }
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_lesionado_pase_medico[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number;
  }
  // Add value to $percent variable.
  if (isset($injured_data->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
    $percent = $percent + $number;
  }
  
  $field_risk_b = field_info_field('field_lesionado_riesgo_b'); // Get info field_lesionado_riesgo_b
  $allowed_values_risk_b = list_allowed_values($field_risk_b); // Add all allowed values.
  
  // Create return object.
  $lesionesDanos = array(
    'name' => $injured_data->field_lesionado_nombre[LANGUAGE_NONE][0]['value'],
    'age' => $injured_data->field_lesionado_edad[LANGUAGE_NONE][0]['value'],
    'thoroughfare' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'],
    'premise' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'],
    'locality' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'],
    'administrative_area' => $admin_area,
    'postal_code' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'],
    'phone' => $injured_data->field_lesionado_telefono[LANGUAGE_NONE][0]['value'],
    'risk_b' => $risk_b,
    'injuries' => $injured_data->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'],
    'ambulance' => $injured_data->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'],
    'ambulance_description' => $injured_data->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'],
    'medical_pass' => $injured_data->field_lesionado_pase_medico[LANGUAGE_NONE][0]['value'],
    'risk_b_options' => $allowed_values_risk_b,
    'percent' => $percent,
  );

  return $lesionesDanos;
}
