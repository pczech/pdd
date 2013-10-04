<?php

/**
 * @file
 * Administration page callbacks for the annotate module.
 */

/**
 * Form builder. Configure annotations.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function annotate_admin_settings() {
  $form = array();

  // Get an array of node types with internal names as keys and
  // "friendly names" as values. E.g.,
  // array('page' => ’Basic Page, 'article' => 'Articles')
  $types = node_type_get_types();

  foreach ($types as $node_type) {
    $options[$node_type->type] = $node_type->name;
  }

  $form['annotate_node_types'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Users may annotate these content types'),
    '#description' => t('A text field will be available on these content types
        to make user-specific notes.'),
    '#default_value' => variable_get('annotate_node_types', array('page')),
  );

  // Add own submit function that will process the form.
  $form['#submit'][] = 'annotate_admin_settings_submit';

  // system_settings_form() adds "Save configuration" button to the form and
  // adds system_settings_form_submit() to the form submit function list. This
  // submit function saves the form elemet data to persistent variable
  // (by calling variable_set()) named like the form element (here
  // 'annotate_node_types'). To use the stored values in the form (to show
  // current settings in the form), the name of the variable used by
  // variable_get() in the form must match the name of the form element
  // (here 'annotate_node_types').
  return system_settings_form($form);
}

/**
 * Process annotation settings submission.
 */
function annotate_admin_settings_submit($form, $form_state) {
}
