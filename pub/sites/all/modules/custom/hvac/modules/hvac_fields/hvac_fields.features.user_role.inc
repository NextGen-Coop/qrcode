<?php
/**
 * @file
 * hvac_fields.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hvac_fields_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: customer.
  $roles['customer'] = array(
    'name' => 'customer',
    'weight' => 2,
  );

  // Exported role: technician.
  $roles['technician'] = array(
    'name' => 'technician',
    'weight' => 3,
  );

  return $roles;
}
