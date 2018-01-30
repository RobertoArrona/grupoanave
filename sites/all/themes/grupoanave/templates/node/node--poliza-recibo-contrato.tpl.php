<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<?php $parent_data = node_collection_api_get_parent_node_instance($node ->nid); 
//  print_r($parent_data); exit;
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
      <table class="tabla-recibo">
    
    <tbody><tr>
      <td class="">
        <table class="print-child tabla-recibo-col1">
          <tr>
            <td>
              <div class="barcode"><?php print render($node->field_codigo_de_barras[LANGUAGE_NONE][0]['safe_value']); ?></div>
            </td>
          </tr>
          <tr>
            <td> <strong>Fecha de expedicion:</strong> <?php print render($node->field_fecha_de_expedicion[LANGUAGE_NONE][0]['value']);?> 
            </td>
          </tr>
          
          <tr>
            <td>
              <strong>Solicitante de contrato:</strong>
              <?php /* if(isset($elements['field_asegurado_nombre'])): */?>
              <?php print render($parent_data->field_asegurado_nombre[LANGUAGE_NONE][0]['value']);?>
              <?php /* endif; */?>
            </td>

          <tr>
            <td>
              <?php /* if(isset($address['thoroughfare'])): */?>
              <div class="label-above">Calle y No:</div>
              <?php print render($parent_data->field_asegurado_domicilio[LANGUAGE_NONE][0][thoroughfare]);?>
              <?php /* endif; */?>
            </td>
          </tr>

          <tr>
            <td>
              <?php /* if(isset($address['premise'])): */?>
              <div class="label-above">Colonia:</div>
              <?php print render($parent_data->field_asegurado_domicilio[LANGUAGE_NONE][0][premise]);?>
              <?php /* endif; */?>
            </td>
          </tr>
          <tr>
            <td>
              <?php /* if(isset($address['locality'])): */?>
              <div class="label-above">Municipio:</div>
              <?php print render($parent_data->field_asegurado_domicilio[LANGUAGE_NONE][0][locality]);?>
              <?php /* endif; */?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php /* if(isset($address['premise'])): */?>
              <div class="label-above">C.P:</div>
              <?php print render($parent_data->field_asegurado_domicilio[LANGUAGE_NONE][0][postal_code]);?>
              <?php /* endif; */?>
            </td>
          </tr>

          <tr class="last amount">
            <td>
              <div class="label-above"><strong>Importe con Letra:</strong> </div>
                <?php print render($node->field_importe_con_letra[LANGUAGE_NONE][0]['value']); ?>
            </td>
          </tr>
          
        </table>
      </td>
      <td class="table-poliza">
        <table class="print-child tabla-recibo-col-2">
          <tbody>
	          <tr>
	            <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td class="serie"><strong>Serie:</strong></td>
                  <td class="left"><?php print render($node->field_serie[LANGUAGE_NONE][0]['value']); ?></td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
              <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td><strong class="folio">Folio del Recibo:</strong></td>
                  <td class="left"><?php print $title ?></td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
            
<!--
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
-->
            
            <tr>
              <td>
                <?php /* if(isset($elements['field_poliza_vigencia'])): */?>
                  <table class="generic">
                    <tr>
                      <td><strong>Vencimiento del Recibo:</strong></td>
                      <td class="left"><?php print render($node->field_vencimiento[LANGUAGE_NONE][0]['value']); ?></td>
                    </tr>
                    <tr>
                      <td><strong>Periodo de cobertura del:</strong></td>
                      <td class="left"><?php print render($node->field_periodo_cobertura[LANGUAGE_NONE][0]['value']);?></td>
                    </tr>
                  </table>
                <?php/*  endif; */?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php /* if(isset($elements['fin_vigencia'])): */?>
                <table class="generic"><tr>
                  <td class="to"><strong>al:</strong></td>
                  <td class="left"><?php print render($node->field_periodo_cobertura[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td>
            </tr>
            <tr>
               <td>
                <?php /* if(isset($elements['title'])): */?>
                <table class="generic"><tr>
                  <td class="contract-number"><strong>Contrato No:</strong></td>
                  <td class="left"><?php print render($parent_data->title);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td> 
              <td>
                <?php /* if(isset($elements['field_poliza_forma_pago'])): */?>
                <table class="generic"><tr>
                  <td class="payment-method"><strong>Forma de Pago:</strong></td>
                  <td class="left"><?php print render($parent_data->field_poliza_forma_pago[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td class="contract-type"><strong>Tipo de Contrato:</strong></td>
                  <td class="left"><?php print render($parent_data->field_poliza_tipo[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
              </td> 
              <td>
                <?php /* if(isset($elements['field_poliza_moneda'])): */?>
                <table class="generic"><tr>
                  <td class="coin"><strong>Moneda:</strong></td>
                  <td class="left"><?php print render($parent_data->field_poliza_moneda[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php /* if(isset($elements['field_poliza_prima_neta'])): */?>
                <table class="generic net-premium"><tr>
                  <td><strong>Prima Neta: </strong></td>
                  <td class="amount">$ <?php print render($parent_data->field_poliza_prima_neta[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Emision </strong></td>
                  <td class="amount">$0.00</td>
                </tr></table>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php /* if(isset($elements['field_poliza_impuesto_iva'])): */?>
                <table class="generic"><tr>
                  <td><strong>I.V.A:</strong></td>
                  <td class="amount"> $ <?php print render($parent_data->field_poliza_impuesto_iva[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td>
            </tr>
            
            <tr>
              <td></td>
              <td>
                <?php /* if(isset($elements['field_poliza_prima_total'])): */?>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Total: </strong></td>
                  <td class="amount">$ <?php print render($parent_data->field_poliza_prima_total[LANGUAGE_NONE][0]['value']);?></td>
                </tr></table>
                <?php /* endif; */?>
              </td>
            </tr>

  
        </table>
    </td></tr></tbody>
  </table>
  <div class="payment-copy">
    <p>En caso de no realizarce el pago del recibo de contrato, este sera cancelado.</p>
    <div class="row-payment">
      <div class="number">
        <p>1.</p>
      </div>
      <div class="text">
        <p>Los pagos deberan realizarce en cualquier sucursarl de Santander y en las oficnas de MN Global Protec A.C. a travez de la referencia bancaria Proporcionada.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>2.</p>
      </div>
      <div class="text">
        <p>Este documento solo sera valido mediente comprovante de pago en el banco, con el sello de la compañia, o certificacion del mismo.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>3.</p>
      </div>
      <div class="text">
        <p>No se aceptara el pago si el recibo ha vencido su fecha de pago.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>4.</p>
      </div>
      <div class="text">
        <p>Si el pago es realizadon con cheque, este sera recibido salvo buen cobro, el cual debera extenderce a nombre de MN Global Protec A.C.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>5.</p>
      </div>
      <div class="text">
        <p>Los recibos deberan pagarce segun su orden en la serie que corresponda y en el orden marcado.</p>
      </div>
    </div>
    <div class="row-payment">
      <div class="number">
        <p>6.</p>
      </div>
      <div class="text last">
        <p>Este documento no es un comprovante fiscal. Puede obtener el comprovante fiscal en las oficinas de la compania, o marcando el 01800 999 00 69 o a travez de su intermediario.</p>
      </div>
    </div>
  </div>
  
  <table class="tabla-recibo">
    
    <tbody><tr>
      <td class="">
        <table class="print-child tabla-recibo-col1">
          <tr>
            <td>
              <div class="barcode"></div>
            </td>
          </tr>
          <tr>
            <td> <strong>Fecha de expedicion:</strong> <?php print render($elements['field_poliza_emision']);?> 
            </td>
          </tr>
          
          <tr>
            <td>
              <strong>Solicitante de contrato:</strong>
              <?php if(isset($elements['field_asegurado_nombre'])):?>
              <?php print render($elements['field_asegurado_nombre']);?>
              <?php endif;?>
            </td>

          <tr>
            <td>
              <?php if(isset($address['thoroughfare'])):?>
              <div class="label-above">Calle y No:</div>
              <?php print $address['thoroughfare'];?>
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
          </tr>
          <tr>
            <td>
              <?php if(isset($address['locality'])):?>
              <div class="label-above">Municipio:</div>
              <?php print $address['locality'];?>
              <?php endif;?>
            </td>
          </tr>
          
          <tr>
            <td>
              <?php if(isset($address['premise'])):?>
              <div class="label-above">C.P:</div>
              <?php print '63780';?>
              <?php endif;?>
            </td>
          </tr>

          <tr class="last amount">
            <td>
              <div class="label-above"><strong>Importe con Letra:</strong> </div>
                (MIL SETECIENTOS CUARENTA PESOS 00/100 M.N.)
            </td>
          </tr>
          
        </table>
      </td>
      <td class="table-poliza">
        <table class="print-child tabla-recibo-col-2">
          <tbody>
	          <tr>
	            <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td class="serie"><strong>Serie:</strong></td>
                  <td class="left">1/1</td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
              <td>
<!--                 <?php if(isset($office)):?> -->
                <table class="generic"><tr>
                  <td><strong class="folio">Folio del Recibo:</strong></td>
                  <td class="left">1000001</td>
                </tr></table>
<!--                 <?php endif;?> -->
              </td>
            
<!--
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
-->
            
            <tr>
              <td>
                <?php if(isset($elements['field_poliza_vigencia'])):?>
                  <table class="generic">
                    <tr>
                      <td><strong>Vencimiento del Recibo:</strong></td>
                      <td class="left"><?php print render($elements['field_poliza_vigencia']);?></td>
                    </tr>
                    <tr>
                      <td><strong>Periodo de cobertura del:</strong></td>
                      <td class="left"><?php print render($elements['field_poliza_vigencia']);?></td>
                    </tr>
                  </table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <?php if(isset($elements['fin_vigencia'])):?>
                <table class="generic"><tr>
                  <td class="to"><strong>al:</strong></td>
                  <td class="left"><?php print render($elements['fin_vigencia']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
               <td>
                <?php if(isset($elements['title'])):?>
                <table class="generic"><tr>
                  <td class="contract-number"><strong>Contrato No:</strong></td>
                  <td class="left"><?php print render($elements['title']);?></td>
                </tr></table>
                <?php endif;?>
              </td> 
              <td>
                <?php if(isset($elements['field_poliza_forma_pago'])):?>
                <table class="generic"><tr>
                  <td class="payment-method"><strong><?php print $elements['field_poliza_forma_pago']['#title'];?>:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_forma_pago']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td>
                <table class="generic"><tr>
                  <td class="contract-type"><strong>Tipo de Contrato:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_tipo']);?> Daños a Terceros</td>
                </tr></table>
              </td> 
              <td>
                <?php if(isset($elements['field_poliza_moneda'])):?>
                <table class="generic"><tr>
                  <td class="coin"><strong><?php print $elements['field_poliza_moneda']['#title'];?>:</strong></td>
                  <td class="left"><?php print render($elements['field_poliza_moneda']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_prima_neta'])):?>
                <table class="generic net-premium"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Neta: </strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_prima_neta']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Emision </strong></td>
                  <td class="amount">$0.00</td>
                </tr></table>
              </td>
            </tr>
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_impuesto_iva'])):?>
                <table class="generic"><tr>
                  <td><strong>I.V.A:</strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_impuesto_iva']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>
            
            <tr>
              <td></td>
              <td>
                <?php if(isset($elements['field_poliza_prima_total'])):?>
                <table class="generic"><tr>
                  <td><strong><!-- <?php print $elements['field_poliza_prima_total']['#title'];?> -->Prima Total: </strong></td>
                  <td class="amount"><?php print render($elements['field_poliza_prima_total']);?></td>
                </tr></table>
                <?php endif;?>
              </td>
            </tr>

  
        </table>
    </td></tr></tbody>
  </table>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
