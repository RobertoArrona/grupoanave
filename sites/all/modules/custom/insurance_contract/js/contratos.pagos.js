(function ($) {
  $(document).on('ready', function(){
    var selector =  $('#edit-field-poliza-forma-pago select');
    var label =  $('#edit-field-poliza-primas-recibos-subs label');
    var labeltitle  = $('label[for="edit-title"]').hide();
    var IVA;
    var sum;
    var totalPremium;
    var numPayments;
    
    if (selector.length > 0) {
      if (selector.val() != '_none' && selector.val() !='anual'){
        updateLabel(label,selector.val());
      }
    }
    selector.change(function(){
      if (selector.length > 0) {
        if (selector.val() != '_none' && selector.val() !='anual'){
          updateLabel(label,selector.val());
        }
      }
    });
    
    //change event for Method of payment
    $('#edit-field-poliza-forma-pago-und').on('change', function () {
      var netPremium = $('#edit-field-poliza-prima-neta-und-0-value').val();
      var rightPolicy = $('#edit-field-derecho-de-poliza2-und').val();
      var IVAinput = $('#edit-field-poliza-impuesto-iva-und-0-value');
      var totalPremInput = $('#edit-field-poliza-prima-total-und-0-value');
      var paymentFirstInput = $('#edit-field-poliza-prima-1er-recibo-und-0-value');
      var subPaymentsInput = $('#edit-field-poliza-primas-recibos-subs-und-0-value');
      if(rightPolicy != '_none' && rightPolicy != undefined && netPremium != '' && netPremium != undefined && this.val() != '_none') {
        IVAinput.val(getIVA (netPremium, rightPolicy));
        totalPremInput.val(getTotalPremium (netPremium, rightPolicy, IVAinput.val()));
        paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, IVAinput.val()));
        subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, IVAinput.val()));
      }
    });
    
    //change event for Right of Policy
    $('#edit-field-derecho-de-poliza2-und').on('change', function () {
      var netPremium = $('#edit-field-poliza-prima-neta-und-0-value').val();
      var rightPolicy = $('#edit-field-derecho-de-poliza2-und').val();
      var IVAinput = $('#edit-field-poliza-impuesto-iva-und-0-value');
      var totalPremInput = $('#edit-field-poliza-prima-total-und-0-value');
      var paymentFirstInput = $('#edit-field-poliza-prima-1er-recibo-und-0-value');
      var subPaymentsInput = $('#edit-field-poliza-primas-recibos-subs-und-0-value');
      if(rightPolicy != '_none' && rightPolicy != undefined) {
        IVAinput.val(getIVA (netPremium, rightPolicy));
        totalPremInput.val(getTotalPremium (netPremium, rightPolicy, IVAinput.val()));
        paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, IVAinput.val()));
        subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, IVAinput.val()));
      }
    });
    
    //change event for Net Premium
    $('#edit-field-poliza-prima-neta-und-0-value').on('change', function () {
      var netPremium = $('#edit-field-poliza-prima-neta-und-0-value').val();
      var rightPolicy = $('#edit-field-derecho-de-poliza2-und').val();
      var IVAinput = $('#edit-field-poliza-impuesto-iva-und-0-value');
      var totalPremInput = $('#edit-field-poliza-prima-total-und-0-value');
      var paymentFirstInput = $('#edit-field-poliza-prima-1er-recibo-und-0-value');
      var subPaymentsInput = $('#edit-field-poliza-primas-recibos-subs-und-0-value');
      if(netPremium != '' && netPremium != undefined) {
        IVAinput.val(getIVA (netPremium, rightPolicy));
        totalPremInput.val(getTotalPremium (netPremium, rightPolicy, IVAinput.val()));
        paymentFirstInput.val(getPaymentFirst(netPremium, rightPolicy, IVAinput.val()));
        subPaymentsInput.val(getSubPayments(netPremium, rightPolicy, IVAinput.val()));
      }
    });
  });
  function updateLabel(label, text) {
    label.text(getPaymentsLabel(text));
  }
  function getPaymentsLabel(period){
    if (period == 'mensual') {
      return 'Primas Recibos Subs:(11) ';
    }
    else if(period == 'trimestral') {
      return 'Primas Recibos Subs:(3) ';
    }
    else if(period == 'semestral') {
      return 'Primas Recibos Subs:(1) ';
    }
  }
  function getIVA (netPre, rightPo) {
    sum = Math.round(netPre * 100) / 100 + parseInt(rightPo);
    return IVA = sum * 0.16;
  }
  
  function getTotalPremium (netPre, rightPo, IVAin) {
    return totalPremium = Math.round(netPre * 100) / 100 + parseInt(rightPo) + Math.round(IVAin * 100) / 100;
  }
  function getPaymentFirst (netPre, rightPo, IVAin) {
    netPre = Math.round(netPre * 100) / 100;
    rightPo = parseInt(rightPo);
    IVAin = Math.round(IVAin * 100) / 100;
    var firstPayment = netPre + IVAin;
    firstPayment = firstPayment / getnumPayments();
    firstPayment = firstPayment + rightPo;
    firstPayment = Math.round(firstPayment * 100) / 100;
    return firstPayment;
  }
  function getSubPayments (netPre, rightPo, IVAin) {
    netPre = Math.round(netPre * 100) / 100;
    rightPo = parseInt(rightPo);
    IVAin = Math.round(IVAin * 100) / 100;
    var SubPayments = netPre + IVAin;
    SubPayments = SubPayments / getnumPayments();
    SubPayments = Math.round(SubPayments * 100) / 100;
    return SubPayments;
  }
  function getnumPayments () {
    var period = $('#edit-field-poliza-forma-pago-und').val();
    if (period == 'mensual') {
      return numPayments = 12;
    }
    else if(period == 'trimestral') {
      return numPayments = 4;
    }
    else if(period == 'semestral') {
      return numPayments = 2;
    } 
    else if(period == 'anual') {
      return numPayments = 1;
    }
  }
})(jQuery);