<?php
/**
 * @file
 * hvac_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hvac_fields_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_calculated_values|node|product|form';
  $field_group->group_name = 'group_calculated_values';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Calculated Values',
    'weight' => '5',
    'children' => array(
      0 => 'field_motor_capacity',
      1 => 'field_voltage_imbalance',
      2 => 'field_under_over_voltage',
      3 => 'field_over_under_full_load_amps',
      4 => 'field_calculated_a_phase_amps',
      5 => 'field_calculated_b_phase_amps',
      6 => 'field_calculated_c_phase_amps',
      7 => 'field_calculated_t_lead_1_4_amps',
      8 => 'field_calculated_t_lead_2_5_amps',
      9 => 'field_calculated_t_lead_3_5_amps',
      10 => 'field_amperage_imbalance',
      11 => 'field_estimated_running_hp',
      12 => 'field_estimated_motor_efficiency',
      13 => 'field_estimated_power_factor',
      14 => 'field_estimated_ave_motor_kw',
      15 => 'field_sync_stator_field_rpm',
      16 => 'field_igv_position',
      17 => 'field_max_body_temp',
      18 => 'field_motor_est_output_sync_rpm',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-calculated-values field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_calculated_values|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_client|node|product|form';
  $field_group->group_name = 'group_client';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Client',
    'weight' => '1',
    'children' => array(
      0 => 'field_client',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-client field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_client|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden_values|node|product|form';
  $field_group->group_name = 'group_hidden_values';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hidden Values',
    'weight' => '7',
    'children' => array(
      0 => 'field_nameplate_calculated_hp',
      1 => 'field_motor_kw_at_fla',
      2 => 'field_kva',
      3 => 'field_phase_average_volts',
      4 => 'field_max_voltage',
      5 => 'field_a_b_phase_absolute_v_ave',
      6 => 'field_b_c_phase_absolute_v_ave',
      7 => 'field_c_a_phase_absolute_v_ave',
      8 => 'field_total_volt_imbalance',
      9 => 'field_phase_average_amps',
      10 => 'field_max_amperage',
      11 => 'field_a_b_phase_absolute_a_ave',
      12 => 'field_b_c_phase_absolute_a_ave',
      13 => 'field_c_a_phase_absolute_a_ave',
      14 => 'field_total_amp_imbalance',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hidden-values field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hidden_values|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_initial_values|node|product|form';
  $field_group->group_name = 'group_initial_values';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Initial Values',
    'weight' => '4',
    'children' => array(
      0 => 'field_design_max_frequency',
      1 => 'field_system_design_voltage',
      2 => 'field_rated_load_amperage',
      3 => 'field_rotor_amperage_y',
      4 => 'field_rotor_amperage_v',
      5 => 'field_design_overload',
      6 => 'field_max_igv_motor_steps',
      7 => 'field_nameplate_power_factor',
      8 => 'field_nameplate_rated_efficiency',
      9 => 'field_motor_poles',
      10 => 'field_maximum_winding_temp',
      11 => 'field_max_shaft_end_bearing_temp',
      12 => 'field_max_outboard_bearing_temp',
      13 => 'field_motor_horsepower_rating',
      14 => 'field_motor_rated_rpm_60_hertz',
      15 => 'field_motor_service_factor',
      16 => 'field_maximum_body_temp',
      17 => 'field_motor_frame',
      18 => 'field_motor_max_temp',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-initial-values field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_initial_values|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_observed_values|node|product|form';
  $field_group->group_name = 'group_observed_values';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Observed Values',
    'weight' => '6',
    'children' => array(
      0 => 'field_measured_display_frequency',
      1 => 'field_a_b_phase_rms_volts',
      2 => 'field_b_c_phase_rms_volts',
      3 => 'field_c_a_phase_rms_volts',
      4 => 'field_measured_a_phase_amps',
      5 => 'field_measured_b_phase_amps',
      6 => 'field_measured_c_phase_amps',
      7 => 'field_measured_t_lead_1_4_amps',
      8 => 'field_measured_t_lead_2_5_amps',
      9 => 'field_measured_t_lead_3_6_amps',
      10 => 'field_measured_motor_kw',
      11 => 'field_winding_temp_a',
      12 => 'field_winding_temp_b',
      13 => 'field_winding_temp_c',
      14 => 'field_shaft_end_bearing_temp',
      15 => 'field_outboard_bearing_temp',
      16 => 'field_igv_motor_position',
      17 => 'field_body_temp',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-observed-values field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_observed_values|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product|node|product|form';
  $field_group->group_name = 'group_product';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product',
    'weight' => '2',
    'children' => array(
      0 => 'field_serial',
      1 => 'field_image',
      2 => 'field_type',
      3 => 'field_model',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_product|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reports|node|product|form';
  $field_group->group_name = 'group_reports';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reports',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-reports field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_reports|node|product|form'] = $field_group;

  return $export;
}
