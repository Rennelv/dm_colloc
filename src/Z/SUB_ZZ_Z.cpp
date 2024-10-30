#include "Z/SUB_ZZ_Z.hpp"

#include "N/ADD_NN_N.hpp"  // сложение модулей чисел
#include "N/COM_NN_D.hpp"  // сравнение модулей
#include "N/SUB_NN_N.hpp"  // вычитание модулей чисел
#include "Z/ABS_Z_N.hpp"   // получение модуля числа
#include "Z/POZ_Z_D.hpp"   // определение знака числа

LongInteger SUB_ZZ_Z(const LongInteger& a, const LongInteger& b) {
    int signA = POZ_Z_D(a);  // определяем знак числа a
    int signB = POZ_Z_D(b);  // определяем знак числа b

    LongNatural absA = ABS_Z_N(a);  // получаем модуль числа a
    LongNatural absB = ABS_Z_N(b);  // получаем модуль числа b

    // если знаки одинаковые
    if (signA == signB) {
        if (COM_NN_D(absA, absB) == 2) {
            LongNatural result = SUB_NN_N(absA, absB);
            return LongInteger(signA == 1, result.getArr());  // если absA > absB, вычитаем absB из absA, возвращая результат с сохранением знака
        } else if (COM_NN_D(absA, absB) == 1) {
            LongNatural result = SUB_NN_N(absB, absA);
            return LongInteger(signA == 2, result.getArr());  // если absA < absB, вычитаем absA из absB, возвращая результат со сменой знака
        } else {
            return LongInteger(false, {0});  // если absA == absB, возвращаем 0
        }
    }

    // если знаки разные, складываем модули и сохраняем знак
    LongNatural result = ADD_NN_N(absA, absB);
    return LongInteger(signA == 1, result.getArr());  // возвращаем с учетом знака
}