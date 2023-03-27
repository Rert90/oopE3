//
// Created by Olariu Robert on 26.03.2023.
//

#ifndef LAB6EX1_SKODA_H
#define LAB6EX1_SKODA_H
#include "Car.h"

class Skoda: public Car{
double speed=300;
public:
    Skoda();
    void SetFuelCapacity() ;
    void SetFuelConsumption();
    double avarageSpeed(Weather condition);
};


#endif //LAB6EX1_SKODA_H
