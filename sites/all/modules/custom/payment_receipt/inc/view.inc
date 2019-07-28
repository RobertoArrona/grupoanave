<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_views_pre_render().
 */
function payment_receipt_views_pre_render(&$view) {
  if ($view->name == 'contract_receipts' && $view->current_display == 'page') {
    // Load javascript for payment receipt view filters.
    $pathJS = drupal_get_path('module', 'payment_receipt') . '/js/payment-receipt-view.js';
    drupal_add_js($pathJS);
  }
}
