<?php

/**
 * @file
 * This file has a function to clear cache.
 */

/**
 * Controller function to clear cache.
 */
function sinister_ws_clear_cache() {
  // Create default response.
  $response = array(
    'valid' => 0,
  );

  if (validate_access()) {
    // Initialize stuff.
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
    // Clear cache.
    drupal_flush_all_caches();

    // Create response.
    $response = array(
      'valid' => 1,
      'msg' => 'Cleared cache on: ' . $_POST['date'],
    );

    // Prepare reponse on json format.
    $response = json_encode($response);

    // Add database log message.
    watchdog('sinister_ws', '<pre>' . 'Cleared cache on: ' . $_POST['date'] . '</pre>');

    return $response;
  }

  return $response;
}

/**
 * Validate Access.
 */
function validate_access() {
  if (!isset($_POST)) {
    return FALSE;
  }

  if (!isset($_POST['token'])) {
    return FALSE;
  }

  $token = sha1('enred-clear-cache');
  if ($_POST['token'] != $token) {
    return FALSE;
  }

  return TRUE;
}
