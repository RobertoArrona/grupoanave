<?php

/**
 * @file
 * This file has all functions to save data to sinister.
 */
function sinister_ws_save($nid, $data) {
  $node = node_load($nid);

  // Poliza.
  if (isset($data->poliza_comentarios)) {
    $node->field_poliza_comentarios[LANGUAGE_NONE][0]['value'] = $data->poliza_comentarios;
  }

  // Lugar de Siniestro.
  if (isset($data->poblacion)) {
    $node->field_poblacion[LANGUAGE_NONE][0]['value'] = $data->poblacion;
  }

  if (isset($data->estado_single)) {
    $node->field_estado_single[LANGUAGE_NONE][0]['value'] = $data->estado_single;
  }

  if (isset($data->lugar_referencias)) {
    $node->field_lugar_referencias[LANGUAGE_NONE][0]['value'] = $data->lugar_referencias;
  }

  if (isset($data->comentarios_del_siniestro)) {
    $node->field_comentarios_del_siniestro[LANGUAGE_NONE][0]['value'] = $data->comentarios_del_siniestro;
  }

  if (isset($data->lugar_atencion)) {
    $node->field_lugar_atencion[LANGUAGE_NONE][0]['value'] = $data->lugar_atencion;
  }

  // Datos de conductor.
  if (($fc_conductor = sinister_ws_get_fc($node, 'field_conductor'))) {
    if (isset($data->conductor_nombre)) {
      $fc_conductor->field_nombre[LANGUAGE_NONE][0]['value'] = $data->conductor_nombre;
    }
  
    if (isset($data->conductor_domicilio_thoroughfare)) {
      $fc_conductor->field_domicilio[LANGUAGE_NONE][0]['thoroughfare'] = $date->conductor_domicilio_thoroughfare;
    }
  
    if (isset($data->conductor_domicilio_premise)) {
      $fc_conductor->field_domicilio[LANGUAGE_NONE][0]['premise'] = $date->conductor_domicilio_premise;
    }

    if (isset($data->conductor_domicilio_locality)) {
      $fc_conductor->field_domicilio[LANGUAGE_NONE][0]['locality'] = $date->conductor_domicilio_locality;
    }

    if (isset($data->conductor_domicilio_administrative_area)) {
      $fc_conductor->field_domicilio[LANGUAGE_NONE][0]['administrative_area'] = $date->conductor_domicilio_administrative_area;
    }

    if (isset($data->conductor_domicilio_postal_code)) {
      $fc_conductor->field_domicilio[LANGUAGE_NONE][0]['postal_code'] = $date->conductor_domicilio_postal_code;
    }

    if (isset($data->conductor_rfc)) {
      $fc_conductor->field_rfc[LANGUAGE_NONE][0]['value'] = $date->conductor_rfc;
    }

    if (isset($data->conductor_licencia_numero)) {
      $fc_conductor->field_licencia_numero[LANGUAGE_NONE][0]['value'] = $date->conductor_licencia_numero;
    }

    if (isset($data->conductor_licencia_tipo)) {
      $fc_conductor->field_licencia_tipo[LANGUAGE_NONE][0]['value'] = $date->conductor_licencia_tipo;
    }
    
    if (isset($data->conductor_licencia_alta_lugar)) {
      $fc_conductor->field_licencia_alta_lugar[LANGUAGE_NONE][0]['value'] = $date->conductor_licencia_alta_lugar;
    }
    
    if (isset($data->conductor_licencia_alta_fecha)) {
      $fc_conductor->field_licencia_alta_fecha[LANGUAGE_NONE][0]['date'] = $date->conductor_licencia_alta_fecha;
    }
    
    if (isset($data->conductor_telefono)) {
      $fc_conductor->field_telefono[LANGUAGE_NONE][0]['value'] = $date->conductor_telefono;
    }
    
    if (isset($data->conductor_es_quien_reporta)) {
      $fc_conductor->field_conductor_es_quien_reporta[LANGUAGE_NONE][0]['value'] = $date->conductor_es_quien_reporta;
    }
  }

  // Datos de Terceros.
  $data_field = 'vehiculo_tercero';
  $i = 0;
  $data_field_i = "{$data_field}_{$i}"
  $tercero_data_fields = array(
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
  while (isset($data->$data_field_i)) {
    if (($fc_tercero = sinister_ws_get_fc($node, 'field_vehiculo_tercero', $i))) {
      foreach ($tercero_data_fields as $tercero_data_field => $value_field) {
        // If this is an array, it must be a Postal Address.
        if (is_array($value_field)) {
          foreach ($value_field as $value_field_item) {
            $data_field_field = "{$data_field_i}_{$tercero_data_field}_{$value_field_item}";
            if (isset($data->$data_field_field)) {
              $fc_field_name = "field_{$tercero_data_field}";
              $fc_tercero->$fc_field_name[LANGUAGE_NONE][0][$value_field_item] = $data->$data_field_field;
            }
          }
        }
        // If this is a Term.
        else if ($value_field == 'tid') {
          $data_field_field = "{$data_field_i}_{$tercero_data_field}";
          if (isset($data->$data_field_field)) {
            if (!empty($data->$data_field_field)) {
              // Try to load Term by Tid.
              if (($term = taxonomy_term_load($data->$data_field_field))) {
                $fc_tercero->$fc_field_name[LANGUAGE_NONE][0][$value_field] = $term->tid;
              }
              // Try load Term by Name.
              else if (($term = taxonomy_get_term_by_name($data->$data_field_field, 'marca'))) {
                $fc_tercero->$fc_field_name[LANGUAGE_NONE][0][$value_field] = $term->tid;
              }
              else {
                $term = (object) array(
                  'vocabulary_machine_name' => 'marca',
                  'name' => $data->$data_field_field,
                );
                taxonomy_term_save($term);
                $term = taxonomy_get_term_by_name($data->$data_field_field, 'marca');
                $fc_tercero->$fc_field_name[LANGUAGE_NONE][0][$value_field] = $term->tid;
              }
            }
            else {
              unset($fc_tercero->$fc_field_name[LANGUAGE_NONE][0]);
            }
          }
        }
        // If this is a date.
        else if ($value_field == 'date') {
          // Pendiente programar para date.
        }
        // If its a regular value, then it can be any field.
        else {
          $data_field_field = "{$data_field_i}_{$tercero_data_field}";
          if (isset($data->$data_field_field)) {
            $fc_field_name = "field_{$tercero_data_field}";
            $fc_tercero->$fc_field_name[LANGUAGE_NONE][0][$value_field] = $data->$data_field_field;
          }
        }
      }
    }

    $i++;
    $data_field_i = "{$data_field}_{$i}"
  } 

  // Save Node.
  $node = node_save($node);

  return array('valid' => 1);
}

/**
 * Load or Create a Field Collection and attaches it to Node.
 */
function sinister_ws_get_fc($node, $field, $i = 0);
  if (!(isset($node->$field[LANGUAGE_NONE][$i]['value']) && $node->$field[LANGUAGE_NONE][$i]['value'] > 0)) {
    // Create field collection item.
    $fc = array(); // new array
    $fc['field_name'] = "field_collection_{$field}";
    $fc_conductor = entity_create('field_collection_item', $fc); // create entity in system
    $fc_conductor->setHostEntity('node', $node); // set host entity, in this case a node
    $fc_conductor->save();

    return $fc_conductor;
  }

  return sinister_ws_load_fc($node->field_conductor[LANGUAGE_NONE][$i]['value']);
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
