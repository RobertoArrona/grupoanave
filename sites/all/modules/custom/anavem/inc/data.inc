<?php

/**
 * @file
 * This file has all functions to manipulate or read data.
 */

/**
 * Gets the consecutive number for a siniestro.
 */
function anavem_get_siniestro_number() {
  $year = date('y');
  $last_digit = variable_get("anavem-siniestro-{$year}-i", 1);
  $last_digit = sprintf("%'.04d\n", $last_digit);
  return "A{$year}{$last_digit}";
}

/**
 * Increase the consecutive number for a siniestro.
 */
function anavem_increase_siniestro_number() {
  $year = date('y');
  $last_digit = variable_get("anavem-siniestro-{$year}-i", 1);
  $last_digit++;
  variable_set("anavem-siniestro-{$year}-i", $last_digit);
}

/**
 * Gets a given field to be used in a custom form.
 */
function anavem_get_field($field_name, $entity_type, $bundle_name, &$form, &$form_state) {
  $entity = anavem_siniestro_get_initial_node($entity_type);
  $langcode = $entity->language;
  $items = field_get_items($entity_type, $entity, $field_name);
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle_name);
  $field_form = field_default_form($entity_type, $entity, $field, $instance, $langcode, $items, $form, $form_state);
  return $field_form;
}

/**
 * Returns an initial node to be used for a custom node add form.
 */
function anavem_siniestro_get_initial_node($type) {
  static $node;
  if (isset($node)) {
    return $node;
  }

  global $user;
  $node = new stdClass();
  $node->uid = $user->uid;
  $node->type = $type;
  $node->status = 0;
  $node->language = LANGUAGE_NONE;
  return $node;
}

/**
 * Saves a Siniestro node.
 */
function anavem_siniestro_save($params) {
  // Core Fields.
  global $user;
  $node = new stdClass();
  $node->uid = $user->uid;
  $node->status = 1;
  $node->type = 'siniestro';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Siniestro';

  // Custom Fields.
  $node->field_poliza = $params['field_poliza'];
  $node->field_ajustador = $params['field_ajustador'];
  $node->field_poblacion = $params['field_poblacion'];
  $node->field_estado_single = $params['field_estado_single'];
  $node->field_lugar_referencias = $params['field_lugar_referencias'];

  // Test.
  if (($node = node_submit($node))) {
    node_save($node);
    $node->title = "Siniestro " . $node->nid;
    node_save($node);
    drupal_set_message('El Siniestro ha sido creado y asignado correctamente.');
  }
}

/**
 * Get all siniestros ids.
 */
function anavem_siniestro_get_all() {
  static $rows;
  if (isset($rows)) {
    return $rows;
  }

  $sql = "SELECT nid FROM {node} WHERE type = 'siniestro'";
  $results = db_query($sql);
  $rows = array();
  while (($row = $results->fetchAssoc())) {
    $rows[$row['nid']] = $row['nid'];
  }

  return $rows;
}

/**
 * Get all polizas ids.
 */
function anavem_poliza_get_all() {
  static $rows;
  if (isset($rows)) {
    return $rows;
  }

  $sql = "SELECT nid FROM {node} WHERE type = 'poliza'";
  $results = db_query($sql);
  $rows = array();

  while (($row = $results->fetchAssoc())) {
    $rows[$row['nid']] = $row['nid'];
  }

  return $rows;
}

/**
 * Get own polizas ids.
 */
function anavem_poliza_get_own($uid) {
  static $rows;
  if (isset($rows)) {
    return $rows;
  }

  $type = 'poliza';
  $results = db_query("SELECT nid FROM node WHERE type = :type AND uid = :uid",
  array(
    ':type' => $type,
    ':uid' => $uid,
  ));
  $rows = array();
  while (($row = $results->fetchAssoc())) {
    $rows[$row['nid']] = $row['nid'];
  }

  return $rows;
}

/**
 * Get assigned polizas ids.
 */
function anavem_poliza_get_assigned($uid) {
  static $rows;
  if (isset($rows)) {
    return $rows;
  }

  $type = 'poliza';
  $results = db_query("SELECT N.nid FROM {node} AS N INNER JOIN {field_data_field_asignar_promotor} AS FDFP ON N.nid = FDFP.entity_id WHERE type = :type AND FDFP.field_asignar_promotor_target_id = :uid",
  array(
    ':type' => $type,
    ':uid' => $uid,
  ));
  $rows = array();
  while (($row = $results->fetchAssoc())) {
    $rows[$row['nid']] = $row['nid'];
  }

  return $rows;
}

/**
 * Returns the Poliza attached to a Siniestro.
 */
function anavem_get_poliza_from_siniestro($siniestro) {
  if (isset($node->field_poliza[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_poliza[LANGUAGE_NONE][0]['target_id']) && ($poliza = node_load($node->field_poliza[LANGUAGE_NONE][0]['target_id']))) {
    return $poliza;
  }

  return FALSE;
}

/**
 * Get all siniestros related with a given poliza.
 */
function anavem_poliza_get_siniestros($poliza) {
  $sql = "SELECT entity_id FROM {field_data_field_poliza} WHERE bundle = 'siniestro' AND field_poliza_target_id = %d";
  $sql = sprintf($sql, $poliza->nid);
  $results = db_query($sql);
  $rows = array();

  while (($row = $results->fetchAssoc())) {
    if (($siniestro = node_load($row['entity_id']))) {
      $rows[$siniestro->nid] = $siniestro;
    }
  }

  return $rows;
}
