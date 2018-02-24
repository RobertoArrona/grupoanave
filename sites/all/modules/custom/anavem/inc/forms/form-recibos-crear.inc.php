<?php

/**
 * @file
 * This file has form crear recibos.
 */

/**
 * Returns a drupal form to create Recibos.
 */
function anavem_recibos_crear_form($form, &$form_state) {
  $form = array();
  $form['usuario'] = array(
    '#type' => 'textfield',
    '#title' => t('Usuario'),
    '#required' => TRUE,
    '#autocomplete_path' => 'anavem/autocomplete/recibo-usuario',
  );
  $form['folioinicio'] = array(
    '#type' => 'textfield',
    '#title' => t('Inicio de Folio'),
    '#required' => TRUE,
  );
  $form['foliofin'] = array(
    '#type' => 'textfield',
    '#title' => t('Fin de Folio'),
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Validation for form anavem_recibos_crear_form().
 */
function anavem_recibos_crear_form_validate($form, &$form_state) {
  if (intval($form_state['values']['folioinicio']) < 1) {
    form_set_error('folioinicio', t('Por favor escriba un número de folio correcto.'));
  }

  if (intval($form_state['values']['foliofin']) < 1) {
    form_set_error('folioinicio', t('Por favor escriba un número de folio correcto.'));
  }
}
