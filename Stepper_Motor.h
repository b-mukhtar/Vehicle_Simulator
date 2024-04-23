#ifndef _STEPPER
#define _STEPPER

#include <math.h>
#include "motor.h"

class Stepper_Motor : public Motor

{
private:
    float Step ;           // the step angle 
    float Angle;           // the angle of the motor 
public:
    Stepper_Motor(float Step, float InitialAngle, Orientation InitalOrientation);
    void UpdatePsition();
    float getAngle();
    ~Stepper_Motor(); //Destructor
};


Stepper_Motor ::Stepper_Motor(float Step, float InitialAngle = 0, Orientation InitalOrientation = Orientation::ClockWise)
{
    this->Type = Motor_Type::Stepper;
    this->Step = Step;
    this->Angle = InitialAngle;
    this->ortientation = InitalOrientation;
}

void Stepper_Motor::UpdatePsition()
{
    switch (ortientation)
    {
    case Orientation::ClockWise:
        this->Angle += Step;
        break;
    case Orientation::CounterClockWise :
        this->Angle -= Step;
        break;
    }

    
}

float Stepper_Motor::getAngle()
{
    return Angle;
}

Stepper_Motor ::~Stepper_Motor()
{
}

#endif