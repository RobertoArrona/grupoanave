<?php

/**
 * @file
 * This file has access records for controlling siniestros and polizas.
 */

/**
 * Implements hook_node_access_records().
 */
function anavem_node_access_records($node) {
  $grants = array();
  switch ($node->type) {
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
 * Implements hook_node_grants().
 */
function anavem_node_grants($account, $op) {
  static $grants;
  if (isset($grants[$account->uid][$op])) {
    return $grants[$account->uid][$op];
  }

  $grants[$account->uid][$op] = array();

  // Grants for Node Siniestro.
  anavem_node_grants_siniestro($account, $op, $grants[$account->uid][$op]);

  // Grants for Node Poliza.
  anavem_node_grants_poliza($account, $op, $grants[$account->uid][$op]);

  return $grants[$account->uid][$op];
}

/**
 * The hook_node_grants helper for node siniestro.
 */
function anavem_node_grants_siniestro($account, $op, &$grants) {
  // Get a list of all siniestro nodes.
  $nids = anavem_siniestro_get_all();

  // Determine if the user can access this siniestro node.
  foreach ($nids as $nid) {
    if (anavem_user_can_access_siniestro($nid, $account)) {
      $grants['anavem_siniestro_node_access_view'][] = $nid;
      $grants['anavem_siniestro_node_access_edit'][] = $nid;
    }
  }
}

/**
 * The hook_node_grants helper for node poliza.
 */
function anavem_node_grants_poliza($account, $op, &$grants) {
  // Get a list of all poliza nodes.
  $all_nids = anavem_poliza_get_all();

  // Get a list of own poliza nodes.
  $own_nids = anavem_poliza_get_own($account->uid);

  // Get a list of assigned poliza nodes.
  $assigned_nids = anavem_poliza_get_assigned($account->uid);

  // Determine if the user can access this poliza node,
  // (permission 'all polizas').
  foreach ($all_nids as $nid) {
    if (anavem_user_can_access_poliza_all_polizas($nid, $account)) {
      $grants['anavem_poliza_node_access_view'][] = $nid;
    }
  }

  // Determine if the user can access this poliza node,
  // (permission 'own polizas').
  foreach ($own_nids as $nid) {
    if (anavem_user_can_access_poliza_own_polizas($nid, $account)) {
      $grants['anavem_poliza_node_access_view'][] = $nid;
    }
  }

  // Determine if the user can access this poliza node,
  // (permission 'assigned polizas').
  foreach ($assigned_nids as $nid) {
    if (anavem_user_can_access_poliza_assigned_polizas($nid, $account)) {
      $grants['anavem_poliza_node_access_view'][] = $nid;
    }
  }
}

/**
 * Determines if a siniestro node can be accesed by a given user.
 */
function anavem_user_can_access_siniestro($nid, $account) {
  // Static Cache.
  static $access;
  if (isset($access[$nid][$account->uid])) {
    return $access[$nid][$account->uid];
  }

  // DB Cache.
  $cid = 'anavem_user_can_access_siniestro_' . $nid . '_' . $account->uid;
  if (($cache = cache_get($cid))) {
    return $cache->data;
  }

  // Cache Expire Default.
  $cache_expire = intval(time()) + (60 * 60);

  // Scenarios where a Siniestro can be accessed.
  // 1.- If the user has right to see all siniestros.
  if (user_access('Administrar Todos los Siniestros', $account)) {
    $access[$nid][$account->uid] = TRUE;
    cache_set($cid, TRUE, 'cache', $cache_expire);
    return TRUE;
  }

  // Validate we can load the node.
  if (!($node = node_load($nid))) {
    $access[$nid][$account->uid] = FALSE;
    cache_set($cid, FALSE, 'cache', $cache_expire);
    return FALSE;
  }

  // 2.- If the user has role Ajustador and the siniestro has him as ajustador.
  $response = anavem_siniestro_user_access($node, $account);
  $access[$nid][$account->uid] = $response;
  cache_set($cid, $response, 'cache', $cache_expire);
  return $response;
}

/**
 * Determines if a poliza node can be accesed by a given user.
 *
 * (permission 'all polizas').
 */
function anavem_user_can_access_poliza_all_polizas($nid, $account) {
  // Static Cache.
  static $access;
  if (isset($access[$nid][$account->uid])) {
    return $access[$nid][$account->uid];
  }

  // DB Cache.
  $cid = 'anavem_user_can_access_poliza_all_polizas_' . $nid . '_' . $account->uid;
  if (($cache = cache_get($cid))) {
    return $cache->data;
  }

  // Cache Expire Default.
  $cache_expire = intval(time()) + (60 * 60);

  // Scenarios where a Poliza can be accessed.
  // 1.- If the user has right to see all Polizas.
  if (user_access('Administrar Todas las Polizas', $account)) {
    $access[$nid][$account->uid] = TRUE;
    cache_set($cid, TRUE, 'cache', $cache_expire);
    return TRUE;
  }

  // Validate we can load the node.
  if (!($node = node_load($nid))) {
    $access[$nid][$account->uid] = FALSE;
    cache_set($cid, FALSE, 'cache', $cache_expire);
    return FALSE;
  }

  // Get Siniestros related to this Poliza.
  $siniestros = anavem_poliza_get_siniestros($node);

  // If user has right to access a siniestro give access to the poliza.
  foreach ($siniestros as $siniestro) {
    if (anavem_siniestro_user_access($siniestro, $account)) {
      $access[$nid][$account->uid] = TRUE;
      cache_set($cid, TRUE, 'cache', $cache_expire);
      return TRUE;
    }
  }

  cache_set($cid, FALSE, 'cache', $cache_expire);
  $access[$nid][$account->uid] = FALSE;
  return FALSE;
}

/**
 * Determines if a poliza node can be accesed by a given user.
 *
 * (permission 'own polizas')
 */
function anavem_user_can_access_poliza_own_polizas($nid, $account) {
  // Static Cache.
  static $access;
  if (isset($access[$nid][$account->uid])) {
    return $access[$nid][$account->uid];
  }

  // DB Cache.
  $cid = 'anavem_user_can_access_poliza_own_polizas_' . $nid . '_' . $account->uid;
  if (($cache = cache_get($cid))) {
    return $cache->data;
  }

  // Cache Expire Default.
  $cache_expire = intval(time()) + (60 * 60);

  // Scenarios where a Poliza can be accessed.
  // 1.- If the user has right to see all Polizas.
  if (user_access('Administrar Polizas propias', $account)) {
    $access[$nid][$account->uid] = TRUE;
    cache_set($cid, TRUE, 'cache', $cache_expire);
    return TRUE;
  }

  // Validate we can load the node.
  if (!($node = node_load($nid))) {
    $access[$nid][$account->uid] = FALSE;
    cache_set($cid, FALSE, 'cache', $cache_expire);
    return FALSE;
  }

  // Get Siniestros related to this Poliza.
  $siniestros = anavem_poliza_get_siniestros($node);

  // If user has right to access a siniestro give access to the poliza.
  foreach ($siniestros as $siniestro) {
    if (anavem_siniestro_user_access($siniestro, $account)) {
      $access[$nid][$account->uid] = TRUE;
      cache_set($cid, TRUE, 'cache', $cache_expire);
      return TRUE;
    }
  }

  cache_set($cid, FALSE, 'cache', $cache_expire);
  $access[$nid][$account->uid] = FALSE;
  return FALSE;
}

/**
 * Determines if a poliza node can be accesed by a given user.
 *
 * (permission 'assigned polizas')
 */
function anavem_user_can_access_poliza_assigned_polizas($nid, $account) {
  // Static Cache.
  static $access;
  if (isset($access[$nid][$account->uid])) {
    return $access[$nid][$account->uid];
  }

  // DB Cache.
  $cid = 'anavem_user_can_access_poliza_assigned_polizas_' . $nid . '_' . $account->uid;
  if (($cache = cache_get($cid))) {
    return $cache->data;
  }

  // Cache Expire Default.
  $cache_expire = intval(time()) + (60 * 60);

  // Scenarios where a Poliza can be accessed.
  // 1.- If the user has right to see all Polizas.
  if (user_access('Administrar Polizas asignadas', $account)) {
    $access[$nid][$account->uid] = TRUE;
    cache_set($cid, TRUE, 'cache', $cache_expire);
    return TRUE;
  }

  // Validate we can load the node.
  if (!($node = node_load($nid))) {
    $access[$nid][$account->uid] = FALSE;
    cache_set($cid, FALSE, 'cache', $cache_expire);
    return FALSE;
  }

  // Get Siniestros related to this Poliza.
  $siniestros = anavem_poliza_get_siniestros($node);

  // If user has right to access a siniestro give access to the poliza.
  foreach ($siniestros as $siniestro) {
    if (anavem_siniestro_user_access($siniestro, $account)) {
      $access[$nid][$account->uid] = TRUE;
      cache_set($cid, TRUE, 'cache', $cache_expire);
      return TRUE;
    }
  }

  cache_set($cid, FALSE, 'cache', $cache_expire);
  $access[$nid][$account->uid] = FALSE;
  return FALSE;
}

/**
 * Helper function to know if a user has the rigth to access a given Siniestro.
 */
function anavem_siniestro_user_access($siniestro, $account) {
  static $cache;
  if (isset($cache[$siniestro->nid][$account->uid])) {
    return $cache[$siniestro->nid][$account->uid];
  }

  foreach ($account->roles as $role) {
    switch ($role) {
      case 'ajustador':
        if (($uid = anavem_siniestro_get_ajustador_uid($siniestro)) && $uid == $account->uid) {
          $cache[$siniestro->nid][$account->uid] = TRUE;
          return TRUE;
        }
        break;

      case 'abogado':
        if (($uid = anavem_siniestro_get_abogado_uid($siniestro)) && $uid == $account->uid) {
          $cache[$siniestro->nid][$account->uid] = TRUE;
          return TRUE;
        }
        break;

      case 'taller':
        if (($uid = anavem_siniestro_get_taller_uid($siniestro)) && $uid == $account->uid) {
          $cache[$siniestro->nid][$account->uid] = TRUE;
          return TRUE;
        }
        break;

      case 'hospital':
        if (($uid = anavem_siniestro_get_hospital_uid($siniestro)) && $uid == $account->uid) {
          $cache[$siniestro->nid][$account->uid] = TRUE;
          return TRUE;
        }
        break;

      case 'gruas':
        if (($uid = anavem_siniestro_get_gruas_uid($siniestro)) && $uid == $account->uid) {
          $cache[$siniestro->nid][$account->uid] = TRUE;
          return TRUE;
        }
        break;

      case 'proveedores':
        if (($uid = anavem_siniestro_get_proveedores_uid($siniestro)) && $uid == $account->uid) {
          $cache[$siniestro->nid][$account->uid] = TRUE;
          return TRUE;
        }
        break;
    }
  }

  $cache[$siniestro->nid][$account->uid] = FALSE;
  return FALSE;
}

/**
 * Gets the Ajustador id from a Siniestro.
 */
function anavem_siniestro_get_ajustador_uid($node) {
  if (isset($node->field_ajustador[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_ajustador[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_ajustador[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}

/**
 * Gets the abogado id from a Siniestro.
 */
function anavem_siniestro_get_abogado_uid($node) {
  if (isset($node->field_abogado[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_abogado[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_abogado[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}

/**
 * Gets the hospital id from a Siniestro.
 */
function anavem_siniestro_get_hospital_uid($node) {
  if (isset($node->field_hospital[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_hospital[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_hospital[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}

/**
 * Gets the taller id from a Siniestro.
 */
function anavem_siniestro_get_taller_uid($node) {
  if (isset($node->field_taller[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_taller[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_taller[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}

/**
 * Gets the grúas id from a Siniestro.
 */
function anavem_siniestro_get_gruas_uid($node) {
  if (isset($node->field_grua[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_grua[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_grua[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}

/**
 * Gets the proveedores id from a Siniestro.
 */
function anavem_siniestro_get_proveedores_uid($node) {
  if (isset($node->field_proveedores[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_proveedores[LANGUAGE_NONE][0]['target_id'])) {
    return $node->field_proveedores[LANGUAGE_NONE][0]['target_id'];
  }

  return FALSE;
}
