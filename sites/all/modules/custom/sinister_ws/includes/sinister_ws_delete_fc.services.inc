<?php

/**
 * @file
 * Retrieve a third vehicle info from nid.
 */

/**
 * Return data from third vehicles.
 */
function sinister_ws_delete_fc($nid = null) {

  $fc_ids = $_POST; // Assign array of field collection ids.

/*
  $fc_ids = array (
    11009
  );
*/

  entity_delete_multiple('field_collection_item', $fc_ids);
  
  $result = array(
    "This field collections have been deleted.",
    $fc_ids
  );

  return $_POST;
}

