#include <stdio.h>
#include "Motor.h"
#include "DC_Motor.h"
#include "Stepper_Motor.h"
#include "Vehicle.h"
#include "Robot.h"
#include "iofile.h"


int main()
{
    printf("program begining\n");
    printf("Please Enter the configuration file name : ");
    char ConfigFileName[20];
    scanf("%s",ConfigFileName);
    iofile f_config(ConfigFileName);
    while (!f_config.openforreading())
    {
        printf("please enter a valid file:");
        scanf("%s\n",ConfigFileName);
    }

    printf("Please Enter the recording file name : ");
    char RecordingFileName[20];
    scanf("%s",RecordingFileName);
    iofile f_record(RecordingFileName);
    while (!f_record.openforwritting())
    {
        printf("please enter a valid file:");
        scanf("%s\n",RecordingFileName);
    }


    if( f_config.getVehicleType() == 'R')
    {
        printf("the Vehicle type is a Robot\n");
        float v[3];
        f_config.getRobotConfig(v);
        float motor_speed = v[0];
        float radius = v[1];
        float trackwidth = v[2];
        
        printf("DC_Motor speed : %f rpm,\nthe wheel radius: %fm,\nthe trackwidth : %fm\n",motor_speed,radius,trackwidth);

        Vehicle *V =  new Robot(radius,trackwidth,5,5);
        /* first step the robot rotates itself toward the target 
        to do that the right motor rotates in the clockwise direction 
        and the left motor rotates in the counter clockwise direction 
        or we can set the right motor to full speed and lest motor to 0 */ 
        
        V->setMotorsConfig(motor_speed,ClockWise,motor_speed,CounterClockWise);
        // V->setMotorsConfig(motor_speed,ClockWise,0,ClockWise);
        
        V->PrintPosition();
        float x,y,theta;
        do
        {
            
            V->UpdatePisition(0.001);
            f_record.writeVehiclePosition(*V);
            V->getPosition(&x,&y,&theta);
        }while(theta < M_PI/2);
        V->setMotorsConfig(motor_speed,ClockWise,motor_speed,ClockWise);
        V->PrintPosition();
        /* second step the robot move straight towards the target toward the target 
        to do that booth the right and the lest motor rotate in the clockwise direction  */ 
        do
        {
            V->UpdatePisition(0.1);
            f_record.writeVehiclePosition(*V);
            V->getPosition(&x,&y,&theta);
        } while (y < 25);
        V->PrintPosition();
    } 
    f_config.Close();
    f_record.Close();


}
