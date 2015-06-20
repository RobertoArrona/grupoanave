<?php
/**
 * Implements hook_permission.
 */
function anavem_permission() {
  return array(
    'Anave User Landing Page' => array(
      'title' => 'Anave User Landing Page', 
      'description' => 'Anave User Landing Page', 
    ), 
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
    'Administrar Siniestros' => array(
      'title' => 'Administrar Siniestros', 
      'description' => 'Administrar Siniestros', 
    ), 
    'Administrar Todos los Siniestros' => array(
      'title' => 'Administrar Todos los Siniestros', 
      'description' => 'Administrar Todos los Siniestros', 
    ), 
    'Administrar Polizas' => array(
      'title' => 'Administrar Polizas', 
      'description' => 'Administrar Polizas', 
    ), 
    'Administrar Todas las Polizas' => array(
      'title' => 'Administrar Todas las Polizas', 
      'description' => 'Administrar Todas las Polizas', 
    ), 
    'Administrar Usuarios' => array(
      'title' => 'Administrar Usuarios', 
      'description' => 'Administrar Usuarios', 
    ), 
  );
}