// LAB4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "supmethods.h"
#include "Numeral_8.h"

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

