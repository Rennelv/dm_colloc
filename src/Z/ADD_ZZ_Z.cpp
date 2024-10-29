#include "Z/ADD_ZZ_Z.hpp"

#include "N/ADD_NN_N.hpp"  // для сложения модулей чисел
#include "N/COM_NN_D.hpp"  // для сравнения модулей
#include "N/SUB_NN_N.hpp"  // для вычитания модулей чисел
#include "Z/ABS_Z_N.hpp"   // для получения модуля числа
#include "Z/POZ_Z_D.hpp"   // для определения знака числа

LongInteger ADD_ZZ_Z(const LongInteger& a, const LongInteger& b) {
    // получаем знак чисел
    int signA = POZ_Z_D(a);
    int signB = POZ_Z_D(b);

    // получаем модули чисел
    LongNatural absA = ABS_Z_N(a);
    LongNatural absB = ABS_Z_N(b);

    // если знаки одинаковые, складываем модули и сохраняем знак
    if (signA == signB) {
        LongNatural result = ADD_NN_N(absA, absB);
        return LongInteger(signA == 1, result.getArr());  // возвращаем с учетом знака
    }

    // если знаки разные, вычитаем меньший модуль из большего и сохраняем знак большего
    if (COM_NN_D(absA, absB) == 2) {  // если absA > absB
        LongNatural result = SUB_NN_N(absA, absB);
        return LongInteger(signA == 1, result.getArr());
    } else {  // если absA <= absB
        LongNatural result = SUB_NN_N(absB, absA);
        return LongInteger(signB == 1, result.getArr());
    }
}
