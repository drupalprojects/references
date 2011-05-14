<?php

/**
 * @file
 * Handler for references_plugin_row_fields.
 */
class references_plugin_row_fields extends views_plugin_row_fields {
  
  function option_definition() {
    $options = parent::option_definition();

    // Provide a default separator.
    $options['separator'] = array('default' => '-');
    
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    // @todo add some descriptoon for inline.
  }

  function pre_render($result) {
    // Force all fields to be inline by default.
    if (empty($this->options['inline'])) {
      $fields = $this->view->get_items('field', $this->display->id);
      $this->options['inline'] = drupal_map_assoc(array_keys($fields));
    }
  }
}
