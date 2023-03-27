#ifndef LAB6EX1_CIRCUIT_H
#define LAB6EX1_CIRCUIT_H
#include "Car.h"

class Circuit{
    double length;
    int nrCars=0;
    Car* cars[15];
    double times[11];
public:

    Weather weather;
    void setLength(int len);
    void setWeather(Weather condition);
    void addCar(Car* c);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotWin();
};


#endif //LAB6EX1_CIRCUIT_H
