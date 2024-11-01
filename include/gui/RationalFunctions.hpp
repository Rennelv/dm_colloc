#ifndef RATIONALFUNCTIONS_HPP
#define RATIONALFUNCTIONS_HPP

enum class RationalFunctions {
    RED_Q_Q,  // Сокращение дроби
    INT_Q_B,  // Проверка сокращенного дробного на целое, если рациональное число является целым, то «да», иначе «нет»
    TRANS_Z_Q,  // Преобразование целого в дробное
    TRANS_Q_Z,  // Преобразование сокращенного дробного в целое (если знаменатель равен 1)
    ADD_QQ_Q,   // Сложение дробей
    SUB_QQ_Q,   // Вычитание дробей
    MUL_QQ_Q,   // Умножение дробей
    DIV_QQ_Q,   // Деление дробей (делитель отличен от нуля)
};

#endif  // RATIONALFUNCTIONS_HPP