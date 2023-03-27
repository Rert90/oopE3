#include "Seat.h"
#include "Weather.h"
#include <cstring>

Seat::Seat() {
    {
        strcpy(this->carName, "Seat");
    }
}
void Seat::SetFuelCapacity()
{
    this->fuelCapacity = 50;
}
void Seat::SetFuelConsumption()
{
    this->fuelConsumption = 7;
}
double Seat::avarageSpeed(Weather condition) {
    switch (condition) {
        case Weather::Sunny:
            return speed;
        case Weather::Rain:
            return speed * 0.75;
        case Weather::Snow:
            return speed * 0.5;


    }
}

