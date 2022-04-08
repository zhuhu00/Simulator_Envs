#include "kg_encoder.h"

int Encoder::nbr = 0;
bool Encoder::initialisation = false;

float Encoder::_position[10] = {0,0,0,0,0,0,0,0,0,0};
int Encoder::_lastReading[10] = {0,0,0,0,0,0,0,0,0,0};
int Encoder::_pin[10] = {0,0,0,0,0,0,0,0,0,0};

Encoder::Encoder(int pin)
{
    id = nbr;
    nbr++;
    _position[id] = analogRead(_pin[id]);
    _pin[id] = pin;
    pinMode(_pin[id],INPUT);
    _lastReading[id] = analogRead(_pin[id]);

    if(!initialisation)
    {
        Timer2Manager::add(update);
        initialisation = true;
    }
}

void Encoder::update()
{
    for(int i = 0; i < nbr;i++)
    {
        int reading = analogRead(_pin[i]);
        float  delta = reading - _lastReading[i];
        delta = delta*360/1026;
        _lastReading[i] = reading;

        if(delta < -180)
        {
           delta += 360;
        }
        if(delta > 180)
        {
            delta -= 360;
        }
        _position[i] += delta;
    }


}
float Encoder::ReadAngle()
{
    return _position[id];
}