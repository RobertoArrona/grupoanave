<?php

/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data term from sinister.
 */
function sinister_ws_termino_resource_retrieve($nid) {
  $term = array();
  $percent = 0;
  if (($node = node_load($nid))) {
    if (!empty($node->field_informe[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $inform = $node->field_informe[LANGUAGE_NONE][0]['value'];
      $term['inform'] = $inform;
    }
    else {
      $term['inform'] = null;
    }
    if (isset($node->field_danos_materiales[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $material_damage = $node->field_danos_materiales[LANGUAGE_NONE][0]['value'];
      $term['material_damage'] = $material_damage;
    }
    else {
      $term['material_damage'] = null;
    }
    if (isset($node->field_robo[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $robbery = $node->field_robo[LANGUAGE_NONE][0]['value'];
      $term['robbery'] = $robbery;
    }
    else {
      $term['robbery'] = null;
    }
    if (isset($node->field_resp_civil[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $civil_liability = $node->field_resp_civil[LANGUAGE_NONE][0]['value'];
      $term['civil_liability'] = $civil_liability;
    }
    else {
      $term['civil_liability'] = null;
    }
    if (isset($node->field_gastos_medicos[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $medical_expenses = $node->field_gastos_medicos[LANGUAGE_NONE][0]['value'];
      $term['medical_expenses'] = $medical_expenses;
    }
    else {
      $term['medical_expenses'] = null;
    }
    if (isset($node->field_rc_viajero[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $rc_traveler = $node->field_rc_viajero[LANGUAGE_NONE][0]['value'];
      $term['rc_traveler'] = $rc_traveler;
    }
    else {
      $term['rc_traveler'] = null;
    }
    if (isset($node->field_reserva_total[LANGUAGE_NONE][0]['value'])) {
      $percent = $percent + 1.538461538461538; // Add value to $percent variable.
      $total_reserve = $node->field_reserva_total[LANGUAGE_NONE][0]['value'];
      $term['total_reserve'] = $total_reserve;
    }
    else {
      $term['total_reserve'] = null;
    }
/*
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
*/
  }
  return $term;
}
