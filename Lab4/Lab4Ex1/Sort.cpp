#include "Sort.h"
#include <cstdio>
#include <ctime>
#include "iostream"
#include <cstdlib>
#include <cstdarg>
using namespace std;
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
    int* tempArray = new int[count];
    for(int i=0;i<count;i++) {
        tempArray[i]= va_arg(v,int);
    }
    quickSort(tempArray,0, count-1,true);

    va_end(v);
    delete[] tempArray;
}
int Sort::GetElementsCount() {
    return this->count;
}
int Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= this->count) {
        std::cerr << "Index out of bounds." << std::endl;
        return -1;  // Or some other error value.
    }
    return this->vector[index];
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
Sort::Sort(int* vector, int count) : count(count)
{
    this->vector = new int[count];
    for (int i = 0; i < count; i++) {
        this->vector[i] = vector[i];
    }
}

Sort::Sort() : count(0), vector(nullptr) {}

Sort::Sort(int count, int min, int max) : count(count)
{
    vector = new int[count];
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        vector[i] = rand() % (max - min + 1) + min;
    }
}

void Sort::Print()
{
    if (this->count == 0)
    {
        cout << "The list is empty!" << endl;
        return;
    }

    cout << "Sorted list: ";
    for (int i = 0; i < this->count; i++)
    {
        cout << this->vector[i];
        if (i != this->count - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
Sort::Sort(char* c) {
    // First, count the number of elements in the string
    int length = strlen(c);
    int count = 1;
    for (int i = 0; i < length; i++) {
        if (c[i] == ',') {
            count++;
        }
    }

    // Allocate memory for the vector
    this->vector = new int[count];
    this->count = count;

    // Parse the string and fill the vector
    char* token = strtok(c, ",");
    int index = 0;
    while (token != NULL) {
        int value = atoi(token);
        this->vector[index] = value;
        token = strtok(NULL, ",");
        index++;
    }
}
