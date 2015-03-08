<?php
/**
 * @file
 * Computed field values.
 */

/**
 * Implements hook_field_nameplate_calculated_hp_compute().
 *
 * ( system_design_voltage * rated_load_amperage * nameplate_rated_fl_efficiency * SQRT( 3 ) * nameplate_power_factor ) / 746
 */
function computed_field_field_nameplate_calculated_hp_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = ($entity->field_system_design_voltage[$langcode][0]['value']
    * $entity->field_rated_load_amperage[$langcode][0]['value']
    * $entity->field_nameplate_rated_efficiency[$langcode][0]['value']
    * sqrt(3)
    * $entity->field_nameplate_power_factor[$langcode][0]['value'])
    / 746;
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_nameplate_calculated_hp_display().
 */
function computed_field_field_nameplate_calculated_hp_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_motor_kw_at_fla_compute().
 * 
 * ( system_design_voltage * rated_load_amperage * SQRT( 3 ) * nameplate_power_factor ) / 1000
 */
function computed_field_field_motor_kw_at_fla_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = ($entity->field_system_design_voltage[$langcode][0]['value']
    * $entity->field_rated_load_amperage[$langcode][0]['value']
    * sqrt(3)
    * $entity->field_nameplate_power_factor[$langcode][0]['value'])
    / 1000;
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_motor_kw_at_fla_display().
 */
function computed_field_field_motor_kw_at_fla_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_kva_compute().
 *
 * (SQRT(3) * system_design_voltage * system_rated_load_average) / 1000
 */
function computed_field_field_kva_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = (sqrt(3)
    * $entity->field_system_design_voltage[$langcode][0]['value']
    * $entity->field_rated_load_amperage[$langcode][0]['value'])
    / 1000;
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_kva_display().
 */
function computed_field_field_kva_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_phase_average_volts_compute().
 *
 * AVERAGE( a_b_phase_rms_volts, b_c_phase_rms_volts, c_a_phase_rms_volts )
 */
function computed_field_field_phase_average_volts_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array(
    $entity->field_a_b_phase_rms_volts[$langcode][0]['value'],
    $entity->field_b_c_phase_rms_volts[$langcode][0]['value'],
    $entity->field_c_a_phase_rms_volts[$langcode][0]['value'],
  );
  $entity_field[$langcode][0]['value'] = array_sum($values) / count($values);
}

/**
 * Implements hook_field_phase_average_volts_display().
 */
function computed_field_field_phase_average_volts_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_max_voltage_compute().
 *
 * MAX( a_b_phase_rms_volts, b_c_phase_rms_volts, c_a_phase_rms_volts )
 */
function computed_field_field_max_voltage_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array(
    $entity->field_a_b_phase_rms_volts[$langcode][0]['value'],
    $entity->field_b_c_phase_rms_volts[$langcode][0]['value'],
    $entity->field_c_a_phase_rms_volts[$langcode][0]['value'],
  );
  $entity_field[$langcode][0]['value'] = max($values);
}

/**
 * Implements hook_field_max_voltage_display().
 */
function computed_field_field_max_voltage_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_b_c_phase_absolute_v_ave_compute().
 *
 * ABS( phase_average_volts - b_c_phase_rms_volts )
 */
function computed_field_field_b_c_phase_absolute_v_ave_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_phase_average_volts[$langcode][$langcode][0]['value']
    - $entity->field_b_c_phase_rms_volts[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = abs($values);
}

/**
 * Implements hook_field_b_c_phase_absolute_v_ave_display().
 */
function computed_field_field_b_c_phase_absolute_v_ave_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_c_a_phase_absolute_v_ave_compute().
 *
 * ABS( phase_average_volts - c_a_phase_rms_volts )
 */
function computed_field_field_c_a_phase_absolute_v_ave_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_phase_average_volts[$langcode][$langcode][0]['value']
    - $entity->field_c_a_phase_rms_volts[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = abs($values);
}

/**
 * Implements hook_field_c_a_phase_absolute_v_ave_display().
 */
function computed_field_field_c_a_phase_absolute_v_ave_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_total_volt_imbalance_compute().
 *
 * SUM( a_b_phase_absolute_v_ave, b_c_phase_absolute_v_ave, c_a_phase_absolute_v_ave ) / 2
 */
function computed_field_field_total_volt_imbalance_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array(
    $entity->field_a_b_phase_absolute_v_ave,
    $entity->field_b_c_phase_absolute_v_ave,
    $entity->field_c_a_phase_absolute_v_ave,
  );
  $entity_field[$langcode][0]['value'] = array_sum($values);
}

/**
 * Implements hook_field_total_volt_imbalance_display().
 */
function computed_field_field_total_volt_imbalance_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_phase_average_amps_compute().
 *
 * AVERAGE( measured_a_phase_amps, measured_b_phase_amps, measured_c_phase_amps )
 */
function computed_field_field_phase_average_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array(
    $entity->field_measured_a_phase_amps[$langcode][0]['value'],
    $entity->field_measured_b_phase_amps[$langcode][0]['value'],
    $entity->field_measured_c_phase_amps[$langcode][0]['value'],
  );
  $entity_field[$langcode][0]['value'] = array_sum($values) / count($values);
}

/**
 * Implements hook_field_phase_average_amps_display().
 */
function computed_field_field_phase_average_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_max_amperage_compute().
 *
 * MAX( measured_a_phase_amps, measured_b_phase_amps, measured_c_phase_amps )
 */
function computed_field_field_max_amperage_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array(
    $entity->field_measured_a_phase_amps[$langcode][0]['value'],
    $entity->field_measured_b_phase_amps[$langcode][0]['value'],
    $entity->field_measured_c_phase_amps[$langcode][0]['value'],
  );
  $entity_field[$langcode][0]['value'] = max($values);
}

/**
 * Implements hook_field_max_amperage_display().
 */
function computed_field_field_max_amperage_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_a_b_phase_absolute_a_ave_compute().
 *
 * ABS( phase_average_amps - measured_a_phase_amps )
 */
function computed_field_field_a_b_phase_absolute_a_ave_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_phase_average_amps[$langcode][$langcode][0]['value']
    - $entity->field_measured_a_phase_amps[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = abs($values);
}

/**
 * Implements hook_field_a_b_phase_absolute_a_ave_display().
 */
function computed_field_field_a_b_phase_absolute_a_ave_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_b_c_phase_absolute_a_ave_compute().
 *
 * ABS( phase_average_amps - measured_b_phase_amps )
 */
function computed_field_field_b_c_phase_absolute_a_ave_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_phase_average_amps[$langcode][$langcode][0]['value']
    - $entity->field_measured_b_phase_amps[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = abs($values);
}

/**
 * Implements hook_field_b_c_phase_absolute_a_ave_display().
 */
function computed_field_field_b_c_phase_absolute_a_ave_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_c_a_phase_absolute_a_ave_compute().
 *
 * ABS( phase_average_amps - measured_c_phase_amps )
 */
function computed_field_field_c_a_phase_absolute_a_ave_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_phase_average_amps[$langcode][$langcode][0]['value']
    - $entity->field_measured_c_phase_amps[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = abs($values);
}

/**
 * Implements hook_field_c_a_phase_absolute_a_ave_display().
 */
function computed_field_field_c_a_phase_absolute_a_ave_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_total_amp_imbalance_compute().
 *
 * SUM( a_b_phase_absolute_a_ave, b_c_phase_absolute_a_ave, c_a_phase_absolute_a_ave ) / 2
 */
function computed_field_field_total_amp_imbalance_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array(
    $entity->field_a_b_phase_absolute_a_ave[$langcode][$langcode][0]['value'],
    $entity->field_b_c_phase_absolute_a_ave[$langcode][$langcode][0]['value'],
    $entity->field_c_a_phase_absolute_a_ave[$langcode][$langcode][0]['value'],
  );  
  $entity_field[$langcode][0]['value'] = array_sum($values);
}

/**
 * Implements hook_field_total_amp_imbalance_display().
 */
function computed_field_field_total_amp_imbalance_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_motor_capacity_compute().
 *
 * max_amperage / rated_load_amperage 
 * > Design Overload Trip Point (TP) = FAULT.
 */
function computed_field_field_motor_capacity_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = -1.00;
  if (!empty($entity->field_max_amperage) && !empty($entity->field_rated_load_amperage)) {
    if ($entity->field_max_amperage[$langcode][0]['value'] > 0 && $entity->field_rated_load_amperage[$langcode][0]['value'] > 0) {
      $values = $entity->field_max_amperage[$langcode][0]['value'] / $entity->field_rated_load_amperage[$langcode][0]['value'];
    }
  }
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_motor_capacity_display().
 */
function computed_field_field_motor_capacity_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_a_b_phase_absolute_v_ave_compute().
 *
 * ABS( phase_average_volts - a_b_phase_rms_volts )
 */
function computed_field_field_a_b_phase_absolute_v_ave_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_phase_average_volts[$langcode][$langcode][0]['value']
    - $entity->field_a_b_phase_rms_volts[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = abs($values);
}

/**
 * Implements hook_field_a_b_phase_absolute_v_ave_display().
 */
function computed_field_field_a_b_phase_absolute_v_ave_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_voltage_imbalance_compute().
 *
 * total_voltage_imbalance / phase_average_volts
 * > 1% is excessive voltage phase imbalance = FAULT.
 */
function computed_field_field_voltage_imbalance_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = -1.00;
  if (!empty($entity->field_total_voltage_imbalance) && !empty($entity->field_phase_average_volts)) {
    if ($entity->field_total_voltage_imbalance[$langcode][0]['value'] > 0 && $entity->field_phase_average_volts[$langcode][0]['value'] > 0) {
      $values = $entity->field_total_voltage_imbalance[$langcode][0]['value'] / $entity->field_phase_average_volts[$langcode][0]['value'];
    }
  }
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_voltage_display_compute().
 */
function computed_field_field_voltage_imbalance_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_under_over_voltage_compute().
 * 
 * ( phase_average_volts - system_design_voltage ) / system_design_voltage
 * > 10% = Over Voltage = FAULT.
 * < 10% = Under Voltage = FAULT.
 */
function computed_field_field_under_over_voltage_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = -1.00;
      $values = ($entity->field_phase_average_volts[$langcode][0]['value']
        - $entity->field_system_design_voltage[$langcode][0]['value'])
        / $entity->field_system_design_voltage[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_under_over_voltage_display().
 */
function computed_field_field_under_over_voltage_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_over_under_full_load_amps_compute().
 *
 * ( max_amperage / rated_load_amperage ) - 1
 */
function computed_field_field_over_under_full_load_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = -1.00;
  if (!empty($entity->field_max_amperage) && !empty($entity->field_rated_load_amperage)) {
    if ($entity->field_max_amperage[$langcode][0]['value'] > 0 && $entity->field_rated_load_amperage[$langcode][0]['value']) {
      $values = ($entity->field_max_amperage[$langcode][0]['value']
        / $entity->field_rated_load_amperage[$langcode][0]['value'])
        - 1;
    }
  }
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_over_under_full_load_amps_display().
 */
function computed_field_field_over_under_full_load_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_max_body_temp_compute().
 * 
 * MAX( body_temp )
 */
function computed_field_field_max_body_temp_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = array();
  foreach ($entity->field_body_temp[$langcode] as $temp) {
    $values[] = $temp['value'];
  }
  $entity_field[$langcode][0]['value'] = max($values);
}

/**
 * Implements_hook_field_max_body_temp_display().
 */
function computed_field_field_max_body_temp_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_motor_est_output_rpm_compute().
 *
 * ( 120 * measured_display_frequency ) / motor_poles
 */
function computed_field_field_motor_est_output_sync_rpm_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = (120 * $entity->field_measured_display_frequency[$langcode][0]['value'])
    / $entity->field_motor_poles[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_motor_est_output_rpm_display().
 */
function computed_field_field_motor_est_output_sync_rpm_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_calculated_a_phase_amps_compute().
 *
 * measured_t_lead_1_4_amps * SQRT( 3 )
 * Calculate Phase-A amps, or if not accessible measure T-Leg Amps.
 */
function computed_field_field_calculated_a_phase_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_measured_t_lead_1_4_amps[$langcode][0]['value'] * sqrt(3);
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_calculated_a_phase_amps_display().
 */
function computed_field_field_calculated_a_phase_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_calculated_b_phase_amps_compute().
 *
 * measured_t_lead_2_5_amps * SQRT( 3 )
 * Calculate Phase-B amps, or if not accessible measure T-Leg Amps.
 */
function computed_field_field_calculated_b_phase_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_measured_t_lead_2_5_amps[$langcode][0]['value'] * sqrt(3);
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_calculated_b_phase_amps_display().
 */
function computed_field_field_calculated_b_phase_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_calculated_c_phase_amps_compute().
 *
 * measured_t_lead_3_6_amps * SQRT( 3 )
 * Calculate Phase-C amps, or if not accessible measure T-Leg Amps.
 */
function computed_field_field_calculated_c_phase_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_measured_t_lead_3_6_amps[$langcode][0]['value'] * sqrt(3);
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_calculated_c_phase_amps_display().
 */
function computed_field_field_calculated_c_phase_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_calculated_t_lead_1_4_amps_compute().
 *
 * measured_a_phase_amps * SQRT( 3 )
 * Enter measured T-Lead 1-4 Amps.
 */
function computed_field_field_calculated_t_lead_1_4_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_measured_a_phase_amps[$langcode][0]['value'] * sqrt(3);
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_calculated_t_lead_1_4_amps_display().
 */
function computed_field_field_calculated_t_lead_1_4_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_calculated_t_lead_2_5_amps_compute().
 *
 * measured_b_phase_amps * SQRT( 3 )
 * Enter measured T-Lead 2-5 Amps.
 */
function computed_field_field_calculated_t_lead_2_5_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_measured_b_phase_amps[$langcode][0]['value'] * sqrt(3);
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_calculated_t_lead_2_5_amps_display().
 */
function computed_field_field_calculated_t_lead_2_5_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_calculated_t_lead_3_5_amps_compute().
 *
 * measured_c_phase_amps * SQRT( 3 )
 * Enter measured T-Lead 3-5 Amps.
 */
function computed_field_field_calculated_t_lead_3_5_amps_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_measured_c_phase_amps[$langcode][0]['value'] * sqrt(3);
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_calculated_t_lead_3_5_amps_display().
 */
function computed_field_field_calculated_t_lead_3_5_amps_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_amperage_imbalance_compute().
 *
 * total_amp_imbalance / phase_average_amps
 * > 15% amperage phase imbalance = FAULT.
 */
function computed_field_field_amperage_imbalance_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = '0.00';
  if (!empty($entity->field_total_amp_imbalance) && !empty($entity->field_phase_average_amps)) {
    if ($entity->field_total_amp_imbalance[$langcode][0]['value'] > 0 && $entity->field_phase_average_amps[$langcode][0]['value']) {
      $values = $entity->field_total_amp_imbalance[$langcode][0]['value']
        / $entity->field_phase_average_amps[$langcode][0]['value'];
    }
  }
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_amperage_inbalance_display();
 */
function computed_field_field_amperage_imbalance_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_estimated_running_hp_compute().
 *
 * ( phase_average_volts * phase_average_amps * nameplate_rated_efficiency * SQRT( 3 ) * nameplate_power_factor ) / 746
 */
function computed_field_field_estimated_running_hp_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = ($entity->field_phase_average_volts[$langcode][0]['value']
    * $entity->field_phase_average_amps[$langcode][0]['value']
    * $entity->field_nameplate_rated_efficiency[$langcode][0]['value']
    * sqrt(3)
    * $entity->field_nameplate_power_factor[$langcode][0]['value'])
    / 746;
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_estimated_running_hp_display().
 */
function computed_field_field_estimated_running_hp_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_estimated_motor_efficiency_compute().
 *
 * ( 746 * estimated_running_hp ) / ( phase_average_volts * phase_average_amps * nameplate_power_factor * ( SQRT( 3 ) ) )
 */
function computed_field_field_estimated_motor_efficiency_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = (746 * (float) $entity->field_estimated_running_hp[$langcode][0]['value'])
    / ((float) $entity->field_phase_average_volts[$langcode][0]['value']
    * (float) $entity->field_phase_average_amps[$langcode][0]['value']
    * (float) $entity->field_nameplate_power_factor[$langcode][0]['value']
    * (sqrt(3)));
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_estimated_motor_efficiency_display().
 */
function computed_field_field_estimated_motor_efficiency_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_estimated_power_factor_compute().
 *
 * ( measured_motor_kw * 1000 ) / ( phase_amperage_volts * phase_amperage_amps * SQRT ( 3 ) )
 * Value > 1 = faulty KW reading.
 */
function computed_field_field_estimated_power_factor_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = ((float) $entity->field_measured_motor_kw[$langcode][0]['value'] * 1000)
    / ((float )$entity->field_phase_average_volts[$langcode][0]['value']
    * (float) $entity->field_phase_average_amps[$langcode][0]['value']
    * sqrt(3));
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_estimated_power_factor_display().
 */
function computed_field_field_estimated_power_factor_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_estimated_ave_motor_kw_compute().
 *
 * ( phase_average_volts * phase_average_amps * SQRT( 3 ) * estimated_power_factor ) / 1000
 */
function computed_field_field_estimated_ave_motor_kw_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = ($entity->field_phase_average_volts[$langcode][$langcode][0]['value']
    * $entity->field_phase_average_amps[$langcode][0]['value']
    * sqrt(3)
    * $entity->field_estimated_power_factor[$langcode][$langcode][0]['value'])
    / 1000;
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_estimated_ave_motor_kw_display().
 */
function computed_field_field_estimated_ave_motor_kw_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_sync_stator_field_rpm_compute().
 *
 * ( 120 * measured_display_frequency ) / motor_poles
 */
function computed_field_field_sync_stator_field_rpm_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = (120 * $entity->field_measured_display_frequency[$langcode][0]['value'])
    / $entity->field_motor_poles[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_sync_stator_field_rpm_display().
 */
function computed_field_field_sync_stator_field_rpm_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}

/**
 * Implements hook_field_igv_position_compute().
 *
 * igv_motor_position / max_igv_motor_steps
 */
function computed_field_field_igv_position_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  $values = $entity->field_igv_motor_position[$langcode][0]['value']
    / $entity->field_max_igv_motor_steps[$langcode][0]['value'];
  $entity_field[$langcode][0]['value'] = $values;
}

/**
 * Implements hook_field_igv_position_display().
 */
function computed_field_field_igv_position_display($field, $entity_field_item, $entity_lang, $langcode, $entity) {
  return $entity_field_item['value'];
}
