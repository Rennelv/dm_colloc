#include "Q/INT_Q_B.hpp"

#include <stdexcept>

bool INT_Q_B(const LongRational &n) {
    LongNatural denominator = n.getDenominator();  // получаем знаменатель
    uint8_t firstNumber = denominator.at(0);       // получаем первую цифру в записи знаменателя
    if (firstNumber == 0) {
        throw std::logic_error("Error: denominator cannot be zero");  // если знаменатель равен нулю, то выбрасываем ошибку
    }
    if (firstNumber == 1 and denominator.getLength() == 1) {
        return true;  // если знаменатель равен единице, то число целое
    } else {
        return false;  // если знаменатель не равен единице, то число нецелое
    }
}