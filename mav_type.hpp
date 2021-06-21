#ifndef MAVLINK_DEMO_MAVLINK_MAV_TYPE_HPP_INCLUDED
#define MAVLINK_DEMO_MAVLINK_MAV_TYPE_HPP_INCLUDED

#include <mavlink.h>

namespace mavlink{

   enum class mav_type : uint8_t{

       generic = 0            //	Generic micro air vehicle.
      , fixed_wing = 1        //  Fixed wing aircraft.
      , quadrotor = 2         //  Quadrotor
      , coaxial = 3           //  Coaxial helicopter
      , helicopter = 4        //  Normal helicopter with tail rotor.
      , antenna_tracker = 5   // antenna tracker
      , gcs = 6               //  Operator control unit / ground control station
      , airship = 7           // Airship, controlled
      , free_balloon  = 8     // Free balloon, uncontrolled
      , rocket = 9            // rocket
      , ground_rover = 10     // Ground rover
      , surface_boat = 11     // Surface vessel, boat, ship
      , submarine = 12        // Submarine
      , hexarotor = 13
      , octorotor = 14
      , tricopter = 15
      , flapping_wing = 16
      , kite = 17
      , onboard_controller = 18
      , vtol_duorotor = 19
      , vtol_quadrotor = 20
      , vtol_tiltrotor = 21
      , vtol_reserved2  = 22
      , vtol_reserved3 = 23
      , vtol_reserved4 = 24
      , vtol_reserved5 = 25  
      , gimbal = 26
      , adsb = 27
      , end_types = 28
   };

   mav_type get_mav_type( mavlink_message_t * pmsg);
   const char * get_mav_type_name( mavlink_message_t * pmsg);
}



#endif //MAVLINK_DEMO_MAVLINK_MAV_TYPE_HPP_INCLUDED
