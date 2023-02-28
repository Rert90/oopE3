#include "myFirstClass.h"
#include <stdio.h>
int main()
{
    myFirstClass firstClass;
    myFirstClass secondClass;
    firstClass.setA(10);
    firstClass.setB(24);
    secondClass.setA(15);
    secondClass.setB(30);
    printf("First Class A: %d\n", firstClass.getA());
    printf("First Class B: %d\n",firstClass.getB());
    printf("Second Class A: %d\n",secondClass.getA());
    printf("Second Class B: %d\n",secondClass.getB());
    return 0;

}