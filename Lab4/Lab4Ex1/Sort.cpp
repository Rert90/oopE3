//
// Created by Olariu Robert on 08.03.2023.
//

#include "Sort.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstdarg>

void swap(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}
int partition(int vec[], int start, int end, bool ascendent) {

    int pivot = vec[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (ascendent ? vec[i] >= pivot : vec[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(vec[pivotIndex], vec[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (ascendent ? vec[i] >= pivot : vec[i] <= pivot) {
            i++;
        }

        while (ascendent ? vec[j] < pivot : vec[j] > pivot) {
            j--;
        }

        if (ascendent ? (i > pivotIndex && j < pivotIndex) : (i < pivotIndex && j > pivotIndex)) {
            swap(vec[i++], vec[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int vec[], int low, int high, bool ascendent)
{
    if (low < high) {

        int pi = partition(vec, low, high, ascendent);

        quickSort(vec, low, pi - 1, ascendent);
        quickSort(vec, pi + 1, high, ascendent);
    }
}



Sort::Sort(int count, ...) {
    this->count=count;
    va_list v;
    va_start(v,count);
    for(int i=0;i<count;i++) {
        va_arg(v, int);

    }
    va_end(v);
}
void Sort::Print() {
    for(int i=0;i<count;i++)
        printf("%d ",vector);
}
int Sort::GetElementsCount() {
    int elem=0;
}

void Sort::BubbleSort(bool ascendent)
{
    if (this->count == 0)
        return;

    for (int i = 0; i < this->count - 1; i++)
        for (int j = i + 1; j < this->count; j++)
            if (this->vector[i] > this->vector[j])
                swap(this->vector[j], this->vector[i]);
}
Sort::Sort(int count, int min, int max) {
    this->count=count;
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0;i<count;i++){

    }
}

void Sort::InsertSort(bool ascendent)
{
    if (this->count == 0)
        return;

    int i, key, j;
    for (i = 1; i < this->count; i++)
    {
        key = this->vector[i];
        j = i - 1;
        while (j >= 0 && (ascendent ? this->vector[j] < key : this->vector[j] > key))
        {
            this->vector[j + 1] = this->vector[j];
            j = j - 1;
        }
        this->vector[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent)
{
    if (this->count == 0)
        return;

    quickSort(this->vector, 0, this->count - 1, ascendent);

}



int Sort::GetElementFromIndex(int index) {
    return vector[index];
}