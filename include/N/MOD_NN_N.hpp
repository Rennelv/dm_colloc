#ifndef MOD_NN_N_HPP
#define MOD_NN_N_HPP

#include <algorithm>
#include <stdexcept>

#include "N/LongNatural.hpp"

/*
    Выполнила Гладилин Евгений 3381

    Функция MOD_NN_N вычисляет остаток от деления первого натурального числа на второе.
    Принимает:
        a - натуральное число
        b - натуральное число
    Возвращает:
        LongNatural - остаток от деления.
*/

LongNatural MOD_NN_N(LongNatural& a, LongNatural& b);

#endif  // MOD_NN_N_HPP
