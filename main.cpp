
#include <cstdio>
#include "serial.hpp"
#include "msg_functions.hpp"

namespace {
   /**
   * @brief read a character from input source, blocks for ever.
   * @param[out] ch  The character to read to.
   * @return true if a character was read, else false.
   */
   bool input_get(char & ch);
   bool input_open(const char * src);
   void input_close();
}

int main(int argc, const char* argv[])
{
   if ( argc < 2){
      printf("useage %s <input source>\n",argv[0]);
      return EXIT_FAILURE;
   }
   try{
      if (! input_open(argv[1])){
         return EXIT_FAILURE;
      }
      printf("input \"%s\" opened ok\n", argv[1]);

      mavlink_message_t msg = {};
      mavlink_status_t status = {};

      for (;;){
       
         char ch;
         if (! input_get(ch)){
            printf("no data from \"%s\" after 2 s\n",argv[0]);
            break;
         }

         if(mavlink_parse_char(MAVLINK_COMM_0, ch, &msg, &status)) {
            switch(msg.msgid) {
               case MAVLINK_MSG_ID_HEARTBEAT:
                  do_mavlink_heartbeat(msg);
                  break;
               case MAVLINK_MSG_ID_SYSTEM_TIME:
                  do_mavlink_system_time(msg);
                  break;
               case MAVLINK_MSG_ID_SYS_STATUS:
                  do_mavlink_sys_status(msg);
                  break;
               case MAVLINK_MSG_ID_ATTITUDE:
                  do_mavlink_attitude(msg);
                  break;
               case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
                  do_mavlink_global_position_int(msg);
                  break;
               case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT:
                  do_mavlink_nav_controller_output(msg);
                  break;
               case MAVLINK_MSG_ID_GPS_RAW_INT:
                  do_mavlink_gps_raw_int(msg);
                  break;
               case MAVLINK_MSG_ID_RAW_IMU:
                  do_mavlink_raw_imu(msg);
                  break;
               case MAVLINK_MSG_ID_SCALED_PRESSURE:
                  do_mavlink_scaled_pressure(msg);
                  break;
               case MAVLINK_MSG_ID_RC_CHANNELS_SCALED:
                  do_mavlink_rc_channels_scaled(msg);
                  break;
               case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
                  do_mavlink_rc_channels_raw(msg);
                  break;
               case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
                  do_mavlink_servo_output_raw(msg);
                  break;
               case MAVLINK_MSG_ID_VFR_HUD:
                  do_mavlink_vfr_hud(msg);
                  break;
               case MAVLINK_MSG_ID_HWSTATUS:
                  do_mavlink_hw_status(msg);
                  break;
               case MAVLINK_MSG_ID_WIND:
                  do_mavlink_wind(msg);
                  break;
               case MAVLINK_MSG_ID_RPM:
                  do_mavlink_rpm(msg);
                  break;
               case MAVLINK_MSG_ID_PID_TUNING:
                  do_mavlink_pid_tuning(msg);
                  break;
               case MAVLINK_MSG_ID_RANGEFINDER:
                  do_mavlink_rangefinder(msg);
                  break;
               case MAVLINK_MSG_ID_MISSION_CURRENT:
                  do_mission_current(msg);
                  break;
               case MAVLINK_MSG_ID_VIBRATION:
                  do_mavlink_vibration(msg);
                  break;
               case MAVLINK_MSG_ID_HOME_POSITION:
                  do_mavlink_home_position(msg);
                  break;
               case MAVLINK_MSG_ID_STATUSTEXT:
                  do_mission_statustext(msg);
                  break;
               case MAVLINK_MSG_ID_AHRS:
                  do_mavlink_ahrs(msg);
                  break;
               case MAVLINK_MSG_ID_MEMINFO:
                  do_mavlink_meminfo(msg);
                  break;
               default:
                  do_uncaptured_message(msg);
                  break;
            }
         }
      }
      input_close();
      return EXIT_SUCCESS;
   }  catch(std::exception & e){

      printf("Exception %s\n",e.what());
      input_close();
      return EXIT_FAILURE;
   }
}

namespace {

   serial_port* m_sp = nullptr;

   bool input_get(char & ch) 
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
 
   bool input_open(const char * port)
   {
      if ( ! m_sp){
         m_sp = new serial_port{port};
         if (!m_sp){
            printf ("memory error : couldnt alloc serial port \n");
            return false;
         }
         m_sp->init(115200);
         if ( !m_sp->good()){
            printf("serial port : invalid on \"%s\"\n",m_sp->get_filename().c_str());
            delete m_sp;
            m_sp = nullptr;
            return false;
         }
      }
      // todo verify same name?
      return true;
   }

   void input_close()
   {
      delete m_sp;
      m_sp = nullptr;
   }
   
}
