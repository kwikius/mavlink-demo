#ifndef MAVLINK_DEMO_MSG_FUNCTIONS_HPP_INCLUDED
#define MAVLINK_DEMO_MSG_FUNCTIONS_HPP_INCLUDED

#include <mavlink.h>

void do_mavlink_heartbeat(mavlink_message_t const & msg);

void do_mavlink_system_time(mavlink_message_t const & msg);

void do_mavlink_rc_channels_raw(mavlink_message_t const & msg);

void do_mavlink_sys_status(mavlink_message_t const & msg);

void do_mavlink_attitude(mavlink_message_t const & msg);

void do_mavlink_global_position_int(mavlink_message_t const & msg);

void do_mavlink_nav_controller_output(mavlink_message_t const & msg);

void do_mavlink_rc_channels_scaled(mavlink_message_t const & msg);

void do_mavlink_servo_output_raw(mavlink_message_t const & msg);

void do_mavlink_vfr_hud(mavlink_message_t const & msg);

void do_mavlink_wind(mavlink_message_t const & msg);

void do_mavlink_rpm(mavlink_message_t const & msg);

void do_mavlink_hw_status(mavlink_message_t const & msg);

void do_mavlink_pid_tuning(mavlink_message_t const & msg);

void do_mavlink_rangefinder(mavlink_message_t const & msg);

void do_mission_current(mavlink_message_t const & msg);

void do_mission_statustext(mavlink_message_t const & msg);

void do_mavlink_home_position(mavlink_message_t const & msg);

void do_uncaptured_message(mavlink_message_t const & msg);

void do_mavlink_gps_raw_int(mavlink_message_t const & msg);

void do_mavlink_raw_imu(mavlink_message_t const & msg);

void do_mavlink_scaled_pressure(mavlink_message_t const & msg);

void do_mavlink_vibration(mavlink_message_t const & msg);

void do_mavlink_ahrs(mavlink_message_t const & msg);

void do_mavlink_meminfo(mavlink_message_t const & msg);


#endif // MAVLINK_DEMO_MSG_FUNCTIONS_HPP_INCLUDED
