#include "cmake-build-debug/Volvo.h"
#include "cmake-build-debug/Fiat.h"
#include "cmake-build-debug/Circuit.h"
#include "cmake-build-debug/BMW.h"
#include "cmake-build-debug/Seat.h"
#include "cmake-build-debug/RangeRover.h"
#include "cmake-build-debug/Skoda.h"

int main()
{
    Circuit c;
    c.setLength(1000);
    c.setWeather(Weather::Rain);
    c.addCar(new Volvo());
    c.addCar(new BMW());
    c.addCar(new Seat());
    c.addCar(new Fiat());
    c.addCar(new RangeRover());
    c.addCar(new Skoda());
    c.Race();
    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
    c.ShowWhoDidNotWin(); // it is possible that some cars don't have enough fuel to finish the circuit
    return 0;
}