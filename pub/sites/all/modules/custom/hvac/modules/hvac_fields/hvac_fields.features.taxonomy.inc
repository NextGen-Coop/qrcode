<?php
/**
 * @file
 * hvac_fields.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hvac_fields_taxonomy_default_vocabularies() {
  return array(
    'manufacturer' => array(
      'name' => 'Manufacturer',
      'machine_name' => 'manufacturer',
      'description' => 'A list of available manufacturers for products.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
