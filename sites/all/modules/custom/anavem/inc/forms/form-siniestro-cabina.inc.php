<?php

/**
 * @file
 * This file has form for selecting ajustador.
 */

/**
 * Siniestro Form for Cabina.
 */
function anavem_siniestro_select_ajustador_form($form, &$form_state) {
  $form['#parents'] = array();

  // Get Poliza Field.
  $poliza_field = anavem_get_field('field_poliza', 'node', 'siniestro', $form, $form_state);
  $form += $poliza_field;

  // Get Poliza Comentarios Field.
  $poliza_comentarios_field = anavem_get_field('field_poliza_comentarios', 'node', 'siniestro', $form, $form_state);
  $form['poliza'] = array(
    '#type' => 'fieldset',
    '#title' => 'Comentarios de Poliza',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 1,
  );

  $form['poliza'] += $poliza_comentarios_field;

  // Get Ajustador Field.
  $ajustador_field = anavem_get_field('field_ajustador', 'node', 'siniestro', $form, $form_state);
  $ajustador_field['#weight'] = 2;
  $form += $ajustador_field;

  // Get Lugar Fields.
  $form['lugar'] = array(
    '#type' => 'fieldset',
    '#title' => 'Lugar del Siniestro',
    '#weight' => 4,
  );

  $poblacion_field = anavem_get_field('field_poblacion', 'node', 'siniestro', $form, $form_state);
  $form['lugar'] += $poblacion_field;
  $estado_field = anavem_get_field('field_estado_single', 'node', 'siniestro', $form, $form_state);
  $form['lugar'] += $estado_field;
  $referencias_field = anavem_get_field('field_lugar_referencias', 'node', 'siniestro', $form, $form_state);
  $form['lugar'] += $referencias_field;

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => 'Crear Siniestro',
    ),
  );

  return $form;
}

/**
 * Process submission of the Siniestro Form for Cabina.
 */
function anavem_siniestro_select_ajustador_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  anavem_siniestro_save($values);
}
