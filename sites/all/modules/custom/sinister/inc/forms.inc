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

/**
 * Form builder; The contract number form.
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
	// field title(numero de siniestro)
  $form['title']['#attributes']['readonly'] = 'readonly';
  $form['title']['#attributes']['style']  = 'display: none;';
  //$form Validate
  //$form['#validate'][] = 'sinister_number_siniestro_node_validate'; 
  //$form attached JS
  drupal_add_js(drupal_get_path('module', 'sinister') . '/js/siniestro.reserva.js');
}
