<?php

/**
 * @file
 * Display Suite 1 column template.
 */
//print_r($elements['field_fecha_de_cancelacion']['#object']->field_pago_fraccionado[LANGUAGE_NONE][0]['value']); exit;
//print_r($elements['field_poliza_tipo']); exit;
$agente_uid = $elements['author']['#object']->uid;
$agente = user_load($agente_uid);
$agente_nombre = '';
if (isset($agente->field_first_name[LANGUAGE_NONE][0]['safe_value'])) {
  $agente_nombre = $agente->field_first_name[LANGUAGE_NONE][0]['safe_value'];
}
if (isset($agente->field_last_name[LANGUAGE_NONE][0]['safe_value'])){
  $agente_nombre = $agente_nombre . ' ' . $agente->field_last_name[LANGUAGE_NONE][0]['safe_value'];  
}
if ( isset($elements['field_asegurado_domicilio']['#items'][0]) ) {
  $address = $elements['field_asegurado_domicilio']['#items'][0]; 
}
if (isset($elements['field_poliza_forma_pago'])) {
  $plazo = $elements['field_poliza_forma_pago']['#items'][0]['value'];
  $pagos_sub_label = 'Recibos Subs:';
  $label = ':(0)';
  if ($plazo != 'anual') {
    switch ($plazo) {
      case 'mensual':
        $label = ':(11)';
        break;
        
      case '3meses':
        $label = ':(2)';
        break;
      
      case 'trimestral':
        $label = ':(3)';
        break;
        
      case 'cuatrimestral':
        $label = ':(2)';
        break;
      
      case 'semestral':
        $label = ':(1)';
        break;
    }
  }
  $pagos_sub_label = 'Recibos Subs' . $label;
}

$termid = $agente->field_estado[LANGUAGE_NONE]['0']['tid'];
if(empty($termid)) {
	return false;
  }else{
    $term = taxonomy_term_load($termid);
		$termname = $term -> name;
  }

$agent_id = $agente->field_agente_clave[LANGUAGE_NONE]['0']['value'];
$office  = "$termname-$agent_id";
print_r($ds_content_wrapper);exit;
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <table class="tabla-recibo">
    
    <tbody><tr>
      <td class="">
        <table class="print-child tabla-recibo-col1">
          <tr>
            <td>
              <div class="barcode"></div>
            </td>
          </tr>
          <tr>
            <td> <strong>Fecha de expedicion:</strong> <?php print render($elements['field_poliza_emision']);?> 
            </td>
          </tr>
          
          <tr>
            <td>
              <strong>Solicitante de contrato:</strong>
              <?php if(isset($elements['field_asegurado_nombre'])):?>
              <?php print render($elements['field_asegurado_nombre']);?>
              <?php endif;?>
            </td>

          <tr>
            <td>
              <?php if(isset($address['thoroughfare'])):?>
              <div class="label-above">Calle y No:</div>
              <?php print $address['thoroughfare'];?>
              <?php endif;?>
            </td>
          </tr>

          <tr>
            <td>
              <?php if(isset($address['premise'])):?>
              <div class="label-above">Colonia:</div>
              <?php print $address['premise'];?>
              <?php endif;?>
            </td>
          </tr>
          <tr>
            <td>
              <?php if(isset($address['locality'])):?>
              <div class="label-above">Municipio:</div>
              <?php print $address['locality'];?>
              <?php endif;?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php if(isset($address['premise'])):?>
              <div class="label-above">C.P:</div>
              <?php print '63780';?>
              <?php endif;?>
            </td>
          </tr>

          <tr class="last amount">
            <td>
              <div class="label-above"><strong>Importe con Letra:</strong> </div>
                (MIL SETECIENTOS CUARENTA PESOS 00/100 M.N.)
            </td>
          </tr>
          
        </table>
      </td>
      <td class="table-poliza">
        <table class="print-child tabla-recibo-col-2">
          <tbody>
	          <tr>
	            <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td class="serie"><strong>Serie:</strong></td>
                  <td class="left">1/1</td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
              <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td><strong class="folio">Folio del Recibo:</strong></td>
                  <td class="left">1000001</td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
            
<!--
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_emision'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_emision']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_emision']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_emision'])):?>
                <table class="generic"><tr>
                  <td><strong></strong></td>
                  <td align="right"></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
-->
            
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_vigencia'])):?>
                  <table class="generic">
                    <tr>
                      <td><strong>Vencimiento del Recibo:</strong></td>
                      <td class="left"><?php print render($elements['field_poliza_vigencia']);?></td>
                    </tr>
                    <tr>
                      <td><strong>Periodo de cobertura del:</strong></td>
                      <td class="left"><?php print render($elements['field_poliza_vigencia']);?></td>
                    </tr>
                  </table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php if(isset($elements['fin_vigencia'])):?>
                <table class="generic"><tr>
                  <td class="to"><strong>al:</strong></td>
                  <td class="left"><?php print render($elements['fin_vigencia']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
               <td>
                <?php if(isset($elements['title'])):?>
                <table class="generic"><tr>
                  <td class="contract-number"><strong>Contrato No:</strong></td>
                  <td class="left"><?php print render($elements['title']);?></td>
                </tr></table>
                <?php endif;?>
              </td> 
              <td>
                <?php if(isset($elements['field_poliza_forma_pago'])):?>
                <table class="generic"><tr>
                  <td class="payment-method"><strong><?php print $elements['field_poliza_forma_pago']['#title'];?>:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_forma_pago']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td class="contract-type"><strong>Tipo de Contrato:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_tipo']);?> Daños a Terceros</td>
                </tr></table>
              </td> 
              <td>
                <?php if(isset($elements['field_poliza_moneda'])):?>
                <table class="generic"><tr>
                  <td class="coin"><strong><?php print $elements['field_poliza_moneda']['#title'];?>:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_moneda']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_prima_neta'])):?>
                <table class="generic net-premium"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Neta: </strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_prima_neta']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Emision </strong></td>
                  <td class="amount">$0.00</td>
                </tr></table>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_impuesto_iva'])):?>
                <table class="generic"><tr>
                  <td><strong>I.V.A:</strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_impuesto_iva']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_prima_total'])):?>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Total: </strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_prima_total']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>

  
        </table>
    </td></tr></tbody>
  </table>
  <div class="payment-copy">
    <p>En caso de no realizarce el pago del recibo de contrato, este sera cancelado.</p>
    <div class="row-payment">
      <div class="number">
        <p>1.</p>
      </div>
      <div class="text">
        <p>Los pagos deberan realizarce en cualquier sucursarl de Santander y en las oficnas de MN Global Protec A.C. a travez de la referencia bancaria Proporcionada.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>2.</p>
      </div>
      <div class="text">
        <p>Este documento solo sera valido mediente comprovante de pago en el banco, con el sello de la compañia, o certificacion del mismo.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>3.</p>
      </div>
      <div class="text">
        <p>No se aceptara el pago si el recibo ha vencido su fecha de pago.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>4.</p>
      </div>
      <div class="text">
        <p>Si el pago es realizadon con cheque, este sera recibido salvo buen cobro, el cual debera extenderce a nombre de MN Global Protec A.C.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>5.</p>
      </div>
      <div class="text">
        <p>Los recibos deberan pagarce segun su orden en la serie que corresponda y en el orden marcado.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>6.</p>
      </div>
      <div class="text last">
        <p>Este documento no es un comprovante fiscal. Puede obtener el comprovante fiscal en las oficinas de la compania, o marcando el 01800 999 00 69 o a travez de su intermediario.</p>
      </div>
    </div>
  </div>
  
  <table class="tabla-recibo">
    
    <tbody><tr>
      <td class="">
        <table class="print-child tabla-recibo-col1">
          <tr>
            <td>
              <div class="barcode"></div>
            </td>
          </tr>
          <tr>
            <td> <strong>Fecha de expedicion:</strong> <?php print render($elements['field_poliza_emision']);?> 
            </td>
          </tr>
          
          <tr>
            <td>
              <strong>Solicitante de contrato:</strong>
              <?php if(isset($elements['field_asegurado_nombre'])):?>
              <?php print render($elements['field_asegurado_nombre']);?>
              <?php endif;?>
            </td>

          <tr>
            <td>
              <?php if(isset($address['thoroughfare'])):?>
              <div class="label-above">Calle y No:</div>
              <?php print $address['thoroughfare'];?>
              <?php endif;?>
            </td>
          </tr>

          <tr>
            <td>
              <?php if(isset($address['premise'])):?>
              <div class="label-above">Colonia:</div>
              <?php print $address['premise'];?>
              <?php endif;?>
            </td>
          </tr>
          <tr>
            <td>
              <?php if(isset($address['locality'])):?>
              <div class="label-above">Municipio:</div>
              <?php print $address['locality'];?>
              <?php endif;?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php if(isset($address['premise'])):?>
              <div class="label-above">C.P:</div>
              <?php print '63780';?>
              <?php endif;?>
            </td>
          </tr>

          <tr class="last amount">
            <td>
              <div class="label-above"><strong>Importe con Letra:</strong> </div>
                (MIL SETECIENTOS CUARENTA PESOS 00/100 M.N.)
            </td>
          </tr>
          
        </table>
      </td>
      <td class="table-poliza">
        <table class="print-child tabla-recibo-col-2">
          <tbody>
	          <tr>
	            <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td class="serie"><strong>Serie:</strong></td>
                  <td class="left">1/1</td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
              <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td><strong class="folio">Folio del Recibo:</strong></td>
                  <td class="left">1000001</td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
            
<!--
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_emision'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_emision']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_emision']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_emision'])):?>
                <table class="generic"><tr>
                  <td><strong></strong></td>
                  <td align="right"></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
-->
            
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_vigencia'])):?>
                  <table class="generic">
                    <tr>
                      <td><strong>Vencimiento del Recibo:</strong></td>
                      <td class="left"><?php print render($elements['field_poliza_vigencia']);?></td>
                    </tr>
                    <tr>
                      <td><strong>Periodo de cobertura del:</strong></td>
                      <td class="left"><?php print render($elements['field_poliza_vigencia']);?></td>
                    </tr>
                  </table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php if(isset($elements['fin_vigencia'])):?>
                <table class="generic"><tr>
                  <td class="to"><strong>al:</strong></td>
                  <td class="left"><?php print render($elements['fin_vigencia']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
               <td>
                <?php if(isset($elements['title'])):?>
                <table class="generic"><tr>
                  <td class="contract-number"><strong>Contrato No:</strong></td>
                  <td class="left"><?php print render($elements['title']);?></td>
                </tr></table>
                <?php endif;?>
              </td> 
              <td>
                <?php if(isset($elements['field_poliza_forma_pago'])):?>
                <table class="generic"><tr>
                  <td class="payment-method"><strong><?php print $elements['field_poliza_forma_pago']['#title'];?>:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_forma_pago']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td class="contract-type"><strong>Tipo de Contrato:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_tipo']);?> Daños a Terceros</td>
                </tr></table>
              </td> 
              <td>
                <?php if(isset($elements['field_poliza_moneda'])):?>
                <table class="generic"><tr>
                  <td class="coin"><strong><?php print $elements['field_poliza_moneda']['#title'];?>:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_moneda']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_prima_neta'])):?>
                <table class="generic net-premium"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Neta: </strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_prima_neta']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Emision </strong></td>
                  <td class="amount">$0.00</td>
                </tr></table>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_impuesto_iva'])):?>
                <table class="generic"><tr>
                  <td><strong>I.V.A:</strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_impuesto_iva']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_prima_total'])):?>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Total: </strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_prima_total']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>

  
        </table>
    </td></tr></tbody>
  </table>