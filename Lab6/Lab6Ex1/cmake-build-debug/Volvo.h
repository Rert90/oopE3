//
// Created by Olariu Robert on 26.03.2023.
//

#ifndef LAB6EX1_VOLVO_H
#define LAB6EX1_VOLVO_H
#include "Car.h"

class Volvo: public Car{
int speed=160;

public:
    Volvo();
    void SetFuelCapacity() ;
    void SetFuelConsumption();
    double avarageSpeed(Weather condition);

};


#endif //LAB6EX1_VOLVO_H
