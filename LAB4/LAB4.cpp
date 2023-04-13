// LAB4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "supmethods.h"
#include "Numeral_8.h"

//class Numeral_8 {
//private:
//    std::string octal_num;
//public:
//    Numeral_8()
//        : octal_num("0") {}
//    Numeral_8(std::string x) 
//        : octal_num(x) {}
//    Numeral_8(int decimal_num) {
//        octal_num = "";
//        while (decimal_num > 0) {
//            octal_num = std::to_string(decimal_num % 8) + octal_num;
//            decimal_num /= 8;
//        }
//        if (octal_num.empty()) {
//            octal_num = "0";
//        }
//    }
//    
//    int octalToDecimal()
//    {
//        int temp = std::stoi(octal_num);
//        int decimalNumber = 0, i = 0, rem;
//        while (temp != 0)
//        {
//            rem = temp % 10;
//            temp /= 10;
//            decimalNumber += rem * (int)pow(8, i);
//            ++i;
//        }
//        return decimalNumber;
//    }
//    std::string decimalToOctal(long n) {
//        int remainder;
//        long octal = 0, i = 1;
//
//        while (n != 0) {
//            remainder = n % 8;
//            n = n / 8;
//            octal = octal + (remainder * i);
//            i = i * 10;
//        }
//        return std::to_string(octal);
//    }
//    std::string getNum() {
//        return octal_num;
//    }
//    Numeral_8 add(Numeral_8& other){
//        return Numeral_8(decimalToOctal(this->octalToDecimal() + other.octalToDecimal()));
//    }
//    
//    Numeral_8 increment() {
//        int result = this->octalToDecimal();
//        octal_num = decimalToOctal(++result);
//        return *this;
//    }
//    
//    Numeral_8 addAssig(int other) {
//        int result = this->octalToDecimal();
//        octal_num = decimalToOctal(result+other);
//        return *this;
//    }
//
//    Numeral_8 operator+(Numeral_8& other) {
//        return add(other);
//    }
//    
//    
//    Numeral_8 operator++() { //pre increment
//        return increment();
//    }
//
//    Numeral_8 operator++(int) { //post increment
//        Numeral_8 temp = *this;
//        increment();
//        return temp;
//    }
//
//    Numeral_8 operator+=(int other) {
//        return addAssig(other);
//    }
//};
//
//    std::ostream& operator<<(std::ostream& stream, Numeral_8& other) {
//        stream << other.getNum();
//        return stream;
//}
//
//    bool checkOct(std::string& other) {
//        if (other[0] == '0')
//        {
//            other.erase(0, 1);
//            return true;
//        }
//        else return false;
//    }

int main()
{
    std::string a, b;
    int addAssignment;
    Numeral_8 N1;
    Numeral_8 N2;
    Numeral_8 N3;
    
    std::cout << "Type number N1(USE '0' prefix to put as octual value otherwise it will be putted as decimal): " << std::endl;
    std::cin >> a;
    std::cout << "Type number N2(USE '0' prefix to put as octual value otherwise it will be putted as decimal): " << std::endl;
    std::cin >> b;
    std::cout << "What value you want to add to N2?" << std::endl;
    std::cin >> addAssignment;
    
    if (checkOct(a)) N1 = Numeral_8(a);
    else N1 = Numeral_8(std::stoi(a));
    if (checkOct(b)) N2 = Numeral_8(b);
    else N2 = Numeral_8(std::stoi(b));

    std::cout << "Your input: " << std::endl;
    std::cout << "Octal N1: " << N1 << std::endl;
    std::cout << "Octal N2: " << N2 << std::endl;
    std::cout << "Increasing value: " << addAssignment << std::endl;

    ++N1;
    N2 += addAssignment;
    N3 = N1 + N2;
    
    std::cout << "\n";
    std::cout << "Results: " << std::endl;
    std::cout << "Octal N1: " << N1 << ", decimal:" << N1.octalToDecimal() << std::endl;
    std::cout << "Octal N2: " << N2 << ", decimal:" << N2.octalToDecimal() << std::endl;
    std::cout << "Decimal (N1+N2): " << N3.octalToDecimal() << std::endl;
    
}

