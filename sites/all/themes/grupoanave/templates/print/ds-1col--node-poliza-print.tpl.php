<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <table class="print">
    <thead>
      <tr>
        <th>Datos del Asegurado</th>
        <th>Datos de la Poliza</th>
      </tr>
    </thead>
    <tbody><tr>
      <td class="table-asegurado">
        <table class="print-child">
          <tr>
            <td colspan="2">
              <?php print render($elements['field_asegurado_nombre']);?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php print render($elements['field_asegurado_calle_num']);?>
            </td>
            <td>
              <?php print render($elements['field_asegurado_rfc']);?>
            </td>
          </tr>
          
          <tr>
            <td colspan="2">
              <?php print render($elements['field_asegurado_colonia']);?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php print render($elements['field_asegurado_poblado']);?>
            </td>
            <td>
              <?php print render($elements['field_asegurado_cp']);?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php print render($elements['field_asegurado_estado']);?>
            </td>
            <td>
              <?php print render($elements['field_asegurado_telefono']);?>
            </td>
          </tr>
          
          <tr class="last">
            <td colspan="2">
              <?php print render($elements['field_asegurado_benef_pref']);?>
            </td>
          </tr>
          
        </table>
      </td>
      <td class="table-poliza">
        <table class="print-child">
          <tbody>
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong>Numero de Contrato:</strong></td>
                  <td align="right"><?php print render($elements['title']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_prima_neta']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_prima_neta']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_emision']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_emision']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_emision']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_reduccion']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_vigencia']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_vigencia']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_rgo_pago_fracc']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_rgo_pago_fracc']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['fin_vigencia']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['fin_vigencia']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_derecho_poliza']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_derecho_poliza']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_moneda']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_moneda']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_impuesto_iva']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_impuesto_iva']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_forma_pago']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_forma_pago']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_prima_total']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_prima_total']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_tipo_movimiento']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_tipo_movimiento']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_prima_1er_recibo']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_prima_1er_recibo']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_conducto_cobro']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_conducto_cobro']);?></td>
                </tr></table>
              </td>
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_primas_recibos_subs']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_primas_recibos_subs']);?></td>
                </tr></table>
              </td>
            </tr>
            
            <tr class="last">
              <td>
                <table class="generic"><tr>
                  <td><strong><?php print $elements['field_poliza_intermediario']['#title'];?>:</strong></td>
                  <td align="right"><?php print render($elements['field_poliza_intermediario']);?></td>
                </tr></table>
              </td>
              <td>&nbsp;</td>
            </tr>
            
          </tbody>
        </table>
      </td>
    </tr></tbody>
  </table>
  
  <table class="print">
    <thead>
      <tr>
        <th>Datos del Vehiculo</th>
      </tr>
    </thead>
    <tbody><tr><td>
      <table class="print-child">
        <tr>
          <td>
            <?php print render($elements['field_vehiculo_marca']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_descripcion']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_uso']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_placas']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_color']);?>
          </td>
        </tr>
        
        <tr>
          <td>
            <?php print render($elements['field_vehiculo_submarca']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_transmision']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_clave_sbg']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_modelo']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_categoria']);?>
          </td>
        </tr>
        
        <tr>
          <td>
            <?php print render($elements['field_vehiculo_capacidad']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_motor']);?>
          </td>
          <td>
            <?php print render($elements['field_vehiculo_repuve']);?>
          </td>
          <td>
            &nbsp;
          </td>
          <td>
            <?php print render($elements['field_vehiculo_carroceria']);?>
          </td>
        </tr>
        
        <tr>
          <td>
            <?php print render($elements['field_vehiculo_serie']);?>
          </td>
          <td colspan="4">
            &nbsp;
          </td>
        </tr>
        
         <tr class="last">
          <td>
            <?php print render($elements['field_vehiculo_cilindro']);?>
          </td>
          <td colspan="4">
            &nbsp;
          </td>
        </tr>
        
      </table>
    </td></tr></tbody>
  </table>
  <?php print render($elements['poliza_block_middle']);?>
  
  <table class="print">
    <thead>
      <tr>
        <th colspan="2">Tipo de Poliza:</th>
      </tr>
    </thead>
    <tbody>
      <tr class="last">
        <td colspan="2">
          <?php print render($elements['field_poliza_tipo']);?>
        </td>
      </tr>
    </tbody>
    <thead>
      <tr>
        <th>
          Riesgos Amparados:
        </th>
        <th>
          Deducibles:
        </th>
      </tr>
    </thead>
    <tbody>
      <tr class="last">
        <td width="50%">
          <?php print render($elements['coberturas_de_poliza']);?>
        </td>
        <td width="50%">
          <?php print render($elements['field_poliza_deducibles']);?>
        </td>
      </tr>
    </tbody>
  </table>
  
  <?php print render($elements['poliza_block_bottom']);?>
  
  <?php print render($elements['poliza_block_aviso_de_privacidad']);?>
  
  <table class="generic">
    <tbody>
      <tr class="last">
        <td width="65%">
          <?php print render($elements['poliza_block_telefono_siniestros']);?>
        </td>
        <td>
          <?php print render($elements['poliza_block_footer_right']);?>
        </td>
      </tr>
    </tbody>
  </table>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
