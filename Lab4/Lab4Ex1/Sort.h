
#ifndef LAB4EX1_SORT_H
#define LAB4EX1_SORT_H
#pragma once

class Sort {
int count;
int* vector;

public:
    Sort();
    Sort(int count,...);
    Sort(int count,int min, int max);
    Sort(int* vector,int count);
    Sort(char* c);


    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent= false);
    void BubbleSort(bool ascendent=false );
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};


#endif //LAB4EX1_SORT_H
