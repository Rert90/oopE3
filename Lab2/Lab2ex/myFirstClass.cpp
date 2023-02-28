#include "myFirstClass.h"
#include <string.h>
myFirstClass::myFirstClass()
{
    this->customName= new char[25];
}
void myFirstClass::setA(int a) {
    this->a=a;
}
void myFirstClass::setB(int b) {
    this->b=b;
}
int myFirstClass::getA() {
    return this->a;
}
int myFirstClass::getB() {
    return this->b;
}
void myFirstClass::setName(char *myname) {
    if(strlen(myname)<25)
    {
        memcpy(this->customName, myname, strlen(myname));
    }
}
char* myFirstClass::getName() {
    return this->customName;
}

