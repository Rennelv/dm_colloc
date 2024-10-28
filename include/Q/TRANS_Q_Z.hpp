#ifndef TRANS_Q_Z_HPP
#define TRANS_Q_Z_HPP

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

/*
    Выполнила Киреева Асия 3381

    Функция TRANS_Q_Z преобразовывает сокращенное дробное число в целое
    Принимает:
        n - рациональное число
    Возвращает:
        если знаменатель равен нулю - ошибка
        если знаменатель равен единице - возвращаем числитель
        если знаменатель не равен единице - ошибка
*/

LongInteger TRANS_Q_Z(const LongRational &n);

#endif