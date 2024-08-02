<?php

/**
 * @file
 * delete all Drush command
 */

/**
 * Implementation of hook_drush_command().
 */
function contract_export_drush_command() {
  $items = array();
  $items['export-contracts'] = array(
    'callback' => 'contract_export_export',
    'description' => 'Export all contract nodes',
    'options' => array(
      'roles' => 'pick roles',
      'reset' => 'Reset counter for node, revision and comment tables.',
    ),
    'aliases' => array('content_ex'),
  );
  return $items;
}

/**
 * Drush callback to delete content
 */
function contract_export_export() {
  $file = fopen(DRUPAL_ROOT . "/dumps/export.txt","w");
  fwrite($file, '');
  fclose($file);
  $results = [];
  $limit = 50;
  $start = 0;

  do {
    $is_more = FALSE;
    $results = [];

    $query = db_select('users', 'n');
    $query->fields('n', array('uid'))
      ->range($start, $limit);
    $results = $query->execute()->fetchAll();

    if (count($results) == $limit) {
      $is_more = TRUE;
    }

    $file = fopen(DRUPAL_ROOT . "/dumps/export.txt","a");
    foreach ($results as $result) {
      if ($result->uid == 0) {
        continue;
      }

      $user = user_load($result->uid);
      $line = contract_export_export_get_users($user);
      fwrite($file, $line.PHP_EOL);
    }
    fclose($file);

    $start = $start + $limit;
    drush_print('Added ' . ($start) . ' users');

  } while ($is_more);

  $start = 0;

  do {
    $is_more = FALSE;
    $results = [];

    $query = db_select('node', 'n');
    $query->fields('n', array('nid'))
      ->range($start, $limit)
      ->condition('n.type', 'poliza');
    $results = $query->execute()->fetchAll();

    if (count($results) == $limit) {
      $is_more = TRUE;
    }

    $file = fopen(DRUPAL_ROOT . "/dumps/export.txt","a");
    foreach ($results as $result) {

      $node = node_load($result->nid);
      $line = contract_export_export_get_contracts($node);
      fwrite($file, $line.PHP_EOL);
    }
    fclose($file);

    $start = $start + $limit;
    drush_print('Added ' . ($start) . ' nodes');

  } while ($is_more);
}

function contract_export_export_get_users($user) {
  $data['type'] = 'user';
  $data['name'] = ($user->name ?? '');
  $data['mail'] = ($user->mail ?? '');
  $data['status'] = ($user->status ?? '');

  // Text Fields.
  if ($user->field_agente_clave) {
    $data['field_agente_clave'] = contract_export_export_get_field_value($user->field_agente_clave, 'text');
  }

  if ($user->field_first_name) {
    $data['field_first_name'] = contract_export_export_get_field_value($user->field_first_name, 'text');
  }

  if ($user->field_last_name) {
    $data['field_last_name'] = contract_export_export_get_field_value($user->field_last_name, 'text');
  }

  if ($user->field_telefono_oficina) {
    $data['field_telefono_oficina'] = contract_export_export_get_field_value($user->field_telefono_oficina, 'text');
  }

  if ($user->field_telefono_movil) {
    $data['field_telefono_movil'] = contract_export_export_get_field_value($user->field_telefono_movil, 'text');
  }

  if ($user->field_poblacion_multiple) {
    $data['field_poblacion_multiple'] = contract_export_export_get_field_value($user->field_poblacion_multiple, 'text');
  }
  // Text Fields End.

  // Term Reference Fields.
  if ($user->field_estado) {
    $data['field_estado'] = contract_export_export_get_field_value($user->field_estado, 'term');
  }
  // Term Reference Fields End.

  // Roles.
  if ($user->roles) {
    foreach ($user->roles as $role) {
      $data['roles'][] = $role;
    }
  }
  // Roles End.

  // Address Field.
  if ($user->field_domicilio) {
    $value = $user->field_domicilio;
    $value = $value[LANGUAGE_NONE][0];
    $address['country'] = $value['country'];
    $address['administrative_area'] = $value['administrative_area'];
    $address['locality'] = $value['locality'];
    $address['postal_code'] = $value['postal_code'];
    $address['thoroughfare'] = $value['thoroughfare'];
    $address['premise'] = $value['premise'];
    $data['field_domicilio'] = $address;
  }
  // Address Field End.

  return json_encode($data);
}

/**
 * Helper function to get all contract data.
 */
function contract_export_export_get_contracts($node) {
  $data['type'] = 'contract';
  $data['title'] = ($node->title ?? '');
  $author = user_load($node->uid);
  $data['author'] = $author->mail;


  // Text Fields.
  if ($node->field_asegurado_benef_pref) {
    $data['field_asegurado_benef_pref'] = contract_export_export_get_field_value($node->field_asegurado_benef_pref, 'text');
  }

  if ($node->field_asegurado_io) {
    $data['field_asegurado_io'] = contract_export_export_get_field_value($node->field_asegurado_io, 'text');
  }

  if ($node->field_asegurado_nombre) {
    $data['field_asegurado_nombre'] = contract_export_export_get_field_value($node->field_asegurado_nombre, 'text');
  }

  if ($node->field_asegurado_rfc) {
    $data['field_asegurado_rfc'] = contract_export_export_get_field_value($node->field_asegurado_rfc, 'text');
  }

  if ($node->field_asegurado_telefono) {
    $data['field_asegurado_telefono'] = contract_export_export_get_field_value($node->field_asegurado_telefono, 'text');
  }

  if ($node->field_poliza_moneda) {
    $data['field_poliza_moneda'] = contract_export_export_get_field_value($node->field_poliza_moneda, 'text');
  }

  if ($node->field_poliza_oficina) {
    $data['field_poliza_oficina'] = contract_export_export_get_field_value($node->field_poliza_oficina, 'text');
  }

  if ($node->field_vehiculo_capacidad) {
    $data['field_vehiculo_capacidad'] = contract_export_export_get_field_value($node->field_vehiculo_capacidad, 'text');
  }

  if ($node->field_vehiculo_carroceria) {
    $data['field_vehiculo_carroceria'] = contract_export_export_get_field_value($node->field_vehiculo_carroceria, 'text');
  }

  if ($node->field_vehiculo_categoria) {
    $data['field_vehiculo_categoria'] = contract_export_export_get_field_value($node->field_vehiculo_categoria, 'text');
  }

  if ($node->field_vehiculo_cilindros) {
    $data['field_vehiculo_cilindros'] = contract_export_export_get_field_value($node->field_vehiculo_cilindros, 'text');
  }

  if ($node->field_vehiculo_clave_sbg) {
    $data['field_vehiculo_clave_sbg'] = contract_export_export_get_field_value($node->field_vehiculo_clave_sbg, 'text');
  }

  if ($node->field_vehiculo_color) {
    $data['field_vehiculo_color'] = contract_export_export_get_field_value($node->field_vehiculo_color, 'text');
  }

  if ($node->field_vehiculo_descripcion_carga) {
    $data['field_vehiculo_descripcion_carga'] = contract_export_export_get_field_value($node->field_vehiculo_descripcion_carga, 'text');
  }

  if ($node->field_vehiculo_motor) {
    $data['field_vehiculo_motor'] = contract_export_export_get_field_value($node->field_vehiculo_motor, 'text');
  }

  if ($node->field_vehiculo_placas) {
    $data['field_vehiculo_placas'] = contract_export_export_get_field_value($node->field_vehiculo_placas, 'text');
  }

  if ($node->field_vehiculo_referencia) {
    $data['field_vehiculo_referencia'] = contract_export_export_get_field_value($node->field_vehiculo_referencia, 'text');
  }

  if ($node->field_vehiculo_remolque) {
    $data['field_vehiculo_remolque'] = contract_export_export_get_field_value($node->field_vehiculo_remolque, 'text');
  }

  if ($node->field_vehiculo_serie) {
    $data['field_vehiculo_serie'] = contract_export_export_get_field_value($node->field_vehiculo_serie, 'text');
  }

  if ($node->field_vehiculo_tipo_carga) {
    $data['field_vehiculo_tipo_carga'] = contract_export_export_get_field_value($node->field_vehiculo_tipo_carga, 'text');
  }

  if ($node->field_vehiculo_tipo_remolque) {
    $data['field_vehiculo_tipo_remolque'] = contract_export_export_get_field_value($node->field_vehiculo_tipo_remolque, 'text');
  }

  if ($node->field_vehiculo_transmision) {
    $data['field_vehiculo_transmision'] = contract_export_export_get_field_value($node->field_vehiculo_transmision, 'text');
  }

  if ($node->field_vehiculo_uso) {
    $data['field_vehiculo_uso'] = contract_export_export_get_field_value($node->field_vehiculo_uso, 'text');
  }
  // Text Fields End.

  // Number Fields.
  if ($node->field_vehiculo_modelo) {
    $data['field_vehiculo_modelo'] = contract_export_export_get_field_value($node->field_vehiculo_modelo, 'number');
  }

  if ($node->field_vehiculo_numero_inventario) {
    $data['field_vehiculo_numero_inventario'] = contract_export_export_get_field_value($node->field_vehiculo_numero_inventario, 'number');
  }

  if ($node->field_vehiculo_numero_pedimento) {
    $data['field_vehiculo_numero_pedimento'] = contract_export_export_get_field_value($node->field_vehiculo_numero_pedimento, 'number');
  }

  if ($node->field_vehiculo_tonelaje) {
    $data['field_vehiculo_tonelaje'] = contract_export_export_get_field_value($node->field_vehiculo_tonelaje, 'number');
  }

  if ($node->field_pago_fraccionado) {
    $data['field_pago_fraccionado'] = contract_export_export_get_field_value($node->field_pago_fraccionado, 'number');
  }

  if ($node->field_poliza_derecho_poliza) {
    $data['field_poliza_derecho_poliza'] = contract_export_export_get_field_value($node->field_poliza_derecho_poliza, 'number');
  }

  if ($node->field_poliza_impuesto_iva) {
    $data['field_poliza_impuesto_iva'] = contract_export_export_get_field_value($node->field_poliza_impuesto_iva, 'number');
  }

  if ($node->field_poliza_prima_1er_recibo) {
    $data['field_poliza_prima_1er_recibo'] = contract_export_export_get_field_value($node->field_poliza_prima_1er_recibo, 'number');
  }

  if ($node->field_poliza_prima_neta) {
    $data['field_poliza_prima_neta'] = contract_export_export_get_field_value($node->field_poliza_prima_neta, 'number');
  }

  if ($node->field_poliza_prima_total) {
    $data['field_poliza_prima_total'] = contract_export_export_get_field_value($node->field_poliza_prima_total, 'number');
  }

  if ($node->field_poliza_primas_recibos_subs) {
    $data['field_poliza_primas_recibos_subs'] = contract_export_export_get_field_value($node->field_poliza_primas_recibos_subs, 'number');
  }

  if ($node->field_poliza_reduccion) {
    $data['field_poliza_reduccion'] = contract_export_export_get_field_value($node->field_poliza_reduccion, 'number');
  }

  if ($node->field_poliza_rgo_pago_fracc) {
    $data['field_poliza_rgo_pago_fracc'] = contract_export_export_get_field_value($node->field_poliza_rgo_pago_fracc, 'number');
  }
  // Number Fields End.

  // Date Fields.
  if ($node->field_fecha_de_cancelacion) {
    $data['field_fecha_de_cancelacion'] = contract_export_export_get_field_value($node->field_fecha_de_cancelacion, 'date');
  }

  if ($node->field_fecha_de_pagado) {
    $data['field_fecha_de_pagado'] = contract_export_export_get_field_value($node->field_fecha_de_pagado, 'date');
  }

  if ($node->field_poliza_emision) {
    $data['field_poliza_emision'] = contract_export_export_get_field_value($node->field_poliza_emision, 'date');
  }

  if ($node->field_poliza_vigencia) {
    $data['field_poliza_vigencia'] = contract_export_export_get_field_value($node->field_poliza_vigencia, 'date');
  }
  // Date Fields End.

  // List Fields.
  if ($node->field_derecho_de_poliza2) {
    $data['field_derecho_de_poliza2'] = contract_export_export_get_field_value($node->field_derecho_de_poliza2, 'list', 'field_derecho_de_poliza2');
  }

  if ($node->field_periodo_de_gracia) {
    $data['field_periodo_de_gracia'] = contract_export_export_get_field_value($node->field_periodo_de_gracia, 'list', 'field_periodo_de_gracia');
  }

  if ($node->field_poliza_forma_pago) {
    $data['field_poliza_forma_pago'] = contract_export_export_get_field_value($node->field_poliza_forma_pago, 'list', 'field_poliza_forma_pago');
  }

  if ($node->field_poliza_status) {
    $data['field_poliza_status'] = contract_export_export_get_field_value($node->field_poliza_status, 'list', 'field_poliza_status');
  }

  if ($node->field_uso_vehiculo) {
    $data['field_uso_vehiculo'] = contract_export_export_get_field_value($node->field_uso_vehiculo, 'list', 'field_uso_vehiculo');
  }

  if ($node->field_vehiculo_servicio) {
    $data['field_vehiculo_servicio'] = contract_export_export_get_field_value($node->field_vehiculo_servicio, 'list', 'field_vehiculo_servicio');
  }
  // List Fields End.

  // Term Reference Fields.
  if ($node->field_motivos_de_cancelacion) {
    $data['field_motivos_de_cancelacion'] = contract_export_export_get_field_value($node->field_motivos_de_cancelacion, 'term');
  }

  if ($node->field_plz_vehiculo_marca) {
    $data['field_plz_vehiculo_marca'] = contract_export_export_get_field_value($node->field_plz_vehiculo_marca, 'term');
  }

  if ($node->field_vehiculo_carroceria_select) {
    $data['field_vehiculo_carroceria_select'] = contract_export_export_get_field_value($node->field_vehiculo_carroceria_select, 'term');
  }

  if ($node->field_vehiculo_descripcion) {
    $data['field_vehiculo_descripcion'] = contract_export_export_get_field_value($node->field_vehiculo_descripcion, 'term');
  }

  if ($node->field_vehiculo_submarca) {
    $data['field_vehiculo_submarca'] = contract_export_export_get_field_value($node->field_vehiculo_submarca, 'term');
  }
  // Term Reference Fields End.

  // User Reference Fields.
  if ($node->field_asignar_promotor) {
    $data['field_asignar_promotor'] = contract_export_export_get_field_value($node->field_asignar_promotor, 'user');
  }

  if ($node->field_usuario_de_cancelado) {
    $data['field_usuario_de_cancelado'] = contract_export_export_get_field_value($node->field_usuario_de_cancelado, 'user');
  }

  if ($node->field_usuario_de_pagado) {
    $data['field_usuario_de_pagado'] = contract_export_export_get_field_value($node->field_usuario_de_pagado, 'user');
  }
  // User Reference Fields End.

  // Address Field.
  if ($node->field_asegurado_domicilio) {
    $value = $node->field_asegurado_domicilio[LANGUAGE_NONE][0];

    $address['country'] = $value['country'];
    $address['administrative_area'] = $value['administrative_area'];
    $address['locality'] = $value['locality'];
    $address['postal_code'] = $value['postal_code'];
    $address['thoroughfare'] = $value['thoroughfare'];
    $address['premise'] = $value['premise'];

    $data['field_asegurado_domicilio'] = $address;
  }
  // Address Field End.

  // Image Field.
  if ($node->field_ficha_de_pago) {
    $value = $node->field_ficha_de_pago[LANGUAGE_NONE][0];
    $image['uri'] = $value['uri'];
    $image['filename'] = $value['filename'];

    $data['field_ficha_de_pago'] = $image;
  }
  // Image Field End.

  // Field collection field.
  $collection = $node->field_poliza_coberturas;

  if ($collection) {
    $cid = $collection[LANGUAGE_NONE][0]['value'];
    $entity = entity_load('field_collection_item', [$cid]);
    $entity = $entity[$cid];

    if ($entity->field_poliza_tipo) {
      $data['field_poliza_tipo'] = contract_export_export_get_field_value($entity->field_poliza_tipo, 'list', 'field_poliza_tipo');
    }

    $collection_items = $entity->field_cobertura;
    if ($collection_items) {
      $items_data = [];

      foreach ($collection_items[LANGUAGE_NONE] as $item) {
        $cid = $item['value'];
        $entity = entity_load('field_collection_item', [$cid]);
        $entity = $entity[$cid];
        $item_data = [];

        if ($entity->field_cobertura_titulo) {
          $item_data['field_cobertura_titulo'] = contract_export_export_get_field_value($entity->field_cobertura_titulo, 'list', 'field_cobertura_titulo');
        }

        if ($entity->field_cobertura_deducible) {
          $item_data['field_cobertura_deducible'] = contract_export_export_get_field_value($entity->field_cobertura_deducible, 'list', 'field_cobertura_deducible');
        }

        if ($entity->field_cobertura_limite_riesgo) {
          $item_data['field_cobertura_limite_riesgo'] = contract_export_export_get_field_value($entity->field_cobertura_limite_riesgo, 'text');
        }

        $items_data[] = $item_data;
      }
    }

    $data['field_cobertura'] = $items_data;
  }
  // Field collection field End.

  return json_encode($data);
}

/**
 * Helper function to get all contract fields data.
 */
function contract_export_export_get_field_value($value, $type, $field_name = '') {
  $value = $value[LANGUAGE_NONE][0];

  switch ($type) {
    case 'text':
    case 'number':
    case 'date':
      $value = $value['value'];
      break;
    case 'list':
      $value = $value['value'];
      if ($field_name) {
        $field = field_info_field($field_name);
        $value = $field['settings']['allowed_values'][$value];
      }
      break;
    case 'term':
      $tid = $value['tid'];
      $term = taxonomy_term_load($tid);
      $value = $term->name;
      break;
    case 'user':
      $uid = $value['target_id'];
      $user = user_load($uid);
      $value = $user->mail;
  }

  return $value;
}
