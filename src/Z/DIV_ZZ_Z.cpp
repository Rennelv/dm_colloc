#include "Z/DIV_ZZ_Z.hpp"

#include "N/ADD_1N_N.hpp"
#include "N/DIV_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "N/MOD_NN_N.hpp"
#include "N/NZER_N_B.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/POZ_Z_D.hpp"

LongInteger DIV_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor) {
    int sign_dividend = POZ_Z_D(dividend);  // Знак делимого
    int sign_divisor = POZ_Z_D(divisor);    // Знак делителя

    // Получение абсолютных значений
    LongNatural abs_dividend = ABS_Z_N(dividend);
    LongNatural abs_divisor = ABS_Z_N(divisor);

    // Выполнение деления натуральных чисел
    LongNatural quotient = DIV_NN_N(abs_dividend, abs_divisor);

    // Если знак делимого положительный и остаток от деления не равен нулю - прибавляется к натуральному частному 1
    if (sign_dividend == 1 && NZER_N_B(MOD_NN_N(abs_dividend, abs_divisor))) {
        quotient = ADD_1N_N(quotient);  // Прибавление 1 к натуральному числу
    }

    // Создаю целое число из знака и натурального (натуральное заранее преобразую в целое)
    LongInteger result(sign_dividend != sign_divisor, quotient.getArr());

    return result;
}
