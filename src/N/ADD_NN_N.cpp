#include "N/ADD_NN_N.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

LongNatural ADD_NN_N(const LongNatural& a, const LongNatural& b) {
    std::vector<uint8_t> aArr = a.getArr();  // получаем массивы цифр числа а
    std::vector<uint8_t> bArr = b.getArr();  // получаем массивы цифр числа b

    // если число а меньше числа b, то меняем их местами
    if (COM_NN_D(a, b) == 1) {
        aArr = b.getArr();
        bArr = a.getArr();
    }

    std::vector<uint8_t> resultArr;      // массив для результата
    resultArr.reserve(aArr.size() + 1);  // резервируем место для результата

    uint8_t carry = 0;  // перенос
    size_t aLen = aArr.size();
    size_t bLen = bArr.size();

    for (size_t i = 0; i < aLen; i++) {
        size_t aIdx = aLen - i - 1;        // индекс для числа а с конца
        uint8_t sum = aArr[aIdx] + carry;  // складываем цифру числа а и перенос

        if (i < bLen) {
            size_t bIdx = bLen - i - 1;  // индекс для числа b с конца
            sum += bArr[bIdx];           // если есть соответсвующая цифра числа b, то прибавляем ее
        }

        carry = sum / 10;               // вычисляем перенос
        resultArr.push_back(sum % 10);  // добавляем остаток от деления на 10 в результат
    }

    if (carry != 0) {
        resultArr.push_back(carry);  // если есть перенос, то добавляем его в результат
    }

    std::reverse(resultArr.begin(), resultArr.end());  // переворачиваем массив

    return LongNatural(resultArr);  // возвращаем результат
}