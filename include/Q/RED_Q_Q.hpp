#ifndef RED_Q_Q_HPP
#define RED_Q_Q_HPP

#include "Q/LongRational.hpp"

/*
    Выполинала Уфимцева Алиса 3381

    Функция RED_Q_Q принимает дробь и сокращает её.
    Принимает:
        a - дробь
    Возвращает:
        LongRational - сокращенная дробь с числителем p, знаменателем q
*/

LongRational RED_Q_Q(const LongRational &a);

#endif  // RED_Q_Q_HPP