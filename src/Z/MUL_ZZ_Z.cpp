#include "Z/MUL_ZZ_Z.hpp"

#include <iostream>
#include <vector>

#include "N/LongNatural.hpp"
#include "N/MUL_NN_N.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/LongInteger.hpp"
#include "Z/MUL_ZM_Z.hpp"
#include "Z/POZ_Z_D.hpp"

using namespace std;

LongInteger MUL_ZZ_Z(const LongInteger &a, const LongInteger &b) {
    if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) {  // проверяем, есть ли среди чисел ноль
        LongInteger c(false, {0});             // создаем целое нулевое число, если одно из чисел ноль
        return c;                              // возвращаем ноль
    }
    bool flag = false;     // флаг для определения знака числа произведения
    if (a.isNegative()) {  // узнаем знак числа a
        flag = !flag;      // увеличием значение flag'а если число отрицательное
    }
    if (b.isNegative()) {  // узнаем знак числа b
        flag = !flag;      // увеличием значение flag'а если число отрицательное
    }
    LongNatural a1 = ABS_Z_N(a);        // находим модуль числа a
    LongNatural b1 = ABS_Z_N(b);        // находим модуль числа b
    LongNatural c1 = MUL_NN_N(a1, b1);  // находим произведение модулей
    LongInteger c(flag, c1.getArr());   // создаем целое число, учитывая знаки переданных чисел
    return c;                           // возвращаем произведение чисел
}