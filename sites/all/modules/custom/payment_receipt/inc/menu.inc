<?php 

/**
 * Implements hook_menu().
 */
function payment_receipt_menu() {
  $items = array();
  $items['admin/config/payment'] = array(
    'title' => 'Receipt',
    'description' => 'General settings for Receipt Features.',
    'position' => 'right',
    'weight' => -200,
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('administer site configuration'),
    'file' => 'system.admin.inc',
    'file path' => drupal_get_path('module', 'system'),
  );
  
  $items['admin/config/payment/receipt'] = array(
    'title' => 'Payment Receipt Number',
    'description' => 'Defines what is the current payment receipt number that each receipt will use to generate a folio.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('payment_receipt_form_settings'),
    'access arguments' => array('administer payment receipt number'),
  );

  $items['admin/config/payment/receipt/number/debug'] = array(
    'title' => 'Debug',
    'page callback' => 'payment_receipt_menu_debug',
    'access arguments' => array('administer payment receipt number'),
    'type' => MENU_CALLBACK,
  );

  return $items;
}

function payment_receipt_menu_debug() {
  $payment_receipt_folio = payment_receipt_receipt_number_folio_get();
  print $payment_receipt_folio;
  exit;
}