<?php

/**
 * @file
 * Retrieve a third vehicle info from nid.
 */

/**
 * Return data from third vehicles.
 */
function sinister_ws_thirds_resource_retrieve($nid) {
  $node = node_load($nid);
  $count = count($node->field_vehiculo_tercero[LANGUAGE_NONE]);

  // Get field collection field_vehiculo item from node.
  $results = array();

  for ($i = 0; $i < $count; $i++) {
    $fc_id = $node->field_vehiculo_tercero[LANGUAGE_NONE][$i]['value'];
    $fc_thirds[$i] = field_collection_item_load($fc_id, $reset = FALSE);
    $results[] = get_vehicle($fc_thirds[$i], $count, $fc_id);
  }

  return $results;
}

/**
 * Returns array from field_vehiculo_tercero.
 *
 * @params $fc_thirds The id item of field_siniestro_archivo field.
 */
function get_vehicle($fc_thirds, $count, $fc_id) {
  $thirds = array();
  $thirds['fc_id'] = $fc_id;

  if (!empty($fc_thirds->field_propietario_nombre[LANGUAGE_NONE][0]['value'])) {
    $field_propietario_nombre = $fc_thirds->field_propietario_nombre[LANGUAGE_NONE][0]['value'];
    $thirds['owner_name'] = $field_propietario_nombre;
  }
  else {
    $thirds['owner_name'] = NULL;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $owner_thoroughfare = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $thirds['owner_thoroughfare'] = $owner_thoroughfare;
  }
  else {
    $thirds['owner_thoroughfare'] = NULL;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $owner_premise = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'];
    $thirds['owner_premise'] = $owner_premise;
  }
  else {
    $thirds['owner_premise'] = NULL;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $owner_locality = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'];
    $thirds['owner_locality'] = $owner_locality;
  }
  else {
    $thirds['owner_locality'] = NULL;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    // Get administrative area field value.
    $owner_key_admin_area = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area'];
    $thirds['owner_administrative_area'] = $owner_key_admin_area;
  }
  else {
    $thirds['owner_administrative_area'] = NULL;
  }

  if (!empty($fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $owner_postal_code = $fc_thirds->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $thirds['owner_postal_code'] = $owner_postal_code;
  }
  else {
    $thirds['owner_postal_code'] = NULL;
  }

  if (!empty($fc_thirds->field_propietario_telefono[LANGUAGE_NONE][0]['value'])) {
    $owner_phone = $fc_thirds->field_propietario_telefono[LANGUAGE_NONE][0]['value'];
    $thirds['owner_phone_number'] = $owner_phone;
  }
  else {
    $thirds['owner_phone_number'] = NULL;
  }

  if (isset($fc_thirds->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'])) {
    $check_owner = $fc_thirds->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'];
    $thirds['is_owner'] = $check_owner;
  }
  else {
    $check_owner = '0';
    $thirds['is_owner'] = $check_owner;
  }

  if (isset($fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value']) && !empty($fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value'])) {
    $diver_name = $fc_thirds->field_conductor_nombre[LANGUAGE_NONE][0]['value'];
    $thirds['driver_name'] = $diver_name;
  }
  else {
    $thirds['driver_name'] = NULL;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
    $driver_thoroughfare = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
    $thirds['driver_thoroughfare'] = $driver_thoroughfare;
  }
  else {
    $thirds['driver_thoroughfare'] = NULL;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'])) {
    $driver_premise = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'];
    $thirds['driver_premise'] = $driver_premise;
  }
  else {
    $thirds['driver_premise'] = NULL;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'])) {
    $diver_locality = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'];
    $thirds['diver_locality'] = $diver_locality;
  }
  else {
    $thirds['diver_locality'] = NULL;
  }

  if (!empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'])) {
    $driver_key_admin_area = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'];
    $thirds['driver_administrative_area'] = $driver_key_admin_area;
  }
  else {
    $thirds['driver_administrative_area'] = NULL;
  }

  if (isset($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code']) && !empty($fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
    $driver_postal_code = $fc_thirds->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'];
    $thirds['driver_postal_code'] = $driver_postal_code;
  }
  else {
    $thirds['driver_postal_code'] = NULL;
  }

  if (isset($fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value']) && !empty($fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value'])) {
    $driver_phone_number = $fc_thirds->field_conductor_telefono[LANGUAGE_NONE][0]['value'];
    $thirds['driver_phone_number'] = $driver_phone_number;
  }
  else {
    $thirds['driver_phone_number'] = NULL;
  }

  if (!empty($fc_thirds->field_licencia_numero[LANGUAGE_NONE][0]['value'])) {
    $license_number = $fc_thirds->field_licencia_numero[LANGUAGE_NONE][0]['value'];
    $thirds['license_number'] = $license_number;
  }
  else {
    $thirds['license_number'] = NULL;
  }

  if (!empty($fc_thirds->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'])) {
    $brand_tid = $fc_thirds->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'];
    $thirds['vehiculo_marca'] = $brand_tid;
  }
  else {
    $thirds['vehiculo_marca'] = NULL;
  }

  if (!empty($fc_thirds->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'])) {
    $type_tid = $fc_thirds->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'];
    $thirds['vehiculo_tipo'] = $type_tid;
  }
  else {
    $thirds['vehiculo_tipo'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'])) {
    $model_vehicle = $fc_thirds->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_modelo'] = $model_vehicle;
  }
  else {
    $thirds['vehiculo_modelo'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'])) {
    $color_tid = $fc_thirds->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'];
    $thirds['vehiculo_color'] = $color_tid;
  }
  else {
    $thirds['vehiculo_color'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_placas = $fc_thirds->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_placas'] = $vehiculo_placas;
  }
  else {
    $thirds['vehiculo_placas'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_serie = $fc_thirds->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_serie'] = $vehiculo_serie;
  }
  else {
    $thirds['vehiculo_serie'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_danos = $fc_thirds->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_danos'] = $vehiculo_danos;
  }
  else {
    $thirds['vehiculo_danos'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'])) {
    $aseguradora_tid = $fc_thirds->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'];
    $thirds['aseguradora'] = $aseguradora_tid;
  }
  else {
    $thirds['aseguradora'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_numero_poliza = $fc_thirds->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'];
    $thirds['numero_poliza'] = $vehiculo_numero_poliza;
  }
  else {
    $thirds['numero_poliza'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_cobertura[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_cobertura = $fc_thirds->field_3ro_cobertura[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_cobertura'] = $vehiculo_cobertura;
  }
  else {
    $thirds['vehiculo_cobertura'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_deducible[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_deducible = $fc_thirds->field_3ro_deducible[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_deducible'] = $vehiculo_deducible;
  }
  else {
    $thirds['vehiculo_deducible'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_vencimiento = $fc_thirds->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'];
    $vehiculo_vencimiento = date('Y/m/d', $vehiculo_vencimiento);
    $thirds['vehiculo_vencimiento'] = $vehiculo_vencimiento;
  }
  else {
    $thirds['vehiculo_vencimiento'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_siniestro[LANGUAGE_NONE][0]['value'])) {
    $vehiculo_siniestro = $fc_thirds->field_3ro_siniestro[LANGUAGE_NONE][0]['value'];
    $thirds['vehiculo_siniestro'] = $vehiculo_siniestro;
  }
  else {
    $thirds['vehiculo_siniestro'] = NULL;
  }

  if (!empty($fc_thirds->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'])) {
    $field_ajustador_tid = $fc_thirds->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'];
    $thirds['vehiculo_ajustador'] = $field_ajustador_tid;
  }
  else {
    $thirds['vehiculo_ajustador'] = NULL;
  }

  if (!empty($fc_thirds->field_taller[LANGUAGE_NONE][0]['target_id'])) {
    $taller_tid = $fc_thirds->field_taller[LANGUAGE_NONE][0]['target_id'];
    $thirds['vehiculo_taller'] = $taller_tid;
  }
  else {
    $thirds['vehiculo_taller'] = NULL;
  }

  return $thirds;
}
