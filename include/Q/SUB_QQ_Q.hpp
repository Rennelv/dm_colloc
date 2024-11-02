#ifndef SUB_QQ_Q_HPP
#define SUB_QQ_Q_HPP

#include <N/LongNatural.hpp>
#include <Q/LongRational.hpp>
#include <Z/LongInteger.hpp>

/*
    Выполнила Деревягина Александра 3381

    Функция SUB_QQ_Q принимает две дроби и возвращает их разность
    Принимает:
        a - рациональное число
        b - рациональное число
    Возвращает:
        разность двух дробей (рациональное число)
*/

LongRational SUB_QQ_Q(const LongRational& a, const LongRational& b);

#endif  // SUB_QQ_Q_HPP
