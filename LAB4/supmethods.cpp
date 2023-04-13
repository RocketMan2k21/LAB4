#include "Numeral_8.h"
#include "supmethods.h"
#include <string>
#include <iostream>

Numeral_8::Numeral_8()
    : octal_num("0") {}
Numeral_8::Numeral_8(std::string x)
    : octal_num(x) {}
Numeral_8::Numeral_8(int decimal_num) {
    octal_num = "";
    while (decimal_num > 0) {
        octal_num = std::to_string(decimal_num % 8) + octal_num;
        decimal_num /= 8;
    }
    if (octal_num.empty()) {
        octal_num = "0";
    }
}

int Numeral_8::octalToDecimal()
{
    int temp = std::stoi(octal_num);
    int decimalNumber = 0, i = 0, rem;
    while (temp != 0)
    {
        rem = temp % 10;
        temp /= 10;
        decimalNumber += rem * (int)pow(8, i);
        ++i;
    }
    return decimalNumber;
}
std::string Numeral_8::decimalToOctal(long n) {
    int remainder;
    long octal = 0, i = 1;

    while (n != 0) {
        remainder = n % 8;
        n = n / 8;
        octal = octal + (remainder * i);
        i = i * 10;
    }
    return std::to_string(octal);
}
std::string Numeral_8::getNum() {
    return octal_num;
}
Numeral_8 Numeral_8::add(Numeral_8& other) {
    return Numeral_8(decimalToOctal(this->octalToDecimal() + other.octalToDecimal()));
}

Numeral_8 Numeral_8::increment() {
    int result = this->octalToDecimal();
    octal_num = decimalToOctal(++result);
    return *this;
}

Numeral_8 Numeral_8::addAssig(int other) {
    int result = this->octalToDecimal();
    octal_num = decimalToOctal(result + other);
    return *this;
}

Numeral_8 Numeral_8::operator+(Numeral_8& other) {
    return add(other);
}


Numeral_8 Numeral_8::operator++() { //pre increment
    return increment();
}

Numeral_8 Numeral_8::operator++(int) { //post increment
    Numeral_8 temp = *this;
    increment();
    return temp;
}

Numeral_8 Numeral_8::operator+=(int other) {
    return addAssig(other);
}

std::ostream& operator<<(std::ostream& stream, Numeral_8& other) {
    stream << other.getNum();
    return stream;
}

bool checkOct(std::string& other) {
    if (other[0] == '0')
    {
        other.erase(0, 1);
        return true;
    }
    else return false;
}