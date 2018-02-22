<?php

/**
 * Returns all of the sinisters assign to an ajustdor user.
 */
function sinister_get_ajustador_sinisters($uid, $type = 1) {
  static $sinisters;
  if (isset($sinisters[$uid][$type])) {
    return $sinisters[$uid][$type];
  }

  $key = 'sinister_get_ajustador_sinisters_' . $uid . '_' . $type;
  if (($cache = cache_get($key))) {
    $sinisters[$uid][$type] = $cache->data;
    return $sinisters[$uid][$type];
  }

  $sql = 'SELECT ajustador.entity_id nid FROM field_data_field_ajustador ajustador 
    INNER JOIN field_data_field_sinister_status status ON ajustador.entity_id = status.entity_id 
    WHERE ajustador.field_ajustador_target_id = %d AND 
    status.field_sinister_status_value = %d';
  $sql = sprintf($sql, $uid, $type);
  $results = db_query($sql);
  $sinisters[$uid][$type] = array();
  while (($row = $results->fetchAssoc())) {
    $sinisters[$uid][$type][$row['nid']] = $row['nid'];
  }

  cache_set($key, $sinisters[$uid][$type], 'cache', strtotime('+1 hour'));
  return $sinisters[$uid][$type];
}

/**
 * Returns the Contract Folio.
 * @return INT The contract folio.
 */
function sinister_number_folio_get($i = 0) {
  $month_digit = intval(date('n'));
  $months = array(
    0 => 'None',
    1 => 'A', // January.
    2 => 'B', // February.
    3 => 'C', // March.
    4 => 'D', // April.
    5 => 'E', // May.
    6 => 'F', // June.
    7 => 'G', // July.
    8 => 'H', // August.
    9 => 'I', // September.
    10 => 'J', // October.
    11 => 'K', // November.
    12 => 'L', // December.
  );
  $month = $months[$month_digit];
  $year = date('y');
  $sinister_number = (variable_get('sinister_number', 0001) + $i);
  $sinister_number_string = sprintf("%'.04d", $sinister_number);  
  $sinister_folio = "{$year}{$month}{$sinister_number_string}";
  return $sinister_folio;
}

/**
 * Increases the Sinister Number by 1.
 */
function sinister_number_increase($i = 0) {
  if (!($sinister_number = variable_get('sinister_number', false))) {
    return false;
  }

  $sinister_number = intval($sinister_number) + 1 + $i;
  if ($sinister_number > 9999) {
    $sinister_number = 0;
  }

  variable_set('sinister_number', $sinister_number);
  return true;
}

/**
 * Returns true if a given sinister is found at the database.
 */
function sinister_number_folio_exists($sinister_folio, $nid) {
  $nid = explode('',$nid);
  $sinister_folio = explode('',$sinister_folio);
  if($nid) {
    $query = db_query("SELECT nid FROM {nodes} WHERE title = '%s' AND nid != %d". $sinister_folio, $nid);
    if ($item = $query->fetchArray()) {
      return $item['nid'];
    }
  }
  return false;
}