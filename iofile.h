#ifndef _IOFILE
#define _IOFILE

#include <stdio.h>
#include <string.h>

#include "Vehicle.h"


class iofile

{
private:
    char *FileName = NULL;
    FILE *f = NULL;
    bool isOpen = false;
    
public:
    iofile(const char* FileName);
    bool openforreading();
    bool openforwritting();
    void Close();
    void getFileName();
    char getVehicleType();
    void getRobotConfig(float* v);
    void writeVehiclePosition(Vehicle V);
    ~iofile();
};

iofile ::iofile(const char* FileName)
{
    this->FileName = new char[sizeof(FileName)];
    strcpy(this->FileName,FileName); 
}

bool iofile::openforreading()
{
    if(f = fopen(FileName,"rt"))
        isOpen = true;
    else
        isOpen = false;
    return isOpen;
}

bool iofile::openforwritting()
{
    if(f = fopen(FileName,"wt"))
        isOpen = true;
    else
        isOpen = false;
    return isOpen;
}

void iofile::Close()
{
    if(isOpen)
        fclose(f);
}

void iofile::getFileName()
{
    printf("%s\n",this->FileName);
}

char iofile::getVehicleType()
{
    if (isOpen)
    {
        char c;
        fscanf(f,"%c, ",&c);
        return c;
    }
    else
        return 0;
    
}

void iofile::getRobotConfig(float *v)
{
    if (isOpen)
        fscanf(f,"%f, %f, %f, ", v,v+1,v+2);
}

void iofile::writeVehiclePosition(Vehicle V)
{
    if(isOpen)
    {
        float x,y,theta;
        V.getPosition(&x,&y,&theta);
        fprintf(f,"%f, %f ,%f, \n",x,y,theta);
    }
}

iofile ::~iofile()
{
    if(isOpen)
        fclose(f);
}

#endif