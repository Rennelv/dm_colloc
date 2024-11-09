#include "N/SUB_NN_N.hpp"

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

    uint8_t carry = 0;            // перенос
    size_t a_len = a_arr.size();  // длина числа a
    size_t b_len = b_arr.size();  // длина числа b

    for (size_t i = 0; i < b_len; i++) {
        size_t a_idx = a_len - 1 - i;  // индес числа a
        size_t b_idx = b_len - 1 - i;  // индекс числа b
        if (a_arr[a_idx] >= b_arr[b_idx] + carry) {
            a_arr[a_idx] = a_arr[a_idx] - carry - b_arr[b_idx];  // из выбранной цифры вычитаем цифру второго числа и перенс
            carry = 0;                                           // не занимаем из следующей цифры
        } else {
            a_arr[a_idx] = a_arr[a_idx] + 10 - carry - b_arr[b_idx];  // занимаем у следующей цифры и вычитаем из выбранной цифру второго числа
            carry = 1;
        }
    }

    size_t a_idx = a_len - 1 - b_len;
    while (carry) {                   // забирает 1 из следующих разрядов, пока дойдёт до цифры большей 0
        if (a_arr[a_idx] >= carry) {  // если цифра больше 0
            a_arr[a_idx] = a_arr[a_idx] - carry;
            carry = 0;
        } else {  // если цифра 0
            a_arr[a_idx] = a_arr[a_idx] + 10 - carry;
            a_idx--;
        }
    }

    while (a_arr.size() > 1 && a_arr.front() == 0) {  // убираем незначащие нули
        a_arr.erase(a_arr.begin());
    }

    return LongNatural(a_arr);  // возвращаем результат
}