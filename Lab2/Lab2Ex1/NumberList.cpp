#include <iostream>
#include "NumberList.h"
#include <stdio.h>
using namespace std;

void NumberList::Init() {
    this->count=0;
}
bool NumberList::Add(int x) {
    if(count>=10)
        return false;
    else {

        this->numbers[count++] = x;

    }
}
void NumberList::Sort() {
    for(int i=0;i<count-1;i++)
    {for(int j=i+1;j<=count;j++)
        if(numbers[i]<numbers[j])
            swap(numbers[i],numbers[j]);}
}
void NumberList::Print() {
    for(int i=0;i<count;i++)
        cout<<numbers[i]<<" ";
}
