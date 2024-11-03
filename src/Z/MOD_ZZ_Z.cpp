#include "Z/MOD_ZZ_Z.hpp"

#include "Z/DIV_ZZ_Z.hpp"  // частное от деления целого на целое
#include "Z/MUL_ZM_Z.hpp"  // умножение целого числа на (-1)
#include "Z/MUL_ZZ_Z.hpp"  // умножение целых чисел
#include "Z/SUB_ZZ_Z.hpp"  // вычитание целых чисел

LongInteger MOD_ZZ_Z(const LongInteger& a, const LongInteger& b) {
    LongInteger quotient = DIV_ZZ_Z(a, b);         // находим частное от деления
    LongInteger product = MUL_ZZ_Z(b, quotient);   // вычисляем произведение b * quotient
    LongInteger remainder = SUB_ZZ_Z(a, product);  // находим остаток: a - (b * quotient)

    // проверяем знак остатка
    if (remainder.isNegative()) {
        remainder = MUL_ZM_Z(remainder);  // если остаток отрицательный, делаем его положительным
    }

    return remainder;
}