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

  // Get field collection field_vehiculo item from node.
  $results = array();
  for ($i=0; $i < count($node->field_vehiculo_tercero[LANGUAGE_NONE]); $i++) {
    $fc_vehiculo[$i] = field_collection_item_load($node->field_vehiculo_tercero[LANGUAGE_NONE][$i]['value'], $reset = FALSE);
    $results[] = get_vehicle($fc_vehiculo[$i]);
  }
  return $results;
}

/**
 * Returns array from field_vehiculo_tercero.
 *
 * @params $fc_vehiculo The id item of field_siniestro_archivo field.
 */
function get_vehicle($fc_vehiculo) {
  $vehiculoTercero = array();
  $percent = 0;
  // Get value from $field_propietario_nombre.
  $field_propietario_nombre = $fc_vehiculo->field_propietario_nombre[LANGUAGE_NONE][0]['value'];
  // Get value from $thoroughfare.
  $thoroughfare = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
  // Get value from $premise.
  $premise = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['premise'];
  // Get value from $locality.
  $locality = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['locality'];
  // Get key value from administrative_area field.
  $key = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area'];
  // Get administrative area field value.
  $country = 'MX';
  module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
  $administrative_areas = addressfield_get_administrative_areas($country);
  $administrative_area = $administrative_areas[$key];
  // Get key value from $postal_code field.
  $postal_code = $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['postal_code'];
  // Get value from $field_propietario_telefono.
  $field_propietario_telefono = $fc_vehiculo->field_propietario_telefono[LANGUAGE_NONE][0]['value'];
  // Get value from $field_propietario_telefono.
  if (isset($fc_vehiculo->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'])) {
    $key_propietario = $fc_vehiculo->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'];
    $field = field_info_field('field_conductor_es_propietario');
    $field_conductor_es_propietario = $field['settings']['allowed_values'][$key_propietario];
  }
  else {
    $key_propietario = '0';
  }
  // Get value from $field_propietario_nombre.
  $field_conductor_nombre = $fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value'];

  // Get value from $field_propietario_nombre.
  $field_conductor_nombre = $fc_vehiculo->field_conductor_nombre[LANGUAGE_NONE][0]['value'];
  // Get value from $thoroughfare.
  $thoroughfare_conductor = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['thoroughfare'];
  // Get value from $premise.
  $premise_conductor = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['premise'];
  // Get value from $locality.
  $locality_conductor = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['locality'];
  // Get key value from administrative_area field.
  $key_conductor = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'];
  // Get administrative area field value.
  $country = 'MX';
  module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
  $administrative_areas = addressfield_get_administrative_areas($country);
  $administrative_area_conductor = $administrative_areas[$key_conductor];
  // Get key value from $postal_code field.
  $postal_code_conductor = $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['postal_code'];
  // Get value from $field_conductor_telefono.
  $field_conductor_telefono = $fc_vehiculo->field_conductor_telefono[LANGUAGE_NONE][0]['value'];
  // Get value from $field_licencia_numero.
  $field_licencia_numero = $fc_vehiculo->field_licencia_numero[LANGUAGE_NONE][0]['value'];
  // Get value from $field_vehiculo_marca_tid.
  $field_vehiculo_marca_tid = $fc_vehiculo->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'];
  // Get fields value from vehicle brand.
  $brand_term = taxonomy_term_load($field_vehiculo_marca_tid);
  $sub_brand = $brand_term->name;
  // Get value from $field_vehiculo_tipo_tid.
  $field_vehiculo_tipo_tid = $fc_vehiculo->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'];
  // Get fields value from vehicle brand.
  $type_term = taxonomy_term_load($field_vehiculo_tipo_tid);
  $type_vehicle = $type_term->name;
  // Get value from $field_vehiculo_modelo.
  $field_vehiculo_modelo = $fc_vehiculo->field_3ro_vehiculo_modelo[LANGUAGE_NONE][0]['value'];

  // Get value from $field_vehiculo_tipo_tid.
  $field_vehiculo_tipo_tid = $fc_vehiculo->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'];
  // Get fields value from vehicle brand.
  $type_term = taxonomy_term_load($field_vehiculo_tipo_tid);
  $type_vehicle = $type_term->name;

  // Get value from $field_vehiculo_color.
  $field_vehiculo_color = $fc_vehiculo->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'];
  // Get fields value from vehicle color.
  $type_term = taxonomy_term_load($field_vehiculo_color);
  $vehiculo_color = $type_term->name;
  // Get value from $field_vehiculo_placas.
  $vehiculo_placas = $fc_vehiculo->field_3ro_vehiculo_placas[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_vehiculo_serie.
  $vehiculo_serie = $fc_vehiculo->field_3ro_vehiculo_serie[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_vehiculo_danos.
  $vehiculo_danos = $fc_vehiculo->field_3ro_vehiculo_danos[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_aseguradora.
  $field_aseguradora_tid = $fc_vehiculo->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'];
  // Get fields value from $aseguradora field.
  $type_term = taxonomy_term_load($field_aseguradora_tid);
  $aseguradora = $type_term->name;
  // Get value from field_3ro_numero_poliza.
  $vehiculo_numero_poliza = $fc_vehiculo->field_3ro_numero_poliza[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_cobertura.
  $vehiculo_cobertura = $fc_vehiculo->field_3ro_cobertura[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_deducible.
  $vehiculo_deducible = $fc_vehiculo->field_3ro_deducible[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_vencimiento.
  $vehiculo_vencimiento = $fc_vehiculo->field_3ro_vencimiento[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_siniestro.
  $vehiculo_siniestro = $fc_vehiculo->field_3ro_siniestro[LANGUAGE_NONE][0]['value'];
  // Get value from field_3ro_ajustador.
  $field_ajustador_tid = $fc_vehiculo->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'];
  // Get fields value from $aseguradora field.
  $type_term = taxonomy_term_load($field_ajustador_tid);
  $field_ajustador_name = $type_term->name;

  /*
  $field_taller_tid = $fc_vehiculo->field_taller[LANGUAGE_NONE][0]['target_id'];
  // Get fields value from $aseguradora field
  $type_term = taxonomy_term_load($field_taller_tid);
  print_r($type_term); exit;
  $field_taller_name = $type_term->name;
   */
  // Get fields from taller.
  $taller_nid = $fc_vehiculo->field_taller[LANGUAGE_NONE][0]['target_id'];
  $taller_fields = entity_load_single('node', $taller_nid);

  // Add value to $percent variable.
  if (isset($field_propietario_nombre)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($thoroughfare)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($premise)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($locality)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($administrative_area)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($postal_code)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($field_propietario_telefono)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if ($key_propietario == '1') {
    $percent = $percent + 10.769230769230766;
  }
  else {
    // Add value to $percent variable.
    if (isset($field_conductor_nombre) && !empty($field_conductor_nombre)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($thoroughfare_conductor) && !empty($thoroughfare_conductor)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($premise_conductor) && !empty($premise_conductor)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($locality_conductor) && !empty($locality_conductor)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($administrative_area_conductor) && !empty($administrative_area_conductor)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($postal_code_conductor) && !empty($postal_code_conductor)) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($field_conductor_telefono) && !empty($field_conductor_telefono)) {
      $percent = $percent + 1.538461538461538;
    }
  }
  // Add value to $percent variable.
  if (isset($field_licencia_numero)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($admin_area)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($sub_brand)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($type_vehicle)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($field_vehiculo_modelo)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_color)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_placas)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_serie)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_danos)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($aseguradora)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_numero_poliza)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_cobertura)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_deducible)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_vencimiento)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($vehiculo_siniestro)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($field_ajustador_name)) {
    $percent = $percent + 1.538461538461538;
  }
  // Add value to $percent variable.
  if (isset($taller_nid)) {
    $percent = $percent + 1.538461538461538;
  }

  $vehiculoTercero = array(
    'owner_name' => $field_propietario_nombre,
    'owner_thoroughfare' => $thoroughfare,
    'owner_premise' => $premise,
    'owner_locality' => $locality,
    'owner_administrative_area' => $fc_vehiculo->field_propietario_domicilio[LANGUAGE_NONE][0]['administrative_area'],
    'owner_postal_code' => $postal_code,
    'owner_phone_number' => $field_propietario_telefono,
    'is_owner' => $key_propietario,
    'driver_name' => $field_conductor_nombre,
    'driver_thoroughfare' => $thoroughfare_conductor,
    'driver_premise' => $premise_conductor,
    'driver_locality' => $locality_conductor,
    'driver_administrative_area' => $fc_vehiculo->field_conductor_domicilio[LANGUAGE_NONE][0]['administrative_area'],
    'driver_postal_code' => $postal_code_conductor,
    'driver_phone_number' => $field_conductor_telefono,
    'license_number' => $field_licencia_numero,
    'vehiculo_marca' => $fc_vehiculo->field_vehiculo_marca[LANGUAGE_NONE][0]['tid'],
    'vehiculo_tipo' => $fc_vehiculo->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid'],
    'vehiculo_modelo' => $field_vehiculo_modelo,
    'vehiculo_color' => $fc_vehiculo->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid'],
    'vehiculo_placas' => $vehiculo_placas,
    'vehiculo_serie' => $vehiculo_serie,
    'vehiculo_danos' => $vehiculo_danos,
    'aseguradora' => $fc_vehiculo->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid'],
    'numero_poliza' => $vehiculo_numero_poliza,
    'vehiculo_cobertura' => $vehiculo_cobertura,
    'vehiculo_deducible' => $vehiculo_deducible,
    'vehiculo_vencimiento' => date('Y/m/d', $vehiculo_vencimiento),
    'vehiculo_siniestro' => $vehiculo_siniestro,
    'vehiculo_ajustador' => $fc_vehiculo->field_3ro_ajustador[LANGUAGE_NONE][0]['tid'],
    'vehiculo_taller' => $taller_nid,
    'percent' => $percent,

  );
  return $vehiculoTercero;
}
