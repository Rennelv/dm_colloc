#ifndef DIV_PP_P_HPP
#define DIV_PP_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполнил: Уфимцева Алиса, группа 3381

    Функция DIV_PP_P выполняет целочисленное деление одного многочлена на другой.
    Принимает:
        p1 - делимый многочлен
        p2 - делитель многочлен
    Возвращает:
        Polynomial - частное от деления p1 на p2
*/

Polynomial DIV_PP_P(const Polynomial& p1, const Polynomial& p2);

#endif
