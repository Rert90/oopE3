#define CRT_SECURE_NO_WARNINGS
#include "BMW.h"
#include "Weather.h"
#include <cstring>


BMW::BMW()
{
    strcpy(this->carName, "BMW");
}

void BMW::SetFuelCapacity()
{
    this->fuelCapacity = 68;
}
void BMW::SetFuelConsumption()
{
    this->fuelConsumption = 20;
}
double BMW::avarageSpeed(Weather condition) {
    switch (condition) {
        case Weather::Sunny:
            return speed;
        case Weather::Rain:
            return speed * 0.75;
        case Weather::Snow:
            return speed * 0.5;


    }
}

