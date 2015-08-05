(function ($) {
  /**
   * Vars
   */
  var blockClosed = $.cookie('blockClosed', '0', { expires: 7, path: '/' });
  $.cookie('blockClosed', '0', { expires: 7, path: '/' });
  
  Drupal.behaviors.cotizacionBlock = {
    attach: function (context, settings) {
      $('#block-webform-client-block-87', context).once('toggle', function () {
        alert($.cookie('blockClosed'));
        $(this).find('> h2.block-title').append('<span class="toggle-button"></span>');
        $(this).find('> h2.block-title span.toggle-button').click(function(event){
          block = $(this).parent().parent();
          $(block).toggleClass('closed');
          $.cookie('blockClosed', '1');
          (event.preventDefault) ? event.preventDefault() : event.returnValue = false;
        });
      });
    }
  };
})(jQuery);