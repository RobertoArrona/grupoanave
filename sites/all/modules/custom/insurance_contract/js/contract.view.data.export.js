/**
 * @file
 * Add functionality to view data export pages.
 */

(function ($) {
  $(document).on('ready', function () {
    // Add go back link on insurance contract view data export.
    if ($('body').hasClass('page-admin-global-contratosxls')) {
      var url = '/admin/global/contratos';
      insurance_contract_add_go_back_link(url);
    }

    // Add go back link on sinister view data export.
    if ($('body').hasClass('page-admin-global-datos-de-siniestroxls')) {
      var url = '/admin/global/siniestros';
      insurance_contract_add_go_back_link(url);
    }

    // Add go back link on payment receipt view data export.
    if ($('body').hasClass('page-admin-global-recibos-de-contratosxls')) {
      var url = '/admin/global/recibos';
      insurance_contract_add_go_back_link(url);
    }
  });

  /**
   * Adds go back link.
   */
  function insurance_contract_add_go_back_link(url) {
    // Create link.
    var link = '<p><a href="' + url + '">Regresar</a></p>';

    // Add link.
    $('#block-system-main .content').prepend(link);
  }
})(jQuery);
