//
// Created by Olariu Robert on 06.03.2023.
//

#include "Math.h"
#include <cstdarg>
#include "cstring"

int Math::Add(int a1,int a2) {
    return a1+a2 ;
}
int Math::Add(int a1, int a2, int a3) {
    return a1+a2+a3;
}
int Math::Add(double a1, double a2) {
    return a1+a2;
}
int Math::Add(double a1, double a2, double a3) {
    return a1+a2+a3;
}
int Math::Mul(int m1 , int m2) {
    return m1*m2;

}
int Math::Mul(int m1 , int m2, int m3) {
    return m1*m2*m3;

}
 int Math::Mul(double m1 , double m2) {
    return m1*m2;
}
int Math::Mul(double m1, double m2 , double m3) {
    return m1*m2*m3;
}
int Math::Add(int count,...) {
   va_list v;

   int sum=0;
    va_start(v,count);
    for (int i = 0; i < count; i++) {
        sum = sum + va_arg(v, int);
    }
    va_end(v);
    return sum;
}
#include <cstring>

char* Add(const char* str1, const char* str2) {
    char* result = new char[std::strlen(str1) + std::strlen(str2) + 1];
    std::strcpy(result, str1);
    std::strcat(result, str2);
    return result;
}
