<?php

/**
 * @file
 * Theme preprocessing file.
 *
 * For all the conditional logic and data processing of the output, there is
 * the template.php file. It is not required, but to keep the .tpl.php files
 * tidy it can be used to hold preprocessors for generating variables before
 * they are merged with the markup inside .tpl.php files. Custom functions,
 * overriding theme functions or any other customization of the raw output
 * should also be done here. This file must start with a PHP opening tag
 * "<?php", but the close tag is not needed and it is recommended that you
 * omit it.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function grayscale_process_html(&$variables) {
  // dpm($variables);
  $classes = explode(' ', $variables['classes']);
  // dpm($classes);
  $classes[] = theme_get_setting('font_family');
  $classes[] = theme_get_setting('font_size');
  $variables['classes'] = trim(implode(' ', $classes));
  // dpm($variables);
}


/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
/*
function grayscale_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  dpm($breadcrumb);

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' * ', $breadcrumb) . '</div>';
    return $output;
  }
}
*/