//
// Created by Olariu Robert on 26.03.2023.
//

#ifndef LAB6EX1_RANGEROVER_H
#define LAB6EX1_RANGEROVER_H
#include "Car.h"

class RangeRover: public Car{
    double speed=150;
public:
    RangeRover();
    void SetFuelCapacity() ;
    void SetFuelConsumption();
    double avarageSpeed(Weather condition);
};


#endif //LAB6EX1_RANGEROVER_H
