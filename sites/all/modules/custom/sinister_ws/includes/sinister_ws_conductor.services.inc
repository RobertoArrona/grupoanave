<?php

/**
 * @file
 * Retrieve driver info from nid.
 */

/**
 * Return driver info from node.
 */
function sinister_ws_conductor_resource_retrieve($nid) {
  $objects = array();
  $percent = 0;
  if (($node = node_load($nid))) {
    // Get driver information.
    $driver_data = entity_load_single('field_collection_item', $node->field_conductor[LANGUAGE_NONE][0]['value']);
    // Get field_licencia_tipo value.
    $license_type = taxonomy_term_load($driver_data->field_licencia_tipo[LANGUAGE_NONE][0]['tid']);
    $license_place = taxonomy_term_load($driver_data->field_licencia_alta_lugar[LANGUAGE_NONE][0]['tid']);
    // Get administrative area field value.
    $key_admin_area = $driver_data->field_domicilio[LANGUAGE_NONE][0]['administrative_area'];
    $country = 'MX';
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $administrative_areas = addressfield_get_administrative_areas($country);
    $admin_area = $administrative_areas[$key_admin_area];

    // Add value to $percent variable.
    if (isset($driver_data->field_nombre[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_domicilio[LANGUAGE_NONE][0]['premise'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_domicilio[LANGUAGE_NONE][0]['locality'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($admin_area)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_rfc[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_licencia_numero[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($license_type->name)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($license_place->name)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_licencia_alta_fecha[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable
    if (isset($driver_data->field_telefono[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    if ($driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value']!='1') {
      $percent = $percent + 3.076923076923076;
    }
    else {
      if (isset($driver_data->field_nombre_de_quien_reporta[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
      if (isset($driver_data->field_tel_fono[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
    }
    // Create return object.
    $return_obj = array(
      'name' => $driver_data->field_nombre[LANGUAGE_NONE][0]['value'],
      'thoroughfare' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'],
      'premise' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['premise'],
      'locality' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['locality'],
      'administrative_area' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['administrative_area'],
      'postal_code' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['postal_code'],
      'driver_rfc' => $driver_data->field_rfc[LANGUAGE_NONE][0]['value'],
      'driver_license' => $driver_data->field_licencia_numero[LANGUAGE_NONE][0]['value'],
      'license_type' => $driver_data->field_licencia_tipo[LANGUAGE_NONE][0]['tid'],
      'license_place' => $driver_data->field_licencia_alta_lugar[LANGUAGE_NONE][0]['tid'],
      'license_date' => date('Y/m/d', $driver_data->field_licencia_alta_fecha[LANGUAGE_NONE][0]['value']),
      'phone' => $driver_data->field_telefono[LANGUAGE_NONE][0]['value'],
      'conductor_reporta' => $driver_data->field_conductor_reporta[LANGUAGE_NONE][0]['value'],
      'nombre_de_quien_reporta' => $driver_data->field_nombre_quien_reporta[LANGUAGE_NONE][0]['value'],
      'phone' => $driver_data->field_telefono[LANGUAGE_NONE][0]['value'],
      'phone_who_reports' => $driver_data->field_telefono_quien_reporta[LANGUAGE_NONE][0]['value'],
      'percent' => $percent,
    );
    $objects[] = $return_obj;
  }
  return $objects;
}

/**
 * Returns percent of driver form.
 */
function get_percent() {
  $percent = 0;
  var_dump($driver_data->field_nombre[LANGUAGE_NONE][0]['value']); exit;
  return $percent;
}
