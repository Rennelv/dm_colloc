#ifndef LED_P_Q_HPP
#define LED_P_Q_HPP

#include "P/Polynomial.hpp"

/*
    Выполнил Салдин Даниил 3381
    Функция LED_P_Q возвращает старший коэффициент многочлена.
    Принимает:
        a - многочлен
    Возвращает:
        LongRational- старший коэффициент многочлена.
*/

Polynomial LED_P_Q(const Polynomial& a);

#endif