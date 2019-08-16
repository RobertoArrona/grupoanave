<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_form_alter().
 */
function payment_receipt_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'recibo_contrato_node_form':
      $pathCSS = drupal_get_path('module', 'payment_receipt') . '/css/payment-receipt.admin.css';
      drupal_add_css($pathCSS);
      $pathJS = drupal_get_path('module', 'payment_receipt') . '/js/payment-receipt.js';
      drupal_add_js($pathJS);
      break;
  }
}

/**
 * Form builder; The contract number form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function payment_receipt_form_settings() {
  if (empty(variable_get('payment_receipt_receipt_number'))) {
    variable_set('payment_receipt_receipt_number', '1000001');
  }
  elseif (!empty(variable_get('payment_receipt_receipt_number'))) {
    $payment_receipt_folio = variable_get('payment_receipt_receipt_number');
    if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio)) {
      $newfolio = payment_receipt_receipt_new_folio();
      variable_set('payment_receipt_receipt_number', $newfolio);
    }
  }

  $form['contract_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Payment Receipt'),
  );

  $form['payment_receipt_information']['payment_receipt_receipt_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#default_value' => variable_get('payment_receipt_receipt_number'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function payment_receipt_form_recibo_contrato_node_form_alter(&$form, &$form_state, $form_id) {
  // Define when is the first payemnt.
  if ($form['field_primer_pago_rc'][LANGUAGE_NONE][0]['value']['#default_value'] != 0) {
    print ("<h1>Es el primer pago</h1>");
  }
  else {
    print ("<h1>Es pago subsecuente</h1>");
  }

  // Hide some fields.
  $form['field_poliza']['#attributes']['style'] = 'display: none;';
  $form['field_fecha_de_expedicion_rc']['#attributes']['style'] = 'display: none;';
  $form['field_asegurado_nombre']['#attributes']['style'] = 'display: none;';
  $form['field_asegurado_domicilio']['#attributes']['style'] = 'display: none;';
  $form['field_primer_pago_rc']['#attributes']['style'] = 'display: none;';
  $form['field_importe_con_letra_rc']['#attributes']['style'] = 'display: none;';
  $form['field_periodo_cobertura_rc']['#attributes']['style'] = 'display: none;';
  $form['field_poliza_forma_pago']['#attributes']['style'] = 'display: none;';
  $form['field_contract_type']['#attributes']['style'] = 'display: none;';
  $form['field_currency']['#attributes']['style'] = 'display: none;';
  $form['field_poliza_prima_neta']['#attributes']['style'] = 'display: none;';
  $form['field_issuance']['#attributes']['style'] = 'display: none;';
  $form['field_total_premium']['#attributes']['style'] = 'display: none;';

  // Get restricted role.
  $uid = $GLOBALS["user"]->uid;
  $user = user_load($uid);
  $restricted_roles = array(
    'agente de ventas',
  );

  // Add css only when is restricted role.
  if (is_array($user->roles)) {
    $user_roles = $user->roles;

    foreach ($restricted_roles as $restricted_role) {
      if (in_array($restricted_role, $user_roles)) {
        drupal_add_css(drupal_get_path('module', 'payment_receipt') . '/css/payment-receipt-form.css');
      }
    }
  }
}
