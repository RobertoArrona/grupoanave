<?php
/**
 * Implements hook_menu.
 */
function anavem_menu() {
  $items = array();
  $items['siniestro/crear'] = array(
    'title' => 'Crear Siniestro', 
    'page callback' => 'drupal_get_form', 
    'page arguments' => array('anavem_siniestro_select_ajustador_form'), 
    'access arguments' => array('Asignar Ajustador'), 
    'type' => MENU_CALLBACK, 
  );
  return $items;
}