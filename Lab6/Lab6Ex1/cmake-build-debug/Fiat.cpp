#define CRT_SECURE_NO_WARNINGS
#include "Fiat.h"
#include "Weather.h"
#include <cstring>


Fiat::Fiat() {
    strcpy(this->carName, "Fiat");
}

void Fiat::SetFuelCapacity()
{
    this->fuelCapacity = 50;
}
void Fiat::SetFuelConsumption()
{
    this->fuelConsumption = 4;
}
double Fiat::avarageSpeed(Weather condition) {
    switch (condition) {
        case Weather::Sunny:
            return speed;
        case Weather::Rain:
            return speed * 0.75;
        case Weather::Snow:
            return speed * 0.5;



    }
}

