#include "Number.h"
#include <cstring>
#include <iostream>
#include "cmath"

Number::Number(const char* value, int base)
        : m_base(base)
{
    int length = strlen(value);
    m_value = new char[length + 1];
    strcpy_s(m_value, length + 1, value);
    m_digitsCount = length;
}

Number::Number(const Number& other)
        : m_base(other.m_base)
{
    int length = strlen(other.m_value);
    m_value = new char[length + 1];
    strcpy_s(m_value, length + 1, other.m_value);
    m_digitsCount = other.m_digitsCount;
}

Number::Number(Number&& other) noexcept
        : m_value(other.m_value)
        , m_base(other.m_base)
        , m_digitsCount(other.m_digitsCount)
{
    other.m_value = nullptr;
    other.m_base = 0;
    other.m_digitsCount = 0;
}

Number::~Number()
{
    delete[] m_value;
}

Number& Number::operator=(const Number& other)
{
    if (this != &other) {
        delete[] m_value;
        m_base = other.m_base;
        int length = strlen(other.m_value);
        m_value = new char[length + 1];
        strcpy_s(m_value, length + 1, other.m_value);
        m_digitsCount = other.m_digitsCount;
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept
{
    if (this != &other) {
        delete[] m_value;
        m_value = other.m_value;
        m_base = other.m_base;
        m_digitsCount = other.m_digitsCount;
        other.m_value = nullptr;
        other.m_base = 0;
        other.m_digitsCount = 0;
    }
    return *this;
}

Number Number::operator+(const Number& other) const
{
    // Convert both numbers to base 10
    int sum = strtol(m_value, nullptr, m_base) + strtol(other.m_value, nullptr, other.m_base);
    // Convert the sum back to the original base
    char buffer[33];
    itoa(sum, buffer, m_base);
    return Number(buffer, m_base);
}

Number Number::operator-(const Number& other) const
{
    // Convert both numbers to base 10
    int diff = strtol(m_value, nullptr, m_base) - strtol(other.m_value, nullptr, other.m_base);
    // Convert the difference back to the original base
    char buffer[33];
    itoa(diff, buffer, m_base);
    return Number(buffer, m_base);
}
