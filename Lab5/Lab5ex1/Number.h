//
// Created by Olariu Robert on 18.03.2023.
//

#ifndef LAB5EX1_NUMBER_H
#define LAB5EX1_NUMBER_H
#pragma once

class Number {


public:
    Number(const char  * value, int base);
    ~Number();


    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};


#endif //LAB5EX1_NUMBER_H
