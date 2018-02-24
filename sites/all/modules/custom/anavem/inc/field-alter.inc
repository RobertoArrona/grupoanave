<?php

/**
 * @file
 * This file contains form alter for widget address.
 */

/**
 * Implements hook_field_widget_form_alter().
 */
function anavem_field_widget_form_alter(&$element, $form_state, $context) {
  if (!empty($element['#addressfield'])) {
    $element['country'] = array(
      '#type' => 'value',
      '#value' => 'MX',
      '#attributes' => array(
        'style' => 'display: none;',
      ),
    );

    $element['street_block']['thoroughfare']['#title'] = t('Calle y Número');
    $element['street_block']['premise']['#title'] = t('Colonia');
    $element['locality_block']['locality']['#title'] = t('Ciudad');
    $element['locality_block']['administrative_area']['#title'] = t('Estado');
    $element['locality_block']['postal_code']['#title'] = t('C&oacute;digo Postal');
    unset($element['locality_block']['dependent_locality']);
  }
}
