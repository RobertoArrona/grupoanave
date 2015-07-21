<?php

/**
 * @file
 * Display Suite 1 column template.
 */
//print_r(array_keys($elements));exit;
?>
<tr class="siniestro-archivo <?php print $zebra;?>" id="siniestro-archivo-<?php print $elements['#entity']->item_id;?>" data-archivo-id="<?php print $elements['#entity']->item_id;?>">
  <td class="fecha"><?php print render($elements['field_fecha']);?></td>
  <td class="archivo"><?php print render($elements['archivo_nombre']);?></td>
  <td class="autor"><?php print render($elements['field_archivo_autor']);?></td>
  <td class="categoria"><?php print render($elements['field_categoria_archivo']);?></td>
  <td class="operaciones">
    <a href="<?php print render($elements['field_siniestro_archivo_adjunto']);?>" target="_blank">Ver</a>
  </td>
</tr>
<tr class="siniestro-archivo-comentario hidden" id="siniestro-archivo-comentario-<?php print $elements['#entity']->item_id;?>">
  <td colspan="4"><?php print render($elements['field_archivo_comentario']);?></td>
</tr>
