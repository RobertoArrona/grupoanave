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

<?php
/* $parent_data = node_collection_api_get_parent_node_instance($node->nid); */

// Get type page.
$url = ($_SERVER['REQUEST_URI']);
$typePage = preg_split('[/]', $url);
$typePage = $typePage[1];

// Set receipt class.
if ($typePage == "content") {
  $receiptClass = $typePage;
}
elseif ($typePage == "print") {
  $receiptClass = $typePage;
}
else {
  $receiptClass = "";
}
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <div id="main-payment-receip">

    <div class="print-header main-payment-header">
      <table>
        <tbody>
         <tr>
            <td class="print-logo">
              <strong>GP Mutual de M&eacute;xico A.C.</strong><br>
              Av. Prisciliano S&agrave;nchez Sur No. 181 Altos, Colonia <br>
              Centro, Tepic, Nayarit, M&eacute;xico<br>
              C.P. 63000<br>
            </td>
            <td class="print-title">
              <h1>CONCENTRACION EMPRESARIAL DE PAGO PARA USO EXCLUSIVO DEL BANCO</h1>
            </td>
          </tr>
        </tbody>
     </table>
    </div>

    <div class="recibo">
      <div class="col6 one">
        <table>
          <tr>
            <td>
              <div class="barcode"><?php print $content['field_codigo_de_barras_rc'][0]['#svg']; ?></div>
              <?php print $node->field_codigo_de_barras_rc[LANGUAGE_NONE][0]['safe_value']; ?>
            </td>
          </tr>
          <tr>
        </table>
      </div>

      <div class="col6 two">
        <table>
          <tr>
            <td> 
              <strong>Serie:</strong>
              <?php print $node->field_serie_rc[LANGUAGE_NONE][0]['value']; ?>
              <strong>Folio del Recibo:</strong>
              <?php print $node->title; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Vencimiento del Recibo:</strong>
              <?php
                if(isset($node->field_vencimiento_rc[LANGUAGE_NONE][0]['value'])) {
                  $due_date = $node->field_vencimiento_rc[LANGUAGE_NONE][0]['value'];
                  $due_date_format = payment_receipt_get_spanish_date_format($due_date);
                  print $due_date_format;
                }
              ?>
          </tr>

          <tr>
            <td>
              <strong>Periodo de cobertura del:</strong>
              <?php
                $coverage_period_format = payment_receipt_get_spanish_date_format($node->field_periodo_cobertura_rc[LANGUAGE_NONE][0]['value']);
                print $coverage_period_format;
              ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong class="to">al:</strong>
              <?php
                $coverage_period_2_format = payment_receipt_get_spanish_date_format($node->field_periodo_cobertura_rc[LANGUAGE_NONE][0]['value2']);
                print $coverage_period_2_format;
              ?>
            </td>
          </tr>

          <tr class="tr-contract-number">
            <td>
              <strong>Contrato No:</strong>
              <?php print $node->field_poliza[LANGUAGE_NONE][0]['entity']->title; ?>
            </td>
          </tr>

          <tr class="tr-payment">
            <td> 
              <strong>Forma de Pago:</strong>
              <?php print $node->field_poliza_forma_pago[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr class="tr-type-contract">
            <td> 
              <strong>Tipo de Contrato:</strong>
              <?php print $node->field_contract_type[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Moneda:</strong>
              <?php print $node->field_currency[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>
        </table>
      </div>

      <div class="col6 three">
        <table>
          <tr>
            <td> 
              <strong>Fecha de expedicion:</strong>
              <?php
                $expedition_date_format = payment_receipt_get_spanish_date_format($node->field_fecha_de_expedicion_rc[LANGUAGE_NONE][0]['value']);
                print $expedition_date_format;
              ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>Solicitante de contrato:</strong>
              <?php print strtoupper($node->field_asegurado_nombre[LANGUAGE_NONE][0]['value']); ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>Calle y No:</strong>
              <?php print $node->field_asegurado_domicilio[LANGUAGE_NONE][0]['thoroughfare']; ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>Municipio:</strong>
              <?php print $node->field_asegurado_domicilio[LANGUAGE_NONE][0]['locality']; ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>C.P:</strong>
              <?php print $node->field_asegurado_domicilio[LANGUAGE_NONE][0]['postal_code']; ?>
            </td>
          </tr>

          <tr class="last amount">
            <td>
              <strong>Importe con Letra:</strong>
              (<?php print $node->field_importe_con_letra_rc[LANGUAGE_NONE][0]['value']; ?>)
            </td>
          </tr>
        </table>
      </div>

      <div class="col6 last">
        <table>
          <tr>
            <td> 
              <strong class="netpremium">Prima Neta:</strong>
              <?php print $node->field_poliza_prima_neta[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong class="emission">Emision:</strong>
              <?php print $node->field_issuance[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Prima Total:</strong>
              <?php print $node->field_total_premium[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>
        </table>
      </div>
    </div>

    <div class="payment-copy">
      <p>En caso de no realizarse el pago del recibo de contrato, este ser&aacute; cancelado.</p>
      <div class="row-payment">
        <div class="number">
          <p>1.</p>
        </div>
        <div class="text">
          <p>Los pagos deber&aacute;n realizarse en cualquier sucursal de BANCOMER y en las oficinas de GP Mutual M&eacute;xico A.C. a trav&eacute;s de la referencia bancaria proporcionada.</p>
          <ul>
            <li>Cuenta: 0113025381</li>
            <li>Clabe interbancaria: 012560001130253814</li>
          </ul>
        </div>
      </div>
      <div class="row-payment">
        <div class="number">
          <p>2.</p>
        </div>
        <div class="text">
          <p>Este documento s&oacute;lo ser&aacute; valido mediante comprobante de pago en el banco, con el sello de la compa&ntilde;&iacute;a, o certificaci&oacute;n del mismo.</p>
        </div>
      </div>
      <div class="row-payment">
        <div class="number">
          <p>3.</p>
        </div>
        <div class="text">
          <p>No se aceptar&aacute; el pago si el recibo ha vencido su fecha de pago.</p>
        </div>
      </div>
      <div class="row-payment">
        <div class="number">
          <p>4.</p>
        </div>
        <div class="text">
          <p>Si el pago es realizado con cheque, este ser&aacute; recibido salvo buen cobro, el cual deber&aacute; extenderse a nombre de GP Mutual M&eacute;xico A.C.</p>
        </div>
      </div>
      <div class="row-payment">
        <div class="number">
          <p>5.</p>
        </div>
        <div class="text">
          <p>Los recibos deber&aacute;n pagarse seg&uacute;n su orden en la serie que corresponda y en el orden marcado.</p>
        </div>
      </div>
      <div class="row-payment">
        <div class="number">
          <p>6.</p>
        </div>
        <div class="text last">
          <p>Este documento no es un comprobante fiscal. Puede obtener el comprobante fiscal en las oficinas de la compa&ntilde;&iacute;a, o marcando el 01800 999 14 55 o a trav&eacute;s de su intermediario.</p>
        </div>
      </div>
    </div>
    <?php print render($content['links']); ?>
    <?php print render($content['comments']); ?>
  </div>

  <div id="main-payment-2" class="<?php print $receiptClass; ?>">
    <div class="print-header">
      <table>
        <tbody>
          <tr>
            <td class="print-logo">
              <strong>GP Mutual de M&eacute;xico A.C.</strong><br>
              Av. Prisciliano Z&agrave;nchez No. 181 Altos, Colonia <br>
              Centro, Tepic, Nayarit, M&eacute;xico<br>
              C.P. 63000<br>
            </td>
            <td class="print-title">
              <h1>CONCENTRACION EMPRESARIAL DE PAGO PARA USO EXCLUSIVO DEL BANCO</h1>
            </td>
          </tr>
        </tbody>
      </table>
    </div>

    <div class="recibo">
      <div class="col6 one">
        <table>
          <tr>
            <td>
              <div class="barcode"><?php print $content['field_codigo_de_barras_rc'][0]['#svg']; ?></div>
              <?php print $node->field_codigo_de_barras_rc[LANGUAGE_NONE][0]['safe_value']; ?>
            </td>
          </tr>
          <tr>
        </table>
      </div>

      <div class="col6 two">
        <table>
          <tr>
            <td>
              <strong>Serie:</strong>
              <?php print $node->field_serie_rc[LANGUAGE_NONE][0]['value']; ?>
              <strong>Folio del Recibo:</strong>
              <?php print $node->title; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Vencimiento del Recibo:</strong>
              <?php
                if(isset($node->field_vencimiento_rc[LANGUAGE_NONE][0]['value'])) {
                  $due_date = $node->field_vencimiento_rc[LANGUAGE_NONE][0]['value'];
                  $due_date_format = payment_receipt_get_spanish_date_format($due_date);
                  print $due_date_format;
                }
              ?>
          </tr>

          <tr>
            <td>
              <strong>Periodo de cobertura del:</strong>
              <?php
                $due_date_format = payment_receipt_get_spanish_date_format($node->field_periodo_cobertura_rc[LANGUAGE_NONE][0]['value']);
                print $due_date_format;
              ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong class="to">al:</strong>
              <?php
                $due_date_2_format = payment_receipt_get_spanish_date_format($node->field_periodo_cobertura_rc[LANGUAGE_NONE][0]['value2']);
                print $due_date_2_format;
              ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Contrato No:</strong>
              <?php print $node->field_poliza[LANGUAGE_NONE][0]['entity']->title; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Forma de Pago:</strong>
              <?php print $node->field_poliza_forma_pago[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Tipo de Contrato:</strong>
              <?php print $node->field_contract_type[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Moneda:</strong>
              <?php print $node->field_currency[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>
        </table>
      </div>

      <div class="col6 three">
        <table>
          <tr>
            <td> 
              <strong>Fecha de expedicion:</strong>
              <?php
                $expedition_date_format = payment_receipt_get_spanish_date_format($node->field_fecha_de_expedicion_rc[LANGUAGE_NONE][0]['value']);
                print $expedition_date_format;
              ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>Solicitante de contrato:</strong>
              <?php print strtoupper($node->field_asegurado_nombre[LANGUAGE_NONE][0]['value']); ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>Calle y No:</strong>
              <?php print $node->field_asegurado_domicilio[LANGUAGE_NONE][0]['thoroughfare']; ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>Municipio:</strong>
              <?php print $node->field_asegurado_domicilio[LANGUAGE_NONE][0]['locality']; ?>
            </td>
          </tr>

          <tr>
            <td>
              <strong>C.P:</strong>
              <?php print $node->field_asegurado_domicilio[LANGUAGE_NONE][0]['postal_code']; ?>
            </td>
          </tr>

          <tr class="last amount">
            <td>
              <strong>Importe con Letra:</strong>
              (<?php print $node->field_importe_con_letra_rc[LANGUAGE_NONE][0]['value']; ?>)
            </td>
          </tr>
        </table>
      </div>

      <div class="col6 last">
        <table>
          <tr>
            <td> 
              <strong class="netpremium">Prima Neta:</strong>
              <?php print $node->field_poliza_prima_neta[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong class="emission">Emision:</strong>
              <?php print $node->field_issuance[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>

          <tr>
            <td> 
              <strong>Prima Total:</strong>
              <?php print $node->field_total_premium[LANGUAGE_NONE][0]['value']; ?>
            </td>
          </tr>
        </table>
      </div>
    </div>
  </div>
</div>
