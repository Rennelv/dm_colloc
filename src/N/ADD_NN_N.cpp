#include "N/ADD_NN_N.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

LongNatural ADD_NN_N(const LongNatural& a, const LongNatural& b) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массивы цифр числа а
    std::vector<uint8_t> b_arr = b.getArr();  // получаем массивы цифр числа b

    // если число а меньше числа b, то меняем их местами
    if (COM_NN_D(a, b) == 1) {
        a_arr = b.getArr();
        b_arr = a.getArr();
    }

    a_arr.reserve(a_arr.size() + 1);  // резервируем место для результата

    uint8_t carry = 0;            // перенос
    size_t a_len = a_arr.size();  // длина числа a
    size_t b_len = b_arr.size();  // длина числа b

    for (size_t i = 0; i < a_len; i++) {
        size_t a_idx = a_len - i - 1;        // индекс для числа а с конца
        uint8_t sum = a_arr[a_idx] + carry;  // складываем цифру числа а и перенос

        if (i < b_len) {
            size_t b_idx = b_len - i - 1;  // индекс для числа b с конца
            sum += b_arr[b_idx];           // если есть соответсвующая цифра числа b, то прибавляем ее
        }

        carry = sum / 10;         // вычисляем перенос
        a_arr[a_idx] = sum % 10;  // добавляем остаток от деления на 10 в результат
    }

    if (carry != 0) {
        a_arr.insert(a_arr.begin(), carry);  // если есть перенос, то добавляем его в новый разряд
    }

    return LongNatural(a_arr);  // возвращаем результат
}