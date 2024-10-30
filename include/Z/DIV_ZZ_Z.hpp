#ifndef DIV_ZZ_Z_HPP
#define DIV_ZZ_Z_HPP

#include "Z/LongInteger.hpp"

/*
    Выполнил Щеглов Михаил, группа 3381

    Функция DIV_ZZ_Z выполняет деление целого числа на целое (делитель отличен от нуля).
    Принимает:
        dividend - делимое (целое число)
        divisor - делитель (целое число, не равен нулю)
    Возвращает:
        LongInteger - частное от деления целого на целое
*/

LongInteger DIV_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor);

#endif
