(function ($) {

  /**
   * The recommended way for producing HTML markup through JavaScript is to write
   * theming functions. These are similiar to the theming functions that you might
   * know from 'phptemplate' (the default PHP templating engine used by most
   * Drupal themes including Omega). JavaScript theme functions accept arguments
   * and can be overriden by sub-themes.
   *
   * In most cases, there is no good reason to NOT wrap your markup producing
   * JavaScript in a theme function.
   */
  Drupal.theme.prototype.anaveExampleButton = function (path, title) {
    // Create an anchor element with jQuery.
    return $('<a href="' + path + '" title="' + title + '">' + title + '</a>');
  };

  /**
   * Behaviors are Drupal's way of applying JavaScript to a page. In short, the
   * advantage of Behaviors over a simple 'document.ready()' lies in how it
   * interacts with content loaded through Ajax. Opposed to the
   * 'document.ready()' event which is only fired once when the page is
   * initially loaded, behaviors get re-executed whenever something is added to
   * the page through Ajax.
   *
   * You can attach as many behaviors as you wish. In fact, instead of overloading
   * a single behavior with multiple, completely unrelated tasks you should create
   * a separate behavior for every separate task.
   *
   * In most cases, there is no good reason to NOT wrap your JavaScript code in a
   * behavior.
   *
   * @param context
   *   The context for which the behavior is being executed. This is either the
   *   full page or a piece of HTML that was just added through Ajax.
   * @param settings
   *   An array of settings (added through drupal_add_js()). Instead of accessing
   *   Drupal.settings directly you should use this because of potential
   *   modifications made by the Ajax callback that also produced 'context'.
   */
  Drupal.behaviors.anaveHomeBlocks = {
    attach: function (context, settings) {
      $('#block-views-home-blocks-block', context).once('foo', function () {
        wrapper = $(this).find('.node--home-blocks--full');
        $(wrapper).find('> .field-collection-container').addClass('vtabs-content');
        $(wrapper).prepend('<div class="vtabs"><ul></ul></div>');
        vtabs = $(wrapper).find('.vtabs ul');
        length = $(this).find('.home-block > .field-collection-view').length;
        $(this).find('.home-block > .field-collection-view').each(function(index){
          i = index+1;
          $(this).attr('id', 'home-vtab-' + i);
          $(this).addClass('vtab-content-page');
          tab_title = $(this).find('.field-collection-item-field-home-block > h3').text();
          classes = '';
          if ( i == 1 ) {
            classes += 'first active';
          }
          if ( i == length ) {
            classes += ' last';
          }
          $(this).addClass(classes);
          classes = 'class="vtab-content-li ' + $.trim(classes) + '"';
          $(vtabs).append('<li ' + classes + '><a class="vtab-anchor" href="#home-vtab-' + i + '">' + tab_title + '</a></li>');
        });
        
        // Click
        $('.vtab-anchor').click(vtabClick);
      });
    }
  };

  function vtabClick(e) {
    if ( !$(this).parent().hasClass('active') ) {
      $('.vtab-content-li.active').removeClass('active');
      $(this).parent().addClass('active');
      idd = $(this).attr('href');
      $('.vtab-content-page.active').fadeOut(500, function(){
        $(this).removeClass('active');
        $(idd).fadeIn(500, function(){
          $(this).addClass('active');
        });
      });
      
    }
    e.preventDefault();
  }

})(jQuery);
