#include <cstdio>
#include "Circuit.h"
void Circuit::setWeather(Weather condition) {
    this->weather=condition;
}
void Circuit::setLength(int len) {
    this->length=len;
}

void Circuit::addCar(Car *c) {
    this->cars[nrCars] = c;
    this->nrCars++;
}

void Circuit::Race()
{
    for (int i = 0; i < this->nrCars; i++)
    {
        Car* c = this->cars[i];
        c->SetFuelCapacity();
        c->SetFuelConsumption();
        c->avarageSpeed(this->weather);

        if (this->length * c->fuelConsumption / 100 <= c->fuelCapacity)
            this->times[i] = (this->length / c->speed) ;
        else this->times[i] = 0;

    }
}

void Circuit::ShowFinalRanks()
{

    for (int i = 0; i < this->nrCars - 1; i++)
    {
        for (int j = i + 1; j < this->nrCars; j++)
        {
            if (this->times[i] > this->times[j] && this->times[i] > 0 && this->times[j] > 0)
            {
                Car* aux = this->cars[i];
                this->cars[i] = this->cars[j];
                this->cars[j] = aux;
                int ax = this->times[i];
                this->times[i] = this->times[j];
                this->times[j] = ax;
            }

        }
    }

    printf("-----THE FINAL RANK-----\n");

    for (int i = 0; i < this->nrCars; i++)
    {
        if (this->times[i])
        {
            printf("%s : ", this->cars[i]->carName);

            if (this->times[i] > 3600)
            {
                printf("%dh ", int(this->times[i] / 3600));
                this->times[i] -= 3600 * int(this->times[i] / 3600);

            }

            if (this->times[i] > 60)
            {
                printf("%dm ", int(this->times[i] / 60));
                this->times[i] -= 60 * int(this->times[i] / 60);
            }

            printf("%ds\n", int(this->times[i]));

            this->times[i] = 1;
        }


    }


}
void Circuit::ShowWhoDidNotWin() {
    printf("-----The ones who didn't finish-----\n");

    for (int i = 0; i < this->nrCars; i++)
    {
        if (!this->times[i])
            printf("%s ", this->cars[i]->carName);

    }
}