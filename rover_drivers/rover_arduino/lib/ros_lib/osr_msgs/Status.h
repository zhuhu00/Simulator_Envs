#ifndef _ROS_osr_msgs_Status_h
#define _ROS_osr_msgs_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace osr_msgs
{

  class Status : public ros::Msg
  {
    public:
      typedef int64_t _battery_type;
      _battery_type battery;
      int64_t error_status[5];
      int64_t temp[5];
      int64_t current[10];

    Status():
      battery(0),
      error_status(),
      temp(),
      current()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_battery;
      u_battery.real = this->battery;
      *(outbuffer + offset + 0) = (u_battery.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_battery.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_battery.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_battery.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_battery.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->battery);
      for( uint32_t i = 0; i < 5; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_error_statusi;
      u_error_statusi.real = this->error_status[i];
      *(outbuffer + offset + 0) = (u_error_statusi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_statusi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_statusi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_statusi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error_statusi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error_statusi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error_statusi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error_statusi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error_status[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_tempi;
      u_tempi.real = this->temp[i];
      *(outbuffer + offset + 0) = (u_tempi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tempi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tempi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tempi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tempi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tempi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tempi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tempi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temp[i]);
      }
      for( uint32_t i = 0; i < 10; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_currenti;
      u_currenti.real = this->current[i];
      *(outbuffer + offset + 0) = (u_currenti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currenti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currenti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currenti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_currenti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_currenti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_currenti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_currenti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_battery;
      u_battery.base = 0;
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_battery.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->battery = u_battery.real;
      offset += sizeof(this->battery);
      for( uint32_t i = 0; i < 5; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_error_statusi;
      u_error_statusi.base = 0;
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error_statusi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error_status[i] = u_error_statusi.real;
      offset += sizeof(this->error_status[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_tempi;
      u_tempi.base = 0;
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tempi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temp[i] = u_tempi.real;
      offset += sizeof(this->temp[i]);
      }
      for( uint32_t i = 0; i < 10; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_currenti;
      u_currenti.base = 0;
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_currenti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current[i] = u_currenti.real;
      offset += sizeof(this->current[i]);
      }
     return offset;
    }

    const char * getType(){ return "osr_msgs/Status"; };
    const char * getMD5(){ return "e23adc2cf93152adf53c80dbe8f06ad9"; };

  };

}
#endif
