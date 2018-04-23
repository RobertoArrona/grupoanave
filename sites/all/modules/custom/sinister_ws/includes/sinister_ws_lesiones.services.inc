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
    $fc_injuries[$i] = field_collection_item_load($fc_id, $reset = FALSE);
    $results[] = get_injured($fc_injuries[$i], $count, $fc_id);
  }

  return $results;
}

 /**
 * Returns array from field_lesionado.
 *
 * @params $fc_injured The id item of field_siniestro_archivo field.
 */
function get_injured($fc_injuries, $count, $fc_id) {
  $injuries = array();
  $percent = 0;
  $number = (1.538461538461538 / $count);
  $injuries['fc_id'] = $fc_id;

  if (!empty($fc_injuries->field_lesionado_nombre[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_name = $fc_injuries->field_lesionado_nombre[LANGUAGE_NONE][0]['value'];
    $injuries['name'] = $injured_name;
  }
  else {
    $injuries['name'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_edad[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_age = $fc_injuries->field_lesionado_edad[LANGUAGE_NONE][0]['value'];
    $injuries['age'] = $injured_age;
  }
  else {
    $injuries['age'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $injured_thoroughfare = $fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $injuries['thoroughfare'] = $injured_thoroughfare;
  }
  else {
    $injuries['thoroughfare'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_locality = $fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'];
    $injuries['locality'] = $injured_locality;
  }
  else {
    $injuries['locality'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_premise = $fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'];
    $injuries['premise'] = $injured_premise;
  }
  else {
    $injuries['premise'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $key_admin_area = $fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area']; // Get administrative area field value.
    $country = 'MX';
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $administrative_areas = addressfield_get_administrative_areas($country);
    $admin_area = $administrative_areas[$key_admin_area];
    $injuries['administrative_area'] = $admin_area;
  }
  else {
    $injuries['administrative_area'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_postal_code = $fc_injuries->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $injuries['postal_code'] = $injured_postal_code;
  }
  else {
    $injuries['postal_code'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_telefono[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_phone = $fc_injuries->field_lesionado_telefono[LANGUAGE_NONE][0]['value'];
    $injuries['phone'] = $injured_phone;
  }
  else {
    $injuries['phone'] = null;
  }

  if (isset($fc_injuries->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_risk_b = $fc_injuries->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'];
    $injuries['risk_b'] = $injured_risk_b;
  }
  else {
    $injuries['risk_b'] = null;
  }

  $field_risk_b = field_info_field('field_lesionado_riesgo_b'); // Get info field_lesionado_riesgo_b
  $allowed_values_risk_b = list_allowed_values($field_risk_b); // Add all allowed values.
  $injuries['risk_b_options'] = $allowed_values_risk_b;

  if (!empty($fc_injuries->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_injuries = $fc_injuries->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'];
    $injuries['injuries'] = $injured_injuries;
  }
  else {
    $injuries['injuries'] = null;
  }

  if (!empty($fc_injuries->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_ambulance = $fc_injuries->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'];
    $injuries['ambulance'] = $injured_ambulance;
  }
  else {
    $injuries['ambulance'] = '0';
  }

  if (!empty($fc_injuries->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $injured_ambulance_info = $fc_injuries->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'];
    $injuries['ambulance_description'] = $injured_ambulance_info;
  }
  else {
    $injuries['ambulance_description'] = null;
  }

  // Get fields from taller.
  if (!empty($fc_injuries->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
    $hospital_tid = $fc_injuries->field_hospital[LANGUAGE_NONE][0]['target_id'];
    $injuries['hospital'] = $hospital_tid;
  }
  else {
    $injuries['hospital'] = null;
  }

  return $injuries;
}
