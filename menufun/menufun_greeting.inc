<?php

/**
 * @file
 * Page callback for menufun module
 */

/**
 * Demonstrates page callback in other file.
 */
function menufun_greeting_hello($first_name = '', $last_name = '', $from_first_name = '', $from_last_name = '') {
  // If a page callback function uses an argument list array, and its path is
  // requested with optional path arguments, then the list array's arguments
  // are passed to the callback function first, followed by the optional path
  // arguments.
  $substitute = array(
    '@fn' => $first_name,
    '@ln' => $last_name,
    '@ffn' => $from_first_name,
    '@fln' => $from_last_name,
  );

  return t('Greeting to @fn @ln from @ffn @fln', $substitute);
}
