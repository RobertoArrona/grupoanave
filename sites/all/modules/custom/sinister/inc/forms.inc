<?php

/**
 * @file
 * Retrieve sinister number data.
 */

/**
 * Implements hook_form_alter().
 */
function sinister_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'siniestro_node_form':
      $pathCSS = drupal_get_path('module', 'sinister') . '/css/sinister.admin.css';
      drupal_add_css($pathCSS);

      $pathJS = drupal_get_path('module', 'sinister') . '/js/siniestro.reserva.js';
      drupal_add_js($pathJS);

      $sinister_folio = $form['title']['#default_value'];

      foreach ($form['field_vehiculo_tercero'][LANGUAGE_NONE] as $delta => $field) {
        if (is_numeric($delta)) {

          $form['field_vehiculo_tercero'][LANGUAGE_NONE][$delta]['field_3ro_siniestro'][LANGUAGE_NONE][0]['value']['#value'] = $sinister_folio;
          $form['field_vehiculo_tercero'][LANGUAGE_NONE][$delta]['field_3ro_siniestro'][LANGUAGE_NONE][0]['value']['#attributes']['disabled'] = TRUE;

        }
      }

      break;
  }
}

/**
 * Form builder; The sinister number form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function sinister_form_settings() {
  $form['sinister_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sinister'),
  );
  $form['sinister_information']['sinister_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#default_value' => variable_get('sinister_number', '0001'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function sinister_form_siniestro_node_form_alter(&$form, &$form_state, $form_id) {
  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    if (($sinister_folio = sinister_number_folio_get())) {
      $form['title']['#default_value'] = $sinister_folio;
    }
  }

  // Field title(numero de siniestro)
  $form['title']['#attributes']['readonly'] = 'readonly';
  $form['title']['#attributes']['style'] = 'display: none;';

}
