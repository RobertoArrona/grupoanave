<?php

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
  $userld= insurance_contract_contract_load_oficina_get();
  
  $form['field_poliza_oficina'][LANGUAGE_NONE][0]['value']['#default_value'] = $userld;
  $form['field_poliza_oficina'][LANGUAGE_NONE][0]['value']['#attributes']['style'] = 'display: none;';
  $form['field_poliza_emision']['#attributes']['style'] = 'display: none;';

  // field title(numero de contrato)
  $form['title']['#attributes']['style']  = 'display: none;';
  //print_r($form); exit;
  // field_asegurado_domicilio
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['street_block']['thoroughfare']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['street_block']['premise']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['locality']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#required'] = 'true';
  $form['field_asegurado_domicilio'][LANGUAGE_NONE][0]['locality_block']['postal_code']['#required'] = 'true';
  //$form Validate
  $form['#validate'][] = 'insurance_contract_form_poliza_node_validate';

  //$form attached JS
  drupal_add_js(drupal_get_path('module', 'insurance_contract') . '/js/contratos.pagos.js');
}

/**
 *
 */
function insurance_contract_form_poliza_node_validate(&$form, &$form_state){
  
  $issuedate = strtotime($form_state['values']['field_poliza_emision'][LANGUAGE_NONE][0]['value']);
  $validity = strtotime($form_state['values']['field_poliza_vigencia'][LANGUAGE_NONE][0]['value']);
  if ($validity < $issuedate) {
    form_set_error('field_poliza_emision', '');
    form_set_error('field_poliza_vigencia', t('The validity start date cannot be earlier than the issue date.'));
  }

  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    if (($contract_folio = insurance_contract_contract_folio_get())) {
      if ($contract_folio != $form_state['values']['title']) {
        form_set_error('title', t('Is forbidden to modify the Contract folio, please contact the administers of the site if you really need this.'));
      }
    }
  }
}
