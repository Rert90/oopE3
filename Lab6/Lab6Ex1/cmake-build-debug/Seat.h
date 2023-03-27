//
// Created by Olariu Robert on 26.03.2023.
//

#ifndef LAB6EX1_SEAT_H
#define LAB6EX1_SEAT_H

#include "Car.h"
class Seat: public Car{
    double speed=130;
public:
    Seat();
    void SetFuelCapacity() ;
    void SetFuelConsumption();
    double avarageSpeed(Weather condition);

};


#endif //LAB6EX1_SEAT_H
