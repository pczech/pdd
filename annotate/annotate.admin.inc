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

  /*
  $types = node_type_get_types();

  foreach($types as $node_type) {
    $options[$node_type->type] = $node_type->name;
  }

  dpm($options);
  */


  $options = array(
    'Option 1' => t('option 1'),
    'Option 2' => t('option 2'),
    );

  $defaults = array(
    'Option 2',
    );

   $form['annotate_node_types'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Users may annotate these content types'),
    '#description' => t('A text field will be available on these content types to
        make user-specific notes.'),
    '#default_value' => $defaults,
     );

  // return system_settings_form($form);
  return $form;
}
