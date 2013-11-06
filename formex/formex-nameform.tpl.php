<?php

/**
 * @file
 *
 * This is the template file for rendering the formexample nameform.
 * In this file each element of the form is rendered individually
 * instead of the entire form at once, giving me the ultimate control
 * over how my forms are laid out. I could also print the whole form
 * at once - using the predefined layout in the module by
 * printing $variables['formexample_nameform_form'];
 *
 */

_formex_trace(basename(__FILE__));
// dpm($variables);

print '<div id="formex_nameform">';
// For example, the order of elements can be changed:
print $variables['formex_nameform']['name_submit'];
print $variables['formex_nameform']['color'];
print $variables['formex_nameform']['name'];
print $variables['formex_nameform']['hidden'];

// Print the whole form.
// print $variables['formex_nameform_form'];
print '</div>';

