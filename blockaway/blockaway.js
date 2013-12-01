/**
 * @file
 * jQuery scipts for block way module.
 */

jQuery(document).ready(function() {
  // Select all div elements of class 'block' inside the left sidebar.
  // and all div elements of class 'block' inside the
  // right sidebar, and hide them.
  // Check your theme’s page.tpl.php file to see what
  // selectors you should use – the following are for garland.
  var blocks = jQuery('#sidebar-first div.block, #sidebar-second div.block');
  
  //Hide them
  blocks.hide();
  
  // Add a button that, when clicked, will make them reappear.
  jQuery('#sidebar-first').prepend('<div id="collapsibutton">Show Blocks</div>');

  jQuery('#collapsibutton').css({
    'width': '90px',
    'border': 'solid',
    'border-width': '1px',
    'padding': '5px',
    'background-color': '#fff'
  });
  
  // Add a handler that runs once when the button is clicked.
  jQuery('#collapsibutton').one('click', function() {
    // Button clicked! Get rid of the button.
    jQuery('#collapsibutton').remove();
    
    // Display all our hidden blocks using an effect.
    blocks.slideDown("slow");
  });
});  
