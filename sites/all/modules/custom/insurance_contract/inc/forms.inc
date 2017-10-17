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
function insurance_contract_form_contrato_node_form_alter(&$form, &$form_state, $form_id) {
  if (($contract_folio = insurance_contract_contract_folio_get())) {
    $form['title']['#default_value'] = $contract_folio;
    $form['title']['#attributes']['readonly'] = 'readonly';
  }
  $form['#validate'][] = 'insurance_contract_form_contrato_node_validate';
}

/**
 *
 */
function insurance_contract_form_contrato_node_validate(&$form, &$form_state){
  $issuedate2 = getdate();
 // $issuedate = strtotime($form_state['values']['field_poliza_emision'][LANGUAGE_NONE][0]['value']);
  $validity = strtotime($form_state['values']['field_poliza_vigencia'][LANGUAGE_NONE][0]['value']);
  if ($validity < $issuedate2) {
    form_set_error('field_poliza_emision', '');
    form_set_error('field_poliza_vigencia', t('The validity start date cannot be earlier than the issue date.'));
  }

  if (($contract_folio = insurance_contract_contract_folio_get())) {
    if ($contract_folio != $form_state['values']['title']) {
      form_set_error('title', t('Is forbidden to modify the Contract folio, please contact the administers of the site if you really need this.'));
    }
  }
}
