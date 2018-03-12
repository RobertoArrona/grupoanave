<?php

/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data term from sinister.
 */
function sinister_ws_taxonomy_resource_retrieve($nid) {
  $objects = array();
  $percent = 0;
  if (($node = node_load($nid))) {
    // Get driver information.
    $driver_data = entity_load_single('field_collection_item', $node->field_conductor[LANGUAGE_NONE][0]['value']);
    // Get vehicle information.
    $vehicle_data = entity_load_single('field_collection_item', $node->field_vehiculo_tercero[LANGUAGE_NONE][0]['value']);
    // Get taxonomy from field_licencia_tipo value.
    $license_type = taxonomy_term_load($driver_data->field_licencia_tipo[LANGUAGE_NONE][0]['tid']);
    $license_type_vocabulary = taxonomy_get_tree($license_type->vid);
     //watchdog('sinister_ws', '<pre>' . print_r($license_type_vocabulary, TRUE) . "</pre>");
    // Get taxonomy from field_liencia_alta_lugar
    $license_place = taxonomy_term_load($driver_data->field_licencia_alta_lugar[LANGUAGE_NONE][0]['tid']);
    $license_place_vocabulary = taxonomy_get_tree($license_place->vid);
watchdog('sinister_ws', '<pre>' . print_r($license_place_vocabulary, TRUE) . "</pre>");
    // Get fields value from vehicle brand.
    $brand_vehicle = taxonomy_term_load($vehicle_data->field_vehiculo_marca[LANGUAGE_NONE][0]['tid']);
    $brand_vehicle_vocabulary = taxonomy_get_tree($brand_vehicle->vid);
 watchdog('sinister_ws', '<pre>' . print_r($brand_vehicle_vocabulary, TRUE) . "</pre>");
    // Get fields value from vehicle brand.
    $type_vehicle = taxonomy_term_load($vehicle_data->field_vehiculo_tipo[LANGUAGE_NONE][0]['tid']);
    $type_vehicle_vocabulary = taxonomy_get_tree($type_vehicle->vid);
    
    // Get fields value from $ajustador field
    $insurance_agent = taxonomy_term_load($vehicle_data->field_3ro_ajustador[LANGUAGE_NONE][0]['tid']);
    $insurance_agent_vocabulary = taxonomy_get_tree($insurance_agent->vid);

    // Get fields value from vehicle color.
    $color_vehicle = taxonomy_term_load($vehicle_data->field_3ro_vehiculo_color[LANGUAGE_NONE][0]['tid']);
    $color_vehicle_vocabulary = taxonomy_get_tree($color_vehicle->vid);

    // Get fields value from $aseguradora field
    $insurance_company = taxonomy_term_load($vehicle_data->field_3ro_aseguradora[LANGUAGE_NONE][0]['tid']);
    $insurance_company_vocabulary = taxonomy_get_tree($insurance_company->vid);

    // Create return object.
    $return_obj = array(
      'license_type' => $license_type_vocabulary,
      'license_place' => $license_place_vocabulary,
      'brand_vehicle' => $brand_vehicle_vocabulary,
      'type_vehicle' => $type_vehicle_vocabulary,
      'insurance_agent' => $insurance_agent_vocabulary,
      'color_vehicle' => $color_vehicle_vocabulary,
      'insurance_company' => $insurance_company_vocabulary,
    );
    $objects[] = $return_obj;
  }
  return $objects;
}
