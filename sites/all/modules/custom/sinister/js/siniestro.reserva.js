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
    if ($('#edit-field-conductor-und-0-field-conductor-reporta-und').prop('checked') == true) {
      $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').removeClass('displayblock');
    }
    else if ($('#edit-field-conductor-und-0-field-conductor-reporta-und').prop('checked') == false) {
      $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').addClass('displayblock');
    }

    // Vefify if driver reports field is checked on click event.
    $(document).on('click', '#edit-field-conductor-und-0-field-conductor-reporta-und', function () {
       console.log('clecked..');
      if ($(this).prop('checked') == true) {
        $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').removeClass('displayblock');
      }
      else if ($(this).prop('checked') == false) {
        $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').addClass('displayblock');
      }
    });

    $('#edit-field-fecha-arribo-und-0-value-datepicker-popup-0').prop('disabled',true);
    $('#edit-field-fecha-arribo-und-0-value-timeEntry-popup-1').prop('disabled',true);
    $('#edit-field-mapa-arribo-und-0-address-field').prop('disabled',true);
    $('#edit-field-mapa-arribo [id^="geolocation-address-geocode"]').css('display','none');
    $('#edit-field-mapa-arribo [id^="geolocation-client-location"]').css('display','none');
    $('#edit-field-mapa-arribo [id^="geolocation-remove"]').css('display','none');
    $('#edit-field-mapa-arribo [id^="geolocation-help"]').css('display','none');
  });

  $(document).on('change', function () {
    var linkcontrato = $('label[for="edit-field-poliza-und-0"] > span > a');
    var checkcontrato = $('#edit-field-poliza-und-0');
    var valuescontrato = $('#field-poliza-values .odd');

    linkcontrato.attr("target", "_blank");
  });

  /**
   * Function to format phone number fields.
   */
  $(document).on('change', 'input[id*="telefono"]', function (e) {
    e.preventDefault();

    var phonenumber = $(this).val(); // Clone input value.
    $(this).val(Phone.format(phonenumber)); // Assign formated phone number.
  });

  // Format phone numbers.
  var Phone = {
    format: function (phone) {
      var key;
      var numberPhone;
      var formatted = '';

      // Declare strings to be deleted.
      key = {
        '-': '',
        ' ': ''
      };

      if (phone) {
        // Delete indicated strings.
        numberPhone = phone.replace(/[- ]/g, (char) => key[char] || '');
        // Format phone number.
        formatted = numberPhone.substr(0, 3) + '-' + numberPhone.substr(3, 3) + '-' + numberPhone.substr(6,4);
      }

      return formatted;
    }
  }

})(jQuery);
