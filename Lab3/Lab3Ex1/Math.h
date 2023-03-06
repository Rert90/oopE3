//
// Created by Olariu Robert on 06.03.2023.
//
#pragma once
#ifndef LAB3EX1_MATH_H
#define LAB3EX1_MATH_H

class Math
{
public:
    static int Add(int,int);
    static int Add(int,int,int);
    static int Add(double,double);
    static int Add(double,double,double);
    static int Mul(int,int);
    static int Mul(int,int,int);
    static int Mul(double,double);
    static int Mul(double,double,double);
    static int Add(int count,...);
    static char* Add(const char *, const char *);
};

#endif //LAB3EX1_MATH_H
