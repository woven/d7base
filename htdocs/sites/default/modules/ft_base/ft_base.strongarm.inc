<?php
/**
 * @file
 * ft_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ft_base_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'rubik';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme_admin_theme_batch';
  $strongarm->value = 1;
  $export['admin_theme_admin_theme_batch'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme_path';
  $strongarm->value = '';
  $export['admin_theme_path'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme_path_disallow';
  $strongarm->value = '';
  $export['admin_theme_path_disallow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = '1';
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tp_base';
  $strongarm->value = FALSE;
  $export['tp_base'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_show_additional_queries';
  $strongarm->value = 0;
  $export['views_show_additional_queries'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_always_live_preview';
  $strongarm->value = 1;
  $export['views_ui_always_live_preview'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_custom_theme';
  $strongarm->value = '_default';
  $export['views_ui_custom_theme'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_advanced_column';
  $strongarm->value = 1;
  $export['views_ui_show_advanced_column'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_advanced_help_warning';
  $strongarm->value = 1;
  $export['views_ui_show_advanced_help_warning'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_listing_filters';
  $strongarm->value = 0;
  $export['views_ui_show_listing_filters'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_master_display';
  $strongarm->value = 1;
  $export['views_ui_show_master_display'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_performance_statistics';
  $strongarm->value = 0;
  $export['views_ui_show_performance_statistics'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_preview_information';
  $strongarm->value = 1;
  $export['views_ui_show_preview_information'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_sql_query';
  $strongarm->value = 0;
  $export['views_ui_show_sql_query'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_sql_query_where';
  $strongarm->value = 'above';
  $export['views_ui_show_sql_query_where'] = $strongarm;

  return $export;
}
