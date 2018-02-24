<?php

/**
 * A [sinister_ws_resource_retrieve] definition.
 * Returns the information about a sinister
 * @param $nid The nid of the sinister node.
 * @return array The node processed information array.
 */
function sinister_ws_termino_resource_retrieve($nid) {
  $objects = array();
  if (($node = node_load($nid))) {
    // Create return object.
    $return_obj = array(
      'inform' => $node->field_informe[LANGUAGE_NONE][0]['value'],
      'material_damage' => $node->field_danos_materiales[LANGUAGE_NONE][0]['value'],
      'robbery' => $node->field_robo[LANGUAGE_NONE][0]['value'],
      'civil_liability' => $node->field_resp_civil[LANGUAGE_NONE][0]['value'],
      'medical_expenses' => $node->field_gastos_medicos[LANGUAGE_NONE][0]['value'],
      'rc_traveler' => $node->field_rc_viajero[LANGUAGE_NONE][0]['value'],
      'total_reserve' => $node->field_reserva_total[LANGUAGE_NONE][0]['value'],
    );
    $objects[$nid] = $return_obj;
  }
  return $objects;
}
