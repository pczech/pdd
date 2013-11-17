<?php

/**
 * @file
 * Common tools for PDD modules.
 */


/**
 * Traces function calls.
 */
function pdd_trace_funct() {
  $trace = debug_backtrace();
  if (isset($trace[1])) {
    dpm($trace[1]['function']);
  }
}