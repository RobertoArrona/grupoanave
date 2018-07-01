<?php

/**
 * @file
 * Display Suite 1 column template.
 */
//print_r($elements['field_visualizador']);exit;
  $archivo_adjunto = render($elements['field_siniestro_archivo_adjunto']);
  $archivo_adjunto2 = render($elements['field_visualizador']);
  $archivo_adjunto3 = render($elements['field_documentos']);
?>
<?php if ( (!empty($archivo_adjunto3)) || (!empty($archivo_adjunto2))):?>
<tr class="siniestro-archivo <?php print $zebra;?>" id="siniestro-archivo-<?php print $elements['#entity']->item_id;?>" data-archivo-id="<?php print $elements['#entity']->item_id;?>">
  <td class="fecha"><?php print render($elements['field_fecha']);?></td>
<!--   <td class="archivo"><?php print render($elements['archivo_nombre']);?></td> -->
  <td class="archivo"><?php print render($elements['field_documentos']);?></td>
  <td class="autor"><?php print render($elements['field_archivo_autor']);?></td>
  <td class="categoria"><?php print render($elements['field_archivo_categoria']);?></td>
<!--
  <td class="operaciones">
    <a href="<?php print render($elements['field_siniestro_archivo_adjunto']);?>" target="_blank">Ver</a>
  </td>
-->
  <td class="galeria"><?php print render($elements['field_visualizador']);?></td>
</tr>
<tr class="siniestro-archivo-comentario hidden" id="siniestro-archivo-comentario-<?php print $elements['#entity']->item_id;?>">
  <td colspan="4"><?php print render($elements['field_archivo_comentario']);?></td>
</tr>
<?php else:?>
&nbsp;
<?php endif;?>
