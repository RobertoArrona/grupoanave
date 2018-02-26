<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_permission().
 */
function payment_receipt_permission() {
  return array(
    'administer payment receipt number' => array(
      'title' => t('Administer Payment Receipt Number'),
      'description' => t('Administer Payment Receipt Number.'),
    ),
  );
}
