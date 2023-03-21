#include "Number.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

Number::Number(const char* value, int base):number_base_10(0),number_base(nullptr),base(base),digits(0)
{
    const char* end = value;
    while (*end != '\0') {
        digits++;
        end++;
    }

    number_base = new char[digits]; //aloc memorie pt nume
    number_base=(char*)memcpy(number_base, value, digits * sizeof(char));
    number_base[digits] = '\0';


    if(base<=10)
    {
        int power = base;
        number_base_10 = value[digits - 1]-'0';

        for (int i = digits - 2; i >= 0; i--)
        {
            number_base_10 = number_base_10 + (value[i] - '0') * power;
            power *= base;
        }
    }
    else
    {
        int power = base;
        int val = value[digits - 1];
        if (val >= 'A' && val <= 'Z')
            val = val - 'A' + 10;
        else
            val = val - '0';
        number_base_10 = val;

        for (int i = digits - 2; i >= 0; i--)
        {
            int val = value[digits - 1];
            if (val >= 'A' && val <= 'Z')
                val = val - 'A' + 10;
            else
                val = val - '0';

            number_base_10 = number_base_10 + val * power;
            power *= base;
        }
    }

}

Number::Number(int value)
{
    digits = 0;
    base = 10;
    number_base_10 = value;
    number_base = new char[15];
    for (int i = 0; i >= 0 && value != 0; i++)
    {
        number_base[i] = value % 10 + '0';
        digits++;
        value /= 10;
    }
    number_base[digits] = '\0';
    for (int i = 0; i < (digits - 1) / 2; i++)
        std::swap(number_base[i], number_base[digits - 1 - i]);

}

Number::Number(const Number& n)
{
    this->number_base = n.number_base;
    this->number_base_10 = n.number_base_10;
    this->digits = n.digits;
    this->base = n.base;
}

Number::Number(const Number&& n)
{
    this->number_base_10 = n.number_base_10;
    strcpy(number_base, n.number_base);
    this->base = n.base;
    this->digits = n.digits;
}

Number::~Number()
{
    if (number_base != nullptr)
        delete[]number_base;
    number_base = nullptr;
}

char Number::operator[](int index)
{
    return number_base[index];
}

Number* Number::operator--()
{
    number_base++;
    digits--;
    number_base_10 = 0;
    for (int i = 0; i < digits; i++)
        number_base_10=number_base_10*10+number_base[i] - '0';
    return this;
}

Number& Number::operator=(int x)
{
    digits = 0;
    base = 10;
    number_base_10 = x;
    number_base = new char[15];
    for (int i = 0; i >= 0 && x != 0; i++)
    {
        number_base[i] = x % 10 + '0';
        digits++;
        x /= 10;
    }
    number_base[digits] = '\0';
    for (int i = 0; i < (digits - 1) / 2; i++)
        std::swap(number_base[i], number_base[digits-1-i]);
    return 0;
}

int Number::operator=(const char* x)

{
    digits = 0;
    base = 10;
    number_base_10 = 0;
    number_base = new char[15];
    for (int i = 0; x[i]>='0'&&x[i]<='9'; i++)
    {
        number_base[i] = x[i];
        number_base_10 = number_base_10 * 10 + x[i]-'0';
        digits++;
    }
    number_base[digits] = '\0';
    return 0;
}

void Number::SwitchBase(int newBase)
{
    if (newBase == base)
        return;


    digits = 0;
    char* temp = new char[15];
    int j = -1;

    int aux = number_base_10;
    while (aux)
    {
        digits++;
        if (newBase > 10)
        {
            int val = aux% newBase;
            if (val >= 10)
                temp[++j] = 'A'+val-10;
            else
                temp[++j] = '0'+val;
        }
        else
            temp[++j] = aux % newBase+'0';

        aux = aux / newBase;
    }

    number_base = new char[digits];
    for (int i = 0; i < digits; i++)
        number_base[i] = temp[j--];
    number_base[digits] = '\0';
    base = newBase;
}

void Number::Print()
{
    std::cout << "Numarul " << number_base_10 << " scris in baza " << base << " este: ";
    for (int i = 0; i < digits; i++)
        std::cout << number_base[i];
    std::cout << std::endl;
}

int Number::GetDigitsCount()
{
    return digits;
}

int Number::GetBase()
{
    return base;
}

Number operator+( Number x,  Number y)
{
    int newBase = y.GetBase();
    if (x.GetBase() > y.GetBase())
        newBase = x.GetBase();

    x.SwitchBase(10);
    y.SwitchBase(10);
    int nr1 = 0, nr2 = 0;
    for (int i = 0; i < x.GetDigitsCount(); i++)
        nr1 = nr1 * 10 + x[i]-'0';
    for (int i = 0; i < y.GetDigitsCount(); i++)
        nr2 = nr2 * 10 + y[i]-'0';

    int sum = nr1 + nr2, maxim;

    if (x.GetDigitsCount() > y.GetDigitsCount())
        maxim = x.GetDigitsCount() + 1;
    else
        maxim = y.GetDigitsCount() + 1;

    char* temp = new char[maxim];

    for (int i = maxim-1;sum!=0&&i >= 0; i--)
    {
        temp[i] = '0'+sum % 10;
        sum = sum / 10;
    }
    while (!(temp[0] >= '0' && temp[0] <= '9'))
    {
        temp++;
        maxim--;
    }
    temp[maxim] = '\0';
    Number A(temp, 10);
    A.SwitchBase(newBase);
    return A;
}

Number operator+=(Number x, Number y)
{

    return x+y;
}

Number operator-(Number x, Number y)
{
    int newBase = y.GetBase();
    if (x.GetBase() > y.GetBase())
        newBase = x.GetBase();

    x.SwitchBase(10);
    y.SwitchBase(10);
    int nr1 = 0, nr2 = 0;
    for (int i = 0; i < x.GetDigitsCount(); i++)
        nr1 = nr1 * 10 + x[i] - '0';
    for (int i = 0; i < y.GetDigitsCount(); i++)
        nr2 = nr2 * 10 + y[i] - '0';


    int sum = nr1 - nr2, maxim;

    if (x.GetDigitsCount() > y.GetDigitsCount())
        maxim = x.GetDigitsCount() + 1;
    else
        maxim = y.GetDigitsCount() + 1;

    char* temp = new char[maxim];

    for (int i = maxim - 1; sum != 0 && i >= 0; i--)
    {
        temp[i] = '0' + sum % 10;
        sum = sum / 10;
    }
    while (!(temp[0] >= '0' && temp[0] <= '9'))
    {
        temp++;
        maxim--;
    }
    temp[maxim] = '\0';
    Number A(temp, 10);
    A.SwitchBase(newBase);
    return A;
}

bool operator>(Number x, Number y)
{
    return x.number_base_10>=y.number_base_10;
}

Number* operator--(Number& num, int value)
{
    num.number_base[num.digits - 1] = '\0';
    num.digits--;
    num.number_base_10 /= 10;
    return &num;
}
