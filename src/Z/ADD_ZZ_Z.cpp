#include "Z/ADD_ZZ_Z.hpp"

#include "N/ADD_NN_N.hpp"  // для сложения модулей чисел
#include "N/COM_NN_D.hpp"  // для сравнения модулей
#include "N/SUB_NN_N.hpp"  // для вычитания модулей чисел
#include "Z/ABS_Z_N.hpp"   // для получения модуля числа
#include "Z/POZ_Z_D.hpp"   // для определения знака числа

LongInteger ADD_ZZ_Z(const LongInteger& a, const LongInteger& b) {
    // получаем знак чисел
    int sign_a = POZ_Z_D(a);
    int sign_b = POZ_Z_D(b);

    // получаем модули чисел
    LongNatural abs_a = ABS_Z_N(a);
    LongNatural abs_b = ABS_Z_N(b);

    // если знаки одинаковые, складываем модули и сохраняем знак
    if (sign_a == sign_b) {
        LongNatural result = ADD_NN_N(abs_a, abs_b);
        return LongInteger(sign_a == 1, result.getArr());  // возвращаем с учетом знака
    }

    // если знаки разные, вычитаем меньший модуль из большего и сохраняем знак большего
    if (COM_NN_D(abs_a, abs_b) == 2) {  // если abs_a > abs_b
        LongNatural result = SUB_NN_N(abs_a, abs_b);
        return LongInteger(sign_a == 1, result.getArr());
    } else {  // если abs_a <= abs_b
        LongNatural result = SUB_NN_N(abs_b, abs_a);
        return LongInteger(sign_b == 1, result.getArr());
    }
}
