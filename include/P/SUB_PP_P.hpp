#ifndef SUB_PP_P_HPP
#define SUB_PP_P_HPP

#include <N/LongNatural.hpp>
#include <P/Polynomial.hpp>
#include <Q/LongRational.hpp>
#include <Z/LongInteger.hpp>

/*
    Выполнила Деревягина Александра 3381

    Функция SUB_PP_P принимает два полинома и возвращает их разность
    Принимает:
        a - полином
        b - полином
    Возвращает:
        разность двух полиномов (полином)
*/

Polynomial SUB_PP_P(const Polynomial& a, const Polynomial& b);

#endif  // SUB_PP_P_HPP
