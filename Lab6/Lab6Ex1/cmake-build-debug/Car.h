#ifndef LAB6EX1_CAR_H
#define LAB6EX1_CAR_H
#include "Weather.h"
class Car {
public:
    int fuelCapacity;
    int fuelConsumption;
    double speed;
    char carName[21];

    virtual double avarageSpeed(Weather condition) {}
    virtual void SetFuelCapacity() {}
    virtual void SetFuelConsumption() {}
};

#endif //LAB6EX1_CAR_H
