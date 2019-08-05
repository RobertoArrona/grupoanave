<?php

/**
 * @file
 * This file has all functionality related to cron.
 */

/**
 * Implements hook_cronapi().
 */
function anavem_cronapi() {
  $items['anavam_clear_cache'] = array(
    'description' => 'Clear all caches.',
    'rule' => '10 25 * * *', // Everyday at 03:05 AM
    'callback' => 'anavem_callback_cron',
  );

  return $items;
}

/**
 * The callback for the cron job.
 */
function anavem_callback_cron() {
  watchdog('anavem', '<pre>' . print_r('Cleared cache.', TRUE) . '</pre>');
}
