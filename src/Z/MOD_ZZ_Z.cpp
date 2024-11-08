#include "Z/MOD_ZZ_Z.hpp"

#include "Z/DIV_ZZ_Z.hpp"  // частное от деления целого на целое
#include "Z/MUL_ZZ_Z.hpp"  // умножение целых чисел
#include "Z/SUB_ZZ_Z.hpp"  // вычитание целых чисел

LongInteger MOD_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor) {
    LongInteger quotient = DIV_ZZ_Z(dividend, divisor);   // находим частное от деления
    LongInteger product = MUL_ZZ_Z(divisor, quotient);    // вычисляем произведение divisor * quotient
    LongInteger remainder = SUB_ZZ_Z(dividend, product);  // находим остаток: dividend - (divisor * quotient)
    return remainder;
}