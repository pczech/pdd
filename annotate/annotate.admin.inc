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
  // Loop through each of the content type checkboxes shown on the form.
  foreach ($form_state['values']['annotate_node_types'] as $key => $value) {
    // If the check box for a content type is unchecked, look to see whether
    // this content type has the annotation field attached to it using the
    // field_info_instance function. If it does then we need to remove the
    // annotation field as the administrator has unchecked the box.
    if (!$value) {
      $instance = field_info_instance('node', 'annotation', $key);
      if (!empty($instance)) {
        field_delete_instance($instance);
        watchdog("Annotation", 'Deleted annotation field from content type:
          %key', array('%key' => $key));
      }
    }
    else {
      // If the check box for a content type is checked, look to see whether
      // the field is associated with that content type. If not then add the
      // annotation field to the content type.
      $instance = field_info_instance('node', 'annotation', $key);
      if (empty($instance)) {
        // There is hook_field_create_instance() available, so the local
        // function to create the annotate field has another name.
        field_annotate_create_instance($key);
        watchdog('Annotation', 'Added annotation field to content type: %key',
          array('%key' => $key));
      }
    }
  }
}


/**
 * Create annotate field instance.
 */
function field_annotate_create_instance($bundle) {
  $instance = array(
    'field_name' => 'annotation',
    'entity_type' => 'node',
    'bundle' => $bundle,
    'label' => t('Annotation'),
    'widget_type' => 'text_textarea_with_summary',
    'settings' => array(
      'display_summary' => TRUE,
    ),
    'display' => array(
      'default' => array(
        'type' => 'text_default',
      ),
      'teaser' => array(
        'type' => 'text_summary_or_trimmed',
      ),
    ),
  );
  $instance = field_create_instance($instance);
}
