<?php

/**
 * @file
 * This file has a presave function to improve specific field collection.
 */

/**
 * Implements hook_field_collection_item_presave().
 */
function anavem_field_collection_item_presave(FieldCollectionItemEntity $field_collection_item) {
  if (isset($field_collection_item->field_name) && $field_collection_item->field_name == 'field_vehiculo_tercero') {
    if (isset($field_collection_item->field_conductor_es_propietario[LANGUAGE_NONE][0]['value']) && $field_collection_item->field_conductor_es_propietario[LANGUAGE_NONE][0]['value'] == 1) {
      $field_collection_item->field_conductor_nombre = $field_collection_item->field_propietario_nombre;
      $field_collection_item->field_conductor_domicilio = $field_collection_item->field_propietario_domicilio;
      $field_collection_item->field_conductor_telefono = $field_collection_item->field_propietario_telefono;
    }
  }
}
