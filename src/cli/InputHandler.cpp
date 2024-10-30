#include "cli/InputHandler.hpp"

#include <iostream>
#include <limits>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

// Считывает натуральное число
LongNatural InputHandler::scanLongNatural() {
    std::string number;
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("InputHandler::scanLongNatural: invalid input");
    }
    return LongNatural(number);
}

// Считывает целое число
LongInteger InputHandler::scanLongInteger() {
    std::string number;
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("InputHandler::scanLongInteger: invalid input");
    }
    return LongInteger(number);
}

// Считывает многочлен
Polynomial InputHandler::scanPolynomial() {
    std::map<LongNatural, LongRational> coefficients;
    std::cout << "Задайте многочлен в виде пар чисел (степень, коэффициент), ввод заканчивается после ввода коэффициента при нулевой степени.\n";
    while (true) {
        std::cout << "Введите степень (натуральное число): ";
        LongNatural degree = scanLongNatural();
        std::cout << "Введите коэффициент (рациональное число) ниже\n";
        LongRational coefficient = scanLongRational();
        coefficients.emplace(degree, coefficient);
        if (degree == LongNatural("0")) {
            break;
        }
    };

    return Polynomial(coefficients);
}

// Считывает длинное рациональное число
LongRational InputHandler::scanLongRational() {
    std::string number1, number2;

    std::cout << "Введите числитель (целое число) и знаменатель (натуральное число) через пробел: ";

    LongInteger numerator = scanLongInteger();

    LongNatural denominator = scanLongNatural();

    return LongRational(numerator, denominator);
}