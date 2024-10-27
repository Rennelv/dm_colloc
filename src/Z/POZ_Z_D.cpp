#include "Z/POZ_Z_D.hpp"

int POZ_Z_D(const LongInteger& a) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массив цифр числа a
    bool negative = a.isNegative();           // получаем знак числа a
    if (a_arr[0] == 0) {
        return 0;  // если в числе первый нуль, тогда это нуль
    }
    if (negative) {
        return 1;  // если отрицательное
    }
    return 2;  // если положительное
}
