<?php
function anavem_get_field($field_name, $entity_type, $bundle_name, &$form, &$form_state) {
  $entity = anavem_siniestro_get_initial_node($entity_type);
  $langcode = $entity->language;
  $items = field_get_items($entity_type, $entity, $field_name);
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle_name);
  $field_form = field_default_form($entity_type, $entity, $field, $instance, $langcode, $items, $form, $form_state);
  return $field_form;
}

function anavem_siniestro_get_initial_node($type) {
  static $node;
  if ( isset($node) ) {
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

function anavem_siniestro_save($params) {
  // Core Fields
  global $user;
  $node = new stdClass();
  $node->uid = $user->uid;
  $node->status = 1;
  $node->type = 'siniestro';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Siniestro';
  
  // Custom Fields
  $node->field_poliza = $params['field_poliza'];
  $node->field_ajustador = $params['field_ajustador'];
  $node->field_poblacion = $params['field_poblacion'];
  $node->field_estado_single = $params['field_estado_single'];
  $node->field_lugar_referencias = $params['field_lugar_referencias'];
  
  // Test
  if ( ($node = node_submit($node)) ) {
    node_save($node);
    $node->title = "Siniestro " . $node->nid;
    node_save($node);
    drupal_set_message('El Siniestro ha sido creado y asignado correctamente.');
  }
}