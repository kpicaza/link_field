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

/**
 * Function that provide a list of 'rel' attribute values.
 * 
 * @see http://www.w3schools.com/TAGS/att_a_rel.asp
 * 
 * @return array
 */
function _link_rel_options() {
  return array(
    '', 'alternate', 'author', 'bookmark', 'help', 'license', 'next', 'nofollow', 'noreferrer', 'prefetch', 'prev', 'search', 'tag',
  );
}

/**
 * Function that provide a list of 'target' attribute values.
 * 
 * @see http://www.w3schools.com/tags/att_a_target.asp
 * 
 * @return array
 */
function _link_target_options() {
  return array(
    '', '_blank', '_self', '_parent', '_top',
  );
}
