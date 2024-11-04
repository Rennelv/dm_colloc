#ifndef MOD_ZZ_Z_HPP
#define MOD_ZZ_Z_HPP

#include "Z/LongInteger.hpp"

/*
    Выполнила Киреева Асия 3381

    Функция MOD_ZZ_Z ищет остаток от деления одного целого числа на другое (делитель отличен от нуля)
    Принимает:
        dividend - делимое, целое число
        divisor - делитель, целое число, не равное нулю
    Возвращает:
        остаток от деления dividend на divisor
*/

LongInteger MOD_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor);

#endif