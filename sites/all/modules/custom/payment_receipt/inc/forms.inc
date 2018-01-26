<?php
  
/**
 * Implements hook_form_alter().
 */
function payment_receipt_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'recibo_contrato_node_form':
      $path = drupal_get_path('module', 'payment_receipt') . '/css/payment_receipt.admin.css';
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
function payment_receipt_form_settings() {
  $form['contract_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contract'),
  );
  $form['payment_receipt_information']['payment_receipt_receipt_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number'),
    '#default_value' => variable_get('payment_receipt_receipt_number', '1000001'),
    '#required' => TRUE,
  );


  return system_settings_form($form);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function payment_receipt_form_recibo_contrato_node_form_alter(&$form, &$form_state, $form_id) {

  if (!(isset($form['nid']['#value']) && !empty($form['nid']['#value']))) {
    $payment_receipt_folio = payment_receipt_receipt_number_folio_get();
    
    if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio)) {
      $payment_receipt_folio = payment_receipt_receipt_new_folio();
    }
    
    $form['title']['#default_value'] = $payment_receipt_folio;
  }
  
  $form['title']['#attributes']['readonly'] = 'readonly';
  $form['title']['#attributes']['style']  = 'display: none;';
  $form['#validate'][] = 'payment_receipt_node_form_validate';
  
}

function payment_receipt_node_form_validate($form, &$form_state) {
  $node = menu_get_object();
  if(empty($node ->nid)) {
    $payment_receipt_folio = $form_state['values']['title'];
    if (payment_receipt_receipt_number_folio_exists($payment_receipt_folio)) {
      $newfolio = payment_receipt_receipt_new_folio();
      $form_state['values']['title'] = $newfolio;
    }
  }
  
}

