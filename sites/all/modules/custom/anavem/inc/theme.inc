<?php

/**
 * @file
 * This files implements hook_theme().
 */

/**
 * Implements hook_theme().
 */
function anavem_theme() {
  return array(
    'anavem-user_landing' => array(
      'arguments' => array(
        'sections' => NULL,
      ),
      'template' => 'templates/anavem-user_landing',
    ),
    'anavem-user_landing-section' => array(
      'arguments' => array(
        'id' => NULL,
        'title' => NULL,
        'description' => NULL,
      ),
      'template' => 'templates/anavem-user_landing-section',
    ),
  );
}
