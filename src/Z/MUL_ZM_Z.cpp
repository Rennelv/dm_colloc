#include "Z/MUL_ZM_Z.hpp"

LongInteger MUL_ZM_Z(const LongInteger& a) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массив цифр числа a
    bool negative = a.isNegative();           // получаем знак числа a
    negative = !negative;                     // Инвертируем знак

    return LongInteger(negative, a_arr);  // Возвращаем новое число с инвертированным знаком
}