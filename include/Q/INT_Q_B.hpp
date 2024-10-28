#ifndef INT_Q_B_HPP
#define INT_Q_B_HPP

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

/*
    Выполнила Киреева Асия 3381

    Функция INT_Q_B проверяет, является ли сокращенное дробное число целым, если рациональное число является целым, то «да», иначе «нет»
    Принимает:
        n - рациональное число
    Возвращает:
        если знаменатель равен нулю - ошибка
        если знаменатель равен единице, то число целое - 1
        если знаменатель не равен единице, то число нецелое - 0
*/

int INT_Q_B(const LongRational &n);

#endif