(function ($) {
  $(document).on('ready', function(){
	  var group =  $('.group-reserva input');
		var reservatotal = $('#edit-field-reserva-total input');
		var total = 0;

		group.change(function(){
			var suma = 0
			group.each(function(){
				if(this.value === ""){
					this.value = 0;
			  }
			    total = parseInt(total + parseInt(this.value));
			    console.log(total);
		  })
		   reservatotal[0].value = total - reservatotal[0].value;
		   total = 0;
		})

	});
	
	$(document).on('change', function(){
		var linkcontrato = $('label[for="edit-field-poliza-und-0"] > span > a');
	  var checkcontrato = $('#edit-field-poliza-und-0');
	  var valuescontrato = $('#field-poliza-values .odd'); 

	  linkcontrato.attr("target", "_blank");

	});
})(jQuery);