#ifndef KG_ENCODER_H
#define KG_ENCODER_H

#include <Arduino.h>
#include "kg_timer2_manager.h"
class Encoder
{
protected:
    static float _position[10];
    static int _lastReading[10];
    static int _pin[10];

    static bool initialisation;
    static int nbr;
    static void update();

    int id;

public:
    Encoder(int pin);
    float ReadAngle();
};


#endif  //KG_ENCODER_H