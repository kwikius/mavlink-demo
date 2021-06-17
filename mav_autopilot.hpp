#ifndef BMS_MAVLINK_MAV_AUTOPILOT_HPP_INCLUDED
#define BMS_MAVLINK_MAV_AUTOPILOT_HPP_INCLUDED

#include <mavlink.h>

namespace bms {

   namespace mavlink{

      enum class mav_autopilot : uint8_t {

           generic = 0
           ,reserved = 1
           ,slugs =2
           ,ardupilot = 3
           ,openpilot = 4
           ,waypoints_only = 5
           ,waypoints_and_simple_nav = 6
           ,generic_mission_full = 7
           ,invalid = 8
           ,papparazzi = 9
           ,uav_dev_board = 10
           ,flexipilot = 11
           ,px4 =12
           ,smaccpilot = 13
           ,autoquad =14
           ,armazila =15
           ,aerob =16
           ,asluav = 17
           ,end_autopilots = 18
      };

      mav_autopilot get_mav_autopilot( mavlink_message_t * pmsg);
      const char * get_mav_autopilot_name( mavlink_message_t * pmsg);

   }

}

#endif // BMS_MAVLINK_MAV_AUTOPILOT_HPP_INCLUDED
