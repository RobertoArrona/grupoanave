/**
 * @file
 * Retrieves contract values.
 */

(function ($) {
  // Declare global variable.
  var arrival_date,
      contract_folio;
  $(document).on('ready', function () {
    var group = $('.group-reserva input');
    var reservatotal = $('#edit-field-reserva-total input');
    var total = 0;

    group.change(function () {
      this.value = Decimal.format(this.value);
      group.each(function () {
        if (this.value === "") {
          this.value = 0;
        }
        total = parseFloat(total) + parseFloat(this.value);
      });
      reservatotal[0].value = Decimal.format(total - reservatotal[0].value);
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
      if ($(this).prop('checked') == true) {
        $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').removeClass('displayblock');
      }
      else if ($(this).prop('checked') == false) {
        $('#edit-field-conductor-und-0-field-nombre-quien-reporta, #edit-field-conductor-und-0-field-telefono-quien-reporta').addClass('displayblock');
      }
    });

    arrival_date = $('#edit-field-fecha-arribo-und-0-value-date').val();
    contract_folio = $('div.form-item-field-poliza-und-0-target-id .field-suffix label span a').text();
    $('#edit-field-vehiculo-tercero-und-0-field-3ro-numero-poliza-und-0-value').val(contract_folio);
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

  /**
   * Function to change arrival date.
   */
  $(document).on('change', '#edit-field-fecha-arribo-und-0-value-date', function (e) {
    e.preventDefault();

    // Add previous date.
    $(this).val(arrival_date);
  });

  /**
   * Change event for field piliza table.
   */
   $(document).on('DOMSubtreeModified', '#field-poliza-values tr td', function (e) {
     e.preventDefault();

     // Clone link text.
     contract_folio = $('div.form-item-field-poliza-und-0-target-id .field-suffix label span a').text();
     // Add contract folio to contract number input.
     $('#edit-field-vehiculo-tercero-und-0-field-3ro-numero-poliza-und-0-value').val(contract_folio);
   })

  /**
   * Function to change contract number input.
   */
  $(document).on('change', '#edit-field-vehiculo-tercero-und-0-field-3ro-numero-poliza-und-0-value', function (e) {
    e.preventDefault();

    // Add contract folio.
    $('#edit-field-vehiculo-tercero-und-0-field-3ro-numero-poliza-und-0-value').val(contract_folio);
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

  // Get number in decimal format.
  var Decimal = {
    format: function (number) {
      var finalNum,
          array,
          newArray;

      if ($.isNumeric(number)) { // Check if value is numeric.
        number = parseFloat(number); // Parse value to integer.
      }
      else {
        number = 0;
      }

      if (number - Math.floor(number) == 0) { // Check if finalNum is a integer value.
        number = number + '.00';
      }

      expr = /./;

      if (expr.test(number) && number != 0) { // Check if finalNum decimal and number is different from zero.
        if (!(number - Math.floor(number) == 0)) { // Check if finalNum is not an integer.
          number = number.toString(); // Convert finalNum to string.
          array = number.split('.'); // Divide string by '.' character.
          if (array[1].length == 1) { // Check if array in position zero has only one digit.
            number = array[0] + '.' + (array[1] + 0); // Add a zero to decimal part. Array in position 0 is the integer number.
          }
          if (array[1].length >= 2) { // Check if array in position zero has only one digit.
            newArray = array[1].split('');
            number = array[0] + '.' + (newArray[0] + newArray[1]); // Add first two decimals.
          }
        }
      }

      finalNum = number;

      return finalNum;
    }
  }

})(jQuery);
