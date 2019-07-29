/**
 * @file
 * Add functionality to contract form.
 */

(function ($) {
  $(document).on('ready', function () {
    var selector = $('#edit-field-poliza-forma-pago select');
    var label = $('#edit-field-poliza-primas-recibos-subs label');
    var labeltitle = $('label[for="edit-title"]').hide();
    var IVA;
    var sum;
    var totalPremium;
    var numPayments;

    var nodeCollection = $('.node-collection-navigation-wrapper');
    nodeCollection.css("display","none");
    var links = $('.action-links li > a');
    var administerLink = links[2];

    if (administerLink) {
      administerLink.hidden = true;
      var listAsociateInvoice = links[0]
      listAsociateInvoice.textContent = 'Ver Recibos de Pago Referenciado';
      listAsociateInvoice.text
      var createInvoice = links[1];
      createInvoice.textContent = 'Crear Recibos Para Pago Referenciado';
      var createReceipt = $('ul.action-links li:nth-child(2) a');
      // Returns path only.
      var pathname = window.location.pathname;
      var split = pathname.split('/');
      var node = split[2];
      var createReceiptURL = '/node/add/recibo-contrato?parent_node_id=' + node;
      createReceipt.attr('href', createReceiptURL);
    }

    if (selector.length > 0) {
      if (selector.val() != '_none' && selector.val() != 'anual') {
        updateLabel(label,selector.val());
      }
    }

    selector.change(function () {
      if (selector.length > 0) {
        if (selector.val() != '_none' && selector.val() != 'anual') {
          updateLabel(label,selector.val());
        }
      }
    });

    // Change event for Method of payment.
    $('#edit-field-poliza-forma-pago-und').on('change', function () {
      var netPremium = $('#edit-field-poliza-prima-neta-und-0-value').val();
      var rightPolicy = $('#edit-field-derecho-de-poliza2-und').val();
      /*var IVAinput = $('#edit-field-poliza-impuesto-iva-und-0-value');*/
      var IVAinput = 0;
      var totalPremInput = $('#edit-field-poliza-prima-total-und-0-value');
      var paymentFirstInput = $('#edit-field-poliza-prima-1er-recibo-und-0-value');
      var subPaymentsInput = $('#edit-field-poliza-primas-recibos-subs-und-0-value');
      var $this = $(this).val();

      if (rightPolicy == '_none' || rightPolicy == undefined) {
        rightPolicy = 0;
      }

      if (netPremium == '' || netPremium == undefined) {
        netPremium = 0;
      }

      if ($this != '_none') {
      /*IVAinput.val(getIVA (netPremium, rightPolicy));
        totalPremInput.val(getTotalPremium (netPremium, rightPolicy, IVAinput.val()));
        paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, IVAinput.val()));
        subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, IVAinput.val()));*/
      totalPremInput.val(getTotalPremium(netPremium, rightPolicy, 0));
      paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, 0));
      subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, 0));
      }
    });

    // Change event for Right of Policy.
    $('#edit-field-derecho-de-poliza2-und').on('change', function () {
      var netPremium = $('#edit-field-poliza-prima-neta-und-0-value').val();
      var rightPolicy = $('#edit-field-derecho-de-poliza2-und').val();
     /*var IVAinput = $('#edit-field-poliza-impuesto-iva-und-0-value');*/
     var IVAinput = 0;
      var totalPremInput = $('#edit-field-poliza-prima-total-und-0-value');
      var paymentFirstInput = $('#edit-field-poliza-prima-1er-recibo-und-0-value');
      var subPaymentsInput = $('#edit-field-poliza-primas-recibos-subs-und-0-value');
      var paymentMethod = $('#edit-field-poliza-forma-pago-und').val();
      if (rightPolicy == '_none' || rightPolicy == undefined) {
        rightPolicy = 0;
      }
      if (netPremium == '' || netPremium == undefined) {
        netPremium = 0;
      }

      // IVAinput.val(getIVA (netPremium, rightPolicy));
      // totalPremInput.val(getTotalPremium (netPremium, rightPolicy, IVAinput.val()));
      totalPremInput.val(getTotalPremium(netPremium, rightPolicy, 0));
      /*var IVA = IVAinput.val();*/
      var IVA = 0;
      if (paymentMethod != '_none') {
        paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, IVA));
        subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, IVA));
      }
    });

    // Change event for Net Premium.
    $('#edit-field-poliza-prima-neta-und-0-value').on('change', function () {
      var netPremium = $('#edit-field-poliza-prima-neta-und-0-value').val();
      var rightPolicy = $('#edit-field-derecho-de-poliza2-und').val();
      /*var IVAinput = $('#edit-field-poliza-impuesto-iva-und-0-value');*/
      var IVAinput = 0;
      var totalPremInput = $('#edit-field-poliza-prima-total-und-0-value');
      var paymentFirstInput = $('#edit-field-poliza-prima-1er-recibo-und-0-value');
      var subPaymentsInput = $('#edit-field-poliza-primas-recibos-subs-und-0-value');
      var paymentMethod = $('#edit-field-poliza-forma-pago-und').val();
      if (rightPolicy == '_none' || rightPolicy == undefined) {
        rightPolicy = 0;
      }
      if (netPremium == '' || netPremium == undefined) {
        netPremium = 0;
      }
      // IVAinput.val(getIVA (netPremium, rightPolicy));
      /*totalPremInput.val(getTotalPremium (netPremium, rightPolicy, IVAinput.val()));*/
      totalPremInput.val(getTotalPremium(netPremium, rightPolicy, 0));
      /*var IVA = IVAinput.val();*/
      var IVA = 0;
      if (paymentMethod != '_none') {
        paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, IVA));
        subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, IVA));
      }
    });
  });

  function updateLabel(label, text) {
    label.text(getPaymentsLabel(text));
  }

  function getPaymentsLabel(period) {
    if (period == 'mensual') {
      return 'Primas Recibos Subs:(11) ';
    }
    else if (period == '3meses') {
      return 'Primas Recibos Subs:(2) ';
    }
    else if (period == 'trimestral') {
      return 'Primas Recibos Subs:(3) ';
    }
    else if (period == 'cuatrimestral') {
      return 'Primas Recibos Subs:(2) ';
    }
    else if (period == 'semestral') {
      return 'Primas Recibos Subs:(1) ';
    }
  }

  function getIVA(netPre, rightPo) {
    sum = Math.round(netPre * 100) / 100 + Math.round(rightPo * 100) / 100;
    IVA = sum * 0.16;
    return Math.round(IVA * 100) / 100;
  }

  function getTotalPremium(netPre, rightPo, IVAin) {
    var totalPremium = Math.round(netPre * 100) / 100 + Math.round(rightPo * 100) / 100 + Math.round(IVAin * 100) / 100;
    return Math.round(totalPremium * 100) / 100;
  }

  function getPaymentFirst(netPre, rightPo, IVAin) {
    netPre = Math.round(netPre * 100) / 100;
    rightPo = Math.round(rightPo * 100) / 100;
    IVAin = Math.round(IVAin * 100) / 100;
    var firstPayment = netPre + IVAin;
    firstPayment = firstPayment / getnumPayments();
    firstPayment = firstPayment + rightPo;
    return Math.round(firstPayment * 100) / 100;
  }

  function getSubPayments(netPre, rightPo, IVAin) {
    netPre = Math.round(netPre * 100) / 100;
    rightPo = Math.round(rightPo * 100) / 100;
    IVAin = Math.round(IVAin * 100) / 100;
    var SubPayments = netPre + IVAin;
    SubPayments = SubPayments / getnumPayments();
    return Math.round(SubPayments * 100) / 100;
  }

  function getnumPayments() {
    var period = $('#edit-field-poliza-forma-pago-und').val();
    if (period == 'mensual') {
      return numPayments = 12;
    }
    else if (period == '3meses') {
      return numPayments = 3;
    }
    else if (period == 'trimestral') {
      return numPayments = 4;
    }
    else if (period == 'cuatrimestral') {
      return numPayments = 3;
    }
    else if (period == 'semestral') {
      return numPayments = 2;
    }
    else if (period == 'anual') {
      return numPayments = 1;
    }
  }

})(jQuery);
