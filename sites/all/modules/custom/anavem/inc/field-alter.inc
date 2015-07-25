<?php
/**
 * Implements hook_field_widget_form_alter().
 */
function anavem_field_widget_form_alter(&$element, $form_state, $context) {
  if(!empty($element['#addressfield'])) {
    $element['country'] = array(
      '#type' => 'value', 
      '#value' => 'MX', 
      '#attributes' => array(
        'style' => 'display: none;', 
      ), 
    );
    unset($element['locality_block']['dependent_locality']);
  }
}