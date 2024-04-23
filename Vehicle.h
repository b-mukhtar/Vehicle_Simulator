#ifndef _VEHICLE
#define _VEHICLE

#include<stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

#include "Motor.h"

class Vehicle
{
protected:
    float x,y,theta;
    float SlidingSpeed;
    float AngularSpeed; 
    
public:
    Vehicle(float x, float y, float theta);
    virtual void UpdateSpeeds();
    
    
    virtual void setMotorsConfig(float RightMotorSpeed, Orientation RightMotorOriention,
                                float LeftMotorSpeed, Orientation LeftMotorOriention);  // applicable to Robot class
    virtual void setMotorsConfig(float BackMotorSpeed, Orientation BackMotorOrientation, 
                                 Orientation SteeringMotorOrientation);                 // applicable to cycle class
    
    void UpdatePisition(float dt);

    void getPosition(float *x, float *y, float *theta);
     
    void PrintPosition();
     
    ~Vehicle();
};

Vehicle::Vehicle(float x = 0, float y = 0, float theta = 0)
{
    this->x = x;
    this->y = y;
    this->theta = theta;
    this->SlidingSpeed = 0;
    this->AngularSpeed = 0;
}

void Vehicle::UpdateSpeeds()
{
    /* in the child class, this function updates the sliding speed and the rotation speed
       of the vehicle as a function of the speeds of the motor */
}

void Vehicle::UpdatePisition(float dt)
{
    theta += dt * AngularSpeed;
    x += dt * SlidingSpeed * cos(theta);
    y += dt * SlidingSpeed * sin(theta);  
}

void Vehicle::getPosition(float* x, float* y, float* theta)
{
    *x = this->x;
    *y = this->y;
    *theta = this->theta;
}

void Vehicle::setMotorsConfig(float RightMotorSpeed, Orientation RightMotorOriention, 
                                float LeftMotorSpeed, Orientation LeftMotorOriention)
{
}

void Vehicle::setMotorsConfig(float BackMotorSpeed, Orientation BackMotorOrientation, Orientation SteeringMotorOrientation)
{
}

void Vehicle::PrintPosition()
{
    printf("Vehicle Position : %f, %f, %f, \n",x,y,theta);
}

Vehicle::~Vehicle()
{
}

#endif