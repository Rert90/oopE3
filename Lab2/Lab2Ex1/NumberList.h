//
// Created by Olariu Robert on 27.02.2023.
//
#pragma once
#ifndef LAB2EX2_NUMBERLIST_H
#define LAB2EX2_NUMBERLIST_H


class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();
    bool Add(int x);

    void Sort();
    void Print();
};

#endif //LAB2EX2_NUMBERLIST_H
