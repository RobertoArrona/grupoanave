<?php

/**
 * @file
 * This files has permissions definitions.
 */

/**
 * Implements hook_permission().
 */
function insurance_contract_permission() {
  return array(
    'administer insurance contract number' => array(
      'title' => t('Administer Insurance Contract number'),
      'description' => t('Administer Insurance Contract number.'),
    ),
  );
}
