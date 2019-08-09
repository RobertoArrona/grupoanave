<?php

/**
 * @file
 * This files has all page functionalities.
 */

/**
 * Implements hook_page_build().
 */
function insurance_contract_page_build(&$page) {
  if (path_is_admin(current_path())) {
    drupal_add_js(drupal_get_path('module', 'insurance_contract') . '/js/contract.view.data.export.js');
  }
}
