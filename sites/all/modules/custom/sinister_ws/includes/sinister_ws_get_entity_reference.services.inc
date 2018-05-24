<?php

/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data entity reference from sinister.
 */
function sinister_ws_entity_reference_resource_retrieve($nid) {
  /**
   * Users with role
   *
   * @param object $role
   *   Mixed The name or rid of the role we're wanting users to have.
   *
   * @param object $active_user
   *   Boolean. Only return active accounts?
   *
   * @return object
   *   Array An array of user objects with the role.
   */
  function users_with_role($role, $active_user = TRUE) {
    $uids = array();
    $users = array();
    if (is_int($role)) {
      $my_rid = $role;
    }
    else {
      $role_obj = user_role_load_by_name($role);
    }
    $result = db_select('users_roles', 'ur')
      ->fields('ur')
      ->condition('ur.rid', $role_obj->rid, '=')
      ->execute();
    foreach ($result as $record) {
      $uids[] = $record->uid;
    };
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'user')
      ->propertyCondition('uid', $uids, 'IN');
    if ($active_user) {
      $query->propertyCondition('status', 1);
    }
    $entities = $query->execute();
    if (!empty($entities)) {
      $users = entity_load('user', array_keys($entities['user']));
    }
    return $users;
  }

  $usuarios['taller'] = users_with_role('taller');
  $usuarios['hospital'] = users_with_role('hospital');

  return $usuarios;

}
