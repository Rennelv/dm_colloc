#ifndef DIV_NN_N_HPP
#define DIV_NN_N_HPP

#include <algorithm>
#include <stdexcept>

#include "N/LongNatural.hpp"

/*
    Выполнила Гладилин Евгений 3381

    Функция DIV_NN_N вычисляет неполное частное от деления первого натурального числа на второе.
    Принимает:
        a - натуральное число
        b - натуральное число
    Возвращает:
        LongNatural - неполное частное от деления.
*/

LongNatural DIV_NN_N(LongNatural& a, LongNatural& b);

#endif  // DIV_NN_N_HPP
