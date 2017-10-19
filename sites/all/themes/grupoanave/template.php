<?php
/**
 * Implements hook_preprocess_page.
 */
function grupoanave_preprocess_page(&$vars) {
  grupoanave_preprocess_page_node($vars);
}

/**
 * Helper function for Preprocess Page on Node pages.
 */
function grupoanave_preprocess_page_node(&$vars) {
  if ( !(arg(0) == 'node' && intval(arg(1)) > 0 && ($node = node_load(arg(1)))) ) {
    return;
  }
  
  $vars['theme_hook_suggestions'][] = "page__node_type__{$node->type}";
}

/**
 * Overrides theme_menu_link().
 */
function grupoanave_menu_link__main_menu(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      //$element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  if ( $element['#original_link']['depth'] == 1 ) {
    $element['#title'] = "<div><span>{$element['#title']}</span></div><div><span>{$element['#title']}</span></div>";
  } else {
    $element['#title'] = "{$element['#title']}";
  }
  $element['#localized_options']['html'] = true;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Overrides theme_menu_link().
 */
function grupoanave_menu_link__menu_social_channels(array $variables) {
  $element = $variables ['element'];
  $sub_menu = '';

  if ($element ['#below']) {
    $sub_menu = drupal_render($element ['#below']);
  }
  $element['#localized_options']['html'] = true;
  $output = l('<span>' . $element ['#title'] . '</span>', $element ['#href'], $element ['#localized_options']);
  return '<li' . drupal_attributes($element ['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Returns an Address String.
 */
function grupoanave_theme_address($element) {
  $address = $element['#items'][0];
  $items = array();
  // Calle
  if ( isset($address['thoroughfare']) && !empty($address['thoroughfare']) ) {
    $items[] = $address['thoroughfare'];
  }
  
  // Calle
  if ( isset($address['premise']) && !empty($address['premise']) ) {
    $items[] = $address['premise'];
  }
  
  // Calle
  if ( isset($address['locality']) && !empty($address['locality']) ) {
    $items[] = $address['locality'];
  }
  
  // Calle
  if ( isset($address['administrative_area']) && !empty($address['administrative_area']) ) {
    $items[] = grupoanave_get_state_name($address['country'], $address['administrative_area']);
  }
  
  // Calle
  if ( isset($address['postal_code']) && !empty($address['postal_code']) ) {
    $items[] = $address['postal_code'];
  }
  
  return implode(', ', $items);
}

/**
 * Get full State Name.
 */
function grupoanave_get_state_name($country, $state) {
  $states = addressfield_get_administrative_areas($country);
  if (isset($states[$state])) {
    return $states[$state];
  }

  return false;
}

/**
 * Implements print_preprocess_print().
 */
function grupoanave_preprocess_print(&$variables) {
  if (isset($variables['node'])) {
    grupoanave_preprocess_print_node($variables);
  }
}

function grupoanave_preprocess_print_node(&$variables) {
  $node = $variables['node'];
  switch ($node->type) {
    case 'poliza':
      grupoanave_preprocess_print_node_poliza($variables);
      break;
  }
}

function grupoanave_preprocess_print_node_poliza(&$variables) {
  $node = $variables['node'];
  $service_type = $node->field_vehiculo_servicio[LANGUAGE_NONE][0]['value'];
  $variables['poliza_title'] = "CONTRATO DE PROTECCION PARA SERVICIO {$service_type}";
}


















