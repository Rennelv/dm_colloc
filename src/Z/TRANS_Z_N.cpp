#include "Z/TRANS_Z_N.hpp"

#include <stdexcept>

LongNatural TRANS_Z_N(const LongInteger &n) {
    std::vector<uint8_t> new_arr = n.getArr();  // получаем массив цифр целого числа n
    if (n.isNegative()) {
        throw std::logic_error("Error: the number must not be negative");  // если n < 0, выбрасываем ошибку
    } else {
        LongNatural result(new_arr);  // создаем натуральное число
        return result;                // возвращаем результат
    }
}