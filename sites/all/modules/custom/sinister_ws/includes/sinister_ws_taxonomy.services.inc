<?php
/**
 * @file
 * Retrieve a term info from nid.
 */

/**
 * Return data term from sinister.
 */
function sinister_ws_taxonomy_resource_retrieve($nid) {
  $objects = array();
  $percent = 0;

  // Asign vocabulary ids.
  $license_type_vid = 4;
  $license_place_vid = 5;
  $brand_vehicle_vid = 6;
  $type_vehicle_vid = 8;
  $color_vehicle_vid = 9;
  $insurance_company_vid = 10;
  $insurance_agent_vid = 11;

  // Load taxonomies by vocabulary id.
  $license_type_vocabulary = taxonomy_get_tree($license_type_vid);
  $license_place_vocabulary = taxonomy_get_tree($license_place_vid);
  $brand_vehicle_vocabulary = taxonomy_get_tree($brand_vehicle_vid);
  $type_vehicle_vocabulary = taxonomy_get_tree($type_vehicle_vid);
  $color_vehicle_vocabulary = taxonomy_get_tree($color_vehicle_vid);
  $insurance_company_vocabulary = taxonomy_get_tree($insurance_company_vid);
  $insurance_agent_vocabulary = taxonomy_get_tree($insurance_agent_vid);

  // Create return object.
  $return_obj = array(
    'license_type' => $license_type_vocabulary,
    'license_place' => $license_place_vocabulary,
    'brand_vehicle' => $brand_vehicle_vocabulary,
    'type_vehicle' => $type_vehicle_vocabulary,
    'insurance_agent' => $insurance_agent_vocabulary,
    'color_vehicle' => $color_vehicle_vocabulary,
    'insurance_company' => $insurance_company_vocabulary,
  );
  $objects[] = $return_obj;

  return $objects;
}
