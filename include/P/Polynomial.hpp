#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <map>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с многочленами с коэффицентами из длинных рациональных чисел.

*/

class Polynomial {
    std::map<LongNatural, LongRational> coefficients;  // словарь (мапа) коэффициентов (степень -> коэффициент)
    LongNatural degree;                                // степень полинома
   public:
    Polynomial(const std::map<LongNatural, LongRational>& map);  // создает полином из мапа коэффициентов

    LongRational getCoef(const LongNatural& degree) const;  // возвращает коэффициент при степени
    LongNatural getDegree() const;                          // возвращает степень полинома
    std::string toString() const;                           // возвращает строку полинома

    bool operator==(const Polynomial& other) const;  // оператор сравнения (проверяет равенство коэффициентов)
    bool operator!=(const Polynomial& other) const;  // оператор сравнения (проверяет равенство коэффициентов)
};

#endif