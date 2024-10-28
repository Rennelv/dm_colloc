#ifndef SUB_NDN_N_HPP
#define SUB_NDN_N_HPP

#include "LongNatural.hpp"

/*
    Выполнил Гладилин Евгений 3381

    Функция SUB_NDN_N принимает два натуральных числа и цифру. Возвращает разность первого и второго, умноженного на цифру.
    Принимает:
        a - первое натуральное число
        b - второе натуральное число(вычитаемое)
        d - цифра, на которую умножают b
    Возвращает:
        LongNatural - разность первого числа и второго, умноженного на цифру
*/

LongNatural SUB_NDN_N(const LongNatural& a, const LongNatural& b, const uint8_t& k);

#endif  // SUB_NDN_N_HPP
