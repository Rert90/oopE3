#include <iostream>

float operator""_Kelvin(unsigned long long int  temp) {
    return static_cast<float>(temp - 273.15);
}
float operator""_Fahrenheit(unsigned long long int temp) {
    return static_cast<float>((temp - 32) * 5 / 9);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("From Kelvin to Celsius: %f \n",a);
    printf("From Fahrenheit to Celsius: %f",b);
    return 0;
}