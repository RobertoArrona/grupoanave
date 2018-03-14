<?php

/**
 * @file
 * Retrieve a third vehicle info from nid.
 */

/**
 * Return data from finished sinister.
 */
 
include_once 'sinister_ws_conductor.services.inc';
include_once 'sinister_ws_vehicles.services.inc';
include_once 'sinister_ws_lesiones.services.inc';
include_once 'sinister_ws_termino.services.inc';
include_once 'sinister_ws_files.services.inc';
 
function sinister_ws_historical_resource_retrieve($nid) {
  //$node = node_load($nid);
  $sinister = array();
  // Get field conductor info.
  $sinister['driver'] = sinister_ws_conductor_resource_retrieve($nid);
  // Get field vehicle info.
  $sinister['vehicle'] = sinister_ws_vehicles_resource_retrieve($nid);
  // Get field injured info.
  $sinister['injured'] = sinister_ws_lesiones_resource_retrieve($nid);
  // Get field termino info.
  $sinister['termino'] = sinister_ws_termino_resource_retrieve($nid);
  // Get field images info.
  $sinister['images'] = sinister_ws_archivos_resource_retrieve($nid);

  return $sinister;

}