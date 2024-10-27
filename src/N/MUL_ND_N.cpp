#include "N/MUL_ND_N.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>

#include "N/LongNatural.hpp"

LongNatural MUL_ND_N(const LongNatural& a, const uint8_t& b) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массивы цифр числа а

    std::vector<uint8_t> result_arr;       // массив для результата
    result_arr.reserve(a_arr.size() + 1);  // резервируем место для результата

    uint8_t carry = 0;            // перенос
    size_t a_len = a_arr.size();  // длина числа a

    for (int i = a_len - 1; i >= 0; i--) {
        uint8_t mul = a_arr[i] * b + carry;  // умножаем цифры чисел и добавляем перенос

        carry = mul / 10;                // вычисляем перенос
        result_arr.push_back(mul % 10);  // добавляем остаток от деления на 10 в результат
    }

    if (carry != 0) {
        result_arr.push_back(carry);  // если есть перенос, то добавляем его в результат
    }

    while (result_arr.size() > 1 && result_arr.back() == 0) {  // убираем незначащие нули
        result_arr.pop_back();
    }

    std::reverse(result_arr.begin(), result_arr.end());  // переворачиваем массив

    return LongNatural(result_arr);  // возвращаем результат
}