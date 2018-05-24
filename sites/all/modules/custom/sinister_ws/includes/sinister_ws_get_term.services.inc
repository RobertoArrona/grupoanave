<?php

/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data term from sinister.
 */
function sinister_ws_term_resource_retrieve($nid) {
  $node = node_load($nid);
  $term = array();

  if (!empty($node->field_informe[LANGUAGE_NONE][0]['value'])) {
    $inform = $node->field_informe[LANGUAGE_NONE][0]['value'];
    $term['inform'] = $inform;
  }
  else {
    $term['inform'] = NULL;
  }
  if (isset($node->field_danos_materiales[LANGUAGE_NONE][0]['value'])) {
    $material_damage = $node->field_danos_materiales[LANGUAGE_NONE][0]['value'];
    $term['material_damage'] = $material_damage;
  }
  else {
    $term['material_damage'] = NULL;
  }
  if (isset($node->field_robo[LANGUAGE_NONE][0]['value'])) {
    $robbery = $node->field_robo[LANGUAGE_NONE][0]['value'];
    $term['robbery'] = $robbery;
  }
  else {
    $term['robbery'] = NULL;
  }
  if (isset($node->field_resp_civil[LANGUAGE_NONE][0]['value'])) {
    $civil_liability = $node->field_resp_civil[LANGUAGE_NONE][0]['value'];
    $term['civil_liability'] = $civil_liability;
  }
  else {
    $term['civil_liability'] = NULL;
  }
  if (isset($node->field_gastos_medicos[LANGUAGE_NONE][0]['value'])) {
    $medical_expenses = $node->field_gastos_medicos[LANGUAGE_NONE][0]['value'];
    $term['medical_expenses'] = $medical_expenses;
  }
  else {
    $term['medical_expenses'] = NULL;
  }
  if (isset($node->field_rc_viajero[LANGUAGE_NONE][0]['value'])) {
    $rc_traveler = $node->field_rc_viajero[LANGUAGE_NONE][0]['value'];
    $term['rc_traveler'] = $rc_traveler;
  }
  else {
    $term['rc_traveler'] = NULL;
  }
  if (isset($node->field_reserva_total[LANGUAGE_NONE][0]['value'])) {
    $total_reserve = $node->field_reserva_total[LANGUAGE_NONE][0]['value'];
    $term['total_reserve'] = $total_reserve;
  }
  else {
    $term['total_reserve'] = NULL;
  }

  $objects[] = $term;

  return $objects;
}
