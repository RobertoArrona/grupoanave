<?php

/**
 * Returns the Contract Folio.
 * @return INT The contract folio.
 */
function insurance_contract_contract_folio_get() {
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
  $contract_number = variable_get('insurance_contract_contract_number', 1001);
  $contract_number_string = sprintf("%'.06d", $contract_number);
  $contract_folio = "{$month}{$year}{$contract_number_string}";
  return $contract_folio;
}

/**
 * Increases the Contract Number by 1.
 */
function insurance_contract_contract_number_increase() {
  if (!($contract_number = variable_get('insurance_contract_contract_number', false))) {
    return false;
  }

  $contract_number = intval($contract_number) + 1;
  if ($contract_number > 999999) {
    $contract_number = 0;
  }

  variable_set('insurance_contract_contract_number', $contract_number);
  return true;
}