

#include "mav_type.hpp"


mavlink::mav_type mavlink::get_mav_type( ::mavlink_message_t * pmsg)
{
   uint8_t result = mavlink_msg_heartbeat_get_type(pmsg);

   if ( result < static_cast<uint8_t>(mav_type::end_types) ){
      return static_cast<mav_type>(result);
   }else {
      return mav_type::end_types;
   }
}

namespace {
   constexpr const char * mav_type_name [] = {
      "generic"
      , "fixed wing"
      , "Quadrotor"
      , "Coaxrotor"
      , "helicopter"
      , "Antenna tracker"
      , "GCS"              //  Operator control unit / ground control station
      , "Airship"           // Airship, controlled
      , "Balloon"
      , "Rocket"
      , "Ground Rover"
      , "Surface vessel"
      , "Submarine"
      , "hexarotor" 
      , "octorotor" 
      , "tricopter"
      , "flapping_wing" 
      , "kite" 
      , "onboard_companion"
      , "vtol duorotor"
      , "vtol quadrotor" 
      , "vtol tiltrotor" 
      , "vtol reserved2" 
      , "vtol reserved3" 
      , "vtol_reserved4" 
      , "vtol_reserved5"   
      , "gimbal" 
      , "adsb" 
      , "unknown type" 
   };

}

const char* mavlink::get_mav_type_name( mavlink_message_t * pmsg)
{
   uint8_t idx = static_cast<uint8_t>(get_mav_type(pmsg));

   return mav_type_name[idx];

}



