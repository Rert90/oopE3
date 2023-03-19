//
// Created by Olariu Robert on 18.03.2023.
//

#ifndef LAB5EX1_NUMBER_H
#define LAB5EX1_NUMBER_H
#pragma once

class Number {
public:
    Number(const char* value, int base);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number operator+(const Number& other) const;
    Number operator-(const Number& other) const;
    char operator[](int index) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

private:
    char* m_value;
    int m_base;
    int m_digitsCount;
};




#endif //LAB5EX1_NUMBER_H
