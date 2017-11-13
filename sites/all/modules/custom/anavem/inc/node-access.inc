<?php
/**
 *
 */

/**
 * Implements hook_node_access_records.
 */
function anavem_node_access_records($node) {
  $grants = array();
  switch($node->type) {
    case 'siniestro':
      $grants[] = array(
        'realm' => 'anavem_siniestro_node_access_view', 
        'gid' => $node->nid, 
        'grant_view' => 1, 
        'grant_update' => 0, 
        'grant_delete' => 0, 
        'priority' => 0, 
      );
      $grants[] = array(
        'realm' => 'anavem_siniestro_node_access_edit', 
        'gid' => $node->nid, 
        'grant_view' => 1, 
        'grant_update' => 1, 
        'grant_delete' => 0, 
        'priority' => 0, 
      );
      break;
    
    case 'poliza':
      $grants[] = array(
        'realm' => 'anavem_poliza_node_access_view', 
        'gid' => $node->nid, 
        'grant_view' => 1, 
        'grant_update' => 0, 
        'grant_delete' => 0, 
        'priority' => 0, 
      );
      break;
  }
  
  return $grants;
}

/**
 * Implements hook_node_grants.
 */
function anavem_node_grants($account, $op) {
  $grants = array();

  // Grants for Node Siniestro
  anavem_node_grants_siniestro($account, $op, $grants);
  
  // Grants for Node Poliza
  anavem_node_grants_poliza($account, $op, $grants);

  return $grants;
}

/**
 * hook_node_grants helper for node siniestro.
 */
function anavem_node_grants_siniestro($account, $op, &$grants) {
  // Get a list of all siniestro nodes.
  $nids = anavem_siniestro_get_all();
  
  // Determine if the user can access this siniestro node.
  foreach($nids as $nid) {
    if ( anavem_user_can_access_siniestro($nid, $account) ) {
      $grants['anavem_siniestro_node_access_view'][] = $nid;
      $grants['anavem_siniestro_node_access_edit'][] = $nid;
    }
  }
}

/**
 * hook_node_grants helper for node poliza.
 */
function anavem_node_grants_poliza($account, $op, &$grants) {
  // Get a list of all siniestro nodes.
  $nids = anavem_poliza_get_all();
  
  // Determine if the user can access this siniestro node.
  foreach($nids as $nid) {
    if ( anavem_user_can_access_poliza($nid, $account) ) {
      $grants['anavem_poliza_node_access_view'][] = $nid;
    }
  }
}

/**
 * Determines if a siniestro node can be accesed by a given user.
 */
function anavem_user_can_access_siniestro($nid, $account) {
  // Scenarios where a Siniestro can be accessed.
  // 1.- If the user has right to see all siniestros.
  if ( user_access('Administrar Todos los Siniestros', $account) ) {
    return true;
  }
  
  // Validate we can load the node.
  if ( !($node=node_load($nid)) ) {
    return false;
  }

  // 2.- If the user has the role Ajustador and the siniestro has him as ajustador.
  return anavem_siniestro_user_access($node, $account);
}

/**
 * Determines if a poliza node can be accesed by a given user.
 */
function anavem_user_can_access_poliza($nid, $account) {
  // Scenarios where a Siniestro can be accessed.
  // 1.- If the user has right to see all Polizas.
  if ( user_access('Administrar Todas las Polizas', $account) ) {
    return true;
  }
  
  // Validate we can load the node.
  if ( !($node=node_load($nid)) ) {
    return false;
  }
  
  // Get Siniestros related to this Poliza
  $siniestros = anavem_poliza_get_siniestros($node);
  
  // If the user has the right to access a siniestro then give him access to the poliza.
  foreach($siniestros as $siniestro) {
    if ( anavem_siniestro_user_access($siniestro, $account) ) {
      return true;
    }
  }

  return false;
}

/**
 * Helper function to know if a user has the rigth to access a given Siniestro.
 */
function anavem_siniestro_user_access($siniestro, $account) {
  foreach($account->roles as $role) {
    switch($role) {
      case 'ajustador':
        if ( ($uid = anavem_siniestro_get_ajustador_uid($siniestro)) && $uid == $account->uid ) {
          return true;
        }
        break;

      case 'abogado':
        if ( ($uid = anavem_siniestro_get_abogado_uid($siniestro)) && $uid == $account->uid ) {
          return true;
        }
        break;

      case 'taller':
        if ( ($uid = anavem_siniestro_get_taller_uid($siniestro)) && $uid == $account->uid ) {
          return true;
        }
        break;

      case 'hospital':
        if ( ($uid = anavem_siniestro_get_hospital_uid($siniestro)) && $uid == $account->uid ) {
          return true;
        }
        break;
      case 'gruas':
        if ( ($uid = anavem_siniestro_get_gruas_uid($siniestro)) && $uid == $account->uid ) {
          return true;
        }
        break;
      case 'proveedores':
        if ( ($uid = anavem_siniestro_get_proveedores_uid($siniestro)) && $uid == $account->uid ) {
          return true;
        }
        break;  
    }
  }
  
  return false;
}

/**
 * Gets the Ajustador id from a Siniestro.
 */
function anavem_siniestro_get_ajustador_uid($node) {
  if ( isset($node->field_ajustador[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_ajustador[LANGUAGE_NONE][0]['target_id']) ) {
    return $node->field_ajustador[LANGUAGE_NONE][0]['target_id'];
  }
  
  return false;
}

/**
 * Gets the abogado id from a Siniestro.
 */
function anavem_siniestro_get_abogado_uid($node) {
  if ( isset($node->field_abogado[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_abogado[LANGUAGE_NONE][0]['target_id']) ) {
    return $node->field_abogado[LANGUAGE_NONE][0]['target_id'];
  }
  
  return false;
}

/**
 * Gets the hospital id from a Siniestro.
 */
function anavem_siniestro_get_hospital_uid($node) {
  if ( isset($node->field_hospital[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_hospital[LANGUAGE_NONE][0]['target_id']) ) {
    return $node->field_hospital[LANGUAGE_NONE][0]['target_id'];
  }
  
  return false;
}

/**
 * Gets the taller id from a Siniestro.
 */
function anavem_siniestro_get_taller_uid($node) {
  if ( isset($node->field_taller[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_taller[LANGUAGE_NONE][0]['target_id']) ) {
    return $node->field_taller[LANGUAGE_NONE][0]['target_id'];
  }
  
  return false;
}

/**
 * Gets the grúas id from a Siniestro.
 */
function anavem_siniestro_get_gruas_uid($node) {
  if ( isset($node->field_gruas[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_gruas[LANGUAGE_NONE][0]['target_id']) ) {
    return $node->field_gruas[LANGUAGE_NONE][0]['target_id'];
  }
  
  return false;
}

/**
 * Gets the proveedores id from a Siniestro.
 */
function anavem_siniestro_get_proveedores_uid($node) {
  if ( isset($node->field_proveedores[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_proveedores[LANGUAGE_NONE][0]['target_id']) ) {
    return $node->field_proveedores[LANGUAGE_NONE][0]['target_id'];
  }
  
  return false;
}