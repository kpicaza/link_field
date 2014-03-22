<?php

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

  return l($values['title'], $url, array('attributes' => $attributes));
}
