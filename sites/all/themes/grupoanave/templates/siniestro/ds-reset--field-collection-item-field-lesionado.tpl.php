<?php
  //print_r(array_keys($elements));exit;
  $address = $conductor_address = '';
  if(isset($elements['field_lesionado_domicilio'])) {
    $address = grupoanave_theme_address($elements['field_lesionado_domicilio']);
  }
?>
<table class="print lesionado">
  <thead><tr>
    <th colspan="2">Lesiones y Da&ntilde;os</th>
  </tr></thead>
  
  <tbody>
    <tr class="nombre-edad">
      <td width="50%">
        <table class="print-child-2"><tbody><tr>
          <td>
            <strong>Nombre</strong>: <br/><?php print render($elements['field_lesionado_nombre']);?>&nbsp;
          </td>
          <td width="10%" class="last">
            <strong>Edad</strong>: <br/><?php print render($elements['field_lesionado_edad']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
      <td width="50%">
        <table class="print-child-2"><tbody><tr>
          <td width="60%">
            <strong>Direcci&oacute;n</strong>: <br/><?php print $address;?>&nbsp;
          </td>
          <td width="20%">
            <strong>Tel&eacute;fono</strong>: <br/><?php print render($elements['field_lesionado_telefono']);?>&nbsp;
          </td>
          <td class="last">
            <strong>Riesgo B</strong>: <br/><?php print render($elements['field_lesionado_riesgo_b']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
    </tr>
    
    <tr class="lesiones">
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="70%">
            <strong>Lesiones Sufridas</strong>: <br/><?php print render($elements['field_lesionado_lesiones']);?>&nbsp;
          </td>
          <td width="30%" class="last">
            <strong>Ambulancia</strong>: <br/><?php print render($elements['field_lesionado_ambulancia_info']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
      
      <td>
        <table class="print-child-2"><tbody><tr>
          <td width="10%">
            <strong>Ambulancia</strong>: <br/><?php print render($elements['field_lesionado_ambulancia']);?>&nbsp;
          </td>
          <td class="last">
            <strong>Se otorg&oacute; Pase M&eacute;dico a la Cl&iacute;nica</strong>: <br/><?php print render($elements['field_lesionado_pase_medico']);?>&nbsp;
          </td>
        </tr></tbody></table>
      </td>
    </tr>
    
  </tbody>
</table>
