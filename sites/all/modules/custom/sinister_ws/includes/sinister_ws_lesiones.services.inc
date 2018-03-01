<?php

/**
 * @file
 * Retrieve injury info from nid.
 */

/**
 * Return data injury from sinister.
 */
function sinister_ws_lesiones_resource_retrieve($nid) {
  $objects = array();
  $percent = 0;
  if (($node = node_load($nid))) {
    // Get injured information.
    $items = count($node->field_lesionado[LANGUAGE_NONE]);
    for ($i = 0; $i < $items; $i++) {
      $injured_data = entity_load_single('field_collection_item', $node->field_lesionado[LANGUAGE_NONE][$i]['value']);
      // Get riesgo b field value.
      $key_riesgo = $injured_data->field_lesionado_riesgo_b[LANGUAGE_NONE][0]['value'];
      $field_info = field_info_field('field_lesionado_riesgo_b');
      $risk_b = $field_info['settings']['allowed_values'][$key_riesgo];
      // Get administrative area field value.
      $key_admin_area = $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['administrative_area'];
      $country = 'MX';
      module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
      $administrative_areas = addressfield_get_administrative_areas($country);
      $admin_area = $administrative_areas[$key_admin_area];
      // Add value to $percent variable.
      if (isset($injured_data->field_lesionado_nombre[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_edad[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($admin_area)) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_telefono[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($risk_b)) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if ($injured_data->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value']=='0') {
        $percent = $percent + 1.538461538461538;
      }
      else {
        // Add value to $percent variable
        if (isset($injured_data->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'])) {
          $percent = $percent + 1.538461538461538;
        }
      }
      // Add value to $percent variable
      if (isset($injured_data->field_lesionado_pase_medico[LANGUAGE_NONE][0]['value'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Add value to $percent variable
      if (isset($injured_data->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
        $percent = $percent + 1.538461538461538;
      }
      // Create return object.
      $return_obj[$i] = array(
        'name' => $injured_data->field_lesionado_nombre[LANGUAGE_NONE][0]['value'],
        'age' => $injured_data->field_lesionado_edad[LANGUAGE_NONE][0]['value'],
        'thoroughfare' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['thoroughfare'],
        'premise' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['premise'],
        'locality' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['locality'],
        'administrative_area' => $admin_area,
        'postal_code' => $injured_data->field_lesionado_domicilio[LANGUAGE_NONE][0]['postal_code'],
        'phone' => $injured_data->field_lesionado_telefono[LANGUAGE_NONE][0]['value'],
        'risk_b' => $risk_b,
        'injuries' => $injured_data->field_lesionado_lesiones[LANGUAGE_NONE][0]['value'],
        'ambulance' => $injured_data->field_lesionado_ambulancia[LANGUAGE_NONE][0]['value'],
        'ambulance_description' => $injured_data->field_lesionado_ambulancia_info[LANGUAGE_NONE][0]['value'],
        'medical_pass' => $injured_data->field_lesionado_pase_medico[LANGUAGE_NONE][0]['value'],
        'percent' => $percent,
      );
      $objects[$nid] = $return_obj;
    }
  }
  return $objects;
}
