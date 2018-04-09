/**
 * @file
 * Retrieves contract values.
 */

(function ($) {
  $(document).on('ready', function () {
    var group = $('.group-reserva input');
    var reservatotal = $('#edit-field-reserva-total input');
    var total = 0;

    group.change(function () {
      var suma = 0;
      group.each(function () {
        if (this.value === "") {
          this.value = 0;
        }
        total = parseInt(total + parseInt(this.value));
        console.log(total);
      })
      reservatotal[0].value = total - reservatotal[0].value;
      total = 0;
    });

    // Vefify if driver reports field is checked on document ready.
    if ($('#edit-field-conductor-und-0-field-conductor-reporta-und').prop('checked') == true){
      $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').removeClass('displayblock');
    }
    else if ($('#edit-field-conductor-und-0-field-conductor-reporta-und').prop('checked') == false) {
      $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').addClass('displayblock');
    }

    // Vefify if driver reports field is checked on click event.
    $(document).on('click', '#edit-field-conductor-und-0-field-conductor-reporta-und', function () {
       console.log('clecked..');
      if ($(this).prop('checked') == true){
        $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').removeClass('displayblock');
      }
      else if ($(this).prop('checked') == false) {
        $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').addClass('displayblock');
      }
    });
  });

  $(document).on('change', function () {
    var linkcontrato = $('label[for="edit-field-poliza-und-0"] > span > a');
    var checkcontrato = $('#edit-field-poliza-und-0');
    var valuescontrato = $('#field-poliza-values .odd');

    linkcontrato.attr("target", "_blank");
  });
})(jQuery);
