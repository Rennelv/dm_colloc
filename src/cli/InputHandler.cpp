#include "cli/InputHandler.hpp"

#include <iostream>
#include <limits>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

LongNatural InputHandler::scanLongNatural() {
    std::cout << "Введите натуральное число: ";
    std::string number;
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return LongNatural(number);
}

LongInteger InputHandler::scanLongInteger() {
    std::cout << "Введите целое число: ";
    std::string number;
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return LongInteger(number);
}

Polynomial InputHandler::scanPolynomial() {
    std::cout << "Задайте многочлен в виде пар чисел (степень, коэффициент) в порядке убывания степеней, ввод заканчивается после ввода коэффициента при "
                 "нулевой степени.\n";
    std::cout << "Введите степень: ";
    size_t degree;
    std::cin >> degree;
    if (std::cin.fail()) {
        std::cout << "Неверный ввод\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    LongRational coefficient = scanLongRational();
    std::vector<LongRational> coefficients(degree + 1, LongRational(LongInteger("0"), LongNatural("1")));
    size_t idx = coefficients.size() - 1 - degree;
    coefficients[idx] = coefficient;
    size_t last_degree = degree;
    while (degree != 0) {
        std::cout << "Введите степень: ";
        std::cin >> degree;
        if (degree >= last_degree) {
            std::cout << "Степень должна быть меньше предыдущей.\n";
            throw std::invalid_argument("Invalid degree");
        }
        idx = coefficients.size() - 1 - degree;
        LongRational coefficient = scanLongRational();
        coefficients[idx] = coefficient;
    }
    return Polynomial(coefficients);
}

LongRational InputHandler::scanLongRational() {
    std::string number1, number2;

    std::cout << "Введите числитель (целое число) и знаменатель (натуральное число) через пробел: ";
    std::cin >> number1 >> number2;

    if (std::cin.fail()) {
        std::cout << "Неверный ввод\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input");
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    LongInteger numerator = LongInteger(number1);

    LongNatural denominator = LongNatural(number2);

    return LongRational(numerator, denominator);
}