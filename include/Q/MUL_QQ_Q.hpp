#ifndef MUL_QQ_Q_HPP
#define MUL_QQ_Q_HPP

#include "Q/LongRational.hpp"

/*
    Выполинала Уфимцева Алиса 3381

    Функция MUL_QQ_Q принимает две дроби и перемножает их.
    Принимает:
        a - первая дробь
        b - вторая дробь
    Возвращает:
        LongRational - произведение дробей (дробь сокращенная)
*/

LongRational MUL_QQ_Q(const LongRational &a, const LongRational &b);

#endif  // MUL_QQ_Q_HPP