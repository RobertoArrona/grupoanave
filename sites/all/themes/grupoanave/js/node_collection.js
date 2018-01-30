(function ($) {
  $( document ).ready(function() {
    var contractFolio = $('.node-collection-navigation-wrapper .node-collection-menu-level-1 .menu li.first.leaf a').attr('href');
    contractFolio = contractFolio.split('/');
    contractFolio = contractFolio[2];
    contractFolio = contractFolio.split('-');
    contractFolio = contractFolio[0];
    contractFolio = contractFolio.toUpperCase();
    var contract = $('.node-collection-navigation-wrapper .node-collection-menu-level-1 .menu li.first.leaf a');
    contract.text('Contrato-' + contractFolio)
    var receipt = $(".node-collection-navigation-wrapper .node-collection-menu-level-1 .menu li:not('.first') a");
    receipt.each(function(){
      var receiptFolio = $(this).text();
      $(this).text('Recibo-'+receiptFolio);
    });
  });
})(jQuery);