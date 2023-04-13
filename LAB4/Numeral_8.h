#pragma once
#include <iostream>
#include <string>

class Numeral_8 {
private:
    std::string octal_num;
public:
    Numeral_8();
    Numeral_8(std::string x);
    Numeral_8(int decimal_num);
    int octalToDecimal();
    std::string decimalToOctal(long n);
    std::string getNum();
    Numeral_8 add(Numeral_8& other);
    Numeral_8 increment();
    Numeral_8 addAssig(int other);
    Numeral_8 operator+(Numeral_8& other);
    Numeral_8 operator++();
    Numeral_8 operator++(int);
    Numeral_8 operator+=(int other);
};