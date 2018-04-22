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
    $fc_id = $node->field_lesionado[LANGUAGE_NONE][$i]['value'];
    $fc_lesiones[$i] = field_collection_item_load($fc_id, $reset = FALSE);
    $results[] = get_injured($fc_lesiones[$i], $count, $fc_id);
  }

  return $results;
}

 /**
 * Returns array from field_lesionado.
 *
 * @params $fc_injured The id item of field_siniestro_archivo field.
 */
function get_injured($fc_lesiones, $count, $fc_id) {
  $objects = array();
  $lesionesDanos = array();
  $percent = 0;
  $number = (1.538461538461538 / $count);
  $lesionesDanos['fc_id'] = $fc_id;

  if (!empty($fc_lesiones->field_lesionado_nombre[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_name = $fc_lesiones->field_lesionado_nombre[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['name'] = $injured_name;
  }
  else {
    $lesionesDanos['name'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_edad[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_age = $fc_lesiones->field_lesionado_edad[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['age'] = $injured_age;
  }
  else {
    $lesionesDanos['age'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $injured_thoroughfare = $fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $lesionesDanos['thoroughfare'] = $injured_thoroughfare;
  }
  else {
    $lesionesDanos['thoroughfare'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_locality = $fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'];
    $lesionesDanos['locality'] = $injured_locality;
  }
  else {
    $lesionesDanos['locality'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_premise = $fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'];
    $lesionesDanos['premise'] = $injured_premise;
  }
  else {
    $lesionesDanos['premise'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $key_admin_area = $fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area']; // Get administrative area field value.
    $country = 'MX';
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $administrative_areas = addressfield_get_administrative_areas($country);
    $admin_area = $administrative_areas[$key_admin_area];
    $lesionesDanos['administrative_area'] = $admin_area;
  }
  else {
    $lesionesDanos['administrative_area'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_postal_code = $fc_lesiones->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $lesionesDanos['postal_code'] = $injured_postal_code;
  }
  else {
    $lesionesDanos['postal_code'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_telefono[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_phone = $fc_lesiones->field_lesionado_telefono[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['phone'] = $injured_phone;
  }
  else {
    $lesionesDanos['phone'] = null;
  }

  if (isset($fc_lesiones->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_risk_b = $fc_lesiones->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['risk_b'] = $injured_risk_b;
  }
  else {
    $lesionesDanos['risk_b'] = null;
  }

  $field_risk_b = field_info_field('field_lesionado_riesgo_b'); // Get info field_lesionado_riesgo_b
  $allowed_values_risk_b = list_allowed_values($field_risk_b); // Add all allowed values.
  $lesionesDanos['risk_b_options'] = $allowed_values_risk_b;

  if (!empty($fc_lesiones->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_injuries = $fc_lesiones->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['injuries'] = $injured_injuries;
  }
  else {
    $lesionesDanos['injuries'] = null;
  }

  if (!empty($fc_lesiones->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_ambulance = $fc_lesiones->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['ambulance'] = $injured_ambulance;
  }
  else {
    $lesionesDanos['ambulance'] = '0';
  }

  if (!empty($fc_lesiones->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_ambulance_info = $fc_lesiones->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'];
    $lesionesDanos['ambulance_description'] = $injured_ambulance_info;
  }
  else {
    $lesionesDanos['ambulance_description'] = null;
  }

  // Get fields from taller.
  if (!empty($fc_lesiones->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
    $hospital_tid = $fc_lesiones->field_hospital[LANGUAGE_NONE][0]['target_id'];
    $lesionesDanos['hospital'] = $hospital_tid;
  }
  else {
    $lesionesDanos['hospital'] = null;
  }

  return $lesionesDanos;
}
