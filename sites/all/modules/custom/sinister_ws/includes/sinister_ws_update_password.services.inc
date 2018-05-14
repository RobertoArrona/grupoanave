<?php

/**
 * @file
 * This file has a function to update user password.
 */

/**
 * Controller function to update a user password.
 */
function sinister_ws_update_pass() {

  require_once DRUPAL_ROOT . '/includes/password.inc';

  $user = user_load($_POST['uid']);
  if (user_check_password($_POST['current_pass'], $user)) {
    // Add new password from POST.
    $user->pass = $_POST['pass'];
  }
  else {
    return array(
      'valid' => 0,
      'msg' => 'La contraseña actual no coincide con la que hay guardada en el sistema',
      'post' => $_POST,
    );
  }

  // Save user datas.
  user_save($user);

  return array(
    'valid' => 1,
    'msg' => 'Los datos se guardaron satisfactoriamente',
    'post' => $_POST,
  );
}
