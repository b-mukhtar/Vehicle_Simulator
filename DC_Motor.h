#ifndef _DC_MOTOR
#define _DC_MOTOR

#include <math.h>
#include "Motor.h"

class DC_motor: public Motor
{
private:
    float Radius;           // the wheel radius in meter (applicable for DC motor)
    float RotationSpeed;     // the speed of rotation of the wheel in rpm (applicable for DC motor)
    int Oriantation;        // 1 for clockwise rotation, -1 for counterclockwise rotation
public:
    DC_motor(float Radius, float InitialRotationSpeed, Orientation InitalOrientation);
    ~DC_motor();
    void setRotationSpeed(float RotationSpeed, Orientation orientation);
    float getSlidingSpeed();
};

DC_motor::DC_motor(float Radius, float InitialRotationSpeed = 0, Orientation InitalOrientation = Orientation::ClockWise)
{
    this->Type = Motor_Type::DC;
    this->Radius = Radius;
    this->RotationSpeed = InitialRotationSpeed;
    this->ortientation = InitalOrientation;
}

DC_motor::~DC_motor()
{
}

void DC_motor::setRotationSpeed(float RotationSpeed, Orientation orientation)
{
    this->RotationSpeed = RotationSpeed;
    this->ortientation = orientation;
}

float DC_motor::getSlidingSpeed()
{
    switch (ortientation)
    {
    case Orientation::ClockWise :
        return Radius * RotationSpeed * 2 * M_PI/60;
        break;
    case Orientation::CounterClockWise :
        return - Radius * RotationSpeed * 2 * M_PI/60;
        break;
    }
    return 0;
}



#endif