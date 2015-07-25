<?php
  //print_r(array_keys($elements));exit;
  $propietario_address = $conductor_address = '';
  if(isset($elements['field_propietario_domicilio'])) {
    $propietario_address = grupoanave_theme_address($elements['field_propietario_domicilio']);
  }
  if(isset($elements['field_conductor_domicilio'])) {
    $conductor_address = grupoanave_theme_address($elements['field_conductor_domicilio']);
  }
?>
<table class="print vehiculo-tercero">
  <thead><tr>
    <th colspan="4">Descripci&oacute;n de Veh&iacute;culo Tercero</th>
  </tr></thead>
  
  <tbody>
    <tr class="nombres">
      <td colspan="2">
        <strong>Nombre de Propietario</strong>: <?php print render($elements['field_propietario_nombre']);?>
      </td>
      <td colspan="2">
        <strong>Nombre de Conductor</strong>: <?php print render($elements['field_conductor_nombre']);?>
      </td>
    </tr>
    
    <tr class="domicilio-telefonos">
      <td>
        <strong>Direcci&oacute;n</strong>: <?php print render($elements['field_propietario_domicilio']);?>
      </td>
      <td>
        <strong>Tel&eacute;fono</strong>: <?php print render($elements['field_propietario_telefono']);?>
      </td>
      <td>
        <strong>Direcci&oacute;n</strong>: <?php print render($elements['field_conductor_domicilio']);?>
      </td>
      <td>
        <strong>Tel&eacute;fono</strong>: <?php print render($elements['field_conductor_telefono']);?>
      </td>
    </tr>
  </tbody>
</table>
