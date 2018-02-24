<?php

/**
 * @file
 * This file provides custom block for anavem.
 */

/**
 * Implements hook_block_info().
 */
function anavem_block_info() {
  $blocks = array();
  $blocks['carrusel'] = array(
    'info' => 'Anavem Carrusel',
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function anavem_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'carrusel':
      $block['content'] = anavem_block_view_carrusel();
      break;
  }
  return $block;
}

/**
 * Returns a Carrusel Block for an Active Generic Page.
 */
function anavem_block_view_carrusel() {
  if (!(arg(0) == 'node' && intval(arg(1)) > 0 && ($node = node_load(arg(1))) && $node->type == 'home_blocks')) {
    return FALSE;
  }

  if (!(isset($node->field_slideshow_show[LANGUAGE_NONE][0]['value']) && $node->field_slideshow_show[LANGUAGE_NONE][0]['value'] == 1)) {
    return FALSE;
  }

  if (!(isset($node->field_carrusel_grupo[LANGUAGE_NONE][0]['tid']) && !empty($node->field_carrusel_grupo[LANGUAGE_NONE][0]['tid']))) {
    return FALSE;
  }

  return views_embed_view('home_slideshow', 'block_1', $node->field_carrusel_grupo[LANGUAGE_NONE][0]['tid']);
}
