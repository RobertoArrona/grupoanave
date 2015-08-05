(function ($) {
  /**
   * Vars
   */
  if (typeof $.cookie('blockClosed') === 'undefined') {
    $.cookie('blockClosed', '0', { expires: 7, path: '/' });
  }
  
  Drupal.behaviors.cotizacionBlock = {
    attach: function (context, settings) {
      $('#block-webform-client-block-87', context).once('toggle', function () {
        if ( $.cookie('blockClosed') == '1' ) {
          $(this).addClass('closed');
        }
        
        $(this).find('> h2.block-title').append('<span class="toggle-button"></span>');
        $(this).find('> h2.block-title span.toggle-button').click(function(event){
          block = $(this).parent().parent();
          if ( $.cookie('blockClosed') == '0' ) {
            $(block).addClass('closed');
            $.cookie('blockClosed', '1');
          } else {
            $.cookie('blockClosed', '0');
            $(block).removeClass('closed');
          }
          
          
          (event.preventDefault) ? event.preventDefault() : event.returnValue = false;
        });
      });
    }
  };
})(jQuery);