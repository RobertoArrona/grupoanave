<?php

/**
 * @file
 * Retrieve driver info from nid.
 */

/**
 * Return driver info from node.
 */
function sinister_ws_conductor_resource_retrieve($nid) {
  $node = node_load($nid);
  $objects = array();
  $driver = array();
  $percent = 0;

  // Get driver information.
  $driver_data = entity_load_single('field_collection_item', $node->field_conductor[LANGUAGE_NONE][0]['value']);

  if (!empty($driver_data->field_nombre[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_name = $driver_data->field_nombre[LANGUAGE_NONE][0]['value'];
    $driver['name'] = $driver_name;
  }
  else {
    $driver['name'] = null;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_thoroughfare = $driver_data->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $driver['thoroughfare'] = $driver_thoroughfare;
  }
  else {
    $driver['thoroughfare'] = null;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_premise = $driver_data->field_domicilio[LANGUAGE_NONE][0]['premise'];
    $driver['premise'] = $driver_premise;
  }
  else {
    $driver['premise'] = null;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_locality = $driver_data->field_domicilio[LANGUAGE_NONE][0]['locality'];
    $driver['locality'] = $driver_locality;
  }
  else {
    $driver['locality'] = null;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $key_admin_area = $driver_data->field_domicilio[LANGUAGE_NONE][0]['administrative_area'];
    $country = 'MX';
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $administrative_areas = addressfield_get_administrative_areas($country);
    $driver_admin_area = $administrative_areas[$key_admin_area];
    $driver['administrative_area'] = $driver_admin_area;
  }
  else {
    $driver['administrative_area'] = null;
  }

  if (!empty($driver_data->field_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_postal_code = $driver_data->field_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $driver['postal_code'] = $driver_postal_code;
  }
  else {
    $driver['postal_code'] = null;
  }

  if (!empty($driver_data->field_rfc[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_rfc = $driver_data->field_rfc[LANGUAGE_NONE][0]['value'];
    $driver['driver_rfc'] = $driver_rfc;
  }
  else {
    $driver['driver_rfc'] = null;
  }

  if (!empty($driver_data->field_licencia_numero[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_license = $driver_data->field_licencia_numero[LANGUAGE_NONE][0]['value'];
    $driver['driver_license'] = $driver_license;
  }
  else {
    $driver['driver_license'] = null;
  }

  if (!empty($driver_data->field_licencia_tipo[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_license_type = taxonomy_term_load($driver_data->field_licencia_tipo[LANGUAGE_NONE][0]['tid']);
    $driver['license_type'] = $driver_license_type;
  }
  else {
    $driver['license_type'] = null;
  }

  if (!empty($driver_data->field_licencia_alta_lugar[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_license_place = taxonomy_term_load($driver_data->field_licencia_alta_lugar[LANGUAGE_NONE][0]['tid']);
    $driver['license_place'] = $driver_license_place;
  }
  else {
    $driver['license_place'] = null;
  }

  if (!empty($driver_data->field_licencia_alta_fecha[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_license_date = $driver_data->field_licencia_alta_fecha[LANGUAGE_NONE][0]['value'];
    $driver_license_date = date('Y/m/d', $driver_license_date);
    $driver['license_date'] = $driver_license_date;
  }
  else {
    $driver['license_date'] = null;
  }

  if (!empty($driver_data->field_telefono[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    $driver_name = $driver_data->field_telefono[LANGUAGE_NONE][0]['value'];
    $driver['phone'] = $driver_name;
  }
  else {
    $driver['phone'] = null;
  }

  if ($driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'] != '1') {
    $percent = $percent + 3.076923076923076; // Add value to $percent variable.
    $driver['conductor_reporta'] = '0';
  }
  else {
    if (isset($driver_data->field_nombre_de_quien_reporta[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    }
    if (isset($driver_data->field_tel_fono[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
    }
  }

  if (!empty($driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'])) {
    $driver_reports = $driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'];
    $driver['conductor_reporta'] = $driver_reports;
  }

  if (!empty($driver_data->field_nombre_de_quien_reporta[LANGUAGE_NONE][0]['value'])) {
    $name_who_reports = $driver_data->field_nombre_de_quien_reporta[LANGUAGE_NONE][0]['value'];
    $driver['nombre_de_quien_reporta'] = $name_who_reports;
  }
  else {
    $driver['nombre_de_quien_reporta'] = null;
  }

  if (!empty($driver_data->field_tel_fono[LANGUAGE_NONE][0]['value'])) {
    $driver_reports = $driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'];
    $phone_who_reports = $driver_data->field_tel_fono[LANGUAGE_NONE][0]['value'];
    $driver['phone_who_reports'] = $phone_who_reports;
  }
  else {
    $driver['phone_who_reports'] = null;
  }
  
  $objects[] = $driver;

  return $objects;
}
