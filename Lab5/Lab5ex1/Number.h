//
// Created by Olariu Robert on 18.03.2023.
//

#ifndef LAB5EX1_NUMBER_H
#define LAB5EX1_NUMBER_H
#pragma once



class Number
{
    // add data members
    char* number_base_b;
    int number_base_10;
    int base;
    int digits;
public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int value);
    Number(const Number& n);
    Number(const Number&& n);
    ~Number();

    char operator[](int);
    friend Number operator+(Number x, Number y);
    friend Number operator+=(Number x, Number y);
    friend Number operator-(Number x, Number y);
    friend bool operator>(Number x, Number y);
    Number* operator--();
    friend Number* operator--(Number& num,int value);
    int operator=(int x);
    int operator=(const char* x);
    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};



#endif //LAB5EX1_NUMBER_H
