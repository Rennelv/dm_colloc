#ifndef DIV_QQ_Q_HPP
#define DIV_QQ_Q_HPP

#include "Q/LongRational.hpp"

/*
    Выполинала Уфимцева Алиса 3381

    Функция DIV_QQ_Q принимает две дроби и делит первую на вторую.
    Принимает:
        a - первая дробь
        b - вторая дробь
    Возвращает:
        LongRational - результат деления дробей (дробь сокращенная)
*/

LongRational DIV_QQ_Q(const LongRational &a, const LongRational &b);

#endif  // DIV_QQ_Q_HPP