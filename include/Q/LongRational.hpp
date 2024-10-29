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
    LongRational(const LongInteger& numerator, const LongNatural& denominator);

    const LongInteger& getNumerator() const;    // возвращает числитель
    const LongNatural& getDenominator() const;  // возвращает знаменатель
    std::string toString() const;               // возвращает число в виде строки (числитель / знаменатель)

    bool operator==(const LongRational& other) const;  // оператор сравнения (проверяет равенство числителей и знаменателей)
    bool operator!=(const LongRational& other) const;  // оператор сравнения (проверяет равенство числителей и знаменателей)
};

#endif  // LONGRATIONAL_HPP