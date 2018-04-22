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
    $fc_vehiculo[$i] = field_collection_item_load($node->field_vehiculo_tercero[LANGUAGE_NONE][$i]['value'], $reset = FALSE);
    $results[] = get_vehicle($fc_vehiculo[$i], $count);
  }
  return $results;
}

/**
 * Returns array from field_vehiculo_tercero.
 *
 * @params $fc_vehiculo The id item of field_siniestro_archivo field.
 */
function get_vehicle($fc_vehiculo, $count) {
  $vehiculoTercero = array();
  $percent = 0;
  $number = (1.538461538461538 / $count);

  if (!empty($fc_vehiculo->field_propietario_nombre[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $field_propietario_nombre = $fc_vehiculo->field_propietario_nombre[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['owner_name'] = $field_propietario_nombre;
  }
  else {
    $vehiculoTercero['owner_name'] = null;
  }

  if (!empty($fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_thoroughfare = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $vehiculoTercero['owner_thoroughfare'] = $owner_thoroughfare;
  }
  else {
    $vehiculoTercero['owner_thoroughfare'] = null;
  }

  if (!empty($fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_premise = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'];
    $vehiculoTercero['owner_premise'] = $owner_premise;
  }
  else {
    $vehiculoTercero['owner_premise'] = null;
  }

  if (!empty($fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_locality = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'];
    $vehiculoTercero['owner_locality'] = $owner_locality;
  }
  else {
    $vehiculoTercero['owner_locality'] = null;
  }

  if (!empty($fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_key_admin_area = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area']; // Get administrative area field value.
    $country = 'MX';
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $owner_administrative_areas = addressfield_get_administrative_areas($country);
    $owner_admin_area = $owner_administrative_areas[$owner_key_admin_area];
    $vehiculoTercero['owner_administrative_area'] = $owner_admin_area;
  }
  else {
    $vehiculoTercero['owner_administrative_area'] = null;
  }

  if (!empty($fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_postal_code = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $vehiculoTercero['owner_postal_code'] = $owner_postal_code;
  }
  else {
    $vehiculoTercero['owner_postal_code'] = null;
  }

  if (!empty($fc_vehiculo->field_propietario_telefono[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $owner_phone = $fc_vehiculo->field_propietario_telefono[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['owner_phone_number'] = $field_propietario_nombre;
  }
  else {
    $vehiculoTercero['owner_phone_number'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'])) {
    $check_owner = $fc_vehiculo->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'];
    $field = field_info_field('field_conductor_es_propietario');
    $driver_is_owner = $field['settings']['allowed_values'][$check_owner];
    $vehiculoTercero['is_owner'] = $check_owner;
  }
  else {
    $check_owner = '0';
    $vehiculoTercero['is_owner'] = $check_owner;
  }

  if ($check_owner == '1') {
    $percent = $percent + (10.769230769230766 / $count); // Add value to $percent variable.
  }

  else {
    
    if (isset($fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value']) && !empty($fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['premise']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['locality']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }

    if (isset($fc_vehiculo->field_conductor_telefono[LANGUAGE_NONE][0]['value']) && !empty($fc_vehiculo->field_conductor_telefono[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + $number; // Add value to $percent variable.
    }
  }

  if (isset($fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value']) && !empty($fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value'])) {
    $diver_name = $fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['driver_name'] = $diver_name;
  }
  else {
    $vehiculoTercero['driver_name'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $driver_thoroughfare = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $vehiculoTercero['driver_thoroughfare'] = $driver_thoroughfare;
  }
  else {
    $vehiculoTercero['driver_thoroughfare'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['premise']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $driver_premise = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'];
    $vehiculoTercero['driver_premise'] = $driver_premise;
  }
  else {
    $vehiculoTercero['driver_premise'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['locality']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $diver_locality = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'];
    $vehiculoTercero['diver_locality'] = $diver_locality;
  }
  else {
    $vehiculoTercero['diver_locality'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $driver_key_admin_area = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'];
    module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
    $administrative_areas = addressfield_get_administrative_areas($country);
    $administrative_area_conductor = $administrative_areas[$driver_key_admin_area];
    $vehiculoTercero['driver_administrative_area'] = $administrative_area_conductor;
  }
  else {
    $vehiculoTercero['driver_administrative_area'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code']) && !empty($fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $driver_postal_code = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $vehiculoTercero['driver_postal_code'] = $driver_postal_code;
  }
  else {
    $vehiculoTercero['driver_postal_code'] = null;
  }

  if (isset($fc_vehiculo->field_conductor_telefono[LANGUAGE_NONE][0]['value']) && !empty($fc_vehiculo->field_conductor_telefono[LANGUAGE_NONE][0]['value'])) {
    $driver_phone_number = $fc_vehiculo->field_conductor_telefono[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['driver_phone_number'] = $driver_phone_number;
  }
  else {
    $vehiculoTercero['driver_phone_number'] = null;
  }

  if (!empty($fc_vehiculo->field_licencia_numero[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $license_number = $fc_vehiculo->field_licencia_numero[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['license_number'] = $license_number;
  }
  else {
    $vehiculoTercero['license_number'] = null;
  }

  if (!empty($fc_vehiculo->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $brand_tid = $fc_vehiculo->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'];
    $brand_term = taxonomy_term_load($brand_tid);
    $brand = $brand_term->name;
    $vehiculoTercero['vehiculo_marca'] = $brand;
  }
  else {
    $vehiculoTercero['vehiculo_marca'] = null;
  }

  if (!empty($fc_vehiculo->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $type_tid = $fc_vehiculo->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'];
    $type_term = taxonomy_term_load($type_tid);
    $type_vehicle = $type_term->name;
    $vehiculoTercero['vehiculo_tipo'] = $type_vehicle;
  }
  else {
    $vehiculoTercero['vehiculo_tipo'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $model_vehicle = $fc_vehiculo->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_modelo'] = $model_vehicle;
  }
  else {
    $vehiculoTercero['vehiculo_modelo'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $color_tid = $fc_vehiculo->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'];
    $color_term = taxonomy_term_load($color_tid);
    $vehiculo_color = $color_term->name;
    $vehiculoTercero['vehiculo_color'] = $vehiculo_color;
  }
  else {
    $vehiculoTercero['vehiculo_color'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_placas = $fc_vehiculo->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_placas'] = $vehiculo_placas;
  }
  else {
    $vehiculoTercero['vehiculo_placas'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_serie = $fc_vehiculo->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_serie'] = $vehiculo_serie;
  }
  else {
    $vehiculoTercero['vehiculo_serie'] = null;
  }
  
  if (!empty($fc_vehiculo->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_danos = $fc_vehiculo->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_danos'] = $vehiculo_danos;
  }
  else {
    $vehiculoTercero['vehiculo_danos'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $aseguradora_tid = $fc_vehiculo->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'];
    $vehiculoTercero['aseguradora'] = $aseguradora_tid;
  }
  else {
    $vehiculoTercero['aseguradora'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_numero_poliza = $fc_vehiculo->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['numero_poliza'] = $vehiculo_numero_poliza;
  }
  else {
    $vehiculoTercero['numero_poliza'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_cobertura[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_cobertura = $fc_vehiculo->field_3ro_cobertura[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_cobertura'] = $vehiculo_cobertura;
  }
  else {
    $vehiculoTercero['vehiculo_cobertura'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_deducible[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_deducible = $fc_vehiculo->field_3ro_deducible[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_deducible'] = $vehiculo_deducible;
  }
  else {
    $vehiculoTercero['vehiculo_deducible'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_vencimiento = $fc_vehiculo->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_vencimiento'] = $vehiculo_vencimiento;
  }
  else {
    $vehiculoTercero['vehiculo_vencimiento'] = null;
  }
  
  if (!empty($fc_vehiculo->field_3ro_siniestro[LANGUAGE_NONE][0]['value'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $vehiculo_siniestro = $fc_vehiculo->field_3ro_siniestro[LANGUAGE_NONE][0]['value'];
    $vehiculoTercero['vehiculo_siniestro'] = $vehiculo_siniestro;
  }
  else {
    $vehiculoTercero['vehiculo_siniestro'] = null;
  }

  if (!empty($fc_vehiculo->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $field_ajustador_tid = $fc_vehiculo->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'];
    $vehiculoTercero['vehiculo_ajustador'] = $field_ajustador_tid;
  }
  else {
    $vehiculoTercero['vehiculo_ajustador'] = null;
  }

  if (!empty($fc_vehiculo->field_taller[LANGUAGE_NONE][0]['target_id'])) {
    $percent = $percent + $number; // Add value to $percent variable.
    $taller_tid = $fc_vehiculo->field_taller[LANGUAGE_NONE][0]['target_id'];
    $vehiculoTercero['vehiculo_taller'] = $taller_tid;
  }
  else {
    $vehiculoTercero['vehiculo_taller'] = null;
  }

  return $vehiculoTercero;
}
