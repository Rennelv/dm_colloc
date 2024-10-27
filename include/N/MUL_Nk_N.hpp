#ifndef MUL_NK_N_HPP
#define MUL_NK_N_HPP

#include "N/LongNatural.hpp"

/*
    Выполнила Кунакова Мария 3381
    
    Функция MUL_Nk_N умножает натуральное число на 10^k.
    Принимает:
        a - натуральное число
        k - степень числа 10, на которую выполнится умножение
    Возвращает:
        LongNatural - результат умножения
*/

LongNatural MUL_Nk_N(const LongNatural& a, size_t k);

#endif
