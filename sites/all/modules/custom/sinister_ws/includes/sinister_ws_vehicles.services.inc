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
  $fc_vehiculo = field_collection_item_load($node->field_vehiculo_tercero[LANGUAGE_NONE][0]['value'], $reset = FALSE);
  $result = get_vehicle($fc_vehiculo);
  return $result;
}

/**
 * Returns array from field_vehiculo_tercero.
 *
 * @params $fc_vehiculo The id item of field_siniestro_archivo field.
 */
function get_vehicle($fc_vehiculo) {
  $vehiculoTercero = array();
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
  $key_propietario = $fc_vehiculo->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'];
  $field = field_info_field('field_conductor_es_propietario');
  $field_conductor_es_propietario = $field['settings']['allowed_values'][$key_propietario];
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

  $vehiculoTercero = array(
    'owner_name' => $field_propietario_nombre,
    'owner_thoroughfare' => $thoroughfare,
    'owner_premise' => $premise,
    'owener_locality' => $locality,
    'owener_administrative_area' => $administrative_area,
    'owner_postal_code' => $postal_code,
    'owner_phone_number' => $field_propietario_telefono,
    'is_owner' => $field_conductor_es_propietario,
    'driver_name' => $field_conductor_nombre,
    'driver_thoroughfare' => $thoroughfare_conductor,
    'driver_premise' => $premise_conductor,
    'driver_locality' => $locality_conductor,
    'driver_administrative_area' => $administrative_area_conductor,
    'driver_postal_code' => $postal_code_conductor,
    'driver_phone_number' => $field_conductor_telefono,
    'license_number' => $field_licencia_numero,
    'brand_vehicle' => $sub_brand,
    'type_vehicle' => $type_vehicle,
    'field_vehiculo_modelo' => $field_vehiculo_modelo,
  );

  return $vehiculoTercero;
}
