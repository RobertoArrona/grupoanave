<?php

/**
 * @file
 * This file has a function to update user password.
 */

/**
 * Controller function to update a user password.
 */
function sinister_ws_update_pass() {

  $user = user_load($_POST['uid']);
  if (user_check_password($_POST['current_pass'], $user)) {

    // Add new password from POST.
    $password = $_POST['pass'];
    // Encrypy password.
    $hash = user_hash_password($password);
    // Add encrypted password to user pass field.
    $user->pass = $hash;

    // Save user data.
    user_save($user);

    return array(
      'valid' => 1,
      'msg' => 'Los datos se guardaron satisfactoriamente',
      'post' => $_POST,
    );

  }
  else {
    return array(
      'valid' => 0,
      'msg' => 'La contraseña actual no coincide con la que hay guardada en el sistema',
      'post' => $_POST,
    );
  }

}

// File needed to work with drupal passwords.
require_once DRUPAL_ROOT . '/includes/password.inc';
