#include "N/MUL_NN_N.hpp"

#include "N/ADD_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "N/MUL_ND_N.hpp"
#include "N/MUL_Nk_N.hpp"

LongNatural MUL_NN_N(const LongNatural& a, const LongNatural& b) {
    const std::vector<uint8_t>& b_arr = b.getArr();  // массив цифр числа b

    LongNatural result({0});  // результат умножения
    LongNatural tmp({0});     // буферная переменная

    size_t b_len = b_arr.size();  // длина числа b

    for (size_t i = 0; i < b_len; i++) {
        size_t idx = b_len - i - 1;  // индексирование числа с начального разряда
        tmp = MUL_ND_N(a, b_arr[idx]);
        tmp = MUL_Nk_N(tmp, i);
        result = ADD_NN_N(tmp, result);
        /*  сначала умножаем число a на цифру из массива b (MUL_ND_N)
            потом домножаем число b на 10^idx (MUL_Nk_N), где idx разряд цифры числа b
            в конце суммируем все произведения (ADD_NN_N)
        */
    }

    return result;
}