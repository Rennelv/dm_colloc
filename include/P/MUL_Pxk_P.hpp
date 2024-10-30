#ifndef MUL_Pxk_P_HPP
#define MUL_Pxk_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполнил Салдин Даниил 3381
    Функция MUL_Pxk_P Умножение многочлена на x^k, k-натуральное или 0.
    Принимает:
        a - многочлен
    Возвращает:
        Polynomial - результат умножения многочлена на x^k, k-натуральное или 0.
*/

Polynomial MUL_Pxk_P(const Polynomial& a, const LongNatural& k);

#endif