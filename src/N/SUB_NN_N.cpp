#include "N/SUB_NN_N.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>
#include <stdexcept>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

LongNatural SUB_NN_N(const LongNatural& a, const LongNatural& b) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массивы цифр числа а
    std::vector<uint8_t> b_arr = b.getArr();  // получаем массивы цифр числа b

    // если число а меньше числа b, то возврашаем ошибку
    if (COM_NN_D(a, b) == 1) {
        throw std::logic_error("The first number is lower than the second");
    }

    std::vector<uint8_t> result_arr;   // массив для результата
    result_arr.reserve(a_arr.size());  // резервируем место для результата

    uint8_t carry = 0;         // перенос
    int a_len = a_arr.size();  // длина числа a
    int b_len = b_arr.size();  // длина числа b

    for (int i = b_len - 1; i >= 0; i--) {
        if (a_arr[i] - carry >= b_arr[i]) {
            result_arr.push_back(a_arr[i] - carry - b_arr[i]);  // из выбранной цифры вычитаем цифру второго числа и перенс
            carry = 0;                                          // не занимаем из следующей цифры
        } else {
            result_arr.push_back(a_arr[i] + 10 - carry - b_arr[i]);  // занимаем у следующей цифры и вычитаем из выбранной цифру второго числа
            carry = 1;
        }
    }

    for (int i = a_len - 1; i >= b_len; i--) {  // добавляем оставшиеся цифры чила a и продолжаем занимать, пока число не будет больше 0
        if (a_arr[i] >= carry) {
            result_arr.push_back(a_arr[i] - carry);
            carry = 0;
        } else {
            result_arr.push_back(a_arr[i] + 10 - carry);
            carry = 1;
        }
    }

    while (result_arr.size() > 1 && result_arr.back() == 0) {  // убираем незначащие нули
        result_arr.pop_back();
    }

    std::reverse(result_arr.begin(), result_arr.end());  // переворачиваем массив

    return LongNatural(result_arr);  // возвращаем результат
}