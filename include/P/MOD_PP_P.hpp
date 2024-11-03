#ifndef MOD_PP_P_HPP
#define MOD_PP_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполнил: Щеглов Михаил, группа 3381

    Функция MOD_PP_P выполняет вычисление остатка от деления одного многочлена на другой.
    Принимает:
        p1 - делимый многочлен
        p2 - делитель многочлен
    Возвращает:
        Polynomial - остаток от деления p1 на p2
*/

Polynomial MOD_PP_P(const Polynomial& p1, const Polynomial& p2);

#endif
