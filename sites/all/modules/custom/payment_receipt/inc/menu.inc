<?php

/**
 * @file
 * This has data manipulation functions.
 */

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

  $items['admin/config/payment/receipt/update/contract/number'] = array(
    'title' => 'Update Contract Number on each Payment Receipt.',
    'page callback' => 'payment_receipt_menu_update_contract_number',
    'access arguments' => array('payment receipt update contract number'),
    'type' => MENU_CALLBACK,
  );

  $items['admin/config/payment/receipt/number/debug'] = array(
    'title' => 'Debug',
    'page callback' => 'payment_receipt_menu_debug',
    'access arguments' => array('administer payment receipt number'),
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Implements payment_receipt_menu_debug().
 */
function payment_receipt_menu_debug() {
  $payment_receipt_folio = payment_receipt_receipt_number_folio_get();
  print $payment_receipt_folio;
  exit;
}

/**
 * Updates contract number on each payment receipt.
 */
function payment_receipt_menu_update_contract_number() {
  // Get payment receipt node IDs.
  $payment_receipt_nids = payment_receipt_get_all_payment_receipt_contract_nids();

  if (!$payment_receipt_nids) {
    print '<h1 style="text-align: center;">Error on database query.</h1>';
    exit;
  }

  // Declare contract number variables.
  $contract_numbers = NULL;
  $count_contract_number = 0;

  // Proccess payment receipt nodes.
  foreach ($payment_receipt_nids as $key => $row) {
    // Get payment receipt node id.
    $payment_receipt_nid = $row['nc_child_nid'];

    // Load payment receipt node.
    $node = node_load($payment_receipt_nid);

    // Update contract number only if the field is empty.
    if (empty($node->field_poliza)) {
      $node->field_poliza[LANGUAGE_NONE][0]['target_id'] = $row['nc_parent_nid'];
      node_save($node);
      $contract_numbers[] = $row['nc_parent_nid'];
      $count_contract_number++;
    }
  }

  // Create array message.
  $msg = [
    $count_contract_number . ' contract numbers were updated:',
    $contract_numbers,
  ];

  // Create BD Log message.
  watchdog('payment_receipt', '<pre>' . print_r($msg, TRUE) . '</pre>');

  // Print mesagge on the page.
  print_r($msg);
  exit;
}
