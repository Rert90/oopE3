#include "Volvo.h"
#include "Weather.h"
#include <cstring>

Volvo::Volvo() {
    {
        strcpy(this->carName, "Volvo");
    }
}
void Volvo::SetFuelCapacity()
{
    this->fuelCapacity = 70;
}
void Volvo::SetFuelConsumption()
{
    this->fuelConsumption = 12;
}
double Volvo::avarageSpeed(Weather condition) {
    switch (condition) {
        case Weather::Sunny:
            return speed;
        case Weather::Rain:
            return speed * 0.75;
        case Weather::Snow:
            return speed * 0.5;



    }
}

