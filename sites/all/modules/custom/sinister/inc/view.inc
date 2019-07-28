<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_views_pre_render().
 */
function sinister_views_pre_render(&$view) {
  if ($view->name == 'siniestros' && $view->current_display == 'page') {
    // Load jquery ui library to use datepicker on date filter for sinister view.
    $pathCSS = drupal_get_path('module', 'sinister') . '/css/jquery-ui.css';
    $pathCSS2 = drupal_get_path('module', 'sinister') . '/css/sinister-view.css';
    $pathJS = drupal_get_path('module', 'sinister') . '/js/jquery-ui.js';
    $pathJS2 = drupal_get_path('module', 'sinister') . '/js/date-picker.js';
    drupal_add_css($pathCSS);
    drupal_add_css($pathCSS2);
    drupal_add_js($pathJS);
    drupal_add_js($pathJS2);
  }
}
