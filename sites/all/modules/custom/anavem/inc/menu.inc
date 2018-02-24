<?php

/**
 * @file
 * This file has all functionality related to menu pages.
 */

/**
 * Implements hook_menu().
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
    'title' => 'Administración Global',
    'page callback' => 'anavem_menu_landing_page',
    'access arguments' => array('Anave User Landing Page'),
    'type' => MENU_CALLBACK,
  );
  $items['node/%node/siniestro'] = array(
    'title' => 'Fotografías del Siniestro',
    'page callback' => 'anavem_node_page_view',
    'page arguments' => array(1, 2),
    'access callback' => 'anavem_has_siniestro',
    'access arguments' => array(1, 'Ver Siniestro'),
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    'weight' => 0,
  );
  $items['node/%node/taller'] = array(
    'title' => 'Fotografías del Taller',
    'page callback' => 'anavem_node_page_view',
    'page arguments' => array(1, 2),
    'access callback' => 'anavem_has_taller',
    'access arguments' => array(1, 'Ver Taller'),
    'type' => MENU_LOCAL_TASK,
    'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    'weight' => 0,
  );
  return $items;
}

/**
 * Function to check for permission.
 */
function anavem_has_siniestro($node, $permission) {
  if ($node->type != 'siniestro') {
    return FALSE;
  }

  if (!isset($node->field_image_siniestro[LANGUAGE_NONE][0])) {
    return FALSE;
  }

  return user_access($permission);
}

/**
 * Function to check for permission.
 */
function anavem_has_taller($node, $permission) {
  if ($node->type != 'siniestro') {
    return FALSE;
  }

  if (!isset($node->field_image_taller[LANGUAGE_NONE][0])) {
    return FALSE;
  }

  return user_access($permission);
}

/**
 * Node View Custom.
 */
function anavem_node_page_view($node, $view_mode) {
  drupal_set_title($node->title);
  $uri = entity_uri('node', $node);
  drupal_add_html_head_link(array(
    'rel' => 'canonical',
    'href' => url($uri['path'],
    $uri['options']),
  ), TRUE);
  drupal_add_html_head_link(array(
    'rel' => 'shortlink',
    'href' => url(
      $uri['path'],
      array_merge($uri['options'], array('alias' => TRUE))
    ),
  ), TRUE);
  return anavem_node_show($node, NULL, $view_mode);
}

/**
 * Override of function node_show.
 */
function anavem_node_show($node, $message = FALSE, $view_mode = 'full') {
  if ($message) {
    drupal_set_title(t('Revision of %title from %date', array('%title' => $node->title, '%date' => format_date($node->revision_timestamp))), PASS_THROUGH);
  }

  $nodes = node_view_multiple(array($node->nid => $node), $view_mode);

  node_tag_new($node);

  return $nodes;
}

/**
 * Implements hook_menu_alter().
 */
function anavem_menu_alter(&$items) {
  $items['user']['page callback'] = array('anavem_user_page');
}

/**
 * Admin Anave Landing Page.
 */
function anavem_menu_landing_page() {
  drupal_set_title('Administración Global');
  // Links.
  $sections = array();

  // Usuarios.
  if (user_access('Administrar Usuarios')) {
    $sections['usuarios'] = array(
      'id' => 'usuarios',
      'title' => 'Usuarios',
      'description' => 'Muestra una tabla donde podrás administrar los diferentes Usuarios.',
      'url' => url('admin/anave/usuarios'),
    );
  }

  // Polizas.
  if (user_access('Administrar Polizas')) {
    $sections['polizas'] = array(
      'id' => 'polizas',
      'title' => 'Contratos',
      'description' => 'Muestra una tabla donde podrás administrar Contratos.',
      'url' => url('admin/anave/contratos'),
    );
  }

  // Siniestros.
  if (user_access('Administrar Siniestros')) {
    $sections['siniestros'] = array(
      'id' => 'siniestros',
      'title' => 'Siniestros',
      'description' => 'Muestra una tabla donde podrás administrar Siniestros.',
      'url' => url('admin/anave/siniestros'),
    );
  }

  $output = '';
  foreach ($sections as $id => $section) {
    $output .= theme('anavem-user_landing-section', $section);
  }

  return theme('anavem-user_landing', array('sections' => $output));
}

/**
 * Override of User Callback.
 */
function anavem_user_page() {
  if (!user_access('Anave User Landing Page')) {
    return user_page();
  }

  global $user;
  if ($user->uid == 0) {
    return drupal_access_denied();
  }

  drupal_goto('admin/anave');
  exit;
}
