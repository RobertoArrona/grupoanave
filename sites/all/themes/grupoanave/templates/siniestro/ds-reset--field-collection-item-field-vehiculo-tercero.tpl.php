<?php
  $pattern = '/field-vehiculo-tercero\/(\d+)?"/msi';
  $string = $variables['layout_attributes'];
  $nid = intval(arg(1));
  
  $vehiculo_tercero_id = 0;
  if (preg_match($pattern, $string, $match)) {
    $vehiculo_tercero_id = $match[1];
  }
  $print_link = l(
    t('Print'), 
    'print/node/' . $nid,
    array(
      'query' => array(
        'print-vehiculo-tercero' => $vehiculo_tercero_id,
      )
    )
  );

  //print_r(array_keys($elements));exit;
  $propietario_address = $conductor_address = '';
  if(isset($elements['field_propietario_domicilio'])) {
    $propietario_address = grupoanave_theme_address($elements['field_propietario_domicilio']);
  }
  if(isset($elements['field_conductor_domicilio'])) {
    $conductor_address = grupoanave_theme_address($elements['field_conductor_domicilio']);
  }

  $active_class = '';
  if (isset($_GET['print-vehiculo-tercero']) && $_GET['print-vehiculo-tercero'] == $vehiculo_tercero_id) {
    $active_class = 'vehiculo-tercero-active';
  }
?>
<table class="print vehiculo-tercero <?php print $active_class; ?>" id="vehiculo-tercero-<?php print $vehiculo_tercero_id; ?>">
  <thead><tr>
    <th colspan="2">
      <span class="table-operations">
        <?php print $print_link;?>
      </span>
      <span class="table-label">Descripci&oacute;n de Veh&iacute;culo Tercero</span>
    </th>
  </tr></thead>
  
  <tbody>
    <tr class="nombres">
      <td width="50%">
        <strong>Nombre de Propietario</strong>: <?php print render($elements['field_propietario_nombre']);?>&nbsp;
      </td>
      <td width="50%">
        <strong>Nombre de Conductor</strong>: <?php print render($elements['field_conductor_nombre']);?>&nbsp;
      </td>
    </tr>
    
    <tr class="domicilio-telefonos">
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="75%">
            <strong>Direcci&oacute;n</strong>: <?php print $propietario_address;?>&nbsp;
          </td>
          <td class="last">
            <strong>Tel&eacute;fono</strong>: <?php print render($elements['field_propietario_telefono']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="75%">
            <strong>Direcci&oacute;n</strong>: <?php print $conductor_address;?>&nbsp;
          </td>
          <td class="last">
            <strong>Tel&eacute;fono</strong>: <?php print render($elements['field_conductor_telefono']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
    </tr>
    
    <tr class="vehiculo-datos">
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="50%">
            <strong>No. de Licencia</strong>: <br/><?php print render($elements['field_licencia_numero']);?>&nbsp;
          </td>
          <td class="last">
            <strong>Vehículo, Marca y Tipo</strong>: <br/><?php print render($elements['field_vehiculo_marca']);?>, <?php print render($elements['field_vehiculo_tipo']);?>
          </td>
        </tr></tbody></table>
      </td>
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="25%">
            <strong>Modelo</strong>: <br/><?php print render($elements['field_3ro_vehiculo_modelo']);?>&nbsp;
          </td>
          <td width="25%">
            <strong>Color</strong>: <br/><?php print render($elements['field_3ro_vehiculo_color']);?>&nbsp;
          </td>
          <td width="25%">
            <strong>Placas</strong>: <br/><?php print render($elements['field_3ro_vehiculo_placas']);?>&nbsp;
          </td>
          <td class="last">
            <strong>Serie</strong>: <br/><?php print render($elements['field_3ro_vehiculo_serie']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
    </tr>

    <tr class="seguros">
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="33%">
            <strong>Compa&ntilde;ía de Seguros</strong>: <br/><?php print render($elements['field_3ro_aseguradora']);?>&nbsp;
          </td>
          <td width="33%">
            <strong>Póliza</strong>: <br/><?php print render($elements['field_3ro_numero_poliza']);?>&nbsp;
          </td>
          <td class="last">
            <strong>Cobertura</strong>: <br/><?php print render($elements['field_3ro_cobertura']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="25%">
            <strong>Deducible</strong>: <br/><?php print render($elements['field_3ro_deducible']);?>&nbsp;
          </td>
          <td width="25%">
            <strong>Vencimiento</strong>: <br/><?php print render($elements['field_3ro_vencimiento']);?>&nbsp;
          </td>
          <td width="25%">
            <strong>Siniestro</strong>: <br/><?php print render($elements['field_3ro_siniestro']);?>&nbsp;
          </td>
          <td class="last">
            <strong>Ajustador</strong>: <br/><?php print render($elements['field_3ro_ajustador']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
    </tr>
    
    <tr class="danos"><td colspan="2">
      <strong>Da&ntilde;os del Vehículo Tercero</strong>: <br/><?php print render($elements['field_3ro_vehiculo_danos']);?>&nbsp;
    </td></tr>
  </tbody>
</table>
