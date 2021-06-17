
#include <mavlink.h>

#include <cstdio>

#include "serial.hpp"
#include "mav_type.hpp"
#include "mav_autopilot.hpp"
#include <quan/utility/timer.hpp>

/**
* See mavlink...common/mavlink_msg_heartbeat.h
*/

namespace {

   quan::timer<quan::time::s>* p_timer;

   double get_time_s()
   {
      if (p_timer == nullptr){
         throw std::runtime_error{"null pointer in get_time_s"};
      }
      return (*p_timer)().numeric_value();
   }
   double last_heartbeat_s = 0.;

   double last_event_interval_s = 0.;

}

static void do_mavlink_heartbeat(mavlink_message_t * pmsg)
{
    double event_time_s = get_time_s();
    double heartbeat_interval_s = event_time_s - last_heartbeat_s;
    last_heartbeat_s = event_time_s;
    if ( heartbeat_interval_s > 1.1 ){
        double event_interval_s = event_time_s - last_event_interval_s;
        last_event_interval_s = event_time_s;
        printf("###############################################\n");
        printf("heartbeat interval %f s, event interval %f s\n",heartbeat_interval_s,event_interval_s);
        printf("###############################################\n");
    }else {
        printf("heartbeat interval %f sn",heartbeat_interval_s);
    }

}

static void do_mavlink_system_time(mavlink_message_t * pmsg)
{
   printf("system time\n");
}

static void  do_mavlink_rc_channels_raw(mavlink_message_t * pmsg)
{
    printf("rc channels raw\n");
}
/*
* From this find out if the system is running
*/
static void do_mavlink_sys_status(mavlink_message_t  * pmsg)
{
    printf("sys status\n");
}

static void do_mavlink_attitude(mavlink_message_t  * pmsg)
{
   printf("attitude\n");
}

static void do_mavlink_global_position_int(mavlink_message_t  * pmsg)
{
    printf("global position int\n");
}

static void do_mavlink_nav_controller_output(mavlink_message_t  * pmsg)
{
   printf("nav controller output\n");
}

static void do_mavlink_rc_channels_scaled(mavlink_message_t  * pmsg)
{
   printf("rc channels scaled\n");
}

static void do_mavlink_servo_output_raw(mavlink_message_t  * pmsg)
{
   printf("servo output raw\n");
}

static void do_mavlink_vfr_hud(mavlink_message_t  * pmsg)
{
  printf("vfr hud\n");
}

static void  do_mavlink_wind(mavlink_message_t  * pmsg)
{
   printf("wind\n");
}

static void  do_mavlink_rpm(mavlink_message_t  * pmsg)
{
   printf("rpm\n");
}
static void do_mavlink_hw_status(mavlink_message_t  * pmsg)
{
 printf("hw status\n");
}
static void do_mavlink_pid_tuning(mavlink_message_t  * pmsg)
{
printf("pid tuning\n");
}

static void  do_mavlink_rangefinder(mavlink_message_t  * pmsg)
{
   printf("rangefinder\n");
}

static void  do_mission_current(mavlink_message_t  * pmsg)
{
   printf("mission current\n");
}

static void  do_mission_statustext(mavlink_message_t  * pmsg)
{
   printf("status text\n");
}

static void do_mavlink_home_position(mavlink_message_t  * pmsg)
{
   printf("home position\n");
}

static void  do_uncaptured_message(mavlink_message_t  * pmsg)
{
   printf("uncaptured message id = %u\n",static_cast<unsigned>(pmsg->msgid));
}

static void do_mavlink_gps_raw_int(mavlink_message_t  * pmsg)
{
   printf("gps raw int\n");
}

static void do_mavlink_raw_imu(mavlink_message_t  * pmsg)
{
    printf("raw imu\n");
}

static void do_mavlink_scaled_pressure(mavlink_message_t  * pmsg)
{
    printf("scaled pressure\n");
}

static void do_mavlink_vibration(mavlink_message_t  * pmsg)
{
    printf("vibration\n");
}

static void do_mavlink_ahrs(mavlink_message_t  * pmsg)
{
      printf("ahrs\n");
}

static void  do_mavlink_meminfo(mavlink_message_t  * pmsg)
{
    printf("meminfo\n");
}

static serial_port* m_sp = nullptr;

/**
* read a character from serial port, blocks for ever.
* @param[out] ch  The character to read to.
* \result True if a character was read, else false.
*/
bool serial_get(char & ch) 
{
  if ( ! m_sp){
      printf("get char called on null serial Port\n");
      return false;
  }
  while (m_sp->in_avail() ==0){asm volatile ("nop":::);}

  if ( m_sp->read((uint8_t*)&ch,1) == 1){
     return true;
  }else{
      printf("serial port read failed\n");
      return false;
  }
}

int main(int argc, const char* argv[])
{
   p_timer = new quan::timer<quan::time::s>;
   if ( argc < 2){
      printf("useage %s <serial_port>\n",argv[0]);
      return EXIT_FAILURE;
   }

   m_sp = new serial_port{argv[1]};
   if (!m_sp){
      printf ("memory error : couldnt alloc serial port \n");
      return EXIT_FAILURE;
   }
   try{
      printf("setting baud\n");
      m_sp->init(115200);
      if ( !m_sp->good()){
         printf("serial port : invalid on \"%s\"\n",m_sp->get_filename().c_str());
         delete m_sp;
         return EXIT_FAILURE;
      }

      printf("serial port initialised ok\n");

      for (;;){
         
         // defined in mavlink_types.h
         mavlink_message_t msg = {};
         mavlink_status_t status = {};

         char ch;
         if (! serial_get(ch)){
            printf("read serial no data after 2 s\n");
            break;
         }

         if(mavlink_parse_char(MAVLINK_COMM_0, ch, &msg, &status)) {

            switch(msg.msgid) {
               case MAVLINK_MSG_ID_HEARTBEAT:
                  do_mavlink_heartbeat(&msg);
                  break;
               case MAVLINK_MSG_ID_SYSTEM_TIME:
                  do_mavlink_system_time(&msg);
                  break;
               case MAVLINK_MSG_ID_SYS_STATUS:
                  do_mavlink_sys_status(&msg);
                  break;
               case MAVLINK_MSG_ID_ATTITUDE:
                  do_mavlink_attitude(&msg);
                  break;
               case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
                  do_mavlink_global_position_int(&msg);
                  break;
               case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT:
                  do_mavlink_nav_controller_output(&msg);
                  break;
               case MAVLINK_MSG_ID_GPS_RAW_INT:
                  do_mavlink_gps_raw_int(&msg);
                  break;
               case MAVLINK_MSG_ID_RAW_IMU:
                  do_mavlink_raw_imu(&msg);
                  break;
               case MAVLINK_MSG_ID_SCALED_PRESSURE:
                  do_mavlink_scaled_pressure(&msg);
                  break;
               case MAVLINK_MSG_ID_RC_CHANNELS_SCALED:
                  do_mavlink_rc_channels_scaled(&msg);
                  break;
               case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
                  do_mavlink_rc_channels_raw(&msg);
                  break;
               case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
                  do_mavlink_servo_output_raw(&msg);
                  break;
               case MAVLINK_MSG_ID_VFR_HUD:
                  do_mavlink_vfr_hud(&msg);
                  break;
               case MAVLINK_MSG_ID_HWSTATUS:
                  do_mavlink_hw_status(&msg);
                  break;
               case MAVLINK_MSG_ID_WIND:
                  do_mavlink_wind(&msg);
                  break;
               case MAVLINK_MSG_ID_RPM:
                  do_mavlink_rpm(&msg);
                  break;
               case MAVLINK_MSG_ID_PID_TUNING:
                  do_mavlink_pid_tuning(&msg);
                  break;
               case MAVLINK_MSG_ID_RANGEFINDER:
                  do_mavlink_rangefinder(&msg);
                  break;
               case MAVLINK_MSG_ID_MISSION_CURRENT:
                  do_mission_current(&msg);
                  break;
               case MAVLINK_MSG_ID_VIBRATION:
                  do_mavlink_vibration(&msg);
                  break;
               case MAVLINK_MSG_ID_HOME_POSITION:
                  do_mavlink_home_position(&msg);
                  break;
               case MAVLINK_MSG_ID_STATUSTEXT:
                  do_mission_statustext(&msg);
                  break;
               case MAVLINK_MSG_ID_AHRS:
                  do_mavlink_ahrs(&msg);
                  break;
               case MAVLINK_MSG_ID_MEMINFO:
                  do_mavlink_meminfo(&msg);
                  break;
               default:
                  do_uncaptured_message(&msg);
                  break;
            }
        }
     }

     delete m_sp;
     return EXIT_FAILURE;

 }catch(std::exception & e){
      printf("Exception %s\n",e.what());
      delete m_sp;
      return EXIT_FAILURE;
 }
}

