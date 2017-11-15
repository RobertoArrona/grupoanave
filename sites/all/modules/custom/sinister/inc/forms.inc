<?php

/**
 * Implements hook_form_alter().
 */
function sinister_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'siniestro_node_form':
      $path = drupal_get_path('module', 'sinister') . '/css/sinister.admin.css';
      drupal_add_css($path);
      break;
  }
}
