#include "Z/ABS_Z_N.hpp"

LongNatural ABS_Z_N(const LongInteger& a) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массив цифр числа a
    LongNatural result(a_arr);                // создаем натуральное число
    return result;                            //возвращаем абсолютное значение числа
}
