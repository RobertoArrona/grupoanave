<?php

/**
 * @file
 * This files has all form functions and definitions.
 */

/**
 * Form builder; The contract number form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function insurance_contract_form_settings() {
  $form['contract_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contract'),
  );
  $form['contract_information']['insurance_contract_contract_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#default_value' => variable_get('insurance_contract_contract_number', '1001'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function insurance_contract_form_poliza_node_form_alter(&$form, &$form_state, $form_id) {
  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    if (($contract_folio = insurance_contract_contract_folio_get())) {
      $form['title']['#default_value'] = $contract_folio;
    }
  }

  $form['title']['#attributes']['readonly'] = 'readonly';
  $userld = insurance_contract_contract_load_oficina_get();

  $form['field_poliza_oficina'][LANGUAGE_NONE][0]['value']['#default_value'] = $userld;
  $form['field_poliza_oficina'][LANGUAGE_NONE][0]['value']['#attributes']['style'] = 'display: none;';
  $form['field_poliza_emision']['#attributes']['style'] = 'display: none;';

  // Field title(numero de contrato).
  $form['title']['#attributes']['style'] = 'display: none;';

  // Fields Premium Read only.
  $form['field_poliza_prima_total'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_poliza_prima_1er_recibo'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';
  $form['field_poliza_primas_recibos_subs'][LANGUAGE_NONE][0]['value']['#attributes']['readonly'] = 'readonly';

  // Field_asegurado_domicilio.
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['street_block']['thoroughfare']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['street_block']['premise']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['locality']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['postal_code']['#required'] = 'true';

  $form['#validate'][] = 'insurance_contract_form_poliza_node_validate';

  // Add need CSS and JS.
  drupal_add_js(drupal_get_path('module', 'insurance_contract') . '/js/contratos.pagos.js');
  drupal_add_css(drupal_get_path('module', 'insurance_contract') . '/css/contratos_pagos.css');
}

/**
 * Validates insurance_contract_form_poliza_node().
 */
function insurance_contract_form_poliza_node_validate(&$form, &$form_state) {
  $issuedate = strtotime($form_state['values']['field_poliza_emision'][LANGUAGE_NONE][0]['value']);
  $validity = strtotime($form_state['values']['field_poliza_vigencia'][LANGUAGE_NONE][0]['value']);
  if ($validity < $issuedate) {
    form_set_error('field_poliza_emision', '');
    form_set_error('field_poliza_vigencia', t('The validity start date cannot be earlier than the issue date.'));
  }
}
