<?php

/**
 * External link markup callback.
 * 
 * @param string $value
 * @return html a tag
 */
function _link_formater_callback($value) {
  $url = !valid_url($value) ? '#' : strip_tags($value);
  return l($url, $url, array('attributes' => array('title' => $url, 'rel' => 'nofollow', 'target' => '_blank')));
}

/**
 * 
 * @param type $link
 * @return type
 */
function _validate_link($link) {
  if (!valid_url($link, TRUE)) {
    return array(
      'error' => 'link_field_url_invalid',
      'message' => t('Link must be valid url.'),
    );
  }
  $response = drupal_http_request($link);
  if ($response->code != 200) {
    return array(
      'error' => 'link_field_url_invalid',
      'message' => t('This url hen not valid response'),
    );
  }
}
