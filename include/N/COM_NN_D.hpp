#ifndef COM_NN_D_HPP
#define COM_NN_D_HPP

#include <N/LongNatural.hpp>

/*
    Выполнил Журавлев Дмитрий 3381

    Функция COM_NN_D принимает два числа и сравнивает их.
    Принимает:
        a - первое число
        b - второе число
    Возвращает:
        0 - если числа равны
        1 - если второе число больше первого
        2 - если первое число больше второго
*/

int COM_NN_D(const LongNatural& a, const LongNatural& b);

#endif  // COM_NN_D_HPP