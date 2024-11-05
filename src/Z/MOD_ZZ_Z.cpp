#include "Z/MOD_ZZ_Z.hpp"

#include "Z/DIV_ZZ_Z.hpp"  // частное от деления целого на целое
#include "Z/MUL_ZM_Z.hpp"  // умножение целого числа на (-1)
#include "Z/MUL_ZZ_Z.hpp"  // умножение целых чисел
#include "Z/SUB_ZZ_Z.hpp"  // вычитание целых чисел

LongInteger MOD_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor) {
    LongInteger quotient = DIV_ZZ_Z(dividend, divisor);   // находим частное от деления
    LongInteger product = MUL_ZZ_Z(divisor, quotient);    // вычисляем произведение divisor * quotient
    LongInteger remainder = SUB_ZZ_Z(dividend, product);  // находим остаток: dividend - (divisor * quotient)

    // проверяем знак остатка
    if (remainder.isNegative()) {
        // проверяем знак делителя
        if (divisor.isNegative()) {
            remainder = SUB_ZZ_Z(remainder, divisor);  // если делитель отрицательный, вычитаем из остатка делитель
        } else {
            remainder = SUB_ZZ_Z(remainder, MUL_ZM_Z(divisor));  // если делитель положительный, вычитаем из остатка делитель, умноженный на (-1)
        }
    }

    return remainder;
}