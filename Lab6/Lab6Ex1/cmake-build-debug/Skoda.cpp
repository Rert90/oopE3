#include "Skoda.h"
#include "Weather.h"
#include <cstring>

Skoda::Skoda() {
    {
        strcpy(this->carName, "Skoda");
    }
}
void Skoda::SetFuelCapacity()
{
    this->fuelCapacity = 100;
}
void Skoda::SetFuelConsumption()
{
    this->fuelConsumption = 12;
}
double Skoda::avarageSpeed(Weather condition) {
    switch (condition) {
        case Weather::Sunny:
            return speed;
        case Weather::Rain:
            return speed * 0.75;
        case Weather::Snow:
            return speed * 0.5;



    }
}

