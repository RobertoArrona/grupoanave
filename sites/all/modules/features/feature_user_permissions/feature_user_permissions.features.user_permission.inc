<?php

/**
 * @file
 * feature_user_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_user_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Administrar Polizas'.
  $permissions['Administrar Polizas'] = array(
    'name' => 'Administrar Polizas',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Polizas asignadas'.
  $permissions['Administrar Polizas asignadas'] = array(
    'name' => 'Administrar Polizas asignadas',
    'roles' => array(
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Polizas propias'.
  $permissions['Administrar Polizas propias'] = array(
    'name' => 'Administrar Polizas propias',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Recibos'.
  $permissions['Administrar Recibos'] = array(
    'name' => 'Administrar Recibos',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Recibos de Contrato asignados'.
  $permissions['Administrar Recibos de Contrato asignados'] = array(
    'name' => 'Administrar Recibos de Contrato asignados',
    'roles' => array(
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Recibos de Contrato propios'.
  $permissions['Administrar Recibos de Contrato propios'] = array(
    'name' => 'Administrar Recibos de Contrato propios',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Siniestros'.
  $permissions['Administrar Siniestros'] = array(
    'name' => 'Administrar Siniestros',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Todas las Polizas'.
  $permissions['Administrar Todas las Polizas'] = array(
    'name' => 'Administrar Todas las Polizas',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Todos los Recibos de Contrato'.
  $permissions['Administrar Todos los Recibos de Contrato'] = array(
    'name' => 'Administrar Todos los Recibos de Contrato',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Todos los Siniestros'.
  $permissions['Administrar Todos los Siniestros'] = array(
    'name' => 'Administrar Todos los Siniestros',
    'roles' => array(
      'administrador' => 'administrador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Administrar Usuarios'.
  $permissions['Administrar Usuarios'] = array(
    'name' => 'Administrar Usuarios',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Anave User Landing Page'.
  $permissions['Anave User Landing Page'] = array(
    'name' => 'Anave User Landing Page',
    'roles' => array(
      'administrador' => 'administrador',
      'agente de ventas' => 'agente de ventas',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Asignar Abogado'.
  $permissions['Asignar Abogado'] = array(
    'name' => 'Asignar Abogado',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Asignar Ajustador'.
  $permissions['Asignar Ajustador'] = array(
    'name' => 'Asignar Ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Asignar Gruas'.
  $permissions['Asignar Gruas'] = array(
    'name' => 'Asignar Gruas',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Asignar Hospital'.
  $permissions['Asignar Hospital'] = array(
    'name' => 'Asignar Hospital',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Asignar Proveedores'.
  $permissions['Asignar Proveedores'] = array(
    'name' => 'Asignar Proveedores',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Asignar Taller'.
  $permissions['Asignar Taller'] = array(
    'name' => 'Asignar Taller',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Ver Siniestro'.
  $permissions['Ver Siniestro'] = array(
    'name' => 'Ver Siniestro',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'Ver Taller'.
  $permissions['Ver Taller'] = array(
    'name' => 'Ver Taller',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'anavem',
  );

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'print',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'abogado' => 'abogado',
      'ajustador' => 'ajustador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'hospital' => 'hospital',
      'promotor de ventas' => 'promotor de ventas',
      'taller' => 'taller',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
      'taller' => 'taller',
    ),
    'module' => 'user',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer insurance contract number'.
  $permissions['administer insurance contract number'] = array(
    'name' => 'administer insurance contract number',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'insurance_contract',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer node collections'.
  $permissions['administer node collections'] = array(
    'name' => 'administer node collections',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'promotor de ventas' => 'promotor de ventas',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
      'taller' => 'taller',
    ),
    'module' => 'node_collection',
  );

  // Exported permission: 'administer node content'.
  $permissions['administer node content'] = array(
    'name' => 'administer node content',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'promotor de ventas' => 'promotor de ventas',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
      'taller' => 'taller',
    ),
    'module' => 'node_collection',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer payment receipt number'.
  $permissions['administer payment receipt number'] = array(
    'name' => 'administer payment receipt number',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'payment_receipt',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer simplify'.
  $permissions['administer simplify'] = array(
    'name' => 'administer simplify',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'administer sinister number'.
  $permissions['administer sinister number'] = array(
    'name' => 'administer sinister number',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'sinister',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'views',
  );

  // Exported permission: 'assign abogado role'.
  $permissions['assign abogado role'] = array(
    'name' => 'assign abogado role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign administrador comercial role'.
  $permissions['assign administrador comercial role'] = array(
    'name' => 'assign administrador comercial role',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign administrador role'.
  $permissions['assign administrador role'] = array(
    'name' => 'assign administrador role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign agente de ventas role'.
  $permissions['assign agente de ventas role'] = array(
    'name' => 'assign agente de ventas role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign ajustador role'.
  $permissions['assign ajustador role'] = array(
    'name' => 'assign ajustador role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign cabina role'.
  $permissions['assign cabina role'] = array(
    'name' => 'assign cabina role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign gruas role'.
  $permissions['assign gruas role'] = array(
    'name' => 'assign gruas role',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign hospital role'.
  $permissions['assign hospital role'] = array(
    'name' => 'assign hospital role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign promotor de ventas role'.
  $permissions['assign promotor de ventas role'] = array(
    'name' => 'assign promotor de ventas role',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign proveedores role'.
  $permissions['assign proveedores role'] = array(
    'name' => 'assign proveedores role',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign supervisor de siniestros role'.
  $permissions['assign supervisor de siniestros role'] = array(
    'name' => 'assign supervisor de siniestros role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign supervisor de ventas role'.
  $permissions['assign supervisor de ventas role'] = array(
    'name' => 'assign supervisor de ventas role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign taller role'.
  $permissions['assign taller role'] = array(
    'name' => 'assign taller role',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_3ro_ajustador'.
  $permissions['create field_3ro_ajustador'] = array(
    'name' => 'create field_3ro_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_aseguradora'.
  $permissions['create field_3ro_aseguradora'] = array(
    'name' => 'create field_3ro_aseguradora',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_cobertura'.
  $permissions['create field_3ro_cobertura'] = array(
    'name' => 'create field_3ro_cobertura',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_deducible'.
  $permissions['create field_3ro_deducible'] = array(
    'name' => 'create field_3ro_deducible',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_numero_poliza'.
  $permissions['create field_3ro_numero_poliza'] = array(
    'name' => 'create field_3ro_numero_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_siniestro'.
  $permissions['create field_3ro_siniestro'] = array(
    'name' => 'create field_3ro_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_vehiculo_color'.
  $permissions['create field_3ro_vehiculo_color'] = array(
    'name' => 'create field_3ro_vehiculo_color',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_vehiculo_danos'.
  $permissions['create field_3ro_vehiculo_danos'] = array(
    'name' => 'create field_3ro_vehiculo_danos',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_vehiculo_modelo'.
  $permissions['create field_3ro_vehiculo_modelo'] = array(
    'name' => 'create field_3ro_vehiculo_modelo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_vehiculo_placas'.
  $permissions['create field_3ro_vehiculo_placas'] = array(
    'name' => 'create field_3ro_vehiculo_placas',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_vehiculo_serie'.
  $permissions['create field_3ro_vehiculo_serie'] = array(
    'name' => 'create field_3ro_vehiculo_serie',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_3ro_vencimiento'.
  $permissions['create field_3ro_vencimiento'] = array(
    'name' => 'create field_3ro_vencimiento',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_abogado'.
  $permissions['create field_abogado'] = array(
    'name' => 'create field_abogado',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ajustador'.
  $permissions['create field_ajustador'] = array(
    'name' => 'create field_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_archivo_autor'.
  $permissions['create field_archivo_autor'] = array(
    'name' => 'create field_archivo_autor',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_archivo_categoria'.
  $permissions['create field_archivo_categoria'] = array(
    'name' => 'create field_archivo_categoria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_archivo_comentario'.
  $permissions['create field_archivo_comentario'] = array(
    'name' => 'create field_archivo_comentario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asegurado_benef_pref'.
  $permissions['create field_asegurado_benef_pref'] = array(
    'name' => 'create field_asegurado_benef_pref',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asegurado_domicilio'.
  $permissions['create field_asegurado_domicilio'] = array(
    'name' => 'create field_asegurado_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asegurado_io'.
  $permissions['create field_asegurado_io'] = array(
    'name' => 'create field_asegurado_io',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asegurado_nombre'.
  $permissions['create field_asegurado_nombre'] = array(
    'name' => 'create field_asegurado_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asegurado_rfc'.
  $permissions['create field_asegurado_rfc'] = array(
    'name' => 'create field_asegurado_rfc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asegurado_telefono'.
  $permissions['create field_asegurado_telefono'] = array(
    'name' => 'create field_asegurado_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_asignar_promotor'.
  $permissions['create field_asignar_promotor'] = array(
    'name' => 'create field_asignar_promotor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_codigo_de_barras_rc'.
  $permissions['create field_codigo_de_barras_rc'] = array(
    'name' => 'create field_codigo_de_barras_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_comentarios_de_siniestro'.
  $permissions['create field_comentarios_de_siniestro'] = array(
    'name' => 'create field_comentarios_de_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conductor'.
  $permissions['create field_conductor'] = array(
    'name' => 'create field_conductor',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conductor_domicilio'.
  $permissions['create field_conductor_domicilio'] = array(
    'name' => 'create field_conductor_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conductor_es_propietario'.
  $permissions['create field_conductor_es_propietario'] = array(
    'name' => 'create field_conductor_es_propietario',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conductor_nombre'.
  $permissions['create field_conductor_nombre'] = array(
    'name' => 'create field_conductor_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conductor_reporta'.
  $permissions['create field_conductor_reporta'] = array(
    'name' => 'create field_conductor_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conductor_telefono'.
  $permissions['create field_conductor_telefono'] = array(
    'name' => 'create field_conductor_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_danos_materiales'.
  $permissions['create field_danos_materiales'] = array(
    'name' => 'create field_danos_materiales',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_derecho_de_poliza2'.
  $permissions['create field_derecho_de_poliza2'] = array(
    'name' => 'create field_derecho_de_poliza2',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_documentos'.
  $permissions['create field_documentos'] = array(
    'name' => 'create field_documentos',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_domicilio'.
  $permissions['create field_domicilio'] = array(
    'name' => 'create field_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_emision_recibo_ref_rc'.
  $permissions['create field_emision_recibo_ref_rc'] = array(
    'name' => 'create field_emision_recibo_ref_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_estado_single'.
  $permissions['create field_estado_single'] = array(
    'name' => 'create field_estado_single',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fecha'.
  $permissions['create field_fecha'] = array(
    'name' => 'create field_fecha',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fecha_arribo'.
  $permissions['create field_fecha_arribo'] = array(
    'name' => 'create field_fecha_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fecha_de_cancelacion'.
  $permissions['create field_fecha_de_cancelacion'] = array(
    'name' => 'create field_fecha_de_cancelacion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fecha_de_expedicion_rc'.
  $permissions['create field_fecha_de_expedicion_rc'] = array(
    'name' => 'create field_fecha_de_expedicion_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_fecha_de_pagado'.
  $permissions['create field_fecha_de_pagado'] = array(
    'name' => 'create field_fecha_de_pagado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ficha_de_pago'.
  $permissions['create field_ficha_de_pago'] = array(
    'name' => 'create field_ficha_de_pago',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_gastos_medicos'.
  $permissions['create field_gastos_medicos'] = array(
    'name' => 'create field_gastos_medicos',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_grua'.
  $permissions['create field_grua'] = array(
    'name' => 'create field_grua',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_hospital'.
  $permissions['create field_hospital'] = array(
    'name' => 'create field_hospital',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_importe_con_letra_rc'.
  $permissions['create field_importe_con_letra_rc'] = array(
    'name' => 'create field_importe_con_letra_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_informe'.
  $permissions['create field_informe'] = array(
    'name' => 'create field_informe',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado'.
  $permissions['create field_lesionado'] = array(
    'name' => 'create field_lesionado',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_ambulancia'.
  $permissions['create field_lesionado_ambulancia'] = array(
    'name' => 'create field_lesionado_ambulancia',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_ambulancia_info'.
  $permissions['create field_lesionado_ambulancia_info'] = array(
    'name' => 'create field_lesionado_ambulancia_info',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_domicilio'.
  $permissions['create field_lesionado_domicilio'] = array(
    'name' => 'create field_lesionado_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_edad'.
  $permissions['create field_lesionado_edad'] = array(
    'name' => 'create field_lesionado_edad',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_lesiones'.
  $permissions['create field_lesionado_lesiones'] = array(
    'name' => 'create field_lesionado_lesiones',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_nombre'.
  $permissions['create field_lesionado_nombre'] = array(
    'name' => 'create field_lesionado_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_pase_medico'.
  $permissions['create field_lesionado_pase_medico'] = array(
    'name' => 'create field_lesionado_pase_medico',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_riesgo_b'.
  $permissions['create field_lesionado_riesgo_b'] = array(
    'name' => 'create field_lesionado_riesgo_b',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lesionado_telefono'.
  $permissions['create field_lesionado_telefono'] = array(
    'name' => 'create field_lesionado_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_licencia_alta_fecha'.
  $permissions['create field_licencia_alta_fecha'] = array(
    'name' => 'create field_licencia_alta_fecha',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_licencia_alta_lugar'.
  $permissions['create field_licencia_alta_lugar'] = array(
    'name' => 'create field_licencia_alta_lugar',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_licencia_numero'.
  $permissions['create field_licencia_numero'] = array(
    'name' => 'create field_licencia_numero',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_licencia_tipo'.
  $permissions['create field_licencia_tipo'] = array(
    'name' => 'create field_licencia_tipo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lugar_atencion'.
  $permissions['create field_lugar_atencion'] = array(
    'name' => 'create field_lugar_atencion',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_lugar_referencias'.
  $permissions['create field_lugar_referencias'] = array(
    'name' => 'create field_lugar_referencias',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_mapa_arribo'.
  $permissions['create field_mapa_arribo'] = array(
    'name' => 'create field_mapa_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_mapa_siniestro'.
  $permissions['create field_mapa_siniestro'] = array(
    'name' => 'create field_mapa_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_motivos_de_cancelacion'.
  $permissions['create field_motivos_de_cancelacion'] = array(
    'name' => 'create field_motivos_de_cancelacion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_nombre'.
  $permissions['create field_nombre'] = array(
    'name' => 'create field_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_nombre_quien_reporta'.
  $permissions['create field_nombre_quien_reporta'] = array(
    'name' => 'create field_nombre_quien_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pago_fraccionado'.
  $permissions['create field_pago_fraccionado'] = array(
    'name' => 'create field_pago_fraccionado',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_pago_subsecuente_rc'.
  $permissions['create field_pago_subsecuente_rc'] = array(
    'name' => 'create field_pago_subsecuente_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_periodo_cobertura_rc'.
  $permissions['create field_periodo_cobertura_rc'] = array(
    'name' => 'create field_periodo_cobertura_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_periodo_de_gracia'.
  $permissions['create field_periodo_de_gracia'] = array(
    'name' => 'create field_periodo_de_gracia',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_plz_vehiculo_marca'.
  $permissions['create field_plz_vehiculo_marca'] = array(
    'name' => 'create field_plz_vehiculo_marca',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poblacion'.
  $permissions['create field_poblacion'] = array(
    'name' => 'create field_poblacion',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza'.
  $permissions['create field_poliza'] = array(
    'name' => 'create field_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_coberturas'.
  $permissions['create field_poliza_coberturas'] = array(
    'name' => 'create field_poliza_coberturas',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_comentarios'.
  $permissions['create field_poliza_comentarios'] = array(
    'name' => 'create field_poliza_comentarios',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_derecho_poliza'.
  $permissions['create field_poliza_derecho_poliza'] = array(
    'name' => 'create field_poliza_derecho_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_emision'.
  $permissions['create field_poliza_emision'] = array(
    'name' => 'create field_poliza_emision',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_forma_pago'.
  $permissions['create field_poliza_forma_pago'] = array(
    'name' => 'create field_poliza_forma_pago',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_impuesto_iva'.
  $permissions['create field_poliza_impuesto_iva'] = array(
    'name' => 'create field_poliza_impuesto_iva',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_moneda'.
  $permissions['create field_poliza_moneda'] = array(
    'name' => 'create field_poliza_moneda',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_oficina'.
  $permissions['create field_poliza_oficina'] = array(
    'name' => 'create field_poliza_oficina',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_prima_1er_recibo'.
  $permissions['create field_poliza_prima_1er_recibo'] = array(
    'name' => 'create field_poliza_prima_1er_recibo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_prima_neta'.
  $permissions['create field_poliza_prima_neta'] = array(
    'name' => 'create field_poliza_prima_neta',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_prima_total'.
  $permissions['create field_poliza_prima_total'] = array(
    'name' => 'create field_poliza_prima_total',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_primas_recibos_subs'.
  $permissions['create field_poliza_primas_recibos_subs'] = array(
    'name' => 'create field_poliza_primas_recibos_subs',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_reduccion'.
  $permissions['create field_poliza_reduccion'] = array(
    'name' => 'create field_poliza_reduccion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_rgo_pago_fracc'.
  $permissions['create field_poliza_rgo_pago_fracc'] = array(
    'name' => 'create field_poliza_rgo_pago_fracc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_status'.
  $permissions['create field_poliza_status'] = array(
    'name' => 'create field_poliza_status',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_poliza_vigencia'.
  $permissions['create field_poliza_vigencia'] = array(
    'name' => 'create field_poliza_vigencia',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_primer_pago_rc'.
  $permissions['create field_primer_pago_rc'] = array(
    'name' => 'create field_primer_pago_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_propietario_domicilio'.
  $permissions['create field_propietario_domicilio'] = array(
    'name' => 'create field_propietario_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_propietario_nombre'.
  $permissions['create field_propietario_nombre'] = array(
    'name' => 'create field_propietario_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_propietario_telefono'.
  $permissions['create field_propietario_telefono'] = array(
    'name' => 'create field_propietario_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_proveedores'.
  $permissions['create field_proveedores'] = array(
    'name' => 'create field_proveedores',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_rc_viajero'.
  $permissions['create field_rc_viajero'] = array(
    'name' => 'create field_rc_viajero',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_reserva_total'.
  $permissions['create field_reserva_total'] = array(
    'name' => 'create field_reserva_total',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_resp_civil'.
  $permissions['create field_resp_civil'] = array(
    'name' => 'create field_resp_civil',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_rfc'.
  $permissions['create field_rfc'] = array(
    'name' => 'create field_rfc',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_robo'.
  $permissions['create field_robo'] = array(
    'name' => 'create field_robo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_serie_rc'.
  $permissions['create field_serie_rc'] = array(
    'name' => 'create field_serie_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_siniestro_archivo'.
  $permissions['create field_siniestro_archivo'] = array(
    'name' => 'create field_siniestro_archivo',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_status_sinister'.
  $permissions['create field_status_sinister'] = array(
    'name' => 'create field_status_sinister',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_taller'.
  $permissions['create field_taller'] = array(
    'name' => 'create field_taller',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_telefono'.
  $permissions['create field_telefono'] = array(
    'name' => 'create field_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_telefono_quien_reporta'.
  $permissions['create field_telefono_quien_reporta'] = array(
    'name' => 'create field_telefono_quien_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_uso_vehiculo'.
  $permissions['create field_uso_vehiculo'] = array(
    'name' => 'create field_uso_vehiculo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_usuario_de_cancelado'.
  $permissions['create field_usuario_de_cancelado'] = array(
    'name' => 'create field_usuario_de_cancelado',
    'roles' => array(
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_usuario_de_pagado'.
  $permissions['create field_usuario_de_pagado'] = array(
    'name' => 'create field_usuario_de_pagado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_capacidad'.
  $permissions['create field_vehiculo_capacidad'] = array(
    'name' => 'create field_vehiculo_capacidad',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_carroceria'.
  $permissions['create field_vehiculo_carroceria'] = array(
    'name' => 'create field_vehiculo_carroceria',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_carroceria_select'.
  $permissions['create field_vehiculo_carroceria_select'] = array(
    'name' => 'create field_vehiculo_carroceria_select',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_categoria'.
  $permissions['create field_vehiculo_categoria'] = array(
    'name' => 'create field_vehiculo_categoria',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_cilindros'.
  $permissions['create field_vehiculo_cilindros'] = array(
    'name' => 'create field_vehiculo_cilindros',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_clave_sbg'.
  $permissions['create field_vehiculo_clave_sbg'] = array(
    'name' => 'create field_vehiculo_clave_sbg',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_color'.
  $permissions['create field_vehiculo_color'] = array(
    'name' => 'create field_vehiculo_color',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_descripcion'.
  $permissions['create field_vehiculo_descripcion'] = array(
    'name' => 'create field_vehiculo_descripcion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_descripcion_carga'.
  $permissions['create field_vehiculo_descripcion_carga'] = array(
    'name' => 'create field_vehiculo_descripcion_carga',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_marca'.
  $permissions['create field_vehiculo_marca'] = array(
    'name' => 'create field_vehiculo_marca',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_modelo'.
  $permissions['create field_vehiculo_modelo'] = array(
    'name' => 'create field_vehiculo_modelo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_motor'.
  $permissions['create field_vehiculo_motor'] = array(
    'name' => 'create field_vehiculo_motor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_numero_inventario'.
  $permissions['create field_vehiculo_numero_inventario'] = array(
    'name' => 'create field_vehiculo_numero_inventario',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_numero_pedimento'.
  $permissions['create field_vehiculo_numero_pedimento'] = array(
    'name' => 'create field_vehiculo_numero_pedimento',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_placas'.
  $permissions['create field_vehiculo_placas'] = array(
    'name' => 'create field_vehiculo_placas',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_referencia'.
  $permissions['create field_vehiculo_referencia'] = array(
    'name' => 'create field_vehiculo_referencia',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_remolque'.
  $permissions['create field_vehiculo_remolque'] = array(
    'name' => 'create field_vehiculo_remolque',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_serie'.
  $permissions['create field_vehiculo_serie'] = array(
    'name' => 'create field_vehiculo_serie',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_servicio'.
  $permissions['create field_vehiculo_servicio'] = array(
    'name' => 'create field_vehiculo_servicio',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_submarca'.
  $permissions['create field_vehiculo_submarca'] = array(
    'name' => 'create field_vehiculo_submarca',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_tercero'.
  $permissions['create field_vehiculo_tercero'] = array(
    'name' => 'create field_vehiculo_tercero',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_tipo'.
  $permissions['create field_vehiculo_tipo'] = array(
    'name' => 'create field_vehiculo_tipo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_tipo_carga'.
  $permissions['create field_vehiculo_tipo_carga'] = array(
    'name' => 'create field_vehiculo_tipo_carga',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_tipo_remolque'.
  $permissions['create field_vehiculo_tipo_remolque'] = array(
    'name' => 'create field_vehiculo_tipo_remolque',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_tonelaje'.
  $permissions['create field_vehiculo_tonelaje'] = array(
    'name' => 'create field_vehiculo_tonelaje',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_transmision'.
  $permissions['create field_vehiculo_transmision'] = array(
    'name' => 'create field_vehiculo_transmision',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vehiculo_uso'.
  $permissions['create field_vehiculo_uso'] = array(
    'name' => 'create field_vehiculo_uso',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_vencimiento_rc'.
  $permissions['create field_vencimiento_rc'] = array(
    'name' => 'create field_vencimiento_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_visualizador'.
  $permissions['create field_visualizador'] = array(
    'name' => 'create field_visualizador',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create home_blocks content'.
  $permissions['create home_blocks content'] = array(
    'name' => 'create home_blocks content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create legal content'.
  $permissions['create legal content'] = array(
    'name' => 'create legal content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create poliza content'.
  $permissions['create poliza content'] = array(
    'name' => 'create poliza content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create poliza_tipo content'.
  $permissions['create poliza_tipo content'] = array(
    'name' => 'create poliza_tipo content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create recibo_contrato content'.
  $permissions['create recibo_contrato content'] = array(
    'name' => 'create recibo_contrato content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'promotor de ventas' => 'promotor de ventas',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create siniestro content'.
  $permissions['create siniestro content'] = array(
    'name' => 'create siniestro content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create slideshow content'.
  $permissions['create slideshow content'] = array(
    'name' => 'create slideshow content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any home_blocks content'.
  $permissions['delete any home_blocks content'] = array(
    'name' => 'delete any home_blocks content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any legal content'.
  $permissions['delete any legal content'] = array(
    'name' => 'delete any legal content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any poliza content'.
  $permissions['delete any poliza content'] = array(
    'name' => 'delete any poliza content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any poliza_tipo content'.
  $permissions['delete any poliza_tipo content'] = array(
    'name' => 'delete any poliza_tipo content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any recibo_contrato content'.
  $permissions['delete any recibo_contrato content'] = array(
    'name' => 'delete any recibo_contrato content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any siniestro content'.
  $permissions['delete any siniestro content'] = array(
    'name' => 'delete any siniestro content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any slideshow content'.
  $permissions['delete any slideshow content'] = array(
    'name' => 'delete any slideshow content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own home_blocks content'.
  $permissions['delete own home_blocks content'] = array(
    'name' => 'delete own home_blocks content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own legal content'.
  $permissions['delete own legal content'] = array(
    'name' => 'delete own legal content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own poliza content'.
  $permissions['delete own poliza content'] = array(
    'name' => 'delete own poliza content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own poliza_tipo content'.
  $permissions['delete own poliza_tipo content'] = array(
    'name' => 'delete own poliza_tipo content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own recibo_contrato content'.
  $permissions['delete own recibo_contrato content'] = array(
    'name' => 'delete own recibo_contrato content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own siniestro content'.
  $permissions['delete own siniestro content'] = array(
    'name' => 'delete own siniestro content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own slideshow content'.
  $permissions['delete own slideshow content'] = array(
    'name' => 'delete own slideshow content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in ajustador'.
  $permissions['delete terms in ajustador'] = array(
    'name' => 'delete terms in ajustador',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in archivos'.
  $permissions['delete terms in archivos'] = array(
    'name' => 'delete terms in archivos',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in aseguradora'.
  $permissions['delete terms in aseguradora'] = array(
    'name' => 'delete terms in aseguradora',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in carroceria'.
  $permissions['delete terms in carroceria'] = array(
    'name' => 'delete terms in carroceria',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in carrusel'.
  $permissions['delete terms in carrusel'] = array(
    'name' => 'delete terms in carrusel',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in licencia_tipo'.
  $permissions['delete terms in licencia_tipo'] = array(
    'name' => 'delete terms in licencia_tipo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in lugar'.
  $permissions['delete terms in lugar'] = array(
    'name' => 'delete terms in lugar',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in marca'.
  $permissions['delete terms in marca'] = array(
    'name' => 'delete terms in marca',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in motivos_de_cancelacion'.
  $permissions['delete terms in motivos_de_cancelacion'] = array(
    'name' => 'delete terms in motivos_de_cancelacion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in promotor'.
  $permissions['delete terms in promotor'] = array(
    'name' => 'delete terms in promotor',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in states'.
  $permissions['delete terms in states'] = array(
    'name' => 'delete terms in states',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in submarca'.
  $permissions['delete terms in submarca'] = array(
    'name' => 'delete terms in submarca',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in vehiculo_color'.
  $permissions['delete terms in vehiculo_color'] = array(
    'name' => 'delete terms in vehiculo_color',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in vehiculo_descripcion'.
  $permissions['delete terms in vehiculo_descripcion'] = array(
    'name' => 'delete terms in vehiculo_descripcion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in vehiculo_tipo'.
  $permissions['delete terms in vehiculo_tipo'] = array(
    'name' => 'delete terms in vehiculo_tipo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any home_blocks content'.
  $permissions['edit any home_blocks content'] = array(
    'name' => 'edit any home_blocks content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any legal content'.
  $permissions['edit any legal content'] = array(
    'name' => 'edit any legal content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any poliza content'.
  $permissions['edit any poliza content'] = array(
    'name' => 'edit any poliza content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any poliza_tipo content'.
  $permissions['edit any poliza_tipo content'] = array(
    'name' => 'edit any poliza_tipo content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any recibo_contrato content'.
  $permissions['edit any recibo_contrato content'] = array(
    'name' => 'edit any recibo_contrato content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any siniestro content'.
  $permissions['edit any siniestro content'] = array(
    'name' => 'edit any siniestro content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any slideshow content'.
  $permissions['edit any slideshow content'] = array(
    'name' => 'edit any slideshow content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_3ro_ajustador'.
  $permissions['edit field_3ro_ajustador'] = array(
    'name' => 'edit field_3ro_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_aseguradora'.
  $permissions['edit field_3ro_aseguradora'] = array(
    'name' => 'edit field_3ro_aseguradora',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_cobertura'.
  $permissions['edit field_3ro_cobertura'] = array(
    'name' => 'edit field_3ro_cobertura',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_deducible'.
  $permissions['edit field_3ro_deducible'] = array(
    'name' => 'edit field_3ro_deducible',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_numero_poliza'.
  $permissions['edit field_3ro_numero_poliza'] = array(
    'name' => 'edit field_3ro_numero_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_siniestro'.
  $permissions['edit field_3ro_siniestro'] = array(
    'name' => 'edit field_3ro_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_vehiculo_color'.
  $permissions['edit field_3ro_vehiculo_color'] = array(
    'name' => 'edit field_3ro_vehiculo_color',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_vehiculo_danos'.
  $permissions['edit field_3ro_vehiculo_danos'] = array(
    'name' => 'edit field_3ro_vehiculo_danos',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_vehiculo_modelo'.
  $permissions['edit field_3ro_vehiculo_modelo'] = array(
    'name' => 'edit field_3ro_vehiculo_modelo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_vehiculo_placas'.
  $permissions['edit field_3ro_vehiculo_placas'] = array(
    'name' => 'edit field_3ro_vehiculo_placas',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_vehiculo_serie'.
  $permissions['edit field_3ro_vehiculo_serie'] = array(
    'name' => 'edit field_3ro_vehiculo_serie',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_3ro_vencimiento'.
  $permissions['edit field_3ro_vencimiento'] = array(
    'name' => 'edit field_3ro_vencimiento',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_abogado'.
  $permissions['edit field_abogado'] = array(
    'name' => 'edit field_abogado',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ajustador'.
  $permissions['edit field_ajustador'] = array(
    'name' => 'edit field_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_archivo_autor'.
  $permissions['edit field_archivo_autor'] = array(
    'name' => 'edit field_archivo_autor',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_archivo_categoria'.
  $permissions['edit field_archivo_categoria'] = array(
    'name' => 'edit field_archivo_categoria',
    'roles' => array(
      'administrador' => 'administrador',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_archivo_comentario'.
  $permissions['edit field_archivo_comentario'] = array(
    'name' => 'edit field_archivo_comentario',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asegurado_benef_pref'.
  $permissions['edit field_asegurado_benef_pref'] = array(
    'name' => 'edit field_asegurado_benef_pref',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asegurado_domicilio'.
  $permissions['edit field_asegurado_domicilio'] = array(
    'name' => 'edit field_asegurado_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asegurado_io'.
  $permissions['edit field_asegurado_io'] = array(
    'name' => 'edit field_asegurado_io',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asegurado_nombre'.
  $permissions['edit field_asegurado_nombre'] = array(
    'name' => 'edit field_asegurado_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asegurado_rfc'.
  $permissions['edit field_asegurado_rfc'] = array(
    'name' => 'edit field_asegurado_rfc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asegurado_telefono'.
  $permissions['edit field_asegurado_telefono'] = array(
    'name' => 'edit field_asegurado_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_asignar_promotor'.
  $permissions['edit field_asignar_promotor'] = array(
    'name' => 'edit field_asignar_promotor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_codigo_de_barras_rc'.
  $permissions['edit field_codigo_de_barras_rc'] = array(
    'name' => 'edit field_codigo_de_barras_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_comentarios_de_siniestro'.
  $permissions['edit field_comentarios_de_siniestro'] = array(
    'name' => 'edit field_comentarios_de_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conductor'.
  $permissions['edit field_conductor'] = array(
    'name' => 'edit field_conductor',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conductor_domicilio'.
  $permissions['edit field_conductor_domicilio'] = array(
    'name' => 'edit field_conductor_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conductor_es_propietario'.
  $permissions['edit field_conductor_es_propietario'] = array(
    'name' => 'edit field_conductor_es_propietario',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conductor_nombre'.
  $permissions['edit field_conductor_nombre'] = array(
    'name' => 'edit field_conductor_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conductor_reporta'.
  $permissions['edit field_conductor_reporta'] = array(
    'name' => 'edit field_conductor_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conductor_telefono'.
  $permissions['edit field_conductor_telefono'] = array(
    'name' => 'edit field_conductor_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_danos_materiales'.
  $permissions['edit field_danos_materiales'] = array(
    'name' => 'edit field_danos_materiales',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_derecho_de_poliza2'.
  $permissions['edit field_derecho_de_poliza2'] = array(
    'name' => 'edit field_derecho_de_poliza2',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_documentos'.
  $permissions['edit field_documentos'] = array(
    'name' => 'edit field_documentos',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_domicilio'.
  $permissions['edit field_domicilio'] = array(
    'name' => 'edit field_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_emision_recibo_ref_rc'.
  $permissions['edit field_emision_recibo_ref_rc'] = array(
    'name' => 'edit field_emision_recibo_ref_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_estado_single'.
  $permissions['edit field_estado_single'] = array(
    'name' => 'edit field_estado_single',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fecha'.
  $permissions['edit field_fecha'] = array(
    'name' => 'edit field_fecha',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fecha_arribo'.
  $permissions['edit field_fecha_arribo'] = array(
    'name' => 'edit field_fecha_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fecha_de_cancelacion'.
  $permissions['edit field_fecha_de_cancelacion'] = array(
    'name' => 'edit field_fecha_de_cancelacion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fecha_de_expedicion_rc'.
  $permissions['edit field_fecha_de_expedicion_rc'] = array(
    'name' => 'edit field_fecha_de_expedicion_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fecha_de_pagado'.
  $permissions['edit field_fecha_de_pagado'] = array(
    'name' => 'edit field_fecha_de_pagado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ficha_de_pago'.
  $permissions['edit field_ficha_de_pago'] = array(
    'name' => 'edit field_ficha_de_pago',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_gastos_medicos'.
  $permissions['edit field_gastos_medicos'] = array(
    'name' => 'edit field_gastos_medicos',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_grua'.
  $permissions['edit field_grua'] = array(
    'name' => 'edit field_grua',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_hospital'.
  $permissions['edit field_hospital'] = array(
    'name' => 'edit field_hospital',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_importe_con_letra_rc'.
  $permissions['edit field_importe_con_letra_rc'] = array(
    'name' => 'edit field_importe_con_letra_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_informe'.
  $permissions['edit field_informe'] = array(
    'name' => 'edit field_informe',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado'.
  $permissions['edit field_lesionado'] = array(
    'name' => 'edit field_lesionado',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_ambulancia'.
  $permissions['edit field_lesionado_ambulancia'] = array(
    'name' => 'edit field_lesionado_ambulancia',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_ambulancia_info'.
  $permissions['edit field_lesionado_ambulancia_info'] = array(
    'name' => 'edit field_lesionado_ambulancia_info',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_domicilio'.
  $permissions['edit field_lesionado_domicilio'] = array(
    'name' => 'edit field_lesionado_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_edad'.
  $permissions['edit field_lesionado_edad'] = array(
    'name' => 'edit field_lesionado_edad',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_lesiones'.
  $permissions['edit field_lesionado_lesiones'] = array(
    'name' => 'edit field_lesionado_lesiones',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_nombre'.
  $permissions['edit field_lesionado_nombre'] = array(
    'name' => 'edit field_lesionado_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_pase_medico'.
  $permissions['edit field_lesionado_pase_medico'] = array(
    'name' => 'edit field_lesionado_pase_medico',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_riesgo_b'.
  $permissions['edit field_lesionado_riesgo_b'] = array(
    'name' => 'edit field_lesionado_riesgo_b',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lesionado_telefono'.
  $permissions['edit field_lesionado_telefono'] = array(
    'name' => 'edit field_lesionado_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_licencia_alta_fecha'.
  $permissions['edit field_licencia_alta_fecha'] = array(
    'name' => 'edit field_licencia_alta_fecha',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_licencia_alta_lugar'.
  $permissions['edit field_licencia_alta_lugar'] = array(
    'name' => 'edit field_licencia_alta_lugar',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_licencia_numero'.
  $permissions['edit field_licencia_numero'] = array(
    'name' => 'edit field_licencia_numero',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_licencia_tipo'.
  $permissions['edit field_licencia_tipo'] = array(
    'name' => 'edit field_licencia_tipo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lugar_atencion'.
  $permissions['edit field_lugar_atencion'] = array(
    'name' => 'edit field_lugar_atencion',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_lugar_referencias'.
  $permissions['edit field_lugar_referencias'] = array(
    'name' => 'edit field_lugar_referencias',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_mapa_arribo'.
  $permissions['edit field_mapa_arribo'] = array(
    'name' => 'edit field_mapa_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_mapa_siniestro'.
  $permissions['edit field_mapa_siniestro'] = array(
    'name' => 'edit field_mapa_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_motivos_de_cancelacion'.
  $permissions['edit field_motivos_de_cancelacion'] = array(
    'name' => 'edit field_motivos_de_cancelacion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_nombre'.
  $permissions['edit field_nombre'] = array(
    'name' => 'edit field_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_nombre_quien_reporta'.
  $permissions['edit field_nombre_quien_reporta'] = array(
    'name' => 'edit field_nombre_quien_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pago_fraccionado'.
  $permissions['edit field_pago_fraccionado'] = array(
    'name' => 'edit field_pago_fraccionado',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_pago_subsecuente_rc'.
  $permissions['edit field_pago_subsecuente_rc'] = array(
    'name' => 'edit field_pago_subsecuente_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_periodo_cobertura_rc'.
  $permissions['edit field_periodo_cobertura_rc'] = array(
    'name' => 'edit field_periodo_cobertura_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_periodo_de_gracia'.
  $permissions['edit field_periodo_de_gracia'] = array(
    'name' => 'edit field_periodo_de_gracia',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_plz_vehiculo_marca'.
  $permissions['edit field_plz_vehiculo_marca'] = array(
    'name' => 'edit field_plz_vehiculo_marca',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poblacion'.
  $permissions['edit field_poblacion'] = array(
    'name' => 'edit field_poblacion',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza'.
  $permissions['edit field_poliza'] = array(
    'name' => 'edit field_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_coberturas'.
  $permissions['edit field_poliza_coberturas'] = array(
    'name' => 'edit field_poliza_coberturas',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_comentarios'.
  $permissions['edit field_poliza_comentarios'] = array(
    'name' => 'edit field_poliza_comentarios',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_derecho_poliza'.
  $permissions['edit field_poliza_derecho_poliza'] = array(
    'name' => 'edit field_poliza_derecho_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_emision'.
  $permissions['edit field_poliza_emision'] = array(
    'name' => 'edit field_poliza_emision',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_forma_pago'.
  $permissions['edit field_poliza_forma_pago'] = array(
    'name' => 'edit field_poliza_forma_pago',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_impuesto_iva'.
  $permissions['edit field_poliza_impuesto_iva'] = array(
    'name' => 'edit field_poliza_impuesto_iva',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_moneda'.
  $permissions['edit field_poliza_moneda'] = array(
    'name' => 'edit field_poliza_moneda',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_oficina'.
  $permissions['edit field_poliza_oficina'] = array(
    'name' => 'edit field_poliza_oficina',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_prima_1er_recibo'.
  $permissions['edit field_poliza_prima_1er_recibo'] = array(
    'name' => 'edit field_poliza_prima_1er_recibo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_prima_neta'.
  $permissions['edit field_poliza_prima_neta'] = array(
    'name' => 'edit field_poliza_prima_neta',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_prima_total'.
  $permissions['edit field_poliza_prima_total'] = array(
    'name' => 'edit field_poliza_prima_total',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_primas_recibos_subs'.
  $permissions['edit field_poliza_primas_recibos_subs'] = array(
    'name' => 'edit field_poliza_primas_recibos_subs',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_reduccion'.
  $permissions['edit field_poliza_reduccion'] = array(
    'name' => 'edit field_poliza_reduccion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_rgo_pago_fracc'.
  $permissions['edit field_poliza_rgo_pago_fracc'] = array(
    'name' => 'edit field_poliza_rgo_pago_fracc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_status'.
  $permissions['edit field_poliza_status'] = array(
    'name' => 'edit field_poliza_status',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_poliza_vigencia'.
  $permissions['edit field_poliza_vigencia'] = array(
    'name' => 'edit field_poliza_vigencia',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_primer_pago_rc'.
  $permissions['edit field_primer_pago_rc'] = array(
    'name' => 'edit field_primer_pago_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_propietario_domicilio'.
  $permissions['edit field_propietario_domicilio'] = array(
    'name' => 'edit field_propietario_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_propietario_nombre'.
  $permissions['edit field_propietario_nombre'] = array(
    'name' => 'edit field_propietario_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_propietario_telefono'.
  $permissions['edit field_propietario_telefono'] = array(
    'name' => 'edit field_propietario_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_proveedores'.
  $permissions['edit field_proveedores'] = array(
    'name' => 'edit field_proveedores',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_rc_viajero'.
  $permissions['edit field_rc_viajero'] = array(
    'name' => 'edit field_rc_viajero',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_reserva_total'.
  $permissions['edit field_reserva_total'] = array(
    'name' => 'edit field_reserva_total',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_resp_civil'.
  $permissions['edit field_resp_civil'] = array(
    'name' => 'edit field_resp_civil',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_rfc'.
  $permissions['edit field_rfc'] = array(
    'name' => 'edit field_rfc',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_robo'.
  $permissions['edit field_robo'] = array(
    'name' => 'edit field_robo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_serie_rc'.
  $permissions['edit field_serie_rc'] = array(
    'name' => 'edit field_serie_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_siniestro_archivo'.
  $permissions['edit field_siniestro_archivo'] = array(
    'name' => 'edit field_siniestro_archivo',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_status_sinister'.
  $permissions['edit field_status_sinister'] = array(
    'name' => 'edit field_status_sinister',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_taller'.
  $permissions['edit field_taller'] = array(
    'name' => 'edit field_taller',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_telefono'.
  $permissions['edit field_telefono'] = array(
    'name' => 'edit field_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_telefono_quien_reporta'.
  $permissions['edit field_telefono_quien_reporta'] = array(
    'name' => 'edit field_telefono_quien_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_uso_vehiculo'.
  $permissions['edit field_uso_vehiculo'] = array(
    'name' => 'edit field_uso_vehiculo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_usuario_de_cancelado'.
  $permissions['edit field_usuario_de_cancelado'] = array(
    'name' => 'edit field_usuario_de_cancelado',
    'roles' => array(
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_usuario_de_pagado'.
  $permissions['edit field_usuario_de_pagado'] = array(
    'name' => 'edit field_usuario_de_pagado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_capacidad'.
  $permissions['edit field_vehiculo_capacidad'] = array(
    'name' => 'edit field_vehiculo_capacidad',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_carroceria'.
  $permissions['edit field_vehiculo_carroceria'] = array(
    'name' => 'edit field_vehiculo_carroceria',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_carroceria_select'.
  $permissions['edit field_vehiculo_carroceria_select'] = array(
    'name' => 'edit field_vehiculo_carroceria_select',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_categoria'.
  $permissions['edit field_vehiculo_categoria'] = array(
    'name' => 'edit field_vehiculo_categoria',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_cilindros'.
  $permissions['edit field_vehiculo_cilindros'] = array(
    'name' => 'edit field_vehiculo_cilindros',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_clave_sbg'.
  $permissions['edit field_vehiculo_clave_sbg'] = array(
    'name' => 'edit field_vehiculo_clave_sbg',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_color'.
  $permissions['edit field_vehiculo_color'] = array(
    'name' => 'edit field_vehiculo_color',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_descripcion'.
  $permissions['edit field_vehiculo_descripcion'] = array(
    'name' => 'edit field_vehiculo_descripcion',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_descripcion_carga'.
  $permissions['edit field_vehiculo_descripcion_carga'] = array(
    'name' => 'edit field_vehiculo_descripcion_carga',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_marca'.
  $permissions['edit field_vehiculo_marca'] = array(
    'name' => 'edit field_vehiculo_marca',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_modelo'.
  $permissions['edit field_vehiculo_modelo'] = array(
    'name' => 'edit field_vehiculo_modelo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_motor'.
  $permissions['edit field_vehiculo_motor'] = array(
    'name' => 'edit field_vehiculo_motor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_numero_inventario'.
  $permissions['edit field_vehiculo_numero_inventario'] = array(
    'name' => 'edit field_vehiculo_numero_inventario',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_numero_pedimento'.
  $permissions['edit field_vehiculo_numero_pedimento'] = array(
    'name' => 'edit field_vehiculo_numero_pedimento',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_placas'.
  $permissions['edit field_vehiculo_placas'] = array(
    'name' => 'edit field_vehiculo_placas',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_referencia'.
  $permissions['edit field_vehiculo_referencia'] = array(
    'name' => 'edit field_vehiculo_referencia',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_remolque'.
  $permissions['edit field_vehiculo_remolque'] = array(
    'name' => 'edit field_vehiculo_remolque',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_serie'.
  $permissions['edit field_vehiculo_serie'] = array(
    'name' => 'edit field_vehiculo_serie',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_servicio'.
  $permissions['edit field_vehiculo_servicio'] = array(
    'name' => 'edit field_vehiculo_servicio',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_submarca'.
  $permissions['edit field_vehiculo_submarca'] = array(
    'name' => 'edit field_vehiculo_submarca',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_tercero'.
  $permissions['edit field_vehiculo_tercero'] = array(
    'name' => 'edit field_vehiculo_tercero',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_tipo'.
  $permissions['edit field_vehiculo_tipo'] = array(
    'name' => 'edit field_vehiculo_tipo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_tipo_carga'.
  $permissions['edit field_vehiculo_tipo_carga'] = array(
    'name' => 'edit field_vehiculo_tipo_carga',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_tipo_remolque'.
  $permissions['edit field_vehiculo_tipo_remolque'] = array(
    'name' => 'edit field_vehiculo_tipo_remolque',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_tonelaje'.
  $permissions['edit field_vehiculo_tonelaje'] = array(
    'name' => 'edit field_vehiculo_tonelaje',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_transmision'.
  $permissions['edit field_vehiculo_transmision'] = array(
    'name' => 'edit field_vehiculo_transmision',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vehiculo_uso'.
  $permissions['edit field_vehiculo_uso'] = array(
    'name' => 'edit field_vehiculo_uso',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_vencimiento_rc'.
  $permissions['edit field_vencimiento_rc'] = array(
    'name' => 'edit field_vencimiento_rc',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_visualizador'.
  $permissions['edit field_visualizador'] = array(
    'name' => 'edit field_visualizador',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own field_3ro_ajustador'.
  $permissions['edit own field_3ro_ajustador'] = array(
    'name' => 'edit own field_3ro_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_aseguradora'.
  $permissions['edit own field_3ro_aseguradora'] = array(
    'name' => 'edit own field_3ro_aseguradora',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_cobertura'.
  $permissions['edit own field_3ro_cobertura'] = array(
    'name' => 'edit own field_3ro_cobertura',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_deducible'.
  $permissions['edit own field_3ro_deducible'] = array(
    'name' => 'edit own field_3ro_deducible',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_numero_poliza'.
  $permissions['edit own field_3ro_numero_poliza'] = array(
    'name' => 'edit own field_3ro_numero_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_siniestro'.
  $permissions['edit own field_3ro_siniestro'] = array(
    'name' => 'edit own field_3ro_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_vehiculo_color'.
  $permissions['edit own field_3ro_vehiculo_color'] = array(
    'name' => 'edit own field_3ro_vehiculo_color',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_vehiculo_danos'.
  $permissions['edit own field_3ro_vehiculo_danos'] = array(
    'name' => 'edit own field_3ro_vehiculo_danos',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_vehiculo_modelo'.
  $permissions['edit own field_3ro_vehiculo_modelo'] = array(
    'name' => 'edit own field_3ro_vehiculo_modelo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_vehiculo_placas'.
  $permissions['edit own field_3ro_vehiculo_placas'] = array(
    'name' => 'edit own field_3ro_vehiculo_placas',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_vehiculo_serie'.
  $permissions['edit own field_3ro_vehiculo_serie'] = array(
    'name' => 'edit own field_3ro_vehiculo_serie',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_3ro_vencimiento'.
  $permissions['edit own field_3ro_vencimiento'] = array(
    'name' => 'edit own field_3ro_vencimiento',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_abogado'.
  $permissions['edit own field_abogado'] = array(
    'name' => 'edit own field_abogado',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ajustador'.
  $permissions['edit own field_ajustador'] = array(
    'name' => 'edit own field_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_archivo_autor'.
  $permissions['edit own field_archivo_autor'] = array(
    'name' => 'edit own field_archivo_autor',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_archivo_categoria'.
  $permissions['edit own field_archivo_categoria'] = array(
    'name' => 'edit own field_archivo_categoria',
    'roles' => array(
      'administrador' => 'administrador',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_archivo_comentario'.
  $permissions['edit own field_archivo_comentario'] = array(
    'name' => 'edit own field_archivo_comentario',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asegurado_benef_pref'.
  $permissions['edit own field_asegurado_benef_pref'] = array(
    'name' => 'edit own field_asegurado_benef_pref',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asegurado_domicilio'.
  $permissions['edit own field_asegurado_domicilio'] = array(
    'name' => 'edit own field_asegurado_domicilio',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asegurado_io'.
  $permissions['edit own field_asegurado_io'] = array(
    'name' => 'edit own field_asegurado_io',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asegurado_nombre'.
  $permissions['edit own field_asegurado_nombre'] = array(
    'name' => 'edit own field_asegurado_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asegurado_rfc'.
  $permissions['edit own field_asegurado_rfc'] = array(
    'name' => 'edit own field_asegurado_rfc',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asegurado_telefono'.
  $permissions['edit own field_asegurado_telefono'] = array(
    'name' => 'edit own field_asegurado_telefono',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_asignar_promotor'.
  $permissions['edit own field_asignar_promotor'] = array(
    'name' => 'edit own field_asignar_promotor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_codigo_de_barras_rc'.
  $permissions['edit own field_codigo_de_barras_rc'] = array(
    'name' => 'edit own field_codigo_de_barras_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_comentarios_de_siniestro'.
  $permissions['edit own field_comentarios_de_siniestro'] = array(
    'name' => 'edit own field_comentarios_de_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conductor'.
  $permissions['edit own field_conductor'] = array(
    'name' => 'edit own field_conductor',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conductor_domicilio'.
  $permissions['edit own field_conductor_domicilio'] = array(
    'name' => 'edit own field_conductor_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conductor_es_propietario'.
  $permissions['edit own field_conductor_es_propietario'] = array(
    'name' => 'edit own field_conductor_es_propietario',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conductor_nombre'.
  $permissions['edit own field_conductor_nombre'] = array(
    'name' => 'edit own field_conductor_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conductor_reporta'.
  $permissions['edit own field_conductor_reporta'] = array(
    'name' => 'edit own field_conductor_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conductor_telefono'.
  $permissions['edit own field_conductor_telefono'] = array(
    'name' => 'edit own field_conductor_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_danos_materiales'.
  $permissions['edit own field_danos_materiales'] = array(
    'name' => 'edit own field_danos_materiales',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_derecho_de_poliza2'.
  $permissions['edit own field_derecho_de_poliza2'] = array(
    'name' => 'edit own field_derecho_de_poliza2',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_documentos'.
  $permissions['edit own field_documentos'] = array(
    'name' => 'edit own field_documentos',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_domicilio'.
  $permissions['edit own field_domicilio'] = array(
    'name' => 'edit own field_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_emision_recibo_ref_rc'.
  $permissions['edit own field_emision_recibo_ref_rc'] = array(
    'name' => 'edit own field_emision_recibo_ref_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_estado_single'.
  $permissions['edit own field_estado_single'] = array(
    'name' => 'edit own field_estado_single',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fecha'.
  $permissions['edit own field_fecha'] = array(
    'name' => 'edit own field_fecha',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fecha_arribo'.
  $permissions['edit own field_fecha_arribo'] = array(
    'name' => 'edit own field_fecha_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fecha_de_cancelacion'.
  $permissions['edit own field_fecha_de_cancelacion'] = array(
    'name' => 'edit own field_fecha_de_cancelacion',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fecha_de_expedicion_rc'.
  $permissions['edit own field_fecha_de_expedicion_rc'] = array(
    'name' => 'edit own field_fecha_de_expedicion_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_fecha_de_pagado'.
  $permissions['edit own field_fecha_de_pagado'] = array(
    'name' => 'edit own field_fecha_de_pagado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ficha_de_pago'.
  $permissions['edit own field_ficha_de_pago'] = array(
    'name' => 'edit own field_ficha_de_pago',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_gastos_medicos'.
  $permissions['edit own field_gastos_medicos'] = array(
    'name' => 'edit own field_gastos_medicos',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_grua'.
  $permissions['edit own field_grua'] = array(
    'name' => 'edit own field_grua',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_hospital'.
  $permissions['edit own field_hospital'] = array(
    'name' => 'edit own field_hospital',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_importe_con_letra_rc'.
  $permissions['edit own field_importe_con_letra_rc'] = array(
    'name' => 'edit own field_importe_con_letra_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_informe'.
  $permissions['edit own field_informe'] = array(
    'name' => 'edit own field_informe',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado'.
  $permissions['edit own field_lesionado'] = array(
    'name' => 'edit own field_lesionado',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_ambulancia'.
  $permissions['edit own field_lesionado_ambulancia'] = array(
    'name' => 'edit own field_lesionado_ambulancia',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_ambulancia_info'.
  $permissions['edit own field_lesionado_ambulancia_info'] = array(
    'name' => 'edit own field_lesionado_ambulancia_info',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_domicilio'.
  $permissions['edit own field_lesionado_domicilio'] = array(
    'name' => 'edit own field_lesionado_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_edad'.
  $permissions['edit own field_lesionado_edad'] = array(
    'name' => 'edit own field_lesionado_edad',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_lesiones'.
  $permissions['edit own field_lesionado_lesiones'] = array(
    'name' => 'edit own field_lesionado_lesiones',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_nombre'.
  $permissions['edit own field_lesionado_nombre'] = array(
    'name' => 'edit own field_lesionado_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_pase_medico'.
  $permissions['edit own field_lesionado_pase_medico'] = array(
    'name' => 'edit own field_lesionado_pase_medico',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_riesgo_b'.
  $permissions['edit own field_lesionado_riesgo_b'] = array(
    'name' => 'edit own field_lesionado_riesgo_b',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lesionado_telefono'.
  $permissions['edit own field_lesionado_telefono'] = array(
    'name' => 'edit own field_lesionado_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_licencia_alta_fecha'.
  $permissions['edit own field_licencia_alta_fecha'] = array(
    'name' => 'edit own field_licencia_alta_fecha',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_licencia_alta_lugar'.
  $permissions['edit own field_licencia_alta_lugar'] = array(
    'name' => 'edit own field_licencia_alta_lugar',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_licencia_numero'.
  $permissions['edit own field_licencia_numero'] = array(
    'name' => 'edit own field_licencia_numero',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_licencia_tipo'.
  $permissions['edit own field_licencia_tipo'] = array(
    'name' => 'edit own field_licencia_tipo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lugar_atencion'.
  $permissions['edit own field_lugar_atencion'] = array(
    'name' => 'edit own field_lugar_atencion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_lugar_referencias'.
  $permissions['edit own field_lugar_referencias'] = array(
    'name' => 'edit own field_lugar_referencias',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_mapa_arribo'.
  $permissions['edit own field_mapa_arribo'] = array(
    'name' => 'edit own field_mapa_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_mapa_siniestro'.
  $permissions['edit own field_mapa_siniestro'] = array(
    'name' => 'edit own field_mapa_siniestro',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_motivos_de_cancelacion'.
  $permissions['edit own field_motivos_de_cancelacion'] = array(
    'name' => 'edit own field_motivos_de_cancelacion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_nombre'.
  $permissions['edit own field_nombre'] = array(
    'name' => 'edit own field_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_nombre_quien_reporta'.
  $permissions['edit own field_nombre_quien_reporta'] = array(
    'name' => 'edit own field_nombre_quien_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pago_fraccionado'.
  $permissions['edit own field_pago_fraccionado'] = array(
    'name' => 'edit own field_pago_fraccionado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_pago_subsecuente_rc'.
  $permissions['edit own field_pago_subsecuente_rc'] = array(
    'name' => 'edit own field_pago_subsecuente_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_periodo_cobertura_rc'.
  $permissions['edit own field_periodo_cobertura_rc'] = array(
    'name' => 'edit own field_periodo_cobertura_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_periodo_de_gracia'.
  $permissions['edit own field_periodo_de_gracia'] = array(
    'name' => 'edit own field_periodo_de_gracia',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_plz_vehiculo_marca'.
  $permissions['edit own field_plz_vehiculo_marca'] = array(
    'name' => 'edit own field_plz_vehiculo_marca',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poblacion'.
  $permissions['edit own field_poblacion'] = array(
    'name' => 'edit own field_poblacion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza'.
  $permissions['edit own field_poliza'] = array(
    'name' => 'edit own field_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_coberturas'.
  $permissions['edit own field_poliza_coberturas'] = array(
    'name' => 'edit own field_poliza_coberturas',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_comentarios'.
  $permissions['edit own field_poliza_comentarios'] = array(
    'name' => 'edit own field_poliza_comentarios',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_derecho_poliza'.
  $permissions['edit own field_poliza_derecho_poliza'] = array(
    'name' => 'edit own field_poliza_derecho_poliza',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_emision'.
  $permissions['edit own field_poliza_emision'] = array(
    'name' => 'edit own field_poliza_emision',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_forma_pago'.
  $permissions['edit own field_poliza_forma_pago'] = array(
    'name' => 'edit own field_poliza_forma_pago',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_impuesto_iva'.
  $permissions['edit own field_poliza_impuesto_iva'] = array(
    'name' => 'edit own field_poliza_impuesto_iva',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_moneda'.
  $permissions['edit own field_poliza_moneda'] = array(
    'name' => 'edit own field_poliza_moneda',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_oficina'.
  $permissions['edit own field_poliza_oficina'] = array(
    'name' => 'edit own field_poliza_oficina',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_prima_1er_recibo'.
  $permissions['edit own field_poliza_prima_1er_recibo'] = array(
    'name' => 'edit own field_poliza_prima_1er_recibo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_prima_neta'.
  $permissions['edit own field_poliza_prima_neta'] = array(
    'name' => 'edit own field_poliza_prima_neta',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_prima_total'.
  $permissions['edit own field_poliza_prima_total'] = array(
    'name' => 'edit own field_poliza_prima_total',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_primas_recibos_subs'.
  $permissions['edit own field_poliza_primas_recibos_subs'] = array(
    'name' => 'edit own field_poliza_primas_recibos_subs',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_reduccion'.
  $permissions['edit own field_poliza_reduccion'] = array(
    'name' => 'edit own field_poliza_reduccion',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_rgo_pago_fracc'.
  $permissions['edit own field_poliza_rgo_pago_fracc'] = array(
    'name' => 'edit own field_poliza_rgo_pago_fracc',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_status'.
  $permissions['edit own field_poliza_status'] = array(
    'name' => 'edit own field_poliza_status',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_poliza_vigencia'.
  $permissions['edit own field_poliza_vigencia'] = array(
    'name' => 'edit own field_poliza_vigencia',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_primer_pago_rc'.
  $permissions['edit own field_primer_pago_rc'] = array(
    'name' => 'edit own field_primer_pago_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_propietario_domicilio'.
  $permissions['edit own field_propietario_domicilio'] = array(
    'name' => 'edit own field_propietario_domicilio',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_propietario_nombre'.
  $permissions['edit own field_propietario_nombre'] = array(
    'name' => 'edit own field_propietario_nombre',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_propietario_telefono'.
  $permissions['edit own field_propietario_telefono'] = array(
    'name' => 'edit own field_propietario_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_proveedores'.
  $permissions['edit own field_proveedores'] = array(
    'name' => 'edit own field_proveedores',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rc_viajero'.
  $permissions['edit own field_rc_viajero'] = array(
    'name' => 'edit own field_rc_viajero',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_reserva_total'.
  $permissions['edit own field_reserva_total'] = array(
    'name' => 'edit own field_reserva_total',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_resp_civil'.
  $permissions['edit own field_resp_civil'] = array(
    'name' => 'edit own field_resp_civil',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rfc'.
  $permissions['edit own field_rfc'] = array(
    'name' => 'edit own field_rfc',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_robo'.
  $permissions['edit own field_robo'] = array(
    'name' => 'edit own field_robo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_serie_rc'.
  $permissions['edit own field_serie_rc'] = array(
    'name' => 'edit own field_serie_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_siniestro_archivo'.
  $permissions['edit own field_siniestro_archivo'] = array(
    'name' => 'edit own field_siniestro_archivo',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'taller' => 'taller',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_status_sinister'.
  $permissions['edit own field_status_sinister'] = array(
    'name' => 'edit own field_status_sinister',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_taller'.
  $permissions['edit own field_taller'] = array(
    'name' => 'edit own field_taller',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_telefono'.
  $permissions['edit own field_telefono'] = array(
    'name' => 'edit own field_telefono',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_telefono_quien_reporta'.
  $permissions['edit own field_telefono_quien_reporta'] = array(
    'name' => 'edit own field_telefono_quien_reporta',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_uso_vehiculo'.
  $permissions['edit own field_uso_vehiculo'] = array(
    'name' => 'edit own field_uso_vehiculo',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_usuario_de_cancelado'.
  $permissions['edit own field_usuario_de_cancelado'] = array(
    'name' => 'edit own field_usuario_de_cancelado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_usuario_de_pagado'.
  $permissions['edit own field_usuario_de_pagado'] = array(
    'name' => 'edit own field_usuario_de_pagado',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_capacidad'.
  $permissions['edit own field_vehiculo_capacidad'] = array(
    'name' => 'edit own field_vehiculo_capacidad',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_carroceria'.
  $permissions['edit own field_vehiculo_carroceria'] = array(
    'name' => 'edit own field_vehiculo_carroceria',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_carroceria_select'.
  $permissions['edit own field_vehiculo_carroceria_select'] = array(
    'name' => 'edit own field_vehiculo_carroceria_select',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_categoria'.
  $permissions['edit own field_vehiculo_categoria'] = array(
    'name' => 'edit own field_vehiculo_categoria',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_cilindros'.
  $permissions['edit own field_vehiculo_cilindros'] = array(
    'name' => 'edit own field_vehiculo_cilindros',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_clave_sbg'.
  $permissions['edit own field_vehiculo_clave_sbg'] = array(
    'name' => 'edit own field_vehiculo_clave_sbg',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_color'.
  $permissions['edit own field_vehiculo_color'] = array(
    'name' => 'edit own field_vehiculo_color',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_descripcion'.
  $permissions['edit own field_vehiculo_descripcion'] = array(
    'name' => 'edit own field_vehiculo_descripcion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_descripcion_carga'.
  $permissions['edit own field_vehiculo_descripcion_carga'] = array(
    'name' => 'edit own field_vehiculo_descripcion_carga',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_marca'.
  $permissions['edit own field_vehiculo_marca'] = array(
    'name' => 'edit own field_vehiculo_marca',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_modelo'.
  $permissions['edit own field_vehiculo_modelo'] = array(
    'name' => 'edit own field_vehiculo_modelo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_motor'.
  $permissions['edit own field_vehiculo_motor'] = array(
    'name' => 'edit own field_vehiculo_motor',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_numero_inventario'.
  $permissions['edit own field_vehiculo_numero_inventario'] = array(
    'name' => 'edit own field_vehiculo_numero_inventario',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_numero_pedimento'.
  $permissions['edit own field_vehiculo_numero_pedimento'] = array(
    'name' => 'edit own field_vehiculo_numero_pedimento',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_placas'.
  $permissions['edit own field_vehiculo_placas'] = array(
    'name' => 'edit own field_vehiculo_placas',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_referencia'.
  $permissions['edit own field_vehiculo_referencia'] = array(
    'name' => 'edit own field_vehiculo_referencia',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_remolque'.
  $permissions['edit own field_vehiculo_remolque'] = array(
    'name' => 'edit own field_vehiculo_remolque',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_serie'.
  $permissions['edit own field_vehiculo_serie'] = array(
    'name' => 'edit own field_vehiculo_serie',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_servicio'.
  $permissions['edit own field_vehiculo_servicio'] = array(
    'name' => 'edit own field_vehiculo_servicio',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_submarca'.
  $permissions['edit own field_vehiculo_submarca'] = array(
    'name' => 'edit own field_vehiculo_submarca',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_tercero'.
  $permissions['edit own field_vehiculo_tercero'] = array(
    'name' => 'edit own field_vehiculo_tercero',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_tipo'.
  $permissions['edit own field_vehiculo_tipo'] = array(
    'name' => 'edit own field_vehiculo_tipo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_tipo_carga'.
  $permissions['edit own field_vehiculo_tipo_carga'] = array(
    'name' => 'edit own field_vehiculo_tipo_carga',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_tipo_remolque'.
  $permissions['edit own field_vehiculo_tipo_remolque'] = array(
    'name' => 'edit own field_vehiculo_tipo_remolque',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_tonelaje'.
  $permissions['edit own field_vehiculo_tonelaje'] = array(
    'name' => 'edit own field_vehiculo_tonelaje',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_transmision'.
  $permissions['edit own field_vehiculo_transmision'] = array(
    'name' => 'edit own field_vehiculo_transmision',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vehiculo_uso'.
  $permissions['edit own field_vehiculo_uso'] = array(
    'name' => 'edit own field_vehiculo_uso',
    'roles' => array(
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_vencimiento_rc'.
  $permissions['edit own field_vencimiento_rc'] = array(
    'name' => 'edit own field_vencimiento_rc',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_visualizador'.
  $permissions['edit own field_visualizador'] = array(
    'name' => 'edit own field_visualizador',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own home_blocks content'.
  $permissions['edit own home_blocks content'] = array(
    'name' => 'edit own home_blocks content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own legal content'.
  $permissions['edit own legal content'] = array(
    'name' => 'edit own legal content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own poliza content'.
  $permissions['edit own poliza content'] = array(
    'name' => 'edit own poliza content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own poliza_tipo content'.
  $permissions['edit own poliza_tipo content'] = array(
    'name' => 'edit own poliza_tipo content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own recibo_contrato content'.
  $permissions['edit own recibo_contrato content'] = array(
    'name' => 'edit own recibo_contrato content',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'agente de ventas' => 'agente de ventas',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own siniestro content'.
  $permissions['edit own siniestro content'] = array(
    'name' => 'edit own siniestro content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own slideshow content'.
  $permissions['edit own slideshow content'] = array(
    'name' => 'edit own slideshow content',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in ajustador'.
  $permissions['edit terms in ajustador'] = array(
    'name' => 'edit terms in ajustador',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in archivos'.
  $permissions['edit terms in archivos'] = array(
    'name' => 'edit terms in archivos',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in aseguradora'.
  $permissions['edit terms in aseguradora'] = array(
    'name' => 'edit terms in aseguradora',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in carroceria'.
  $permissions['edit terms in carroceria'] = array(
    'name' => 'edit terms in carroceria',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in carrusel'.
  $permissions['edit terms in carrusel'] = array(
    'name' => 'edit terms in carrusel',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in licencia_tipo'.
  $permissions['edit terms in licencia_tipo'] = array(
    'name' => 'edit terms in licencia_tipo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in lugar'.
  $permissions['edit terms in lugar'] = array(
    'name' => 'edit terms in lugar',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in marca'.
  $permissions['edit terms in marca'] = array(
    'name' => 'edit terms in marca',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in motivos_de_cancelacion'.
  $permissions['edit terms in motivos_de_cancelacion'] = array(
    'name' => 'edit terms in motivos_de_cancelacion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in promotor'.
  $permissions['edit terms in promotor'] = array(
    'name' => 'edit terms in promotor',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in states'.
  $permissions['edit terms in states'] = array(
    'name' => 'edit terms in states',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in submarca'.
  $permissions['edit terms in submarca'] = array(
    'name' => 'edit terms in submarca',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in vehiculo_color'.
  $permissions['edit terms in vehiculo_color'] = array(
    'name' => 'edit terms in vehiculo_color',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in vehiculo_descripcion'.
  $permissions['edit terms in vehiculo_descripcion'] = array(
    'name' => 'edit terms in vehiculo_descripcion',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in vehiculo_tipo'.
  $permissions['edit terms in vehiculo_tipo'] = array(
    'name' => 'edit terms in vehiculo_tipo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'export nodes'.
  $permissions['export nodes'] = array(
    'name' => 'export nodes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'export own nodes'.
  $permissions['export own nodes'] = array(
    'name' => 'export own nodes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'geocoder_service_all_handlers'.
  $permissions['geocoder_service_all_handlers'] = array(
    'name' => 'geocoder_service_all_handlers',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_exif'.
  $permissions['geocoder_service_handler_exif'] = array(
    'name' => 'geocoder_service_handler_exif',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_google'.
  $permissions['geocoder_service_handler_google'] = array(
    'name' => 'geocoder_service_handler_google',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_gpx'.
  $permissions['geocoder_service_handler_gpx'] = array(
    'name' => 'geocoder_service_handler_gpx',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_json'.
  $permissions['geocoder_service_handler_json'] = array(
    'name' => 'geocoder_service_handler_json',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_kml'.
  $permissions['geocoder_service_handler_kml'] = array(
    'name' => 'geocoder_service_handler_kml',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_latlon'.
  $permissions['geocoder_service_handler_latlon'] = array(
    'name' => 'geocoder_service_handler_latlon',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_mapquest_nominatim'.
  $permissions['geocoder_service_handler_mapquest_nominatim'] = array(
    'name' => 'geocoder_service_handler_mapquest_nominatim',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_wkt'.
  $permissions['geocoder_service_handler_wkt'] = array(
    'name' => 'geocoder_service_handler_wkt',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_yahoo'.
  $permissions['geocoder_service_handler_yahoo'] = array(
    'name' => 'geocoder_service_handler_yahoo',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_yandex'.
  $permissions['geocoder_service_handler_yandex'] = array(
    'name' => 'geocoder_service_handler_yandex',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'geocoder',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'print_ui',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'services',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrador' => 'administrador',
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use PHP to import nodes'.
  $permissions['use PHP to import nodes'] = array(
    'name' => 'use PHP to import nodes',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format true_full_html'.
  $permissions['use text format true_full_html'] = array(
    'name' => 'use text format true_full_html',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view field_3ro_ajustador'.
  $permissions['view field_3ro_ajustador'] = array(
    'name' => 'view field_3ro_ajustador',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_aseguradora'.
  $permissions['view field_3ro_aseguradora'] = array(
    'name' => 'view field_3ro_aseguradora',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_cobertura'.
  $permissions['view field_3ro_cobertura'] = array(
    'name' => 'view field_3ro_cobertura',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_deducible'.
  $permissions['view field_3ro_deducible'] = array(
    'name' => 'view field_3ro_deducible',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_numero_poliza'.
  $permissions['view field_3ro_numero_poliza'] = array(
    'name' => 'view field_3ro_numero_poliza',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_siniestro'.
  $permissions['view field_3ro_siniestro'] = array(
    'name' => 'view field_3ro_siniestro',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_vehiculo_color'.
  $permissions['view field_3ro_vehiculo_color'] = array(
    'name' => 'view field_3ro_vehiculo_color',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_vehiculo_danos'.
  $permissions['view field_3ro_vehiculo_danos'] = array(
    'name' => 'view field_3ro_vehiculo_danos',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_vehiculo_modelo'.
  $permissions['view field_3ro_vehiculo_modelo'] = array(
    'name' => 'view field_3ro_vehiculo_modelo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_vehiculo_placas'.
  $permissions['view field_3ro_vehiculo_placas'] = array(
    'name' => 'view field_3ro_vehiculo_placas',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_vehiculo_serie'.
  $permissions['view field_3ro_vehiculo_serie'] = array(
    'name' => 'view field_3ro_vehiculo_serie',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_3ro_vencimiento'.
  $permissions['view field_3ro_vencimiento'] = array(
    'name' => 'view field_3ro_vencimiento',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_abogado'.
  $permissions['view field_abogado'] = array(
    'name' => 'view field_abogado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ajustador'.
  $permissions['view field_ajustador'] = array(
    'name' => 'view field_ajustador',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_archivo_autor'.
  $permissions['view field_archivo_autor'] = array(
    'name' => 'view field_archivo_autor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_archivo_categoria'.
  $permissions['view field_archivo_categoria'] = array(
    'name' => 'view field_archivo_categoria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_archivo_comentario'.
  $permissions['view field_archivo_comentario'] = array(
    'name' => 'view field_archivo_comentario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asegurado_benef_pref'.
  $permissions['view field_asegurado_benef_pref'] = array(
    'name' => 'view field_asegurado_benef_pref',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asegurado_domicilio'.
  $permissions['view field_asegurado_domicilio'] = array(
    'name' => 'view field_asegurado_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asegurado_io'.
  $permissions['view field_asegurado_io'] = array(
    'name' => 'view field_asegurado_io',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asegurado_nombre'.
  $permissions['view field_asegurado_nombre'] = array(
    'name' => 'view field_asegurado_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asegurado_rfc'.
  $permissions['view field_asegurado_rfc'] = array(
    'name' => 'view field_asegurado_rfc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asegurado_telefono'.
  $permissions['view field_asegurado_telefono'] = array(
    'name' => 'view field_asegurado_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_asignar_promotor'.
  $permissions['view field_asignar_promotor'] = array(
    'name' => 'view field_asignar_promotor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_codigo_de_barras_rc'.
  $permissions['view field_codigo_de_barras_rc'] = array(
    'name' => 'view field_codigo_de_barras_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_comentarios_de_siniestro'.
  $permissions['view field_comentarios_de_siniestro'] = array(
    'name' => 'view field_comentarios_de_siniestro',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conductor'.
  $permissions['view field_conductor'] = array(
    'name' => 'view field_conductor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conductor_domicilio'.
  $permissions['view field_conductor_domicilio'] = array(
    'name' => 'view field_conductor_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conductor_es_propietario'.
  $permissions['view field_conductor_es_propietario'] = array(
    'name' => 'view field_conductor_es_propietario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conductor_nombre'.
  $permissions['view field_conductor_nombre'] = array(
    'name' => 'view field_conductor_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conductor_reporta'.
  $permissions['view field_conductor_reporta'] = array(
    'name' => 'view field_conductor_reporta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conductor_telefono'.
  $permissions['view field_conductor_telefono'] = array(
    'name' => 'view field_conductor_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_danos_materiales'.
  $permissions['view field_danos_materiales'] = array(
    'name' => 'view field_danos_materiales',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_derecho_de_poliza2'.
  $permissions['view field_derecho_de_poliza2'] = array(
    'name' => 'view field_derecho_de_poliza2',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_documentos'.
  $permissions['view field_documentos'] = array(
    'name' => 'view field_documentos',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_domicilio'.
  $permissions['view field_domicilio'] = array(
    'name' => 'view field_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_emision_recibo_ref_rc'.
  $permissions['view field_emision_recibo_ref_rc'] = array(
    'name' => 'view field_emision_recibo_ref_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_estado_single'.
  $permissions['view field_estado_single'] = array(
    'name' => 'view field_estado_single',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fecha'.
  $permissions['view field_fecha'] = array(
    'name' => 'view field_fecha',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fecha_arribo'.
  $permissions['view field_fecha_arribo'] = array(
    'name' => 'view field_fecha_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fecha_de_cancelacion'.
  $permissions['view field_fecha_de_cancelacion'] = array(
    'name' => 'view field_fecha_de_cancelacion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fecha_de_expedicion_rc'.
  $permissions['view field_fecha_de_expedicion_rc'] = array(
    'name' => 'view field_fecha_de_expedicion_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fecha_de_pagado'.
  $permissions['view field_fecha_de_pagado'] = array(
    'name' => 'view field_fecha_de_pagado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ficha_de_pago'.
  $permissions['view field_ficha_de_pago'] = array(
    'name' => 'view field_ficha_de_pago',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_gastos_medicos'.
  $permissions['view field_gastos_medicos'] = array(
    'name' => 'view field_gastos_medicos',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_grua'.
  $permissions['view field_grua'] = array(
    'name' => 'view field_grua',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_hospital'.
  $permissions['view field_hospital'] = array(
    'name' => 'view field_hospital',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_importe_con_letra_rc'.
  $permissions['view field_importe_con_letra_rc'] = array(
    'name' => 'view field_importe_con_letra_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_informe'.
  $permissions['view field_informe'] = array(
    'name' => 'view field_informe',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado'.
  $permissions['view field_lesionado'] = array(
    'name' => 'view field_lesionado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_ambulancia'.
  $permissions['view field_lesionado_ambulancia'] = array(
    'name' => 'view field_lesionado_ambulancia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_ambulancia_info'.
  $permissions['view field_lesionado_ambulancia_info'] = array(
    'name' => 'view field_lesionado_ambulancia_info',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_domicilio'.
  $permissions['view field_lesionado_domicilio'] = array(
    'name' => 'view field_lesionado_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_edad'.
  $permissions['view field_lesionado_edad'] = array(
    'name' => 'view field_lesionado_edad',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_lesiones'.
  $permissions['view field_lesionado_lesiones'] = array(
    'name' => 'view field_lesionado_lesiones',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_nombre'.
  $permissions['view field_lesionado_nombre'] = array(
    'name' => 'view field_lesionado_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_pase_medico'.
  $permissions['view field_lesionado_pase_medico'] = array(
    'name' => 'view field_lesionado_pase_medico',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_riesgo_b'.
  $permissions['view field_lesionado_riesgo_b'] = array(
    'name' => 'view field_lesionado_riesgo_b',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lesionado_telefono'.
  $permissions['view field_lesionado_telefono'] = array(
    'name' => 'view field_lesionado_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_licencia_alta_fecha'.
  $permissions['view field_licencia_alta_fecha'] = array(
    'name' => 'view field_licencia_alta_fecha',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_licencia_alta_lugar'.
  $permissions['view field_licencia_alta_lugar'] = array(
    'name' => 'view field_licencia_alta_lugar',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_licencia_numero'.
  $permissions['view field_licencia_numero'] = array(
    'name' => 'view field_licencia_numero',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_licencia_tipo'.
  $permissions['view field_licencia_tipo'] = array(
    'name' => 'view field_licencia_tipo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lugar_atencion'.
  $permissions['view field_lugar_atencion'] = array(
    'name' => 'view field_lugar_atencion',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_lugar_referencias'.
  $permissions['view field_lugar_referencias'] = array(
    'name' => 'view field_lugar_referencias',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_mapa_arribo'.
  $permissions['view field_mapa_arribo'] = array(
    'name' => 'view field_mapa_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_mapa_siniestro'.
  $permissions['view field_mapa_siniestro'] = array(
    'name' => 'view field_mapa_siniestro',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_motivos_de_cancelacion'.
  $permissions['view field_motivos_de_cancelacion'] = array(
    'name' => 'view field_motivos_de_cancelacion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_nombre'.
  $permissions['view field_nombre'] = array(
    'name' => 'view field_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_nombre_quien_reporta'.
  $permissions['view field_nombre_quien_reporta'] = array(
    'name' => 'view field_nombre_quien_reporta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pago_fraccionado'.
  $permissions['view field_pago_fraccionado'] = array(
    'name' => 'view field_pago_fraccionado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_pago_subsecuente_rc'.
  $permissions['view field_pago_subsecuente_rc'] = array(
    'name' => 'view field_pago_subsecuente_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_periodo_cobertura_rc'.
  $permissions['view field_periodo_cobertura_rc'] = array(
    'name' => 'view field_periodo_cobertura_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_periodo_de_gracia'.
  $permissions['view field_periodo_de_gracia'] = array(
    'name' => 'view field_periodo_de_gracia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_plz_vehiculo_marca'.
  $permissions['view field_plz_vehiculo_marca'] = array(
    'name' => 'view field_plz_vehiculo_marca',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poblacion'.
  $permissions['view field_poblacion'] = array(
    'name' => 'view field_poblacion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza'.
  $permissions['view field_poliza'] = array(
    'name' => 'view field_poliza',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_coberturas'.
  $permissions['view field_poliza_coberturas'] = array(
    'name' => 'view field_poliza_coberturas',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_comentarios'.
  $permissions['view field_poliza_comentarios'] = array(
    'name' => 'view field_poliza_comentarios',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_derecho_poliza'.
  $permissions['view field_poliza_derecho_poliza'] = array(
    'name' => 'view field_poliza_derecho_poliza',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_emision'.
  $permissions['view field_poliza_emision'] = array(
    'name' => 'view field_poliza_emision',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_forma_pago'.
  $permissions['view field_poliza_forma_pago'] = array(
    'name' => 'view field_poliza_forma_pago',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_impuesto_iva'.
  $permissions['view field_poliza_impuesto_iva'] = array(
    'name' => 'view field_poliza_impuesto_iva',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_moneda'.
  $permissions['view field_poliza_moneda'] = array(
    'name' => 'view field_poliza_moneda',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_oficina'.
  $permissions['view field_poliza_oficina'] = array(
    'name' => 'view field_poliza_oficina',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_prima_1er_recibo'.
  $permissions['view field_poliza_prima_1er_recibo'] = array(
    'name' => 'view field_poliza_prima_1er_recibo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_prima_neta'.
  $permissions['view field_poliza_prima_neta'] = array(
    'name' => 'view field_poliza_prima_neta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_prima_total'.
  $permissions['view field_poliza_prima_total'] = array(
    'name' => 'view field_poliza_prima_total',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_primas_recibos_subs'.
  $permissions['view field_poliza_primas_recibos_subs'] = array(
    'name' => 'view field_poliza_primas_recibos_subs',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_reduccion'.
  $permissions['view field_poliza_reduccion'] = array(
    'name' => 'view field_poliza_reduccion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_rgo_pago_fracc'.
  $permissions['view field_poliza_rgo_pago_fracc'] = array(
    'name' => 'view field_poliza_rgo_pago_fracc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_status'.
  $permissions['view field_poliza_status'] = array(
    'name' => 'view field_poliza_status',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_poliza_vigencia'.
  $permissions['view field_poliza_vigencia'] = array(
    'name' => 'view field_poliza_vigencia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_primer_pago_rc'.
  $permissions['view field_primer_pago_rc'] = array(
    'name' => 'view field_primer_pago_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_propietario_domicilio'.
  $permissions['view field_propietario_domicilio'] = array(
    'name' => 'view field_propietario_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_propietario_nombre'.
  $permissions['view field_propietario_nombre'] = array(
    'name' => 'view field_propietario_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_propietario_telefono'.
  $permissions['view field_propietario_telefono'] = array(
    'name' => 'view field_propietario_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_proveedores'.
  $permissions['view field_proveedores'] = array(
    'name' => 'view field_proveedores',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_rc_viajero'.
  $permissions['view field_rc_viajero'] = array(
    'name' => 'view field_rc_viajero',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_reserva_total'.
  $permissions['view field_reserva_total'] = array(
    'name' => 'view field_reserva_total',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_resp_civil'.
  $permissions['view field_resp_civil'] = array(
    'name' => 'view field_resp_civil',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_rfc'.
  $permissions['view field_rfc'] = array(
    'name' => 'view field_rfc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_robo'.
  $permissions['view field_robo'] = array(
    'name' => 'view field_robo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_serie_rc'.
  $permissions['view field_serie_rc'] = array(
    'name' => 'view field_serie_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_siniestro_archivo'.
  $permissions['view field_siniestro_archivo'] = array(
    'name' => 'view field_siniestro_archivo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_status_sinister'.
  $permissions['view field_status_sinister'] = array(
    'name' => 'view field_status_sinister',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_taller'.
  $permissions['view field_taller'] = array(
    'name' => 'view field_taller',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_telefono'.
  $permissions['view field_telefono'] = array(
    'name' => 'view field_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_telefono_quien_reporta'.
  $permissions['view field_telefono_quien_reporta'] = array(
    'name' => 'view field_telefono_quien_reporta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_uso_vehiculo'.
  $permissions['view field_uso_vehiculo'] = array(
    'name' => 'view field_uso_vehiculo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_usuario_de_cancelado'.
  $permissions['view field_usuario_de_cancelado'] = array(
    'name' => 'view field_usuario_de_cancelado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_usuario_de_pagado'.
  $permissions['view field_usuario_de_pagado'] = array(
    'name' => 'view field_usuario_de_pagado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_capacidad'.
  $permissions['view field_vehiculo_capacidad'] = array(
    'name' => 'view field_vehiculo_capacidad',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_carroceria'.
  $permissions['view field_vehiculo_carroceria'] = array(
    'name' => 'view field_vehiculo_carroceria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_carroceria_select'.
  $permissions['view field_vehiculo_carroceria_select'] = array(
    'name' => 'view field_vehiculo_carroceria_select',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_categoria'.
  $permissions['view field_vehiculo_categoria'] = array(
    'name' => 'view field_vehiculo_categoria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_cilindros'.
  $permissions['view field_vehiculo_cilindros'] = array(
    'name' => 'view field_vehiculo_cilindros',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_clave_sbg'.
  $permissions['view field_vehiculo_clave_sbg'] = array(
    'name' => 'view field_vehiculo_clave_sbg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_color'.
  $permissions['view field_vehiculo_color'] = array(
    'name' => 'view field_vehiculo_color',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_descripcion'.
  $permissions['view field_vehiculo_descripcion'] = array(
    'name' => 'view field_vehiculo_descripcion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_descripcion_carga'.
  $permissions['view field_vehiculo_descripcion_carga'] = array(
    'name' => 'view field_vehiculo_descripcion_carga',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_marca'.
  $permissions['view field_vehiculo_marca'] = array(
    'name' => 'view field_vehiculo_marca',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_modelo'.
  $permissions['view field_vehiculo_modelo'] = array(
    'name' => 'view field_vehiculo_modelo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_motor'.
  $permissions['view field_vehiculo_motor'] = array(
    'name' => 'view field_vehiculo_motor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_numero_inventario'.
  $permissions['view field_vehiculo_numero_inventario'] = array(
    'name' => 'view field_vehiculo_numero_inventario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_numero_pedimento'.
  $permissions['view field_vehiculo_numero_pedimento'] = array(
    'name' => 'view field_vehiculo_numero_pedimento',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_placas'.
  $permissions['view field_vehiculo_placas'] = array(
    'name' => 'view field_vehiculo_placas',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_referencia'.
  $permissions['view field_vehiculo_referencia'] = array(
    'name' => 'view field_vehiculo_referencia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_remolque'.
  $permissions['view field_vehiculo_remolque'] = array(
    'name' => 'view field_vehiculo_remolque',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_serie'.
  $permissions['view field_vehiculo_serie'] = array(
    'name' => 'view field_vehiculo_serie',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_servicio'.
  $permissions['view field_vehiculo_servicio'] = array(
    'name' => 'view field_vehiculo_servicio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_submarca'.
  $permissions['view field_vehiculo_submarca'] = array(
    'name' => 'view field_vehiculo_submarca',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_tercero'.
  $permissions['view field_vehiculo_tercero'] = array(
    'name' => 'view field_vehiculo_tercero',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_tipo'.
  $permissions['view field_vehiculo_tipo'] = array(
    'name' => 'view field_vehiculo_tipo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_tipo_carga'.
  $permissions['view field_vehiculo_tipo_carga'] = array(
    'name' => 'view field_vehiculo_tipo_carga',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_tipo_remolque'.
  $permissions['view field_vehiculo_tipo_remolque'] = array(
    'name' => 'view field_vehiculo_tipo_remolque',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_tonelaje'.
  $permissions['view field_vehiculo_tonelaje'] = array(
    'name' => 'view field_vehiculo_tonelaje',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_transmision'.
  $permissions['view field_vehiculo_transmision'] = array(
    'name' => 'view field_vehiculo_transmision',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vehiculo_uso'.
  $permissions['view field_vehiculo_uso'] = array(
    'name' => 'view field_vehiculo_uso',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_vencimiento_rc'.
  $permissions['view field_vencimiento_rc'] = array(
    'name' => 'view field_vencimiento_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_visualizador'.
  $permissions['view field_visualizador'] = array(
    'name' => 'view field_visualizador',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'abogado' => 'abogado',
      'administrador' => 'administrador',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'gruas' => 'gruas',
      'hospital' => 'hospital',
      'proveedores' => 'proveedores',
      'supervisor de siniestros' => 'supervisor de siniestros',
      'supervisor de ventas' => 'supervisor de ventas',
      'taller' => 'taller',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view hidden fields'.
  $permissions['view hidden fields'] = array(
    'name' => 'view hidden fields',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'view own field_3ro_ajustador'.
  $permissions['view own field_3ro_ajustador'] = array(
    'name' => 'view own field_3ro_ajustador',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_aseguradora'.
  $permissions['view own field_3ro_aseguradora'] = array(
    'name' => 'view own field_3ro_aseguradora',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_cobertura'.
  $permissions['view own field_3ro_cobertura'] = array(
    'name' => 'view own field_3ro_cobertura',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_deducible'.
  $permissions['view own field_3ro_deducible'] = array(
    'name' => 'view own field_3ro_deducible',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_numero_poliza'.
  $permissions['view own field_3ro_numero_poliza'] = array(
    'name' => 'view own field_3ro_numero_poliza',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_siniestro'.
  $permissions['view own field_3ro_siniestro'] = array(
    'name' => 'view own field_3ro_siniestro',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_vehiculo_color'.
  $permissions['view own field_3ro_vehiculo_color'] = array(
    'name' => 'view own field_3ro_vehiculo_color',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_vehiculo_danos'.
  $permissions['view own field_3ro_vehiculo_danos'] = array(
    'name' => 'view own field_3ro_vehiculo_danos',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_vehiculo_modelo'.
  $permissions['view own field_3ro_vehiculo_modelo'] = array(
    'name' => 'view own field_3ro_vehiculo_modelo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_vehiculo_placas'.
  $permissions['view own field_3ro_vehiculo_placas'] = array(
    'name' => 'view own field_3ro_vehiculo_placas',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_vehiculo_serie'.
  $permissions['view own field_3ro_vehiculo_serie'] = array(
    'name' => 'view own field_3ro_vehiculo_serie',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_3ro_vencimiento'.
  $permissions['view own field_3ro_vencimiento'] = array(
    'name' => 'view own field_3ro_vencimiento',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_abogado'.
  $permissions['view own field_abogado'] = array(
    'name' => 'view own field_abogado',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ajustador'.
  $permissions['view own field_ajustador'] = array(
    'name' => 'view own field_ajustador',
    'roles' => array(
      'administrador' => 'administrador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_archivo_autor'.
  $permissions['view own field_archivo_autor'] = array(
    'name' => 'view own field_archivo_autor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_archivo_categoria'.
  $permissions['view own field_archivo_categoria'] = array(
    'name' => 'view own field_archivo_categoria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_archivo_comentario'.
  $permissions['view own field_archivo_comentario'] = array(
    'name' => 'view own field_archivo_comentario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asegurado_benef_pref'.
  $permissions['view own field_asegurado_benef_pref'] = array(
    'name' => 'view own field_asegurado_benef_pref',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asegurado_domicilio'.
  $permissions['view own field_asegurado_domicilio'] = array(
    'name' => 'view own field_asegurado_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asegurado_io'.
  $permissions['view own field_asegurado_io'] = array(
    'name' => 'view own field_asegurado_io',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asegurado_nombre'.
  $permissions['view own field_asegurado_nombre'] = array(
    'name' => 'view own field_asegurado_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asegurado_rfc'.
  $permissions['view own field_asegurado_rfc'] = array(
    'name' => 'view own field_asegurado_rfc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asegurado_telefono'.
  $permissions['view own field_asegurado_telefono'] = array(
    'name' => 'view own field_asegurado_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_asignar_promotor'.
  $permissions['view own field_asignar_promotor'] = array(
    'name' => 'view own field_asignar_promotor',
    'roles' => array(
      'administrador' => 'administrador',
      'administrador comercial' => 'administrador comercial',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de ventas' => 'supervisor de ventas',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_codigo_de_barras_rc'.
  $permissions['view own field_codigo_de_barras_rc'] = array(
    'name' => 'view own field_codigo_de_barras_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_comentarios_de_siniestro'.
  $permissions['view own field_comentarios_de_siniestro'] = array(
    'name' => 'view own field_comentarios_de_siniestro',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conductor'.
  $permissions['view own field_conductor'] = array(
    'name' => 'view own field_conductor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conductor_domicilio'.
  $permissions['view own field_conductor_domicilio'] = array(
    'name' => 'view own field_conductor_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conductor_es_propietario'.
  $permissions['view own field_conductor_es_propietario'] = array(
    'name' => 'view own field_conductor_es_propietario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conductor_nombre'.
  $permissions['view own field_conductor_nombre'] = array(
    'name' => 'view own field_conductor_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conductor_reporta'.
  $permissions['view own field_conductor_reporta'] = array(
    'name' => 'view own field_conductor_reporta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conductor_telefono'.
  $permissions['view own field_conductor_telefono'] = array(
    'name' => 'view own field_conductor_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_danos_materiales'.
  $permissions['view own field_danos_materiales'] = array(
    'name' => 'view own field_danos_materiales',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_derecho_de_poliza2'.
  $permissions['view own field_derecho_de_poliza2'] = array(
    'name' => 'view own field_derecho_de_poliza2',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_documentos'.
  $permissions['view own field_documentos'] = array(
    'name' => 'view own field_documentos',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_domicilio'.
  $permissions['view own field_domicilio'] = array(
    'name' => 'view own field_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_emision_recibo_ref_rc'.
  $permissions['view own field_emision_recibo_ref_rc'] = array(
    'name' => 'view own field_emision_recibo_ref_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_estado_single'.
  $permissions['view own field_estado_single'] = array(
    'name' => 'view own field_estado_single',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fecha'.
  $permissions['view own field_fecha'] = array(
    'name' => 'view own field_fecha',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fecha_arribo'.
  $permissions['view own field_fecha_arribo'] = array(
    'name' => 'view own field_fecha_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fecha_de_cancelacion'.
  $permissions['view own field_fecha_de_cancelacion'] = array(
    'name' => 'view own field_fecha_de_cancelacion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fecha_de_expedicion_rc'.
  $permissions['view own field_fecha_de_expedicion_rc'] = array(
    'name' => 'view own field_fecha_de_expedicion_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_fecha_de_pagado'.
  $permissions['view own field_fecha_de_pagado'] = array(
    'name' => 'view own field_fecha_de_pagado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ficha_de_pago'.
  $permissions['view own field_ficha_de_pago'] = array(
    'name' => 'view own field_ficha_de_pago',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_gastos_medicos'.
  $permissions['view own field_gastos_medicos'] = array(
    'name' => 'view own field_gastos_medicos',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_grua'.
  $permissions['view own field_grua'] = array(
    'name' => 'view own field_grua',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_hospital'.
  $permissions['view own field_hospital'] = array(
    'name' => 'view own field_hospital',
    'roles' => array(
      'administrador' => 'administrador',
      'agente de ventas' => 'agente de ventas',
      'ajustador' => 'ajustador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_importe_con_letra_rc'.
  $permissions['view own field_importe_con_letra_rc'] = array(
    'name' => 'view own field_importe_con_letra_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_informe'.
  $permissions['view own field_informe'] = array(
    'name' => 'view own field_informe',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado'.
  $permissions['view own field_lesionado'] = array(
    'name' => 'view own field_lesionado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_ambulancia'.
  $permissions['view own field_lesionado_ambulancia'] = array(
    'name' => 'view own field_lesionado_ambulancia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_ambulancia_info'.
  $permissions['view own field_lesionado_ambulancia_info'] = array(
    'name' => 'view own field_lesionado_ambulancia_info',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_domicilio'.
  $permissions['view own field_lesionado_domicilio'] = array(
    'name' => 'view own field_lesionado_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_edad'.
  $permissions['view own field_lesionado_edad'] = array(
    'name' => 'view own field_lesionado_edad',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_lesiones'.
  $permissions['view own field_lesionado_lesiones'] = array(
    'name' => 'view own field_lesionado_lesiones',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_nombre'.
  $permissions['view own field_lesionado_nombre'] = array(
    'name' => 'view own field_lesionado_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_pase_medico'.
  $permissions['view own field_lesionado_pase_medico'] = array(
    'name' => 'view own field_lesionado_pase_medico',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_riesgo_b'.
  $permissions['view own field_lesionado_riesgo_b'] = array(
    'name' => 'view own field_lesionado_riesgo_b',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lesionado_telefono'.
  $permissions['view own field_lesionado_telefono'] = array(
    'name' => 'view own field_lesionado_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_licencia_alta_fecha'.
  $permissions['view own field_licencia_alta_fecha'] = array(
    'name' => 'view own field_licencia_alta_fecha',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_licencia_alta_lugar'.
  $permissions['view own field_licencia_alta_lugar'] = array(
    'name' => 'view own field_licencia_alta_lugar',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_licencia_numero'.
  $permissions['view own field_licencia_numero'] = array(
    'name' => 'view own field_licencia_numero',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_licencia_tipo'.
  $permissions['view own field_licencia_tipo'] = array(
    'name' => 'view own field_licencia_tipo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lugar_atencion'.
  $permissions['view own field_lugar_atencion'] = array(
    'name' => 'view own field_lugar_atencion',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_lugar_referencias'.
  $permissions['view own field_lugar_referencias'] = array(
    'name' => 'view own field_lugar_referencias',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_mapa_arribo'.
  $permissions['view own field_mapa_arribo'] = array(
    'name' => 'view own field_mapa_arribo',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_mapa_siniestro'.
  $permissions['view own field_mapa_siniestro'] = array(
    'name' => 'view own field_mapa_siniestro',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_motivos_de_cancelacion'.
  $permissions['view own field_motivos_de_cancelacion'] = array(
    'name' => 'view own field_motivos_de_cancelacion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_nombre'.
  $permissions['view own field_nombre'] = array(
    'name' => 'view own field_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_nombre_quien_reporta'.
  $permissions['view own field_nombre_quien_reporta'] = array(
    'name' => 'view own field_nombre_quien_reporta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pago_fraccionado'.
  $permissions['view own field_pago_fraccionado'] = array(
    'name' => 'view own field_pago_fraccionado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_pago_subsecuente_rc'.
  $permissions['view own field_pago_subsecuente_rc'] = array(
    'name' => 'view own field_pago_subsecuente_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_periodo_cobertura_rc'.
  $permissions['view own field_periodo_cobertura_rc'] = array(
    'name' => 'view own field_periodo_cobertura_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_periodo_de_gracia'.
  $permissions['view own field_periodo_de_gracia'] = array(
    'name' => 'view own field_periodo_de_gracia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_plz_vehiculo_marca'.
  $permissions['view own field_plz_vehiculo_marca'] = array(
    'name' => 'view own field_plz_vehiculo_marca',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poblacion'.
  $permissions['view own field_poblacion'] = array(
    'name' => 'view own field_poblacion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza'.
  $permissions['view own field_poliza'] = array(
    'name' => 'view own field_poliza',
    'roles' => array(
      'administrador' => 'administrador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_coberturas'.
  $permissions['view own field_poliza_coberturas'] = array(
    'name' => 'view own field_poliza_coberturas',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_comentarios'.
  $permissions['view own field_poliza_comentarios'] = array(
    'name' => 'view own field_poliza_comentarios',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_derecho_poliza'.
  $permissions['view own field_poliza_derecho_poliza'] = array(
    'name' => 'view own field_poliza_derecho_poliza',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_emision'.
  $permissions['view own field_poliza_emision'] = array(
    'name' => 'view own field_poliza_emision',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_forma_pago'.
  $permissions['view own field_poliza_forma_pago'] = array(
    'name' => 'view own field_poliza_forma_pago',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_impuesto_iva'.
  $permissions['view own field_poliza_impuesto_iva'] = array(
    'name' => 'view own field_poliza_impuesto_iva',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_moneda'.
  $permissions['view own field_poliza_moneda'] = array(
    'name' => 'view own field_poliza_moneda',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_oficina'.
  $permissions['view own field_poliza_oficina'] = array(
    'name' => 'view own field_poliza_oficina',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_prima_1er_recibo'.
  $permissions['view own field_poliza_prima_1er_recibo'] = array(
    'name' => 'view own field_poliza_prima_1er_recibo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_prima_neta'.
  $permissions['view own field_poliza_prima_neta'] = array(
    'name' => 'view own field_poliza_prima_neta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_prima_total'.
  $permissions['view own field_poliza_prima_total'] = array(
    'name' => 'view own field_poliza_prima_total',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_primas_recibos_subs'.
  $permissions['view own field_poliza_primas_recibos_subs'] = array(
    'name' => 'view own field_poliza_primas_recibos_subs',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_reduccion'.
  $permissions['view own field_poliza_reduccion'] = array(
    'name' => 'view own field_poliza_reduccion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_rgo_pago_fracc'.
  $permissions['view own field_poliza_rgo_pago_fracc'] = array(
    'name' => 'view own field_poliza_rgo_pago_fracc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_status'.
  $permissions['view own field_poliza_status'] = array(
    'name' => 'view own field_poliza_status',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_poliza_vigencia'.
  $permissions['view own field_poliza_vigencia'] = array(
    'name' => 'view own field_poliza_vigencia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_primer_pago_rc'.
  $permissions['view own field_primer_pago_rc'] = array(
    'name' => 'view own field_primer_pago_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_propietario_domicilio'.
  $permissions['view own field_propietario_domicilio'] = array(
    'name' => 'view own field_propietario_domicilio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_propietario_nombre'.
  $permissions['view own field_propietario_nombre'] = array(
    'name' => 'view own field_propietario_nombre',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_propietario_telefono'.
  $permissions['view own field_propietario_telefono'] = array(
    'name' => 'view own field_propietario_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_proveedores'.
  $permissions['view own field_proveedores'] = array(
    'name' => 'view own field_proveedores',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rc_viajero'.
  $permissions['view own field_rc_viajero'] = array(
    'name' => 'view own field_rc_viajero',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_reserva_total'.
  $permissions['view own field_reserva_total'] = array(
    'name' => 'view own field_reserva_total',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_resp_civil'.
  $permissions['view own field_resp_civil'] = array(
    'name' => 'view own field_resp_civil',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rfc'.
  $permissions['view own field_rfc'] = array(
    'name' => 'view own field_rfc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_robo'.
  $permissions['view own field_robo'] = array(
    'name' => 'view own field_robo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_serie_rc'.
  $permissions['view own field_serie_rc'] = array(
    'name' => 'view own field_serie_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_siniestro_archivo'.
  $permissions['view own field_siniestro_archivo'] = array(
    'name' => 'view own field_siniestro_archivo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_status_sinister'.
  $permissions['view own field_status_sinister'] = array(
    'name' => 'view own field_status_sinister',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_taller'.
  $permissions['view own field_taller'] = array(
    'name' => 'view own field_taller',
    'roles' => array(
      'administrador' => 'administrador',
      'ajustador' => 'ajustador',
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
      'supervisor de siniestros' => 'supervisor de siniestros',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_telefono'.
  $permissions['view own field_telefono'] = array(
    'name' => 'view own field_telefono',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_telefono_quien_reporta'.
  $permissions['view own field_telefono_quien_reporta'] = array(
    'name' => 'view own field_telefono_quien_reporta',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_uso_vehiculo'.
  $permissions['view own field_uso_vehiculo'] = array(
    'name' => 'view own field_uso_vehiculo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_usuario_de_cancelado'.
  $permissions['view own field_usuario_de_cancelado'] = array(
    'name' => 'view own field_usuario_de_cancelado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_usuario_de_pagado'.
  $permissions['view own field_usuario_de_pagado'] = array(
    'name' => 'view own field_usuario_de_pagado',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'cabina' => 'cabina',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_capacidad'.
  $permissions['view own field_vehiculo_capacidad'] = array(
    'name' => 'view own field_vehiculo_capacidad',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_carroceria'.
  $permissions['view own field_vehiculo_carroceria'] = array(
    'name' => 'view own field_vehiculo_carroceria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_carroceria_select'.
  $permissions['view own field_vehiculo_carroceria_select'] = array(
    'name' => 'view own field_vehiculo_carroceria_select',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_categoria'.
  $permissions['view own field_vehiculo_categoria'] = array(
    'name' => 'view own field_vehiculo_categoria',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_cilindros'.
  $permissions['view own field_vehiculo_cilindros'] = array(
    'name' => 'view own field_vehiculo_cilindros',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_clave_sbg'.
  $permissions['view own field_vehiculo_clave_sbg'] = array(
    'name' => 'view own field_vehiculo_clave_sbg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_color'.
  $permissions['view own field_vehiculo_color'] = array(
    'name' => 'view own field_vehiculo_color',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_descripcion'.
  $permissions['view own field_vehiculo_descripcion'] = array(
    'name' => 'view own field_vehiculo_descripcion',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_descripcion_carga'.
  $permissions['view own field_vehiculo_descripcion_carga'] = array(
    'name' => 'view own field_vehiculo_descripcion_carga',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_marca'.
  $permissions['view own field_vehiculo_marca'] = array(
    'name' => 'view own field_vehiculo_marca',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_modelo'.
  $permissions['view own field_vehiculo_modelo'] = array(
    'name' => 'view own field_vehiculo_modelo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_motor'.
  $permissions['view own field_vehiculo_motor'] = array(
    'name' => 'view own field_vehiculo_motor',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_numero_inventario'.
  $permissions['view own field_vehiculo_numero_inventario'] = array(
    'name' => 'view own field_vehiculo_numero_inventario',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_numero_pedimento'.
  $permissions['view own field_vehiculo_numero_pedimento'] = array(
    'name' => 'view own field_vehiculo_numero_pedimento',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_placas'.
  $permissions['view own field_vehiculo_placas'] = array(
    'name' => 'view own field_vehiculo_placas',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_referencia'.
  $permissions['view own field_vehiculo_referencia'] = array(
    'name' => 'view own field_vehiculo_referencia',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_remolque'.
  $permissions['view own field_vehiculo_remolque'] = array(
    'name' => 'view own field_vehiculo_remolque',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_serie'.
  $permissions['view own field_vehiculo_serie'] = array(
    'name' => 'view own field_vehiculo_serie',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_servicio'.
  $permissions['view own field_vehiculo_servicio'] = array(
    'name' => 'view own field_vehiculo_servicio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_submarca'.
  $permissions['view own field_vehiculo_submarca'] = array(
    'name' => 'view own field_vehiculo_submarca',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_tercero'.
  $permissions['view own field_vehiculo_tercero'] = array(
    'name' => 'view own field_vehiculo_tercero',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_tipo'.
  $permissions['view own field_vehiculo_tipo'] = array(
    'name' => 'view own field_vehiculo_tipo',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_tipo_carga'.
  $permissions['view own field_vehiculo_tipo_carga'] = array(
    'name' => 'view own field_vehiculo_tipo_carga',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_tipo_remolque'.
  $permissions['view own field_vehiculo_tipo_remolque'] = array(
    'name' => 'view own field_vehiculo_tipo_remolque',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_tonelaje'.
  $permissions['view own field_vehiculo_tonelaje'] = array(
    'name' => 'view own field_vehiculo_tonelaje',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_transmision'.
  $permissions['view own field_vehiculo_transmision'] = array(
    'name' => 'view own field_vehiculo_transmision',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vehiculo_uso'.
  $permissions['view own field_vehiculo_uso'] = array(
    'name' => 'view own field_vehiculo_uso',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_vencimiento_rc'.
  $permissions['view own field_vencimiento_rc'] = array(
    'name' => 'view own field_vencimiento_rc',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_visualizador'.
  $permissions['view own field_visualizador'] = array(
    'name' => 'view own field_visualizador',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrador' => 'administrador',
      'developer' => 'developer',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrador' => 'administrador',
      'authenticated user' => 'authenticated user',
      'developer' => 'developer',
    ),
    'module' => 'system',
  );

  return $permissions;
}
