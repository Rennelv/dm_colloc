#include "Z/SUB_ZZ_Z.hpp"

#include "N/ADD_NN_N.hpp"  // сложение модулей чисел
#include "N/COM_NN_D.hpp"  // сравнение модулей
#include "N/SUB_NN_N.hpp"  // вычитание модулей чисел
#include "Z/ABS_Z_N.hpp"   // получение модуля числа
#include "Z/LongInteger.hpp"
#include "Z/POZ_Z_D.hpp"  // определение знака числа

LongInteger SUB_ZZ_Z(const LongInteger& a, const LongInteger& b) {
    int sign_a = POZ_Z_D(a);  // определяем знак числа a
    int sign_b = POZ_Z_D(b);  // определяем знак числа b

    LongNatural abs_a = ABS_Z_N(a);  // получаем модуль числа a
    LongNatural abs_b = ABS_Z_N(b);  // получаем модуль числа b

    // если знаки разные, складываем модули и сохраняем знак
    if (sign_a != sign_b) {
        if (sign_a == 0) return LongInteger(sign_b == 2, abs_b.getArr());  // возвращаем с учетом знака второго числа, если первое нуль

        LongNatural result = ADD_NN_N(abs_a, abs_b);
        return LongInteger(sign_a == 1, result.getArr());  // возвращаем с учетом знака
    }

    // если знаки одинаковые
    if (COM_NN_D(abs_a, abs_b) == 2) {
        LongNatural result = SUB_NN_N(abs_a, abs_b);
        return LongInteger(sign_a == 1, result.getArr());  // если abs_a > abs_b, вычитаем abs_b из abs_a, возвращая результат с сохранением знака

    } else if (COM_NN_D(abs_a, abs_b) == 1) {
        LongNatural result = SUB_NN_N(abs_b, abs_a);
        return LongInteger(sign_a == 2, result.getArr());  // если abs_a < abs_b, вычитаем abs_a из abs_b, возвращая результат со сменой знака

    } else {
        return LongInteger::ZERO;  // если abs_a == abs_b, возвращаем 0
    }
}
