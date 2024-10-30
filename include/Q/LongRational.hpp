#ifndef LONGRATIONAL_HPP
#define LONGRATIONAL_HPP

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"

/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с рациональными числами (дробями).

*/

class LongRational {
    LongInteger numerator;    // числитель
    LongNatural denominator;  // знаменатель

   public:
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