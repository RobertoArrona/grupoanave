<?php

/**
 * @file
 * This files has all user functionalities.
 */

/**
 * Implements function load_user().
 */
function insurance_contract_contract_load_user_get() {
  global $user;
  if ($user->uid === 0 || empty($user->uid)) {
    return FALSE;
  }
  $user_fields = user_load($user->uid);
  return $user_fields;
}

/**
 * Implements function taxonomy_term_load().
 */
function insurance_contract_contract_load_taxonomy_get() {
  if (($user_fields = insurance_contract_contract_load_user_get())) {
    $termid = $user_fields->field_estado[LANGUAGE_NONE]['0']['tid'];
    if (empty($termid)) {
      return FALSE;
    }
    else {
      $term = taxonomy_term_load($termid);
      $termname = $term->name;
    }
  }
  return $termname;
}

/**
 * Implements function user_agent_load().
 */
function insurance_contract_contract_load_agent_id_get() {
  if (($user_fields = insurance_contract_contract_load_user_get())) {
    $agent_id = $user_fields->field_agente_clave[LANGUAGE_NONE]['0']['value'];
  }
  return $agent_id;
}

/**
 * Implements function insurance_contract_contract_load_user_get().
 */
function insurance_contract_contract_load_oficina_get() {
  $agent_id = insurance_contract_contract_load_agent_id_get();
  $termname = insurance_contract_contract_load_taxonomy_get();

  $office = $termname . '-' . $agent_id;
  return $office;
}
