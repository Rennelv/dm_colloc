#include "Q/TRANS_Q_Z.hpp"

#include <stdexcept>

LongInteger TRANS_Q_Z(const LongRational &n) {
    LongInteger numerator = n.getNumerator();            // получаем числитель
    LongNatural denominator = n.getDenominator();        // получаем знаменатель
    std::vector<uint8_t> newArr = denominator.getArr();  // получаем массив цифр знаменателя
    if (newArr[0] == 0) {
        throw std::logic_error("Ошибка: знаменатель не может быть равен нулю");  // если знаменатель равен нулю, то выбрасываем ошибку
    }
    if (newArr[0] == 1 and denominator.getLength() == 1) {
        LongInteger numerator = n.getNumerator();  // получаем числитель
        return numerator;                          // возвращаем числитель
    } else {
        throw std::logic_error("Ошибка: знаменатель не равен единице");  // знаменатель не равен единице
    }
}