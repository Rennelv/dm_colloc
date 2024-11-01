#ifndef MUL_PQ_P_HPP
#define MUL_PQ_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполнил Салдин Даниил 3381
    Функция MUL_PQ_P - умножение многочлена на рациональное число.
    Принимает:
        a - многочлен
        q - рациональное число
    Возвращает:
        Polynomial - результат умножение многочлена на рациональное число.
*/

Polynomial MUL_PQ_P(const Polynomial& a, const LongRational& q);

#endif