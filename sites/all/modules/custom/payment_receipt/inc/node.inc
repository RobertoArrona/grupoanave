<?php

/**
   * Implements hook_node_submit().
   */
  function payment_receipt_node_submit($node, $form, &$form_state){
    if(empty($node ->nid)) {
      switch ($node ->type){
        case 'recibo_contrato':
          payment_receipt_receipt_number_increase();
          break;
      }
    }
  }