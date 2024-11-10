#ifndef LONGRATIONAL_HPP
#define LONGRATIONAL_HPP

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"

/**
 * @file LongRational.hpp
 * @brief Класс для работы с рациональными числами (дробями).
 */

/**
 * @class LongRational
 * @brief Класс для работы с рациональными числами (дробями).
 *
 * @details Класс предоставляет методы для создания рациональных чисел из длинного целого числа (числитель)
 * и длинного натурального числа (знаменатель), а также методы для получения числителя и знаменателя и
 * представления числа в виде строки.
 * Число хранится в виде пары (числитель (LongInteger), знаменатель (LongNatural)).
 *
 * @author Журавлев Дмитрий 3381
 */

class LongRational {
    LongInteger numerator;    // числитель
    LongNatural denominator;  // знаменатель

   public:
    // Рациональное нулевое число (0/1)
    static const LongRational ZERO;
    // Рациональное единичное число (1/1)
    static const LongRational ONE;

    // Создает число из длинного целого числа(числитель) и длинного натурального числа(знаменатель)
    LongRational(const LongInteger& numerator, const LongNatural& denominator);

    // Возвращает числитель (const&)
    const LongInteger& getNumerator() const;

    // Возвращает знаменатель (const&)
    const LongNatural& getDenominator() const;

    // Возвращает число в виде строки (числитель/знаменатель)
    std::string toString() const;

    // Оператор сравнения (проверяет равенство числителей и знаменателей)
    bool operator==(const LongRational& other) const;
    // Оператор сравнения (обратный оператору ==)
    bool operator!=(const LongRational& other) const;
};

#endif  // LONGRATIONAL_HPP