<?php

/**
 * @file
 * This file implements hook_menu().
 */

/**
 * Implements hook_menu().
 */
function insurance_contract_menu() {
  $items = array();
  $items['admin/config/insurance'] = array(
    'title' => 'Insurance',
    'description' => 'General settings for Insurance Features.',
    'position' => 'right',
    'weight' => -200,
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('administer site configuration'),
    'file' => 'system.admin.inc',
    'file path' => drupal_get_path('module', 'system'),
  );

  $items['admin/config/insurance/contract'] = array(
    'title' => 'Contract Number',
    'description' => 'Defines what is the current contract number that each contract will use to generate a folio.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('insurance_contract_form_settings'),
    'access arguments' => array('administer insurance contract number'),
  );

  $items['admin/config/insurance/contract/debug'] = array(
    'title' => 'Debug',
    'page callback' => 'insurance_contract_menu_debug',
    'access arguments' => array('administer insurance contract number'),
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Debugs a contract.
 */
function insurance_contract_menu_debug() {
  $contract_folio = insurance_contract_contract_folio_get();
  print $contract_folio;
  exit;
}
