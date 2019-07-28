/**
 * @file
 * Set date picker on sinister view filters.
 */

(function ($) {

  $(document).on('ready', function () {
    if (!$('body').hasClass('page-admin-anave-siniestros')) {
      return false;
    }

    // Setup date picker.
    $('.views-widget-filter-created .form-item #edit-created-min, .views-widget-filter-created .form-item #edit-created-max').datepicker();

    // Setup date labels.
    sinister_add_date_labels();
  });

  /**
   * Adds date labels.
   */
  function sinister_add_date_labels() {
    // Add "Desde" label on created min field.
    $('.form-type-textfield.form-item-created-min').prepend('<label for"edit-created-min">Desde</label>');
    // Modify label on created max field.
    $('.form-type-textfield.form-item-created-max').find('> label').text('Hasta');
  }

})(jQuery);
