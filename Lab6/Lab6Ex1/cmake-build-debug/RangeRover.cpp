#include "RangeRover.h"
#include "Weather.h"
#include <cstring>

RangeRover::RangeRover() {
    {
        strcpy(this->carName, "RangeRover");
    }
}
void RangeRover::SetFuelCapacity()
{
    this->fuelCapacity = 80;
}
void RangeRover::SetFuelConsumption()
{
    this->fuelConsumption = 8;
}
double RangeRover::avarageSpeed(Weather condition) {
    switch (condition) {
        case Weather::Sunny:
            return speed;
        case Weather::Rain:
            return speed * 0.75;
        case Weather::Snow:
            return speed * 0.5;



    }
}

