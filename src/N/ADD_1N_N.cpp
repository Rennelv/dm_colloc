#include "N/ADD_1N_N.hpp"

#include <vector>

LongNatural ADD_1N_N(const LongNatural& a) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массив цифр числа a
    uint8_t carry = 1;                        // начальный перенос = 1

    // Проходим по цифрам числа, начиная с младшего разряда
    for (int i = a_arr.size() - 1; i >= 0; i--) {
        uint8_t sum = a_arr[i] + carry;  // добавляем перенос к текущей цифре
        carry = sum / 10;                // вычисляем перенос для следующего разряда
        a_arr[i] = sum % 10;             // сохраняем текущую цифру

        // Если перенос стал 0, можем завершить цикл
        if (carry == 0) {
            break;
        }
    }

    // Если остался перенос, добавляем новый разряд
    if (carry != 0) {
        a_arr.insert(a_arr.begin(), carry);
    }

    return LongNatural(a_arr);
}
