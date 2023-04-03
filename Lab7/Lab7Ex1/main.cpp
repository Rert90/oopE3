#include <iostream>

float operator""_Kelvin(long double temp) {
    return static_cast<float>(temp - 273.15);
}
float operator""_Fahrenheit(long double temp) {
    return static_cast<float>((temp - 32) * 5 / 9);
}

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    printf("From Kelvin to Celsius: %f \n",a);
    printf("From Fahrenheit to Celsius: %f",b);
    return 0;
}