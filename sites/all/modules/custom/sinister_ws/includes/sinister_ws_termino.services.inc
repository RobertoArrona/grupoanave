<?php

/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data term from sinister.
 */
function sinister_ws_termino_resource_retrieve($nid) {
  $objects = array();
  $percent = 0;
  if (($node = node_load($nid))) {
    // Add value to $percent variable.
    if (isset($node->field_informe[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($node->field_danos_materiales[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($node->field_robo[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($node->field_resp_civil[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($node->field_gastos_medicos[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($node->field_rc_viajero[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Add value to $percent variable.
    if (isset($node->field_reserva_total[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538;
    }
    // Create return object.
    $return_obj = array(
      'inform' => $node->field_informe[LANGUAGE_NONE][0]['value'],
      'material_damage' => $node->field_danos_materiales[LANGUAGE_NONE][0]['value'],
      'robbery' => $node->field_robo[LANGUAGE_NONE][0]['value'],
      'civil_liability' => $node->field_resp_civil[LANGUAGE_NONE][0]['value'],
      'medical_expenses' => $node->field_gastos_medicos[LANGUAGE_NONE][0]['value'],
      'rc_traveler' => $node->field_rc_viajero[LANGUAGE_NONE][0]['value'],
      'total_reserve' => $node->field_reserva_total[LANGUAGE_NONE][0]['value'],
      'percent' => $percent,
    );
    $objects[] = $return_obj;
  }
  return $objects;
}
