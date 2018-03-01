<?php

/**
 * @file
 * Retrieves items from sinister.
 */

/**
 * Implements hook_menu().
 */
function sinister_menu() {
  $items = array();
  $items['admin/config/sinister'] = array(
    'title' => 'Sinister',
    'description' => 'General settings for Sinister Features.',
    'position' => 'right',
    'weight' => -200,
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('administer site configuration'),
    'file' => 'system.admin.inc',
    'file path' => drupal_get_path('module', 'system'),
  );

  $items['admin/config/sinister/number'] = array(
    'title' => 'Sinister Number',
    'description' => 'Defines what is the current contract number that each sinister will use to generate a folio.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('sinister_form_settings'),
    'access arguments' => array('administer sinister number'),
  );

  $items['admin/config/sinister/number/debug'] = array(
    'title' => 'Debug',
    'page callback' => 'sinister_menu_debug',
    'access arguments' => array('administer sinister number'),
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Returns sinister folio.
 */
function sinister_menu_debug() {
  $sinister_folio = sinister_number_folio_get();
  print $sinister_folio;
  exit;
}
