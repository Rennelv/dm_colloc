#include "N/ADD_1N_N.hpp"

#include <vector>

LongNatural ADD_1N_N(const LongNatural& a) {
    std::vector<uint8_t> a_arr = a.getArr();    // получаем массив цифр числа a
    std::vector<uint8_t> result_arr;
    result_arr.reserve(a_arr.size() + 1);       // резервируем место для возможного нового разряда

    uint8_t carry = 1;                          // начальный перенос = 1

    // Проходим по цифрам числа, начиная с младшего разряда
    for (size_t i = 0; i < a_arr.size(); i++) {
        uint8_t sum = a_arr[i] + carry;       // добавляем перенос к текущей цифре
        carry = sum / 10;                     // вычисляем перенос для следующего разряда
        result_arr.push_back(sum % 10);       // сохраняем текущую цифру
    }

    // Если остался перенос, добавляем новый разряд
    if (carry != 0) {
        result_arr.push_back(carry);
    }

    return LongNatural(result_arr);
}
