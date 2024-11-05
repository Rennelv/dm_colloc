#ifndef NMR_P_P_HPP
#define NMR_P_P_HPP

#include "P/Polynomial.hpp"

/*
    Выполинал Щеглов Михаил 3381

    Функция NMR_P_P принимает многочлен и преобразует кратные корни в простые
    Принимает:
        p - многочлен
    Возвращает:
        Polynomial - преобразованный многочлен
*/

Polynomial NMR_P_P(const Polynomial &p);

#endif  // NMR_P_P_HPP