<?php

/**
 * @file
 * Display Suite 1 column template.
 */
 $cabina_uid = $elements['author']['#object']->uid;
 $cabina = user_load($cabina_uid);
 $cabina_name = "{$cabina->field_first_name[LANGUAGE_NONE][0]['safe_value']} {$cabina->field_last_name[LANGUAGE_NONE][0]['safe_value']}";
 //print_r(array_keys($elements));exit;
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <h1><?php print $title;?></h1>

  <table class="print">
    <thead>
      <tr>
        <th>Datos Generales</th>
        <th>Lugar de Siniestro</th>
        <th>Agentes</th>
      </tr>
    </thead>
    <tbody><tr>
      <td class="table-generales">
        <table class="print-child">
          <tbody>
            <tr><td>
              <strong>Numero de Contrato:</strong>
              <?php if(isset($elements['field_poliza'])):?>
              <div>
              <?php print render($elements['field_poliza']);?>
              </div>
              <?php endif;?>
            </td></tr>
            
            <tr><td>
              <strong>Fecha de Siniestro:</strong>
              <div>
              <?php print render($elements['post_date']);?>
              </div>
            </td></tr>
            
            <tr class="last"><td>
              <strong>Asegurado:</strong>
              <div>
              <?php print render($elements['asegurado']);?>
              </div>
            </td></tr>
            
          </tbody>
        </table>
      </td>
      
      <td class="table-generales">
        <table class="print-child">
          <tbody>
            <tr><td>
              <strong>Poblaci&oacute;n:</strong>
              <?php if(isset($elements['field_poblacion'])):?>
              <div>
              <?php print render($elements['field_poblacion']);?>
              </div>
              <?php endif;?>
            </td></tr>
            
            <tr><td>
              <strong>Estado:</strong>
              <?php if(isset($elements['field_poblacion'])):?>
              <div>
              <?php print render($elements['field_estado_single']);?>
              </div>
              <?php endif;?>
            </td></tr>
            
            <tr><td>
              <strong>Referencias del Lugar:</strong>
              <?php if(isset($elements['field_lugar_referencias'])):?>
              <div>
              <?php print render($elements['field_lugar_referencias']);?>
              </div>
              <?php endif;?>
            </td></tr>
            
          </tbody>
        </table>
      </td>
      
      <td class="table-agentes">
        <table class="print-child">
          <tbody>
            <tr>
              <td>
                <strong>Cabina:</strong>
                <div>
                <?php print $cabina_name;?>
                </div>
              </td>
            </tr>
            
            <tr>
              <td>
                <strong>Ajustador:</strong>
                <?php if(isset($elements['field_ajustador'])):?>
                <div>
                <?php print render($elements['field_ajustador']);?>
                </div>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <strong>Abogado:</strong>
                <?php if(isset($elements['field_abogado'])):?>
                <?php print render($elements['field_abogado']);?>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <strong>Hospital:</strong>
                <?php if(isset($elements['field_hospital'])):?>
                <?php print render($elements['field_hospital']);?>
                <?php endif;?>
              </td>
            </tr>
            
            <tr class="last">
              <td>
                <strong>Taller:</strong>
                <?php if(isset($elements['field_taller'])):?>
                <?php print render($elements['field_taller']);?>
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
        <tr class="row-1">
          <td>
            <?php if(isset($elements['field_vehiculo_marca'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_marca']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_marca']);?></td>
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
            <?php if(isset($elements['field_vehiculo_clave_sbg'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_clave_sbg']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_clave_sbg']);?></td>
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
            <?php if(isset($elements['field_vehiculo_uso'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_uso']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_uso']);?></td>
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
        </tr>
        
        <tr class="row-3">
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
            <?php if(isset($elements['field_vehiculo_referencia'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_referencia']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_referencia']);?></td>
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
            <?php if(isset($elements['field_vehiculo_numero_pedimento'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_numero_pedimento']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_numero_pedimento']);?></td>
            </tr></table>
            <?php endif;?>
          </td>
          <td>
            <?php if(isset($elements['field_vehiculo_numero_inventario'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_numero_inventario']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_numero_inventario']);?></td>
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
        </tr>
        
         <tr class="row-5 last">
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
            <?php if(isset($elements['field_vehiculo_servicio'])):?>
            <table class="generic"><tr>
              <td><strong><?php print $elements['field_vehiculo_servicio']['#title'];?>:</strong></td>
              <td align="right"><?php print render($elements['field_vehiculo_servicio']);?></td>
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
        </tr>
        
      </table>
    </td></tr></tbody>
  </table>
  
  <table class="print">
    <thead>
      <tr>
        <th colspan="2">Tipo de Poliza:</th>
      </tr>
    </thead>
    <tbody>
      <tr class="last">
        <td colspan="2">
          <?php if(isset($elements['field_poliza_tipo'])):?>
          <?php print render($elements['field_poliza_tipo']);?>
          <?php endif;?>
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
          <?php if(isset($elements['coberturas_de_poliza'])):?>
          <?php print render($elements['coberturas_de_poliza']);?>
          <?php endif;?>
        </td>
        <td width="50%">
          <?php if(isset($elements['field_poliza_deducibles'])):?>
          <?php print render($elements['field_poliza_deducibles']);?>
          <?php endif;?>
        </td>
      </tr>
    </tbody>
  </table>
  
  <?php if(isset($elements['links'])):?>
  <?php print render($elements['links']);?>
  <?php endif;?>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
