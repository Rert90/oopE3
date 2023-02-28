#pragma once
#ifndef LAB2_MYFIRSTCLASS_H
#define LAB2_MYFIRSTCLASS_H
#include "string.h"

class myFirstClass {
int a,b;
char* customName;
public:
    myFirstClass();
    void setA(int a);
    void setB(int b);
    void setName(char* name);

    int getA();
    int getB();
    char* getName();
};


#endif //LAB2_MYFIRSTCLASS_H
