(function ($) {
  Drupal.behaviors.rgb_color_colorpicker = {
    attach: function(context) {
      $(".edit-rgb-color-colorpicker").live("focus", function(event) {
        var edit_field = this;
        var picker = $(this).closest('tr').find(".rgb-color-colorpicker");
        
        // Hide all color pickers except this one.
        $(".rgb-color-colorpicker").hide();
        $(picker).show();
        $.farbtastic(picker, function(color) {
          edit_field.value = color;
        }).setColor(edit_field.value);
      });
    }
  }
})(jQuery);
