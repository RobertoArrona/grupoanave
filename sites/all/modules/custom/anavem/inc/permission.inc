<?php
/**
 * Implements hook_permission.
 */
function anavem_permission() {
  return array(
    'Asignar Ajustador' => array(
      'title' => 'Iniciar Ajustador', 
      'description' => 'Iniciar Ajustador', 
    ), 
    'Asignar Abogado' => array(
      'title' => 'Asignar Abogado', 
      'description' => 'Asignar Abogado', 
    ), 
    'Asignar Hospital' => array(
      'title' => 'Asignar Hospital', 
      'description' => 'Asignar Hospital', 
    ), 
    'Asignar Taller' => array(
      'title' => 'Asignar Taller', 
      'description' => 'Asignar Taller', 
    ), 
  );
}