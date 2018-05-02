<?php

/**
 * @file
 * This file has a function to login.
 */

/**
 * Function to login with POST method.
 */
function sinister_ws_login() {

  $username = $_POST['username'];
  $password = $_POST['password'];

  $login_url = 'http://seguros.loc/rest/user/login';

  $user_data = '{
    "username" : "' . $username . '",
    "password" : "' . $password . '"
  }';

  $user_options = array(
    'headers' => array('Content-Type' => 'application/json'),
    'method' => 'POST',
    'data' => $user_data,
  );

  $result = drupal_http_request($login_url, $user_options);

  if ($result->code == 200) {
    $user_data = json_decode($result->data);

    return array(
      'token' => $user_data->token,
      'cookie' => $user_data->sessid,
      'uid' => $user_data->user->uid,
    );
  }
  else {
    return FALSE;
  }

}
