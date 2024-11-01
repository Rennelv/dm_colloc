#ifndef FAC_P_Q_HPP
#define FAC_P_Q_HPP

#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"

/*
    Выполнил Гладилин Евгений 3381
    Функция FAC_P_Q выносит НОД числителей многочлена и НОК знаменятелей многочлена.
    Принимает:
        a - многочлен
    Возвращает:
        LongInteger - дробь, в числителе которой находится НОД всех числителей, а в знаменателе НОК знаменателей.
*/

LongRational FAC_P_Q(Polynomial& a);

#endif