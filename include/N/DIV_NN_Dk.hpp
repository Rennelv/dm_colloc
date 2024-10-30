#ifndef DIV_NN_DK_HPP
#define DIV_NN_DK_HPP

#include <algorithm>
#include <stdexcept>

#include "N/LongNatural.hpp"

/*
    Выполнила Кунакова Мария 3381

    Функция DIV_NN_Dk вычисляет первую цифру деления большего натурального на меньшее,
    домноженную на 10^k. Ипсользует базовые модули COM_NN_D и MUL_Nk_N.
    Принимает:
        a - натуральное число
        b - натуральное число
    Возвращает:
        LongNatural - первая цифра деления большего числа на меньшее, умноженное на 10^k,
        где k - номер позиции этой цифры.
*/

LongNatural DIV_NN_Dk(const LongNatural& a, const LongNatural& b);

#endif  // DIV_NN_DK_HPP
