<?php

/**
 * @file
 * Retrieve list sinisters info from uid.
 */

/**
 * Return list sinisters info.
 */
function sinister_ws_list_sinisters_resource_retrieve($uid) {
  $sinisters = sinister_get_ajustador_sinisters($uid, 0);
  $objects = array();
  foreach ($sinisters as $nid => $sinister) {
    if (!($node = node_load($nid))) {
      continue;
    }

    // Create return object.
    $return_obj = array(
      'nid' => $node->nid,
      'sinister' => $node->title,
      'created' => date('Y/m/d h:i a', $node->created),
    );

    if (isset($node->field_poliza[LANGUAGE_NONE][0]['target_id'])) {
      // Get fields from poliza.
      $poliza_nid = $node->field_poliza[LANGUAGE_NONE][0]['target_id'];
      $poliza_fields = entity_load_single('node', $poliza_nid);
      // Get poliza field title.
      $contract = $poliza_fields->title;
      $return_obj['contract'] = $contract;
    }
    else {
      $return_obj['contract'] = NULL;
    }

    if (isset($poliza_fields->field_vehiculo_color[LANGUAGE_NONE][0]['value'])) {
      // Get vehicle model field value.
      $vehicle_color = $poliza_fields->field_vehiculo_color[LANGUAGE_NONE][0]['value'];
      $return_obj['color'] = $vehicle_color;
    }
    else {
      $return_obj['color'] = NULL;
    }

    if (isset($poliza_fields->field_vehiculo_submarca[LANGUAGE_NONE][0]['tid'])) {
      // Get fields value from vehicle brand.
      $sub_brand_term = taxonomy_term_load($poliza_fields->field_vehiculo_submarca[LANGUAGE_NONE][0]['tid']);
      $sub_brand = $sub_brand_term->name;
      $return_obj['type'] = $sub_brand;
    }
    else {
      $return_obj['type'] = NULL;
    }

    if (isset($poliza_fields->field_vehiculo_modelo[LANGUAGE_NONE][0]['value'])) {
      // Get vehicle model field value.
      $vehicle_model = $poliza_fields->field_vehiculo_modelo[LANGUAGE_NONE][0]['value'];
      $return_obj['model'] = $vehicle_model;
    }
    else {
      $return_obj['model'] = NULL;
    }

    if (isset($poliza_fields->field_vehiculo_serie[LANGUAGE_NONE][0]['value'])) {
      // Get vehicle model field value.
      $vehicle_serie = $poliza_fields->field_vehiculo_serie[LANGUAGE_NONE][0]['value'];
      $return_obj['serie'] = $vehicle_serie;
    }
    else {
      $return_obj['serie'] = NULL;
    }

    if (isset($poliza_fields->field_vehiculo_motor[LANGUAGE_NONE][0]['value'])) {
      // Get vehicle model field value.
      $vehicle_engine = $poliza_fields->field_vehiculo_motor[LANGUAGE_NONE][0]['value'];
      $return_obj['engine'] = $vehicle_engine;
    }
    else {
      $return_obj['engine'] = NULL;
    }

    $objects[] = $return_obj;
  }

  return $objects;
}
