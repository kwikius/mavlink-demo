
#include <cstdio>
#include "msg_functions.hpp"

/**
* See mavlink...common/mavlink_msg_heartbeat.h
*/
void do_mavlink_heartbeat(mavlink_message_t const & msg)
{
   printf("mavlink heartbeat\n");
}

void do_mavlink_system_time(mavlink_message_t const & msg)
{
   printf("system time\n");
}

void  do_mavlink_rc_channels_raw(mavlink_message_t const & msg)
{
    printf("rc channels raw\n");
}
/*
* From this find out if the system is running
*/
void do_mavlink_sys_status(mavlink_message_t const & msg)
{
    printf("sys status\n");
}

void do_mavlink_attitude(mavlink_message_t const & msg)
{
   printf("attitude\n");
}

void do_mavlink_global_position_int(mavlink_message_t const & msg)
{
    printf("global position int\n");
}

void do_mavlink_nav_controller_output(mavlink_message_t const & msg)
{
   printf("nav controller output\n");
}

void do_mavlink_rc_channels_scaled(mavlink_message_t const & msg)
{
   printf("rc channels scaled\n");
}

void do_mavlink_servo_output_raw(mavlink_message_t const & msg)
{
   printf("servo output raw\n");
}

void do_mavlink_vfr_hud(mavlink_message_t const & msg)
{
  printf("vfr hud\n");
}

void  do_mavlink_wind(mavlink_message_t const & msg)
{
   printf("wind\n");
}

void  do_mavlink_rpm(mavlink_message_t const & msg)
{
   printf("rpm\n");
}
void do_mavlink_hw_status(mavlink_message_t const & msg)
{
 printf("hw status\n");
}
void do_mavlink_pid_tuning(mavlink_message_t const & msg)
{
printf("pid tuning\n");
}

void  do_mavlink_rangefinder(mavlink_message_t const & msg)
{
   printf("rangefinder\n");
}

void  do_mission_current(mavlink_message_t const & msg)
{
   printf("mission current\n");
}

void  do_mission_statustext(mavlink_message_t const & msg)
{
   printf("status text\n");
}

void do_mavlink_home_position(mavlink_message_t const & msg)
{
   printf("home position\n");
}

void  do_uncaptured_message(mavlink_message_t const & msg)
{
   printf("uncaptured message id = %u\n",static_cast<unsigned>(msg.msgid));
}

void do_mavlink_gps_raw_int(mavlink_message_t const & msg)
{
   printf("gps raw int\n");
}

void do_mavlink_raw_imu(mavlink_message_t const & msg)
{
    printf("raw imu\n");
}

void do_mavlink_scaled_pressure(mavlink_message_t const & msg)
{
    printf("scaled pressure\n");
}

void do_mavlink_vibration(mavlink_message_t const & msg)
{
    printf("vibration\n");
}

void do_mavlink_ahrs(mavlink_message_t const & msg)
{
      printf("ahrs\n");
}

void  do_mavlink_meminfo(mavlink_message_t const & msg)
{
    printf("meminfo\n");
}

