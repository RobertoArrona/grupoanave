<?php

/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data term from sinister.
 */
function sinister_ws_termino_resource_retrieve($nid) {
  $node = node_load($nid);
  $term = array();
  $percent = 0;

  if (!empty($node->field_informe[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $inform = $node->field_informe[LANGUAGE_NONE][0]['value'];
    $term['inform'] = $inform;
  }
  else {
    $term['inform'] = NULL;
  }
  if (isset($node->field_danos_materiales[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $material_damage = $node->field_danos_materiales[LANGUAGE_NONE][0]['value'];
    $term['material_damage'] = $material_damage;
  }
  else {
    $term['material_damage'] = NULL;
  }
  if (isset($node->field_robo[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $robbery = $node->field_robo[LANGUAGE_NONE][0]['value'];
    $term['robbery'] = $robbery;
  }
  else {
    $term['robbery'] = NULL;
  }
  if (isset($node->field_resp_civil[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $civil_liability = $node->field_resp_civil[LANGUAGE_NONE][0]['value'];
    $term['civil_liability'] = $civil_liability;
  }
  else {
    $term['civil_liability'] = NULL;
  }
  if (isset($node->field_gastos_medicos[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $medical_expenses = $node->field_gastos_medicos[LANGUAGE_NONE][0]['value'];
    $term['medical_expenses'] = $medical_expenses;
  }
  else {
    $term['medical_expenses'] = NULL;
  }
  if (isset($node->field_rc_viajero[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $rc_traveler = $node->field_rc_viajero[LANGUAGE_NONE][0]['value'];
    $term['rc_traveler'] = $rc_traveler;
  }
  else {
    $term['rc_traveler'] = NULL;
  }
  if (isset($node->field_reserva_total[LANGUAGE_NONE][0]['value'])) {
    // Add value to $percent variable.
    $percent = $percent + 1.538461538461538;
    $total_reserve = $node->field_reserva_total[LANGUAGE_NONE][0]['value'];
    $term['total_reserve'] = $total_reserve;
  }
  else {
    $term['total_reserve'] = NULL;
  }

  $objects[] = $term;

  return $objects;
}
