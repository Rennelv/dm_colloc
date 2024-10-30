#include "Z/DIV_ZZ_Z.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/MUL_ZM_Z.hpp"
#include "Z/POZ_Z_D.hpp"
#include "Z/TRANS_N_Z.hpp"

LongInteger DIV_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor) {
    int sign_dividend = POZ_Z_D(dividend);  // Знак делимого
    int sign_divisor = POZ_Z_D(divisor);    // Знак делителя

    // Получение абсолютных значений
    LongNatural abs_dividend = ABS_Z_N(dividend);
    LongNatural abs_divisor = ABS_Z_N(divisor);

    // Выполнение деления натуральных чисел
    LongNatural quotient = DIV_NN_N(abs_dividend, abs_divisor);

    // Преобразование результата в целое число
    LongInteger result = TRANS_N_Z(quotient);

    // Если знаки разные, делаем результат отрицательным
    if (sign_dividend != sign_divisor) {
        result = MUL_ZM_Z(result);
    }

    return result;
}
