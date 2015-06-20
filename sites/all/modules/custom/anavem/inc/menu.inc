<?php
/**
 * Implements hook_menu.
 */
function anavem_menu() {
  $items = array();
  $items['admin/anave/siniestros/crear'] = array(
    'title' => 'Crear Siniestro', 
    'page callback' => 'drupal_get_form', 
    'page arguments' => array('anavem_siniestro_select_ajustador_form'), 
    'access arguments' => array('Asignar Ajustador'), 
    'type' => MENU_CALLBACK, 
  );
  $items['admin/anave'] = array(
    'title' => 'Administración Anave', 
    'page callback' => 'anavem_menu_landing_page', 
    'access arguments' => array('Anave User Landing Page'), 
    'type' => MENU_CALLBACK, 
  );
  return $items;
}

/**
 * Implements hook_menu_alter.
 */
function anavem_menu_alter(&$items) {
  $items['user']['page callback'] = array('anavem_user_page');
}

/**
 * Admin Anave Landing Page.
 */
function anavem_menu_landing_page() {
  // Links
  $sections = array();
  
  // Usuarios
  if ( user_access('Administrar Usuarios') ) {
    $sections['usuarios'] = array(
      'id' => 'usuarios', 
      'title' => 'Usuarios', 
      'description' => 'Muestra una tabla donde podrás administrar los diferentes Usuarios.', 
      'url' => url('admin/anave/usuarios'), 
    );
  }
  
  // Polizas
  if ( user_access('Administrar Polizas') ) {
    $sections['polizas'] = array(
      'id' => 'polizas', 
      'title' => 'Polizas', 
      'description' => 'Muestra una tabla donde podrás administrar Polizas.', 
      'url' => url('admin/anave/polizas'), 
    );
  }

  // Siniestros
  if ( user_access('Administrar Siniestros') ) {
    $sections['siniestros'] = array(
      'id' => 'siniestros', 
      'title' => 'Siniestros', 
      'description' => 'Muestra una tabla donde podrás administrar Siniestros.', 
      'url' => url('admin/anave/siniestros'), 
    );
  }
  $output = '';
  foreach($sections as $id => $section) {
    $output .= theme('anavem-user_landing-section', $section);
  }
  return theme('anavem-user_landing', array('sections' => $output));
}

/**
 * Override of User Callback.
 */
function anavem_user_page() {
  if ( !user_access('Anave User Landing Page') ) {
    return user_page();
  }
  
  global $user;
  if ( $user->uid == 0 ) {
    return drupal_access_denied();
  }

  drupal_goto('admin/anave');
  exit;
}