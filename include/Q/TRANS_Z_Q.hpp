#ifndef TRANS_Z_Q_HPP
#define TRANS_Z_Q_HPP

#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

/*
    Выполнил Гладилин Евгений 3381

    Функция TRANS_Z_Q преобразовывает целое число в дробное.
    Принимает:
        n - целое число
    Возвращает:
        LongRational - дробное число со знаменателем 1.
*/

LongRational TRANS_Z_Q(const LongInteger &n);

#endif