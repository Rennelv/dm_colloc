#ifndef GCF_NN_N_HPP
#define GCF_NN_N_HPP

#include "N/LongNatural.hpp"

/*
    Выполнил Гладилин Евгений 3381

    Функция GCF_NN_N вычисляет НОД двух натуральных чисел. Для поиска НОД используется алгоритм Евклида.
    Принимает:
        a - натуральное число
        b - натуральное число
    Возвращает:
        LongNatural - НОД двух чисел.
*/

LongNatural GCF_NN_N(const LongNatural& a, const LongNatural& b);

#endif  // GCF_NN_N_HPP
