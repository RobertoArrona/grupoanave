<?php
/**
 * Implements hook_preprocess_page.
 */
function anavem_preprocess_page(&$vars) {
  if ( $_GET['q'] == 'admin/anave/polizas' ) {
    drupal_add_css(drupal_get_path('module', 'anavem') . '/css/anavem.contextual-links.css');
  }
}