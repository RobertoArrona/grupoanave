<?php

/**
 * @file
 * Retrieve a third vehicle info from nid.
 */

/**
 * Return data from third vehicles.
 */
function sinister_ws_vehicles_resource_retrieve($nid) {
  $node = node_load($nid);
  $count = count($node->field_vehiculo_tercero[LANGUAGE_NONE]);

  // Get field collection field_vehiculo item from node.
  $results = array();
  for ($i=0; $i < $count; $i++) {
    $fc_thirds[$i] = field_collection_item_load($node->field_vehiculo_tercero[LANGUAGE_NONE][$i]['value'], $reset = FALSE);
    $results[] = get_vehicle($fc_thirds[$i], $count);
  }
  return $results;
}

/**
 * Returns array from field_vehiculo_tercero.
 *
 * @params $fc_thirds The id item of field_siniestro_archivo field.
 */
function get_vehicle($fc_thirds, $count) {
  $objects = array();
  $thirds = array();
  $percent = 0;
  $number = (1.538461538461538 / $count);

  if (!empty($fc_thirds->field_propietario_nombre[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $field_propietario_nombre = $fc_thirds->field_propietario_nombre[LANGUAGE_NONE][0]['value'];
    $thirds['owner_name'] = $field_propietario_nombre;
  }
  else {
    $thirds['owner_name'] = null;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_thoroughfare = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $thirds['owner_thoroughfare'] = $owner_thoroughfare;
  }
  else {
    $thirds['owner_thoroughfare'] = null;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_premise = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'];
    $thirds['owner_premise'] = $owner_premise;
  }
  else {
    $thirds['owner_premise'] = null;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_locality = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'];
    $thirds['owner_locality'] = $owner_locality;
  }
  else {
    $thirds['owner_locality'] = null;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_key_admin_area = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area']; // Get administrative area field value.
    $country = 'MX';
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $owner_administrative_areas = addressfield_get_administrative_areas($country);
    $owner_admin_area = $owner_administrative_areas[$owner_key_admin_area];
    $thirds['owner_administrative_area'] = $owner_admin_area;
  }
  else {
    $thirds['owner_administrative_area'] = null;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_postal_code = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $thirds['owner_postal_code'] = $owner_postal_code;
  }
  else {
    $thirds['owner_postal_code'] = null;
  }

  if (!empty($fc_thirds->field_propietario_telefono[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_phone = $fc_thirds->field_propietario_telefono[LANGUAGE_NONE][0]['value'];
    $thirds['owner_phone_number'] = $field_propietario_nombre;
  }
  else {
    $thirds['owner_phone_number'] = null;
  }

  if (isset($fc_thirds->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'])) {
    $check_owner = $fc_thirds->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'];
    $field = field_info_field('field_conductor_es_propietario');
    $driver_is_owner = $field['settings']['allowed_values'][$check_owner];
    $thirds['is_owner'] = $check_owner;
  }
  else {
    $check_owner = '0';
    $thirds['is_owner'] = $check_owner;
  }

  if ($check_owner == '1') {
    $percent = $percent + (10.769230769230766 / $count); // Add value to $percent variable.
  }

  else {
    
    if (isset($fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value']) && !empty($fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value']) && !empty($fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }
  }

  if (isset($fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value']) && !empty($fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value'])) {
    $diver_name = $fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value'];
    $thirds['driver_name'] = $diver_name;
  }
  else {
    $thirds['driver_name'] = null;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $driver_thoroughfare = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $thirds['driver_thoroughfare'] = $driver_thoroughfare;
  }
  else {
    $thirds['driver_thoroughfare'] = null;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $driver_premise = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'];
    $thirds['driver_premise'] = $driver_premise;
  }
  else {
    $thirds['driver_premise'] = null;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $diver_locality = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'];
    $thirds['diver_locality'] = $diver_locality;
  }
  else {
    $thirds['diver_locality'] = null;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $driver_key_admin_area = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'];
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $administrative_areas = addressfield_get_administrative_areas($country);
    $administrative_area_conductor = $administrative_areas[$driver_key_admin_area];
    $thirds['driver_administrative_area'] = $administrative_area_conductor;
  }
  else {
    $thirds['driver_administrative_area'] = null;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $driver_postal_code = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $thirds['driver_postal_code'] = $driver_postal_code;
  }
  else {
    $thirds['driver_postal_code'] = null;
  }

  if (isset($fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value']) && !empty($fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value'])) {
    $driver_phone_number = $fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value'];
    $thirds['driver_phone_number'] = $driver_phone_number;
  }
  else {
    $thirds['driver_phone_number'] = null;
  }

  if (!empty($fc_thirds->field_licencia_numero[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $license_number = $fc_thirds->field_licencia_numero[LANGUAGE_NONE][0]['value'];
    $thirds['license_number'] = $license_number;
  }
  else {
    $thirds['license_number'] = null;
  }

  if (!empty($fc_thirds->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $brand_tid = $fc_thirds->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'];
    $brand_term = taxonomy_term_load($brand_tid);
    $brand = $brand_term->name;
    $thirds['vehiculo_marca'] = $brand;
  }
  else {
    $thirds['vehiculo_marca'] = null;
  }

  if (!empty($fc_thirds->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $type_tid = $fc_thirds->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'];
    $type_term = taxonomy_term_load($type_tid);
    $type_vehicle = $type_term->name;
    $thirds['vehiculo_tipo'] = $type_vehicle;
  }
  else {
    $thirds['vehiculo_tipo'] = null;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $model_vehicle = $fc_thirds->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_modelo'] = $model_vehicle;
  }
  else {
    $thirds['vehiculo_modelo'] = null;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $color_tid = $fc_thirds->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'];
    $color_term = taxonomy_term_load($color_tid);
    $vehiculo_color = $color_term->name;
    $thirds['vehiculo_color'] = $vehiculo_color;
  }
  else {
    $thirds['vehiculo_color'] = null;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_placas = $fc_thirds->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_placas'] = $vehiculo_placas;
  }
  else {
    $thirds['vehiculo_placas'] = null;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_serie = $fc_thirds->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_serie'] = $vehiculo_serie;
  }
  else {
    $thirds['vehiculo_serie'] = null;
  }
  
  if (!empty($fc_thirds->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_danos = $fc_thirds->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_danos'] = $vehiculo_danos;
  }
  else {
    $thirds['vehiculo_danos'] = null;
  }

  if (!empty($fc_thirds->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $aseguradora_tid = $fc_thirds->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'];
    $thirds['aseguradora'] = $aseguradora_tid;
  }
  else {
    $thirds['aseguradora'] = null;
  }

  if (!empty($fc_thirds->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_numero_poliza = $fc_thirds->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'];
    $thirds['numero_poliza'] = $vehiculo_numero_poliza;
  }
  else {
    $thirds['numero_poliza'] = null;
  }

  if (!empty($fc_thirds->field_3ro_cobertura[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_cobertura = $fc_thirds->field_3ro_cobertura[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_cobertura'] = $vehiculo_cobertura;
  }
  else {
    $thirds['vehiculo_cobertura'] = null;
  }

  if (!empty($fc_thirds->field_3ro_deducible[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_deducible = $fc_thirds->field_3ro_deducible[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_deducible'] = $vehiculo_deducible;
  }
  else {
    $thirds['vehiculo_deducible'] = null;
  }

  if (!empty($fc_thirds->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_vencimiento = $fc_thirds->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_vencimiento'] = $vehiculo_vencimiento;
  }
  else {
    $thirds['vehiculo_vencimiento'] = null;
  }
  
  if (!empty($fc_thirds->field_3ro_siniestro[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_siniestro = $fc_thirds->field_3ro_siniestro[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_siniestro'] = $vehiculo_siniestro;
  }
  else {
    $thirds['vehiculo_siniestro'] = null;
  }

  if (!empty($fc_thirds->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $field_ajustador_tid = $fc_thirds->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'];
    $thirds['vehiculo_ajustador'] = $field_ajustador_tid;
  }
  else {
    $thirds['vehiculo_ajustador'] = null;
  }

  if (!empty($fc_thirds->field_taller[LANGUAGE_NONE][0]['target_id'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $taller_tid = $fc_thirds->field_taller[LANGUAGE_NONE][0]['target_id'];
    $thirds['vehiculo_taller'] = $taller_tid;
  }
  else {
    $thirds['vehiculo_taller'] = null;
  }

  $objects[] = $thirds;

  return $objects;
}
