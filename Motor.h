#ifndef _MOTOR
#define _MOTOR

#include <string.h>

enum Motor_Type { DC, Stepper};
enum Orientation {ClockWise = 1, CounterClockWise = -1};

class Motor
{
protected:
    Motor_Type Type;  // the type of the motor
    Orientation ortientation;

public:
    Motor(); 
    ~Motor();
    void setOrientation(Orientation orientation);
    virtual void setRotationSpeed(float RotationSpeed, Orientation orientation) ;// applicable for DC motor 
    virtual float getSlidingSpeed();   // applicable for DC motor
    virtual void UpdatePsition(); // applicable for stepper motor
    virtual float getAngle();      // applicable for stepper motor
};

void Motor::setOrientation(Orientation orientation)
{
    this->ortientation = orientation;
}

void Motor::setRotationSpeed(float RotationSpeed, Orientation orientation)
{
    // this method shold be implemented in the child class DC_motor 
}

float Motor::getSlidingSpeed()
{
    // this  method should be implemented in the child class DC_motor
    return 0.0f;
}

void Motor::UpdatePsition()
{
    // this  method should be implemented in the child class Stepper_Motor
}

float Motor::getAngle()
{
    // this  method should be implemented in the child class Stepper_Motor
    return 0.0f;
}



Motor::Motor()
{
}

Motor::~Motor()
{
}

#endif