#include <iostream>
#include "Math.h"

int main() {
    int result = Math::Add(3, 4, 5, 6);
   std:: cout<<result<<" ";
   std::cout<<Math::Mul(3.5,2.3)<<" ";
   std::cout<<Math::Add("V","C");
    return 0;
}
