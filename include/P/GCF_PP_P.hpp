#ifndef GCF_PP_P_HPP
#define GCF_PP_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполнила: Уфимцева Алиса, группа 3381

    Функция GCF_PP_P находит наибольший общий делитель (НОД) двух многочленов.
    Принимает:
        p1 - первый многочлен
        p2 - второй многочлен
    Возвращает:
        Polynomial - НОД многочленов p1 и p2
*/

Polynomial GCF_PP_P(const Polynomial& p1, const Polynomial& p2);

#endif
