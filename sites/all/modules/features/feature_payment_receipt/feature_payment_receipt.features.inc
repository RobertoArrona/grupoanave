<?php

/**
 * @file
 * feature_payment_receipt.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_payment_receipt_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_payment_receipt_node_info() {
  $items = array(
    'recibo_contrato' => array(
      'name' => t('Recibo Contrato'),
      'base' => 'node_content',
      'description' => t('Registra los recibos de contratos.'),
      'has_title' => '1',
      'title_label' => t('Folio'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
