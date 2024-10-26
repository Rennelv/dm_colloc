#include "N/SUB_NN_N.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

LongNatural SUB_NN_N(const LongNatural& a, const LongNatural& b) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массивы цифр числа а
    std::vector<uint8_t> b_arr = b.getArr();  // получаем массивы цифр числа b

    // если число а меньше числа b, то меняем их местами
    if (COM_NN_D(a, b) == 1) {
        a_arr = b.getArr();
        b_arr = a.getArr();
    }

    std::vector<uint8_t> result_arr;       // массив для результата
    result_arr.reserve(a_arr.size() + 1);  // резервируем место для результата

    uint8_t carry = 0;  // перенос
    size_t a_len = a_arr.size();
    size_t b_len = b_arr.size();

    for (size_t i = a_len; i > 0; i--) {
        if (a_arr[i] - carry >= b_arr[i]) {
            result_arr.push_back(a_arr[i] - carry - b_arr[i]);
            carry = 0;
        } else {
            result_arr.push_back(a_arr[i] + 10 - carry - b_arr[i]);
            carry = 1;
        }
    }

    std::reverse(result_arr.begin(), result_arr.end());  // переворачиваем массив

    return LongNatural(result_arr);  // возвращаем результат
}