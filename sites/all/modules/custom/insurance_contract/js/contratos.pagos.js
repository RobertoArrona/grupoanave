(function ($) {
    $(document).on('ready', function(){
      var selector =  $('#edit-field-poliza-forma-pago select');
      var label =  $('#edit-field-poliza-primas-recibos-subs label');
      var labeltitle  = $('label[for="edit-title"]').hide();
      
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
  })(jQuery);