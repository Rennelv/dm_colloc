#include "Z/TRANS_Z_N.hpp"

#include <stdexcept>

LongNatural TRANS_Z_N(const LongInteger &n) {
    std::vector<uint8_t> newArr = n.getArr();  // получаем массив цифр целого числа n
    if (newArr[0] == 0) {
        throw std::logic_error("Ошибка: число должно быть положительным");  // если n = 0, выбрасываем ошибку
    } else {
        LongNatural result(newArr);  // создаем натуральное число
        return result;               // возвращаем результат
    }
}