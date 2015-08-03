(function ($) {
  Drupal.behaviors.cotizacionBlock = {
   attach: function (context, settings) {
     $('#block-webform-client-block-87', context).once('toggle', function () {
        $(this).find('> h2.block-title').append('<span class="toggle-button"></span>');
        $(this).find('> h2.block-title span.toggle-button').click(function(event){
          block = $(this).parent().parent();
          $(block).toggleClass('closed');
          (event.preventDefault) ? event.preventDefault() : event.returnValue = false;
        });
      });
    }
  };
})(jQuery);