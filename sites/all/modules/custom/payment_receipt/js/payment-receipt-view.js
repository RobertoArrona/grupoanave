/**
 * @file
 * Set up labels on payment receipt view filters.
 */

(function ($) {

  $(document).on('ready', function () {
    if (!$('body').hasClass('page-admin-global-recibos')) {
      return false;
    }

    // Setup date labels.
    sinister_modify_date_labels();
  });

  /**
   * Modifies date labels.
   */
  function sinister_modify_date_labels() {
    // Modify label on period coverage min field.
    $('.form-type-date-popup.form-item-field-periodo-cobertura-rc-value-min').find('> label').text('Desde');
    // Modify label on period coverage max field.
    $('.form-type-date-popup.form-item-field-periodo-cobertura-rc-value-max').find('> label').text('Hasta');
  }

})(jQuery);
