#include "Q/TRANS_Q_Z.hpp"

#include <stdexcept>

LongInteger TRANS_Q_Z(const LongRational &n) {
    LongNatural denominator = n.getDenominator();         // получаем знаменатель
    std::vector<uint8_t> new_arr = denominator.getArr();  // получаем массив цифр знаменателя
    if (new_arr[0] == 0) {
        throw std::logic_error("Error: denominator cannot be zero");  // если знаменатель равен нулю, то выбрасываем ошибку
    }
    if (new_arr[0] == 1 and denominator.getLength() == 1) {
        LongInteger numerator = n.getNumerator();  // получаем числитель
        return numerator;                          // возвращаем числитель
    } else {
        throw std::logic_error("Error: denominator is not equal to one");  // знаменатель не равен единице
    }
}