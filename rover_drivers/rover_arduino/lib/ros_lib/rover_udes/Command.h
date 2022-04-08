#ifndef _ROS_rover_udes_Command_h
#define _ROS_rover_udes_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_udes
{

  class Command : public ros::Msg
  {
    public:
      typedef bool _is_active_type;
      _is_active_type is_active;
      typedef float _linear_type;
      _linear_type linear;
      typedef float _angular_type;
      _angular_type angular;

    Command():
      is_active(0),
      linear(0),
      angular(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_active;
      u_is_active.real = this->is_active;
      *(outbuffer + offset + 0) = (u_is_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_active);
      union {
        float real;
        uint32_t base;
      } u_linear;
      u_linear.real = this->linear;
      *(outbuffer + offset + 0) = (u_linear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linear);
      union {
        float real;
        uint32_t base;
      } u_angular;
      u_angular.real = this->angular;
      *(outbuffer + offset + 0) = (u_angular.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angular);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_active;
      u_is_active.base = 0;
      u_is_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_active = u_is_active.real;
      offset += sizeof(this->is_active);
      union {
        float real;
        uint32_t base;
      } u_linear;
      u_linear.base = 0;
      u_linear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linear = u_linear.real;
      offset += sizeof(this->linear);
      union {
        float real;
        uint32_t base;
      } u_angular;
      u_angular.base = 0;
      u_angular.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angular = u_angular.real;
      offset += sizeof(this->angular);
     return offset;
    }

    const char * getType(){ return "rover_udes/Command"; };
    const char * getMD5(){ return "53e547be5f92f7cd818ea563ca9c778b"; };

  };

}
#endif
