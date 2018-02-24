<?php

/**
 * [sinister_ws_resource_retrieve] definition.
 * Returns the information about a sinister
 * @param $nid The nid of the sinister node.
 * @return array The node processed information array.
 */
function sinister_ws_conductor_resource_retrieve($nid) {
  $objects = array();
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
      // Create return object. 
      $return_obj = array(
        'name' => $driver_data->field_nombre[LANGUAGE_NONE][0]['value'],
        'thoroughfare' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'],      
        'premise' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['premise'],
        'locality' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['locality'],
        'administrative_area'=> $admin_area,
        'postal_code' => $driver_data->field_domicilio[LANGUAGE_NONE][0]['postal_code'],
        'driver_license' => $driver_data->field_licencia_numero[LANGUAGE_NONE][0]['value'],
        'license_type' => $license_type->name,
        'license_place' => $license_place->name,
        'license_date' => date('Y/m/d H:s A', $driver_data->field_licencia_alta_fecha[LANGUAGE_NONE][0]['value']),
        'phone' => $driver_data->field_telefono[LANGUAGE_NONE][0]['value'],
      );
  
      $objects[$nid] = $return_obj;
    }
  return $objects;
  
}


