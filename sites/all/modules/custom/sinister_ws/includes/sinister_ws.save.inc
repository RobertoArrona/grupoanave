<?php

/**
 * @file
 * This file has all functions to save data to sinister.
 */

/**
 * Controller function to save a sinsiter node using the $_POST variables.
 */
function sinister_ws_save_controller() {
  //watchdog('sinister_ws', '<pre>' . print_r($_POST, TRUE) . "</pre>");
  sinister_ws_save($_POST);
  return array('valid' => 1, 'msg' => 'Yeaaa baby', 'post' => $_POST);
}

/**
 * Saves sinister data fields into a node.
 */
function sinister_ws_save($data) {
  if (!isset($data['nid'])) {
    return FALSE;
  }

  if (!($node = node_load($data['nid']))) {
    return FALSE;
  }

  // Datos Generales.
  $data_fields = array();
  $data_fields['poliza_comentarios'] = 'value';
  $data_fields['poblacion'] = 'value';
  $data_fields['estado_single'] = 'tid';
  $data_fields['lugar_referencia'] = 'value';
  $data_fields['comentarios_del_siniestro'] = 'value';
  $data_fields['lugar_atencion'] = 'value';

  // Lugar de Siniestro.
  $data_fields['mapa_siniestro'] = 'lat';
  $data_fields['mapa_siniestro'] = 'lng';

  // Termino.
  $data_fields['informe'] = 'value';
  $data_fields['danos_materiales'] = 'value';
  $data_fields['robo'] = 'value';
  $data_fields['resp_civil'] = 'value';
  $data_fields['gastos_medicos'] = 'value';
  $data_fields['rc_viajero'] = 'value';
  $data_fields['reserva_total'] = 'value';

  foreach ($data_fields as $data_field => $data_value) {
    if (isset($data[$data_field])) {
      $data_field_name = "field_{$data_field}";
      if (!empty($data[$data_field])) {
        $node->{$data_field_name}[LANGUAGE_NONE][0][$data_value] = $data[$data_field];
      }
      else {
        $node->{$data_field_name} = array();
      }
    }
  }

  // Datos de conductor.
  $data_fields = array(
    'nombre' => 'value',
    'domicilio' => array(
      'thoroughfare',
      'premise',
      'locality',
      'administrative_area',
      'postal_code',
    ),
    'rfc' => 'value',
    'licencia_numero' => 'value',
    'licencia_tipo' => 'value',
    'licencia_alta_lugar' => 'value',
    'licencia_alta_fecha' => 'date',
    'telefono' => 'value',
    'es_quien_reporta' => 'value',
  );
  sinister_ws_save_fc_data($node, 'conductor', $data_fields, $data);

  // Vehiculo Terceros.
  $data_fields = array(
    'propietario_nombre' => 'value',
    'propietario_domicilio' => array(
      'thoroughfare',
      'premise',
      'locality',
      'administrative_area',
      'postal_code',
    ),
    'propietario_telefono' => 'value',
    'conductor_es_propietario' => 'value',
    'licencia_numero' => 'value',
    // Pendiente taxonomy.
    'vehiculo_marca' => 'tid',
    'vehiculo_tipo' => 'tid',
    '3ro_vehiculo_modelo' => 'value',
    '3ro_vehiculo_color' => 'tid',
    '3ro_vehiculo_placas' => 'value',
    '3ro_vehiculo_serie' => 'value',
    '3ro_vehiculo_danos' => 'value',
    '3ro_aseguradora' => 'tid',
    '3ro_numero_poliza' => 'value',
    '3ro_cobertura' => 'value',
    '3ro_deducible' => 'value',
    '3ro_vencimiento' => 'date',
    '3ro_siniestro' => 'value',
    '3ro_ajustador' => 'tid',
    'taller' => 'target_id',
  );
  sinister_ws_save_fc_data($node, 'vehiculo_tercero', $data_fields, $data);

  // Lesiones y Danos.
  $data_fields = array(
    'lesionado_nombre' => 'value',
    'lesionado_domicilio' => array(
      'thoroughfare',
      'premise',
      'locality',
      'administrative_area',
      'postal_code',
    ),
    'lesionado_telefono' => 'value',
    'lesionado_riesgo_b' => 'value',
    'lesionado_lesiones' => 'value',
    'lesionado_ambulancia' => 'value',
    'lesionado_pase_medico' => 'value',
    'hospital' => 'target_id',
  );
  sinister_ws_save_fc_data($node, 'lesionado', $data_fields, $data);

  // Save Node.
  $node = node_save($node);

  return $node;
}

/**
 * Iterates all fields that are going to get saved in a field collection item.
 */
function sinister_ws_save_fc_data(&$node, $data_field, $data_fields, $data) {
  $i = 0;
  $first_data_field = array_keys($data_fields);
  $first_data_field = $first_data_field[0];
  $data_field_i = "{$data_field}_{$i}";
  $data_field_i_data_field = "{$data_field_i}_{$first_data_field}";

  while (isset($data[$data_field_i_data_field])) {
    if (($fc_item = sinister_ws_get_fc($node, $data_field, $i))) {
      // watchdog('sinister_ws', $fc_item->item_id);
      $fc_item_wrapper = entity_metadata_wrapper('field_collection_item', $fc_item);
      $fc_item_wrapper = sinister_ws_save_fc($data_field_i, $data_fields, $fc_item_wrapper);
    }

    $field_data_field = "field_{$data_field}";
    $node->{$field_data_field}[LANGUAGE_NONE][$i]['value'] = $fc_item->item_id;
    $node->{$field_data_field}[LANGUAGE_NONE][$i]['revision_id'] = $fc_item->revision_id;
    $i++;

    $data_field_i = "{$data_field}_{$i}";
    $data_field_i_data_field = "{$data_field_i}_{$first_data_field}";
  }
}

/**
 * Saves a Field collection section.
 */
function sinister_ws_save_fc($data_field_i, $fc_data_fields, $fc_item_wrapper) {
  foreach ($fc_data_fields as $fc_data_field => $value_field) {
    // If this is an array, it must be a Postal Address.
    if (is_array($value_field)) {
      foreach ($value_field as $value_field_item) {
        $data_field_field = "{$data_field_i}_{$fc_data_field}_{$value_field_item}";
        if (isset($data[$data_field_field])) {
          $fc_field_name = "field_{$fc_data_field}";
          $fc_item_wrapper->{$fc_field_name}->set($data[$data_field_field]);
          // $fc_item->{$fc_field_name}[LANGUAGE_NONE][0][$value_field_item] = $data[$data_field_field];
        }
      }
    }
    // If this is a Term.
    elseif ($value_field == 'tid') {
      $data_field_field = "{$data_field_i}_{$fc_data_field}";
      if (isset($data[$data_field_field])) {
        if (!empty($data[$data_field_field])) {
          // Try to load Term by Tid.
          if (($term = taxonomy_term_load($data[$data_field_field]))) {
            $fc_item_wrapper->{$fc_field_name}->set($term->tid);
            //$fc_item->{$fc_field_name}[LANGUAGE_NONE][0][$value_field] = $term->tid;
          }
        }
        else {
          // pending $fc_item->{$fc_field_name} = array();
        }
      }
    }
    // If this is a date.
    elseif ($value_field == 'date') {
      $data_field_field = "{$data_field_i}_{$fc_data_field}";
      if (isset($data[$data_field_field])) {
        if (!empty($data[$data_field_field])) {
          $fc_item_wrapper->{$fc_field_name}->set(strtotime($data[$data_field_field]));
          /*$fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['value'] = strtotime($data[$data_field_field]);
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['timezone'] = 'America/Mazatlan';
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['timezone_db'] = 'UTC';
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['date_type'] = 'datestamp';*/
        }
        else {
          // pending $fc_item->{$fc_field_name} = array();
        }
      }
    }
    // If its a regular value, then it can be any field.
    else {
      $data_field_field = "{$data_field_i}_{$fc_data_field}";
      //watchdog('sinister_ws', 'data_field_field = ' . $data_field_field);
      
      if (isset($data[$data_field_field])) {
        $fc_field_name = "field_{$fc_data_field}";
        if (!empty($data[$data_field_field])) {
          $fc_item_wrapper->{$fc_field_name}->set($data[$data_field_field]);
          // $fc_item->{$fc_field_name}[LANGUAGE_NONE][0][$value_field] = $data[$data_field_field];
        }
        else {
          // pending $fc_item->{$fc_field_name} = array();
        }
      }
    }
  }

  $fc_item_wrapper->save();
  // $fc_item->save();
  return $fc_item_wrapper;
}

/**
 * Load or Create a Field Collection and attaches it to Node.
 */
function sinister_ws_get_fc($node, $field, $i = 0) {
  // Create field collection item.
  $field_field = "field_{$field}";
  if (!(isset($node->{$field_field}[LANGUAGE_NONE][$i]['value']) && $node->{$field_field}[LANGUAGE_NONE][$i]['value'] > 0)) {
    $fc = array();
    $fc['field_name'] = "field_{$field}";
    $fc_item = entity_create('field_collection_item', $fc);
    watchdog('sinister_ws', '1');
    $fc_item->setHostEntity('node', $node);
    $fc_item->save();

    return $fc_item;
  }

  return sinister_ws_load_fc($node->{$field_field}[LANGUAGE_NONE][$i]['value']);
}

/**
 * Loads a Field Collection Item.
 */
function sinister_ws_load_fc($id) {
  if (!($items = entity_load('field_collection_item', array($id)))) {
    return FALSE;
  }

  if (!isset($items[$id])) {
    return FALSE;
  }

  return $items[$id];
}
