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
      
       <tr class="row-5 odd last">
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
