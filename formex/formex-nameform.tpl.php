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

print '<div id="formex_nameform">';
print 'DUPA';
print $variables['formex_nameform']['color'];
print $variables['formex_nameform']['name'];
print $variables['formex_nameform']['submit'];
print $variables['formex_nameform']['hidden'];
print '</div>';

