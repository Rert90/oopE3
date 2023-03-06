#include <iostream>
#include "Math.h"

int main() {
    int result = Math::Add(3, 4, 5, 6);
    printf("%d\n",result);
   printf("%d\n",Math::Mul(3.5,2.3));
    printf("%d",Math::Add('a','a'));
    return 0;
}
