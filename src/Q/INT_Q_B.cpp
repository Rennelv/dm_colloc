#include "Q/INT_Q_B.hpp"

#include <stdexcept>

int INT_Q_B(const LongRational &n) {
    LongInteger numerator = n.getNumerator();            // получаем числитель
    LongNatural denominator = n.getDenominator();        // получаем знаменатель
    std::vector<uint8_t> newArr = denominator.getArr();  // получаем массив цифр знаменателя
    if (newArr[0] == 0) {
        throw std::logic_error("Ошибка: знаменатель не может быть равен нулю");  // если знаменатель равен нулю, то выбрасываем ошибку
    }
    if (newArr[0] == 1 and denominator.getLength() == 1) {
        return 1;  // если знаменатель равен единице, то число целое
    } else {
        return 0;  // если знаменатель не равен единице, то число нецелое
    }
}