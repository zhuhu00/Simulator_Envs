#ifndef _ROS_osr_msgs_Encoder_h
#define _ROS_osr_msgs_Encoder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace osr_msgs
{

  class Encoder : public ros::Msg
  {
    public:
      uint32_t abs_enc_length;
      typedef int64_t _abs_enc_type;
      _abs_enc_type st_abs_enc;
      _abs_enc_type * abs_enc;
      uint32_t abs_enc_angles_length;
      typedef int64_t _abs_enc_angles_type;
      _abs_enc_angles_type st_abs_enc_angles;
      _abs_enc_angles_type * abs_enc_angles;

    Encoder():
      abs_enc_length(0), abs_enc(NULL),
      abs_enc_angles_length(0), abs_enc_angles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->abs_enc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->abs_enc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->abs_enc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->abs_enc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->abs_enc_length);
      for( uint32_t i = 0; i < abs_enc_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_abs_enci;
      u_abs_enci.real = this->abs_enc[i];
      *(outbuffer + offset + 0) = (u_abs_enci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_abs_enci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_abs_enci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_abs_enci.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_abs_enci.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_abs_enci.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_abs_enci.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_abs_enci.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->abs_enc[i]);
      }
      *(outbuffer + offset + 0) = (this->abs_enc_angles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->abs_enc_angles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->abs_enc_angles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->abs_enc_angles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->abs_enc_angles_length);
      for( uint32_t i = 0; i < abs_enc_angles_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_abs_enc_anglesi;
      u_abs_enc_anglesi.real = this->abs_enc_angles[i];
      *(outbuffer + offset + 0) = (u_abs_enc_anglesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_abs_enc_anglesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_abs_enc_anglesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_abs_enc_anglesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_abs_enc_anglesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_abs_enc_anglesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_abs_enc_anglesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_abs_enc_anglesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->abs_enc_angles[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t abs_enc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      abs_enc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      abs_enc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      abs_enc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->abs_enc_length);
      if(abs_enc_lengthT > abs_enc_length)
        this->abs_enc = (int64_t*)realloc(this->abs_enc, abs_enc_lengthT * sizeof(int64_t));
      abs_enc_length = abs_enc_lengthT;
      for( uint32_t i = 0; i < abs_enc_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_abs_enc;
      u_st_abs_enc.base = 0;
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_abs_enc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_abs_enc = u_st_abs_enc.real;
      offset += sizeof(this->st_abs_enc);
        memcpy( &(this->abs_enc[i]), &(this->st_abs_enc), sizeof(int64_t));
      }
      uint32_t abs_enc_angles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      abs_enc_angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      abs_enc_angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      abs_enc_angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->abs_enc_angles_length);
      if(abs_enc_angles_lengthT > abs_enc_angles_length)
        this->abs_enc_angles = (int64_t*)realloc(this->abs_enc_angles, abs_enc_angles_lengthT * sizeof(int64_t));
      abs_enc_angles_length = abs_enc_angles_lengthT;
      for( uint32_t i = 0; i < abs_enc_angles_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_abs_enc_angles;
      u_st_abs_enc_angles.base = 0;
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_abs_enc_angles.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_abs_enc_angles = u_st_abs_enc_angles.real;
      offset += sizeof(this->st_abs_enc_angles);
        memcpy( &(this->abs_enc_angles[i]), &(this->st_abs_enc_angles), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "osr_msgs/Encoder"; };
    const char * getMD5(){ return "a664fd7d99f4f1ea35127a5719501f67"; };

  };

}
#endif
