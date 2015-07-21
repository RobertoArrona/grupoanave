<?php
  //print_r(array_keys($elements));exit;
  if(isset($elements['field_domicilio'])) {
    $address = grupoanave_theme_address($elements['field_domicilio']);
  }
?>
<table class="print">
  <thead><tr>
    <th colspan="4" class="conductor-nombre">Conductor</th>
  </tr></thead>
  <tbody>
    <tr>
      <td colspan="4">
        <?php if(isset($elements['field_nombre'])):?>
        <?php print render($elements['field_nombre']);?>
        <?php endif;?>
      </td>
    </tr>
  </tbody>
  <thead>
    <tr>
      <th class="conductor-rfc">RFC</th>
      <th class="conductor-licencia">No y Tipo de Licencia</th>
      <th class="conductor-alta">Lugar y Fecha de Alta</th>
      <th class="conductor-telefono">Tel&eacute;fono</th>
    </tr>
  </thead>
  <tbody><tr>
    <td class="conductor-rfc">
      <?php if(isset($elements['field_rfc'])):?>
      <?php print render($elements['field_rfc']);?>
      <?php endif;?>
    </td>
    
    <td class="conductor-licencia">
      <?php if(isset($elements['field_licencia_numero'])):?>
      <?php print render($elements['field_licencia_numero']);?>
      <?php endif;?>
      <?php if(isset($elements['field_licencia_tipo'])):?>
      <em>(<?php print render($elements['field_licencia_tipo']);?>)</em>
      <?php endif;?>
    </td>
    
    <td class="conductor-alta">
      <?php if(isset($elements['field_licencia_alta_lugar'])):?>
      <?php print render($elements['field_licencia_alta_lugar']);?>
      <?php endif;?>, 
      <?php if(isset($elements['field_licencia_alta_fecha'])):?>
      <?php print render($elements['field_licencia_alta_fecha']);?>
      <?php endif;?>
    </td>
    
    <td class="conductor-telefono">
      <?php if(isset($elements['field_telefono'])):?>
      <?php print render($elements['field_telefono']);?>
      <?php endif;?>, 
    </td>
  </tr></tbody>
  <thead>
    <tr>
      <th colspan="4" class="conductor-domicilio">Domicilio</th>
    </tr>
  </thead>
  <tbody><tr>
    <td colspan="4" class="conductor-domicilio">
      <?php if(isset($address)):?>
      <?php print $address; ?>
      <?php endif;?>
    </td>
  </tr></tbody>
</table>
