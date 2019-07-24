/**
 * @file
 * Set date picker on sinister view filters.
 */

(function ($) {

  $(document).on('ready', function () {
    // Setup date picker.
    $('.views-widget-filter-created .form-item #edit-created-min, .views-widget-filter-created .form-item #edit-created-max').datepicker();
  });

})(jQuery);
