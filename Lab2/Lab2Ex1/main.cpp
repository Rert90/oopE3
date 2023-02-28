#include <iostream>
#include "NumberList.h"
int main() {
    NumberList list;
    list.Init();
    list.Add(1);
    list.Add(3);
    list.Add(2);
    list.Add(4);
    list.Add(22);
    list.Sort();
    list.Print();
    return 0;
}
