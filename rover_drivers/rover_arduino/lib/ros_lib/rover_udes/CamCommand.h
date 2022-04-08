#ifndef _ROS_rover_udes_CamCommand_h
#define _ROS_rover_udes_CamCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_udes
{

  class CamCommand : public ros::Msg
  {
    public:
      typedef bool _is_pano_type;
      _is_pano_type is_pano;
      typedef int32_t _cam_horizontal_type;
      _cam_horizontal_type cam_horizontal;
      typedef int32_t _cam_vertical_type;
      _cam_vertical_type cam_vertical;

    CamCommand():
      is_pano(0),
      cam_horizontal(0),
      cam_vertical(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_pano;
      u_is_pano.real = this->is_pano;
      *(outbuffer + offset + 0) = (u_is_pano.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_pano);
      union {
        int32_t real;
        uint32_t base;
      } u_cam_horizontal;
      u_cam_horizontal.real = this->cam_horizontal;
      *(outbuffer + offset + 0) = (u_cam_horizontal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cam_horizontal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cam_horizontal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cam_horizontal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cam_horizontal);
      union {
        int32_t real;
        uint32_t base;
      } u_cam_vertical;
      u_cam_vertical.real = this->cam_vertical;
      *(outbuffer + offset + 0) = (u_cam_vertical.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cam_vertical.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cam_vertical.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cam_vertical.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cam_vertical);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_pano;
      u_is_pano.base = 0;
      u_is_pano.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_pano = u_is_pano.real;
      offset += sizeof(this->is_pano);
      union {
        int32_t real;
        uint32_t base;
      } u_cam_horizontal;
      u_cam_horizontal.base = 0;
      u_cam_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cam_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cam_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cam_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cam_horizontal = u_cam_horizontal.real;
      offset += sizeof(this->cam_horizontal);
      union {
        int32_t real;
        uint32_t base;
      } u_cam_vertical;
      u_cam_vertical.base = 0;
      u_cam_vertical.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cam_vertical.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cam_vertical.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cam_vertical.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cam_vertical = u_cam_vertical.real;
      offset += sizeof(this->cam_vertical);
     return offset;
    }

    const char * getType(){ return "rover_udes/CamCommand"; };
    const char * getMD5(){ return "6cbf974437ab72bc89c284fde406a0bd"; };

  };

}
#endif
