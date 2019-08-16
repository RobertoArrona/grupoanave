<?php

/**
 * @file
 * feature_payment_receipt.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_payment_receipt_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contract_receipts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recibos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recibos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'Administrar Recibos';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Folio del Recibo';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Contrato */
  $handler->display->display_options['fields']['field_poliza']['id'] = 'field_poliza';
  $handler->display->display_options['fields']['field_poliza']['table'] = 'field_data_field_poliza';
  $handler->display->display_options['fields']['field_poliza']['field'] = 'field_poliza';
  $handler->display->display_options['fields']['field_poliza']['label'] = 'No. de Contrato';
  $handler->display->display_options['fields']['field_poliza']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Solicitante de contrato */
  $handler->display->display_options['fields']['field_asegurado_nombre']['id'] = 'field_asegurado_nombre';
  $handler->display->display_options['fields']['field_asegurado_nombre']['table'] = 'field_data_field_asegurado_nombre';
  $handler->display->display_options['fields']['field_asegurado_nombre']['field'] = 'field_asegurado_nombre';
  $handler->display->display_options['fields']['field_asegurado_nombre']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['fields']['field_asegurado_nombre']['label'] = 'Solicitante de Contrato';
  $handler->display->display_options['fields']['field_asegurado_nombre']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Vencimiento */
  $handler->display->display_options['fields']['field_vencimiento_rc']['id'] = 'field_vencimiento_rc';
  $handler->display->display_options['fields']['field_vencimiento_rc']['table'] = 'field_data_field_vencimiento_rc';
  $handler->display->display_options['fields']['field_vencimiento_rc']['field'] = 'field_vencimiento_rc';
  $handler->display->display_options['fields']['field_vencimiento_rc']['label'] = 'Vencimiento del Recibo';
  $handler->display->display_options['fields']['field_vencimiento_rc']['settings'] = array(
    'format_type' => 'short_desc',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Periodo Cobertura */
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['id'] = 'field_periodo_cobertura_rc';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['table'] = 'field_data_field_periodo_cobertura_rc';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['field'] = 'field_periodo_cobertura_rc';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['label'] = 'Periodo de Cobertura';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['settings'] = array(
    'format_type' => 'short_desc',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Forma de Pago */
  $handler->display->display_options['fields']['field_poliza_forma_pago']['id'] = 'field_poliza_forma_pago';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['table'] = 'field_data_field_poliza_forma_pago';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['field'] = 'field_poliza_forma_pago';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Prima Total */
  $handler->display->display_options['fields']['field_total_premium']['id'] = 'field_total_premium';
  $handler->display->display_options['fields']['field_total_premium']['table'] = 'field_data_field_total_premium';
  $handler->display->display_options['fields']['field_total_premium']['field'] = 'field_total_premium';
  $handler->display->display_options['fields']['field_total_premium']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'editar';
  /* Field: Print */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Print';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'imprimir';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '/print/content/[title]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'print';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: PDF */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'PDF';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'descargar';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = '/printpdf/[nid]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Operaciones';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[edit_node] [nothing]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recibo_contrato' => 'recibo_contrato',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Folio del Recibo';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: No. de Contrato */
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['id'] = 'field_codigo_de_barras_rc_value';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['table'] = 'field_data_field_codigo_de_barras_rc';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['field'] = 'field_codigo_de_barras_rc_value';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['ui_name'] = 'No. de Contrato';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['group'] = 1;
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['operator_id'] = 'field_codigo_de_barras_rc_value_op';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['label'] = 'No. de Contrato';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['operator'] = 'field_codigo_de_barras_rc_value_op';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['identifier'] = 'field_codigo_de_barras_rc_value';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Solicitante de contrato (field_asegurado_nombre) */
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['id'] = 'field_asegurado_nombre_value';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['table'] = 'field_data_field_asegurado_nombre';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['field'] = 'field_asegurado_nombre_value';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['group'] = 1;
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['operator_id'] = 'field_asegurado_nombre_value_op';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['label'] = 'Solicitante de Contrato';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['operator'] = 'field_asegurado_nombre_value_op';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['identifier'] = 'field_asegurado_nombre_value';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Vencimiento (field_vencimiento_rc) */
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['id'] = 'field_vencimiento_rc_value';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['table'] = 'field_data_field_vencimiento_rc';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['field'] = 'field_vencimiento_rc_value';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['group'] = 1;
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['operator_id'] = 'field_vencimiento_rc_value_op';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['label'] = 'Vencimiento del Recibo';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['operator'] = 'field_vencimiento_rc_value_op';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['identifier'] = 'field_vencimiento_rc_value';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Periodo Cobertura -  start date (field_periodo_cobertura_rc) */
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['id'] = 'field_periodo_cobertura_rc_value';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['table'] = 'field_data_field_periodo_cobertura_rc';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['field'] = 'field_periodo_cobertura_rc_value';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['group'] = 1;
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['operator_id'] = 'field_periodo_cobertura_rc_value_op';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['label'] = 'Periodo de Cobertura';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['operator'] = 'field_periodo_cobertura_rc_value_op';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['identifier'] = 'field_periodo_cobertura_rc_value';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['form_type'] = 'date_popup';
  /* Filter criterion: Forma de Pago */
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['id'] = 'field_poliza_forma_pago_value';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['table'] = 'field_data_field_poliza_forma_pago';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['field'] = 'field_poliza_forma_pago_value';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['ui_name'] = 'Forma de Pago';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['group'] = 1;
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['operator_id'] = 'field_poliza_forma_pago_value_op';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['label'] = 'Forma de Pago';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['operator'] = 'field_poliza_forma_pago_value_op';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['identifier'] = 'field_poliza_forma_pago_value';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: Prima Total */
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['id'] = 'field_poliza_prima_total_value';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['table'] = 'field_data_field_poliza_prima_total';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['field'] = 'field_poliza_prima_total_value';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['ui_name'] = 'Prima Total';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['group'] = 1;
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['operator_id'] = 'field_poliza_prima_total_value_op';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['label'] = 'Prima Total';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['operator'] = 'field_poliza_prima_total_value_op';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['identifier'] = 'field_poliza_prima_total_value';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/anave/recibos';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Recibos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-anave';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recibos';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'Administrar Recibos';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'datos-de-recibo-de-contrato.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Folio del Recibo';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Contrato */
  $handler->display->display_options['fields']['field_poliza']['id'] = 'field_poliza';
  $handler->display->display_options['fields']['field_poliza']['table'] = 'field_data_field_poliza';
  $handler->display->display_options['fields']['field_poliza']['field'] = 'field_poliza';
  $handler->display->display_options['fields']['field_poliza']['label'] = 'No. de Contrato';
  $handler->display->display_options['fields']['field_poliza']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Solicitante de contrato */
  $handler->display->display_options['fields']['field_asegurado_nombre']['id'] = 'field_asegurado_nombre';
  $handler->display->display_options['fields']['field_asegurado_nombre']['table'] = 'field_data_field_asegurado_nombre';
  $handler->display->display_options['fields']['field_asegurado_nombre']['field'] = 'field_asegurado_nombre';
  $handler->display->display_options['fields']['field_asegurado_nombre']['label'] = 'Solicitante de Contrato';
  $handler->display->display_options['fields']['field_asegurado_nombre']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Vencimiento */
  $handler->display->display_options['fields']['field_vencimiento_rc']['id'] = 'field_vencimiento_rc';
  $handler->display->display_options['fields']['field_vencimiento_rc']['table'] = 'field_data_field_vencimiento_rc';
  $handler->display->display_options['fields']['field_vencimiento_rc']['field'] = 'field_vencimiento_rc';
  $handler->display->display_options['fields']['field_vencimiento_rc']['label'] = 'Vencimiento del Recibo';
  $handler->display->display_options['fields']['field_vencimiento_rc']['settings'] = array(
    'format_type' => 'short_desc',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Periodo Cobertura */
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['id'] = 'field_periodo_cobertura_rc';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['table'] = 'field_data_field_periodo_cobertura_rc';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['field'] = 'field_periodo_cobertura_rc';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['label'] = 'Periodo de Cobertura';
  $handler->display->display_options['fields']['field_periodo_cobertura_rc']['settings'] = array(
    'format_type' => 'short_desc',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Forma de Pago */
  $handler->display->display_options['fields']['field_poliza_forma_pago']['id'] = 'field_poliza_forma_pago';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['table'] = 'field_data_field_poliza_forma_pago';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['field'] = 'field_poliza_forma_pago';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['fields']['field_poliza_forma_pago']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Prima Total */
  $handler->display->display_options['fields']['field_total_premium']['id'] = 'field_total_premium';
  $handler->display->display_options['fields']['field_total_premium']['table'] = 'field_data_field_total_premium';
  $handler->display->display_options['fields']['field_total_premium']['field'] = 'field_total_premium';
  $handler->display->display_options['fields']['field_total_premium']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recibo_contrato' => 'recibo_contrato',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Folio del Recibo';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: No. de Contrato */
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['id'] = 'field_codigo_de_barras_rc_value';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['table'] = 'field_data_field_codigo_de_barras_rc';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['field'] = 'field_codigo_de_barras_rc_value';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['ui_name'] = 'No. de Contrato';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['group'] = 1;
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['operator_id'] = 'field_codigo_de_barras_rc_value_op';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['label'] = 'No. de Contrato';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['operator'] = 'field_codigo_de_barras_rc_value_op';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['identifier'] = 'field_codigo_de_barras_rc_value';
  $handler->display->display_options['filters']['field_codigo_de_barras_rc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Solicitante de contrato (field_asegurado_nombre) */
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['id'] = 'field_asegurado_nombre_value';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['table'] = 'field_data_field_asegurado_nombre';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['field'] = 'field_asegurado_nombre_value';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['group'] = 1;
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['operator_id'] = 'field_asegurado_nombre_value_op';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['label'] = 'Solicitante de Contrato';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['operator'] = 'field_asegurado_nombre_value_op';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['identifier'] = 'field_asegurado_nombre_value';
  $handler->display->display_options['filters']['field_asegurado_nombre_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Vencimiento (field_vencimiento_rc) */
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['id'] = 'field_vencimiento_rc_value';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['table'] = 'field_data_field_vencimiento_rc';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['field'] = 'field_vencimiento_rc_value';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['group'] = 1;
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['operator_id'] = 'field_vencimiento_rc_value_op';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['label'] = 'Vencimiento del Recibo';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['operator'] = 'field_vencimiento_rc_value_op';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['identifier'] = 'field_vencimiento_rc_value';
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_vencimiento_rc_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Periodo Cobertura -  start date (field_periodo_cobertura_rc) */
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['id'] = 'field_periodo_cobertura_rc_value';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['table'] = 'field_data_field_periodo_cobertura_rc';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['field'] = 'field_periodo_cobertura_rc_value';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['group'] = 1;
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['operator_id'] = 'field_periodo_cobertura_rc_value_op';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['label'] = 'Periodo de Cobertura';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['operator'] = 'field_periodo_cobertura_rc_value_op';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['identifier'] = 'field_periodo_cobertura_rc_value';
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_periodo_cobertura_rc_value']['form_type'] = 'date_popup';
  /* Filter criterion: Forma de Pago */
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['id'] = 'field_poliza_forma_pago_value';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['table'] = 'field_data_field_poliza_forma_pago';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['field'] = 'field_poliza_forma_pago_value';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['ui_name'] = 'Forma de Pago';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['group'] = 1;
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['operator_id'] = 'field_poliza_forma_pago_value_op';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['label'] = 'Forma de Pago';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['operator'] = 'field_poliza_forma_pago_value_op';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['identifier'] = 'field_poliza_forma_pago_value';
  $handler->display->display_options['filters']['field_poliza_forma_pago_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  /* Filter criterion: Prima Total */
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['id'] = 'field_poliza_prima_total_value';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['table'] = 'field_data_field_poliza_prima_total';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['field'] = 'field_poliza_prima_total_value';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['relationship'] = 'field_poliza_target_id';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['ui_name'] = 'Prima Total';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['group'] = 1;
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['operator_id'] = 'field_poliza_prima_total_value_op';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['label'] = 'Prima Total';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['operator'] = 'field_poliza_prima_total_value_op';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['identifier'] = 'field_poliza_prima_total_value';
  $handler->display->display_options['filters']['field_poliza_prima_total_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    13 => 0,
    14 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    15 => 0,
    12 => 0,
    11 => 0,
    16 => 0,
    10 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'admin/global/recibos-de-contratos.xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['contract_receipts'] = $view;

  return $export;
}
