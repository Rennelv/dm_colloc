#ifndef TRANS_Z_N_HPP
#define TRANS_Z_N_HPP

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"

/*
    Выполнила Киреева Асия 3381

    Функция TRANS_Z_N преобразовывает целое неорицательное число в натуральное
    Принимает:
        n - целое неорицательное число
    Возвращает:
        если n > 0 - возвращаем натуральное число
        если n = 0 - ошибка
*/

LongNatural TRANS_Z_N(const LongInteger &n);

#endif