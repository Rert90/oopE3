#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <iostream>
using namespace std;

int str_to_int(char *str) {
    int result = 0;
    for (int i = 0; i < strlen(str)-1; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

int main() {
    FILE* file;
    int sum = 0;
    file = fopen("/Users/olariurobert/projects/oopE3/oopE3/Lab1/ini.txt", "r");
    if (file == NULL)
    {
        printf("Eroare. Nu am putut deschide fisierul\n");
    }
    else {
        printf("Am deschis fisierul cu success!\n");
        char line[200];
        while (fgets(line, 100, file) != NULL) {
            sum += str_to_int(line);
        }
    }
    printf("%d", sum);
    printf("\n\n");
}