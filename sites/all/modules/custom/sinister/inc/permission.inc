<?php

/**
 * Implements hook_permission().
 */
function sinister_permission() {
  return array(
    'administer sinister number' => array(
      'title' => t('Administer Sinister Number'),
      'description' => t('Administer Sinister Number.'),
    ),
  );
}
