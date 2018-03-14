<?php

/**
 * @file
 * This file has all functions to save data to sinister.
 */

/**
 * Controller function to save a sinsiter node using the $_POST variables.
 */
function sinister_ws_save_controller() {
  // watchdog('sinister_ws', '<pre>' . print_r($_POST, TRUE) . "</pre>");.
  sinister_ws_save($_POST);
  return array(
    'valid' => 1,
    'msg' => 'Los datos se guardaron satisfactoriamente',
    'post' => $_POST,
  );
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

  if (!isset($data['uid'])) {
    $data['uid'] = 1;
  }

  // Datos Generales.
  $data_fields = array();
  $data_fields['poliza_comentarios'] = 'value';
  $data_fields['poblacion'] = 'value';
  $data_fields['estado_single'] = 'tid';
  $data_fields['lugar_referencias'] = 'value';
  $data_fields['comentarios_de_siniestro'] = 'value';
  $data_fields['lugar_atencion'] = 'value';

  // Archivos.
  // Prepare siniestro_archivo_visualizador (imagenes).
  if (isset($_FILES['siniestro_archivo_visualizador'])) {
    $data['siniestro_archivo_visualizadores'] = array();
    foreach ($_FILES['siniestro_archivo_visualizador']['name'] as $i => $siniestro_archivo_visualizador) {
      $data['siniestro_archivo_visualizadores'][] = array(
        'name' => $_FILES['siniestro_archivo_visualizador']['name'][$i],
        'type' => $_FILES['siniestro_archivo_visualizador']['type'][$i],
        'tmp_name' => $_FILES['siniestro_archivo_visualizador']['tmp_name'][$i],
        'error' => $_FILES['siniestro_archivo_visualizador']['error'][$i],
        'size' => $_FILES['siniestro_archivo_visualizador']['size'][$i],
      );
    }
    sinister_ws_save_fc_archivo_visualizador($node, $data);
  }

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
    'licencia_tipo' => 'tid',
    'licencia_alta_lugar' => 'tid',
    'licencia_alta_fecha' => 'date',
    'telefono' => 'value',
    'nombre_quien_reporta' => 'value',
    'telefono_quien_reporta' => 'value',
    'conductor_reporta' => 'checkbox',
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
    'conductor_es_propietario' => 'checkbox',
    'conductor_nombre' => 'value',
    'conductor_telefono' => 'value',
    'conductor_domicilio' => array(
      'thoroughfare',
      'premise',
      'locality',
      'administrative_area',
      'postal_code',
    ),
  );
  sinister_ws_save_fc_data($node, 'vehiculo_tercero', $data_fields, $data);

  // Lesiones y Danos.
  $data_fields = array(
    'lesionado_nombre' => 'value',
    'lesionado_edad' => 'value',
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
    'lesionado_ambulancia' => 'checkbox',
    'lesionado_ambulancia_info' => 'value',
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
      $fc_item = sinister_ws_save_fc($data_field_i, $data_fields, $fc_item, $node, $data);
    }

    $field_data_field = "field_{$data_field}";
    $i++;

    $data_field_i = "{$data_field}_{$i}";
    $data_field_i_data_field = "{$data_field_i}_{$first_data_field}";
  }
}

/**
 * Saves archivo visualizador into a new field collection.
 */
function sinister_ws_save_fc_archivo_visualizador($node, $data) {
  // Create Field Collection.
  $fc_item = entity_create('field_collection_item', array(
    'field_name' => "field_siniestro_archivo",
  ));
  $fc_item->setHostEntity('node', $node);

  // Save Files.
  $fc_item->field_visualizador[LANGUAGE_NONE] = array();
  foreach ($data['siniestro_archivo_visualizadores'] as $i => $file_raw) {
    $file_contents = file_get_contents($file_raw['tmp_name']);
    $file_uri = file_default_scheme() . '://siniestros/archivos/' . $file_raw['name'];
    if (($file = file_save_data($file_contents, $file_uri))) {
      $file->uid = $data['uid'];
      $file->status = FILE_STATUS_PERMANENT;
      $fc_item->field_visualizador[LANGUAGE_NONE][$i] = array(
        'fid' => $file->fid,
      );
      $fc_item->field_archivo_categoria[LANGUAGE_NONE][0]['value'] = 'Fotografías de siniestro';
      $fc_item->field_fecha[LANGUAGE_NONE][0]['value'] = strtotime('now');
      $fc_item->field_fecha[LANGUAGE_NONE][0]['timezone'] = 'America/Mazatlan';
      $fc_item->field_fecha[LANGUAGE_NONE][0]['timezone_db'] = 'UTC';
      $fc_item->field_fecha[LANGUAGE_NONE][0]['date_type'] = 'datestamp';
      $fc_item->field_archivo_autor[LANGUAGE_NONE][0]['target_id'] = $data['uid'];
      $fc_item->field_archivo_comentario[LANGUAGE_NONE][0]['value'] = $data['field_archivo_comentario'];
       watchdog('sinister_ws', '<pre>' . print_r($fc_item, TRUE) . "</pre>");
    }
  }

  $fc_item->save();
}

/**
 * Saves a Field collection section.
 */
function sinister_ws_save_fc($data_field_i, $fc_data_fields, $fc_item, $node, $data) {
  foreach ($fc_data_fields as $fc_data_field => $value_field) {
    // If this is an array, it must be a Postal Address.
    if (is_array($value_field)) {
      foreach ($value_field as $value_field_item) {
        $data_field_field = "{$data_field_i}_{$fc_data_field}_{$value_field_item}";
        if (isset($data[$data_field_field])) {
          $fc_field_name = "field_{$fc_data_field}";
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0][$value_field_item] = $data[$data_field_field];
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
            $fc_field_name = "field_{$fc_data_field}";
            $fc_item->{$fc_field_name}[LANGUAGE_NONE][0][$value_field] = $term->tid;
          }
        }
        else {
          // Pending $fc_item->{$fc_field_name} = array();.
        }
      }
    }
    // If this is a date.
    elseif ($value_field == 'date') {
      $data_field_field = "{$data_field_i}_{$fc_data_field}";
      if (isset($data[$data_field_field])) {
        if (!empty($data[$data_field_field])) {
          $fc_field_name = "field_{$fc_data_field}";
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['value'] = strtotime($data[$data_field_field]);
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['timezone'] = 'America/Mazatlan';
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['timezone_db'] = 'UTC';
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['date_type'] = 'datestamp';
        }
        else {
          // Pending $fc_item->{$fc_field_name} = array();
        }
      }
    }
    // If this is a checkbox.
    elseif ($value_field == 'checkbox') {
      $data_field_field = "{$data_field_i}_{$fc_data_field}";
      $fc_field_name = "field_{$fc_data_field}";
      if (isset($data[$data_field_field])) {
        $fc_field_name = "field_{$fc_data_field}";
        $fc_item->{$fc_field_name}[LANGUAGE_NONE][0]['value'] = $data[$data_field_field];
        $fc_item->{$fc_field_name}[LANGUAGE_NONE][1]['value'] = $data[$data_field_field];
      }
    }
    // If its a regular value, then it can be any field.
    else {
      $data_field_field = "{$data_field_i}_{$fc_data_field}";
      if (isset($data[$data_field_field])) {
        $fc_field_name = "field_{$fc_data_field}";
        if (!empty($data[$data_field_field])) {
          $fc_item->{$fc_field_name}[LANGUAGE_NONE][0][$value_field] = $data[$data_field_field];
        }
        else {
          // Pending $fc_item->{$fc_field_name} = array();.
        }
      }
    }
  }

  $fc_item->save(TRUE);
  return $fc_item;
}

/**
 * Load or Create a Field Collection and attaches it to Node.
 */
function sinister_ws_get_fc($node, $field, $i = 0) {
  // Create field collection item.
  $field_field = "field_{$field}";
  if (!(isset($node->{$field_field}[LANGUAGE_NONE][$i]['value']) && $node->{$field_field}[LANGUAGE_NONE][$i]['value'] > 0)) {
    $fc_item = entity_create('field_collection_item', array(
      'field_name' => "field_{$field}",
    ));
    $fc_item->setHostEntity('node', $node);

    return $fc_item;
  }

  return sinister_ws_load_fc($node->{$field_field}[LANGUAGE_NONE][$i]['value'], $node);
}

/**
 * Loads a Field Collection Item.
 */
function sinister_ws_load_fc($id, $node) {
  $fc_item = entity_load('field_collection_item', array($id));
  $fc_item = $fc_item[$id];
  // $fc_item->setHostEntity('node', $node);.
  return $fc_item;
}
