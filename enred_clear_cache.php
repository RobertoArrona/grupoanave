<?php

/**
 * @file
 * This file requests a webservice to clear cache.
 */

// Start process.
enred_clear_cache_start();

/**
 * Starts process to clear cache on the site.
 */
function enred_clear_cache_start() {
  // Create new date and time object.
  $date = new DateTime();
  // Increase 1 hour because the server hour.
  $date->modify('+1 hour');
  // Format date.
  $date_format = $date->format('Y-m-d h:ia');

  // Post them.
  $post_url = 'http://global.dev.d4all.mx/rest/sinister-clear-cache';
  $post_vars = [
    'token' => sha1('enred-clear-cache'),
    'date' => $date_format,
  ];

  // Post.
  try {
    $response = enred_clear_cache_curl_post($post_url, $post_vars);
    echo $response . '\n\n';
  }
  catch (Exception $e) {
    echo 'Something failed!\n\n';
  }
}

/**
 * Send a POST requst using cURL
 * @param string $url to request
 * @param array $post values to send
 * @param array $options for cURL
 * @return string
 */
function enred_clear_cache_curl_post($url, array $post = NULL, array $options = array()) {
  $defaults = array( 
    CURLOPT_POST => 1,
    CURLOPT_HEADER => 0,
    CURLOPT_URL => $url,
    CURLOPT_FRESH_CONNECT => 1,
    CURLOPT_RETURNTRANSFER => 1,
    CURLOPT_FORBID_REUSE => 1,
    CURLOPT_TIMEOUT => 120,
    CURLOPT_POSTFIELDS => http_build_query($post)
  );

  $ch = curl_init();
  curl_setopt_array($ch, ($options + $defaults));
  if (!($result = curl_exec($ch))) {
    trigger_error(curl_error($ch));
  }
  curl_close($ch);

  return $result;
}

