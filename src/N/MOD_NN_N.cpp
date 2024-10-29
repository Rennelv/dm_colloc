#include "N/MOD_NN_N.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/MUL_NN_N.hpp"
#include "N/NZER_N_B.hpp"
#include "N/SUB_NN_N.hpp"

LongNatural MOD_NN_N(LongNatural& a, LongNatural& b) {
    if (!NZER_N_B(b)) {
        throw std::logic_error("Divider is zero");
    }
    // халтурный момент, исправиттся сразу после фикса деления нацело
    LongNatural a_copy = a;
    LongNatural integerPart = DIV_NN_N(a_copy, b);  // Получаем целую часть от деления
    LongNatural tmp = MUL_NN_N(b, integerPart);     // Умножаем целую часть от деления на делитель
    LongNatural result = SUB_NN_N(a, tmp);  // Получаем остаток путём вычитания из делимого значения из прошлой строки

    return result;
}