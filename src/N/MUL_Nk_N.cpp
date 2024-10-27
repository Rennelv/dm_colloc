#include "N/MUL_Nk_N.hpp"

LongNatural MUL_Nk_N(const LongNatural& a, size_t k) {
    // проверяем, является ли число нулем
    if (a.getLength() == 1 && a.at(0) == 0) {
        return LongNatural({0});
    }

    std::vector<uint8_t> a_arr = a.getArr();  // получаем массив цифр числа
    a_arr.insert(a_arr.end(), k, 0);  // добавляем k нулей в конец массива цифр числа, то есть умножаем на 10^k

    return LongNatural(a_arr);
}
