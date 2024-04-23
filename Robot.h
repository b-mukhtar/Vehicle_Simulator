#ifndef _ROBOT
#define _ROBOT

#include <math.h>
#include "Motor.h"
#include "DC_Motor.h"
#include "Vehicle.h"

class Robot: public Vehicle
{
private:
    Motor *RightMotor;    // right motor
    Motor *LeftMotor;    // left motor 
    float TrackWidth; 
public:
    Robot(float radius, float TrackWidth, 
             float x, float y, float theta,
             float RightMotorInitialRotationSpeed, float LeftMotorInitialRotationSpeed,
             Orientation RightMotorInitalOrientation, Orientation LeftMotorInitalOrientation);

    void setMotorsConfig(float RightMotorSpeed, Orientation RightMotorOriention,
                         float LeftMotorSpeed, Orientation LeftMotorOriention);

    void UpdateSpeeds();

    ~Robot(); //Destructor for Robot
};

Robot::Robot(float Radius, float TrackWidth, 
             float x = 0, float y = 0, float theta = 0,
             float RightMotorInitialRotationSpeed = 0, float  LeftMotorInitialRotationSpeed = 0,
             Orientation RightMotorInitalOrientation = Orientation::ClockWise, 
             Orientation LeftMotorInitalOrientation = Orientation::CounterClockWise) 
{
    this->TrackWidth = TrackWidth;
    this->x = x;
    this->y = y;
    printf("(%f,%f)\n",this->x,this->y);
    this->theta = theta;
    this->RightMotor = new DC_motor(Radius, RightMotorInitialRotationSpeed, RightMotorInitalOrientation);
    this->LeftMotor = new DC_motor(Radius, LeftMotorInitialRotationSpeed, LeftMotorInitalOrientation);
    this->UpdateSpeeds();
}

void Robot::setMotorsConfig(float RightMotorSpeed, Orientation RightMotorOriention, 
                                   float LeftMotorSpeed, Orientation LeftMotorOriention)
{
    RightMotor->setRotationSpeed(RightMotorSpeed,RightMotorOriention);
    LeftMotor->setRotationSpeed(LeftMotorSpeed,LeftMotorOriention);
    this->UpdateSpeeds();
}

void Robot::UpdateSpeeds()
{
    this->AngularSpeed = 0.5  * (RightMotor->getSlidingSpeed() - LeftMotor->getSlidingSpeed()) / TrackWidth;

    this->SlidingSpeed = 0.5 * (RightMotor->getSlidingSpeed() + LeftMotor->getSlidingSpeed());
}

/*void Robot::setMotorsAngularSpeed(float M_r_speed, float M_l_speed, Orientation M_r_orientation, Orientation M_l_orientation)
{
    M_r.setAngularSpeed(M_r_speed,M_r_orientation);
    M_l.setAngularSpeed(M_l_speed,M_l_orientation);
}
*/
Robot::~Robot()
{
}

#endif