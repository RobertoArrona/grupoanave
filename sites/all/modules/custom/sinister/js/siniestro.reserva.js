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
  })(jQuery);