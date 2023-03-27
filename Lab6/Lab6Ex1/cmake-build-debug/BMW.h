#pragma once
#include "Weather.h"
#include "Car.h"

class BMW : public Car
{
    double speed=250;
public:

    BMW();
    void SetFuelCapacity() ;
    void SetFuelConsumption() ;
    double avarageSpeed(Weather condition) ;

};

