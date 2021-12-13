<?php

/**
 * @file
 * This has data manipulation functions.
 */

/**
 * Implements hook_menu().
 */
function payment_receipt_menu() {
  $items = array();
  $items['admin/config/payment'] = array(
    'title' => 'Receipt',
    'description' => 'General settings for Receipt Features.',
    'position' => 'right',
    'weight' => -200,
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('administer site configuration'),
    'file' => 'system.admin.inc',
    'file path' => drupal_get_path('module', 'system'),
  );

  $items['admin/config/payment/receipt'] = array(
    'title' => 'Payment Receipt Number',
    'description' => 'Defines what is the current payment receipt number that each receipt will use to generate a folio.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('payment_receipt_form_settings'),
    'access arguments' => array('administer payment receipt number'),
  );

  $items['admin/config/payment/receipt/update/new/fields'] = array(
    'title' => 'Update new fields on each Payment Receipt.',
    'page callback' => 'payment_receipt_menu_update_new_fields',
    'access arguments' => array('payment receipt update new fields'),
    'type' => MENU_CALLBACK,
  );

  $items['admin/config/payment/receipt/number/debug'] = array(
    'title' => 'Debug',
    'page callback' => 'payment_receipt_menu_debug',
    'access arguments' => array('administer payment receipt number'),
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Implements hook_menu_debug().
 */
function payment_receipt_menu_debug() {
  $payment_receipt_folio = payment_receipt_receipt_number_folio_get();
  print $payment_receipt_folio;
  exit;
}

/**
 * Updates data for new fields on each payment receipt.
 */
function payment_receipt_menu_update_new_fields() {
  // Get payment receipt node IDs.
  $payment_receipt_nids = payment_receipt_get_all_payment_receipt_nids();

  if (!$payment_receipt_nids) {
    print '<h1 style="text-align: center;">Error on database query.</h1>';
    exit;
  }

  // Declare contract number variables.
  $payment_receip_nids = NULL;
  $count_payment_receipt = 0;

  // Proccess payment receipt nodes.
  foreach ($payment_receipt_nids as $payment_receipt_nid) {
    // Load payment receipt node.
    $node = node_load($payment_receipt_nid);

    // Update contract number only if the new fields are empty.
    if (empty($node->field_asegurado_nombre) || empty($node->field_asegurado_domicilio) || empty($node->field_poliza_forma_pago) || empty($node->field_contract_type) || empty($node->field_currency) || empty($node->field_poliza_prima_neta) || empty($node->field_issuance) || empty($node->field_total_premium)) {

      // Validate field poliza.
      if (!empty($node->field_poliza)) {
        // Get contract node id.
        $contract_nid = $node->field_poliza[LANGUAGE_NONE][0]['target_id'];

        // Load contract node.
        $contract_node = node_load($contract_nid);

        // Set contract requester name.
        if (!empty($contract_node->field_asegurado_nombre)) {
          $requester_name = $contract_node->field_asegurado_nombre[LANGUAGE_NONE][0]['value'];
          $node->field_asegurado_nombre[LANGUAGE_NONE][0]['value'] = $requester_name;
        }

        // Set contract requester address.
        if (!empty($contract_node->field_asegurado_domicilio)) {
          $requester_address = $contract_node->field_asegurado_domicilio[LANGUAGE_NONE][0];
          $node->field_asegurado_domicilio[LANGUAGE_NONE][0] = $requester_address;
        }

        // Set payment type.
        if (!empty($contract_node->field_poliza_forma_pago)) {
          $payment_type = $contract_node->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'];
          $node->field_poliza_forma_pago[LANGUAGE_NONE][0]['value'] = $payment_type;
        }

        // Set contract type.
        if (!empty($contract_node->field_poliza_coberturas)) {
          $field_collection_entity = field_collection_item_load($contract_node->field_poliza_coberturas[LANGUAGE_NONE][0]['value'], $reset = FALSE);
          $contract_type = $field_collection_entity->field_poliza_tipo[LANGUAGE_NONE][0]['value'];
          $node->field_contract_type[LANGUAGE_NONE][0]['value'] = $contract_type;
        }

        // Set currency.
        if (!empty($contract_node->field_poliza_moneda)) {
          $currency = $contract_node->field_poliza_moneda[LANGUAGE_NONE][0]['value'];
          $node->field_currency[LANGUAGE_NONE][0]['value'] = $currency;
        }

        // Set net premium.
        if (!empty($contract_node->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value'])) {
          $net_premium = $contract_node->field_poliza_primas_recibos_subs[LANGUAGE_NONE][0]['value'];
          $net_premium = round($net_premium, 2);
          $node->field_poliza_prima_neta[LANGUAGE_NONE][0]['value'] = $net_premium;
        }
        else {
          $node->field_poliza_prima_neta[LANGUAGE_NONE][0]['value'] = 0;
        }

        // Set issuance.
        if (!empty($contract_node->field_derecho_de_poliza2)) {
          $issuance = $contract_node->field_derecho_de_poliza2[LANGUAGE_NONE][0]['value'];
          $node->field_issuance[LANGUAGE_NONE][0]['value'] = $issuance;
        }
        else {
          $node->field_issuance[LANGUAGE_NONE][0]['value'] = 0;
        }

        // Set total premium.
        if (isset($node->field_primer_pago_rc[LANGUAGE_NONE][0]['value']) && isset($node->field_pago_subsecuente_rc[LANGUAGE_NONE][0]['value'])) {
          $first_payment = $node->field_primer_pago_rc[LANGUAGE_NONE][0]['value'];
          $subsequent_payment = $node->field_pago_subsecuente_rc[LANGUAGE_NONE][0]['value'];
          $total_premium = $first_payment + $subsequent_payment;
          $total_premium = round($total_premium, 2);
          $node->field_total_premium[LANGUAGE_NONE][0]['value'] = $total_premium;
        }
        else {
          $node->field_total_premium[LANGUAGE_NONE][0]['value'] = 0;
        }

        // Payment receipt node.
        node_save($node);

        // Add payment receipt node id to array.
        $payment_receip_nids[] = $payment_receipt_nid;

        // Increase payment receipt counter.
        $count_payment_receipt++;
      }
    }
  }

  // Create array message.
  $msg = [
    $count_payment_receipt . ' payment receipts were updated:',
    $payment_receip_nids,
  ];

  // Create BD Log message.
  $msg = '<pre>' . print_r($msg, TRUE) . '</pre>';
  watchdog('payment_receipt', $msg);

  // Print mesagge on the page.
  print_r($msg);
  exit;
}
