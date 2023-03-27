#pragma once
#include "Weather.h"
#include "Car.h"

class Fiat : public Car
{ double speed=170;
public:
    Fiat();
    void SetFuelCapacity() ;
    void SetFuelConsumption();
    double avarageSpeed(Weather condition);

};


