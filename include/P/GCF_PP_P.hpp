#ifndef GCF_PP_P_HPP
#define GCF_PP_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполинала Уфимцева Алиса 3381

    Функция GCF_PP_P принимает два многочлена и находит их наибольший общий делитель.
    Принимает:
        p1 - первый многочлен
        p2 - второй многочлен
    Возвращает:
        Polynomial - НОД многочленов (приведенный многочлен)
*/

Polynomial GCF_PP_P(const Polynomial &a, const Polynomial &b);

#endif  // GCF_PP_P_HPP