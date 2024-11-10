#include "N/MUL_ND_N.hpp"

#include <cstddef>

#include "N/LongNatural.hpp"

LongNatural MUL_ND_N(const LongNatural& a, uint8_t b) {
    std::vector<uint8_t> a_arr = a.getArr();  // получаем массивы цифр числа а

    a_arr.reserve(a_arr.size() + 1);  // резервируем место, если увеличится разряд числа
    uint8_t carry = 0;                // перенос
    size_t a_len = a_arr.size();      // длина числа a

    for (size_t i = 0; i < a_len; i++) {
        size_t idx = a_len - 1 - i;            // индекс цифры в числе a
        uint8_t mul = a_arr[idx] * b + carry;  // умножаем цифру числа a ицифру b, затем добавляем перенос

        carry = mul / 10;       // вычисляем перенос
        a_arr[idx] = mul % 10;  // добавляем остаток от деления на 10 в результат
    }

    if (carry != 0) {
        a_arr.insert(a_arr.begin(), carry);  // если есть перенос, то добавляем его в результат
    }

    while (a_arr.size() > 1 && a_arr.front() == 0) {  // убираем незначащие нули
        a_arr.erase(a_arr.begin());
    }

    return LongNatural(a_arr);  // возвращаем результат
}