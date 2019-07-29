<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_node_submit().
 */
function payment_receipt_node_submit($node, $form, &$form_state) {
  if (empty($node->nid)) {
    switch ($node->type) {
      case 'recibo_contrato':
        payment_receipt_receipt_number_increase();
        break;
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function payment_receipt_preprocess_node(&$variables, $hook) {
  if ($variables['node']->type != 'recibo_contrato') {
    return FALSE;
  }

  // Add needed CSS.
  $pathCSS = drupal_get_path('module', 'payment_receipt') . '/css/payment-receipt-node.css';
  drupal_add_css($pathCSS);
}
