<?php

function _link_field_path() {
  return drupal_get_path('module', 'link_field');
}

/**
 * External link markup callback.
 * 
 * @param array $values
 * @return html a tag
 */
function _link_formater_callback($values) {
  $url = !valid_url($values['url']) ? '#' : strip_tags($values['url']);
  $attributes = array();
  foreach ($values as $key => $value) {
    if (!empty($value)) {
      $attributes[$key] = $value;
    }
  }
  unset($attributes['url']);
  unset($attributes['link_text']);

  return l($values['link_text'], $url, array('attributes' => $attributes));
}
