<?php

/**
 * @file
 * Display Suite 1 column template.
 */
 //print_r($elements);exit;
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
  $pagos_sub_label = 'Primas Recibos Subs:';
  $label = ':(0)';
  if ($plazo != 'anual') {
    switch ($plazo) {
      case 'mensual':
        $label = ':(11)';
        break;
      
      case 'trimestral':
        $label = ':(4)';
        break;
      
      case 'semestral':
        $label = ':(1)';
        break;
    }
  }
  $pagos_sub_label = 'Primas Recibos Subs' . $label;
}

?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <table class="print">
    <thead>
      <tr>
        <th>Datos del socio</th>
        <th>Datos del contrato</th>
      </tr>
    </thead>
    <tbody><tr>
      <td class="table-asegurado">
        <table class="print-child">
          <tr>
            <td colspan="2">
              <?php if(isset($elements['field_asegurado_nombre'])):?>
              <?php print render($elements['field_asegurado_nombre']);?>
              <?php endif;?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php if(isset($address['thoroughfare'])):?>
              <div class="label-above">Calle y Numero:</div>
              <?php print $address['thoroughfare'];?>
              <?php endif;?>
            </td>
            <td>
              <?php if(isset($elements['field_asegurado_rfc'])):?>
              <?php print render($elements['field_asegurado_rfc']);?>
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
            <td>
              <?php if(isset($address['locality'])):?>
              <div class="label-above">Poblado:</div>
              <?php print $address['locality'];?>
              <?php endif;?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php if(isset($address['administrative_area'])):?>
              <div class="label-above">Estado:</div>
              <?php print grupoanave_get_state_name($address['country'], $address['administrative_area']);?>
              <?php endif;?>
            </td>
            <td>
              <?php if(isset($address['postal_code'])):?>
              <div class="label-above">C&oacute;digo Postal:</div>
              <?php print $address['postal_code'];?>
              <?php endif;?>
            </td>
          </tr>

          <tr class="last">
            <td>
              <?php if(isset($elements['field_asegurado_telefono'])):?>
              <?php print render($elements['field_asegurado_telefono']);?>
              <?php endif;?>
            </td>
            <td>
              <?php if(isset($elements['field_asegurado_benef_pref'])):?>
              <div class="label-above">Beneficiario Preferente:</div>
              <?php print render($elements['field_asegurado_benef_pref']);?>
              <?php endif;?>
            </td>
          </tr>
          
        </table>
      </td>
      <td class="table-poliza">
        <table class="print-child">
          <tbody>
            <tr>
              <td>
                <?php if(isset($elements['title'])):?>
                <table class="generic"><tr>
                  <td><strong>Numero de Contrato:</strong></td>
                  <td align="right"><?php print render($elements['title']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_prima_neta'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_prima_neta']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_prima_neta']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
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
            
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_vigencia'])):?>
                <table class="generic"><tr>
                  <td><strong>Inicio de Vigencia:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_vigencia']);?> 12:00 Horas</td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_rgo_pago_fracc'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_rgo_pago_fracc']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_rgo_pago_fracc']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php if(isset($elements['fin_vigencia'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['fin_vigencia']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['fin_vigencia']);?> 12:00 Horas</td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_derecho_poliza'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_derecho_poliza']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_derecho_poliza']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_moneda'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_moneda']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_moneda']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_impuesto_iva'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_impuesto_iva']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_impuesto_iva']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_forma_pago'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_forma_pago']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_forma_pago']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_prima_total'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_prima_total']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_prima_total']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong>Nombre del Agente:</strong></td>
                  <td align="right"><?php print $agente_nombre;?></td>
                </tr></table>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_prima_1er_recibo'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_prima_1er_recibo']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_prima_1er_recibo']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr class="last">
              <td>
                <table class="generic"><tr>
                  <td><strong>Clave del Agente:</strong></td>
                  <td align="right"><?php print $agente_uid;?></td>
                </tr></table>
              </td>
              <td>
                <?php if(isset($elements['field_poliza_primas_recibos_subs'])):?>
                <table class="generic"><tr>
                  <td><strong><?php print $pagos_sub_label;?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_primas_recibos_subs']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
          </tbody>
        </table>
      </td>
    </tr></tbody>
  </table>
  
  <table class="print table-vehiculo">
    <thead>
      <tr>
        <th>Datos del Vehiculo</th>
      </tr>
    </thead>
    <tbody><tr><td>
      <table class="print-child">
        <tr class="row-1 odd">
          <td>
            <?php if(isset($elements['field_plz_vehiculo_marca'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_plz_vehiculo_marca']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_plz_vehiculo_marca']);?></td>
            </tr></table>
            <?php endif;?>
          </td>
          <td>
            <?php if(isset($elements['field_vehiculo_color'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_color']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_color']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_tonelaje'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_tonelaje']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_tonelaje']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_placas'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_placas']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_placas']);?></td>
            </tr></table>
            <?php endif;?>
          </td>
        </tr>
        
        <tr class="row-2">
          <td>
            <?php if(isset($elements['field_vehiculo_submarca'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_submarca']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_submarca']);?></td>
            </tr></table>
            <?php endif;?>
          </td>
          <td>
            <?php if(isset($elements['field_vehiculo_cilindros'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_cilindros']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_cilindros']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_tipo_carga'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_tipo_carga']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_tipo_carga']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_modelo'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_modelo']['#title'];?>:</strong></td>
              <td align="right"><?php print $elements['field_vehiculo_modelo']['#items'][0]['value'];?></td>
            </tr></table>
            <?php endif;?>
          </td>
        </tr>
        
        <tr class="row-3 odd">
          <td>
            <?php if(isset($elements['field_vehiculo_serie'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_serie']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_serie']);?></td>
            </tr></table>
            <?php endif;?>
          </td>
          <td>
            <?php if(isset($elements['field_vehiculo_capacidad'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_capacidad']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_capacidad']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_descripcion_carga'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_descripcion_carga']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_descripcion_carga']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <table class="generic"><tr>
            </tr></table>
          </td>
        </tr>
        
        <tr class="row-4">
          <td>
            <?php if(isset($elements['field_vehiculo_motor'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_motor']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_motor']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_servicio'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_servicio']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_servicio']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_remolque'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_remolque']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_remolque']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <table class="generic"><tr>
            </tr></table>
          </td>
        </tr>
        
         <tr class="row-5 odd">
          <td>
            <?php if(isset($elements['field_vehiculo_transmision'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_transmision']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_transmision']);?></td>
            </tr></table>
            <?php endif;?>
          </td>
          <td>
            <?php if(isset($elements['field_vehiculo_carroceria'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_carroceria']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_carroceria']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <?php if(isset($elements['field_vehiculo_tipo_remolque'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_tipo_remolque']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_tipo_remolque']);?></td>
            </tr></table>
            <?php endif;?>
          </td>

          <td>
            <table class="generic"><tr>
            </tr></table>
          </td>
        </tr>

        <tr class="row-6 last">
          
            <?php if(isset($elements['field_vehiculo_descripcion'])):?>
            <table class="generic"><tr>
              <td class="padding-descripcion left-descripcion" ><strong><?php print $elements['field_vehiculo_descripcion']['#title'];?>:</strong></td>
              <td class="padding-descripcion" align="left"><?php print render($elements['field_vehiculo_descripcion']);?></td>
            </tr></table>
            <?php endif;?>
          
        </tr>
        
      </table>
    </td></tr></tbody>
  </table>
  
  <?php if(isset($elements['poliza_block_middle'])):?>
  <?php print render($elements['poliza_block_middle']);?>
  <?php endif;?>
  
  <?php print render($elements['field_poliza_coberturas']);?>
  
  <?php if(isset($elements['poliza_block_bottom'])):?>
  <?php print render($elements['poliza_block_bottom']);?>
  <?php endif;?>
  
  <?php if(isset($elements['poliza_block_aviso_de_privacidad'])):?>
  <?php print render($elements['poliza_block_aviso_de_privacidad']);?>
  <?php endif;?>
  
  <table class="generic">
    <tbody>
      <tr class="last">
        <td width="65%">
          <?php if(isset($elements['poliza_block_telefono_siniestros'])):?>
          <?php print render($elements['poliza_block_telefono_siniestros']);?>
          <?php endif;?>
        </td>
        <td>
          <?php if(isset($elements['poliza_block_footer_right'])):?>
          <?php print render($elements['poliza_block_footer_right']);?>
          <?php endif;?>
        </td>
      </tr>
    </tbody>
  </table>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
