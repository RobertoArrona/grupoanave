<?php

/**
 * @file
 * Retrieve historical data from nid.
 */

// Include needed files.
include_once 'sinister_ws_get_files.services.inc';
include_once 'sinister_ws_get_driver.services.inc';
include_once 'sinister_ws_get_thirds.services.inc';
include_once 'sinister_ws_get_injuries.services.inc';
include_once 'sinister_ws_get_term.services.inc';

/**
 * Function to retrieve sinister historical data.
 */
function sinister_ws_historical_resource_retrieve($nid) {

  $sinister = array();
  // Get field files info.
  $sinister['files'] = sinister_ws_files_resource_retrieve($nid);
  // Get field driver info.
  $sinister['driver'] = sinister_ws_driver_resource_retrieve($nid);
  // Get field thirds info.
  $sinister['thirds'] = sinister_ws_thirds_resource_retrieve($nid);
  // Get field injuries info.
  $sinister['injuries'] = sinister_ws_injuries_resource_retrieve($nid);
  // Get field term info.
  $sinister['term'] = sinister_ws_term_resource_retrieve($nid);

  return $sinister;

}
