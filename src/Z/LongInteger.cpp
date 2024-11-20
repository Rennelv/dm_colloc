#include "Z/LongInteger.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <vector>

#include "N/LongNatural.hpp"

const LongInteger LongInteger::ZERO = LongInteger(false, "0");
const LongInteger LongInteger::ONE = LongInteger(false, "1");

LongInteger::LongInteger() : negative(false), _natural_number(LongNatural::ZERO) {
}

LongInteger::LongInteger(bool negative, std::initializer_list<uint8_t> list) : negative(negative) {
    std::vector<uint8_t> vec(list);
    std::reverse(vec.begin(), vec.end());
    _natural_number = LongNatural(vec);
    if (_natural_number.isZero()) {
        this->negative = false;
    }
}

LongInteger::LongInteger(bool negative, const std::vector<uint8_t>& vec) : negative(negative), _natural_number(vec) {
}

LongInteger::LongInteger(bool negative, const std::string& string) : negative(negative), _natural_number(string) {
}

LongInteger::LongInteger(bool negative, const LongNatural& number) : negative(negative), _natural_number(number) {
    if (_natural_number.isZero()) {
        this->negative = false;
    }
}

LongInteger::LongInteger(const std::string& string) : LongInteger(string.at(0) == '-', string.at(0) == '-' ? string.substr(1) : string) {
}

const std::vector<uint8_t>& LongInteger::getArr() const {
    return _natural_number.getArr();
}

const LongNatural& LongInteger::getNaturalNumber() const {
    return _natural_number;
}

std::string LongInteger::toString() const {
    std::string result;
    result.reserve(_natural_number.getLength() + negative);
    if (negative) {
        result += '-';
    }

    result += _natural_number.toString();

    return result;
}

bool LongInteger::isNegative() const {
    return negative;
}

size_t LongInteger::getLength() const {
    return _natural_number.getLength();
}

uint8_t LongInteger::at(size_t i) const {
    return _natural_number.at(i);
}

uint8_t LongInteger::radix(size_t i) const {
    return _natural_number.radix(i);
}

bool LongInteger::operator==(const LongInteger& other) const {
    return negative == other.negative && this->_natural_number == other._natural_number;  // Если знаки и массивы равны, то числа равны
}

bool LongInteger::operator!=(const LongInteger& other) const {
    return !(*this == other);  // Если числа не равны, то они не равны
}

bool LongInteger::operator<(const LongInteger& other) const {
    if (negative != other.negative) {
        return negative;
    }
    if (negative) {
        return _natural_number > other._natural_number;
    }
    return _natural_number < other._natural_number;
}

bool LongInteger::operator>(const LongInteger& other) const {
    return other < *this;
}

bool LongInteger::operator<=(const LongInteger& other) const {
    return !(*this > other);
}

bool LongInteger::operator>=(const LongInteger& other) const {
    return !(*this < other);
}

LongInteger LongInteger::operator-() const {
    return LongInteger(!negative, _natural_number);
}

LongNatural LongInteger::abs() const {
    return _natural_number;
}

bool LongInteger::isZero() const {
    return _natural_number.isZero();
}

LongInteger::operator bool() const {
    return bool(_natural_number);
}

LongInteger LongInteger::operator+(const LongInteger& other) const {
    if (this->negative == other.negative) {
        LongNatural sum = this->_natural_number + other._natural_number;
        return LongInteger(this->negative, sum);
    } else {
        if (this->_natural_number >= other._natural_number) {
            LongNatural diff = this->_natural_number - other._natural_number;
            return LongInteger(this->negative, diff);
        } else {
            LongNatural diff = other._natural_number - this->_natural_number;
            return LongInteger(other.negative, diff);
        }
    }
}

LongInteger& LongInteger::operator+=(const LongInteger& other) {
    if (this->negative == other.negative) {
        this->_natural_number += other._natural_number;
    } else {
        if (this->_natural_number >= other._natural_number) {
            this->_natural_number -= other._natural_number;
        } else {
            this->_natural_number = other._natural_number - this->_natural_number;
            this->negative = !this->negative;
        }
    }
    if (this->_natural_number.isZero()) {
        this->negative = false;
    }
    return *this;
}

LongInteger LongInteger::operator-(const LongInteger& other) const {
    if (this->negative == other.negative) {
        if (this->_natural_number >= other._natural_number) {
            LongNatural diff = this->_natural_number - other._natural_number;
            return LongInteger(this->negative, diff);
        } else {
            LongNatural diff = other._natural_number - this->_natural_number;
            return LongInteger(!this->negative, diff);
        }
    } else {
        LongNatural sum = this->_natural_number + other._natural_number;
        return LongInteger(this->negative, sum);
    }
}

LongInteger& LongInteger::operator-=(const LongInteger& other) {
    if (this->negative == other.negative) {
        if (this->_natural_number >= other._natural_number) {
            this->_natural_number -= other._natural_number;
        } else {
            this->_natural_number = other._natural_number - this->_natural_number;
            this->negative = !this->negative;
        }
    } else {
        this->_natural_number += other._natural_number;
    }
    if (this->_natural_number.isZero()) {
        this->negative = false;
    }
    return *this;
}

LongInteger LongInteger::operator*(const LongInteger& other) const {
    return LongInteger(negative != other.negative, _natural_number * other._natural_number);
}

LongInteger& LongInteger::operator*=(const LongInteger& other) {
    this->negative = this->negative != other.negative;
    this->_natural_number *= other._natural_number;
    return *this;
}

LongInteger LongInteger::operator/(const LongInteger& other) const {
    int sign_dividend = this->isNegative();
    int sign_divisor = other.isNegative();

    // Получение абсолютных значений
    LongNatural abs_dividend = this->abs();
    LongNatural abs_divisor = other.abs();

    // Выполнение деления натуральных чисел
    LongNatural quotient = abs_dividend / abs_divisor;

    // Если знак делимого отрицательный и остаток от деления не равен нулю - прибавляется к натуральному частному 1
    if (sign_dividend && !(abs_dividend % abs_divisor).isZero()) {
        quotient++;
    }

    // Создаю целое число из знака и натурального (натуральное заранее преобразую в целое)
    LongInteger result(sign_dividend != sign_divisor, quotient);

    return result;
}

LongInteger& LongInteger::operator/=(const LongInteger& other) {
    int sign_dividend = this->isNegative();
    int sign_divisor = other.isNegative();

    // Получение абсолютных значений
    LongNatural abs_dividend = this->abs();
    LongNatural abs_divisor = other.abs();

    // Выполнение деления натуральных чисел
    LongNatural quotient = abs_dividend / abs_divisor;

    // Если знак делимого отрицательный и остаток от деления не равен нулю - прибавляется к натуральному частному 1
    if (sign_dividend && !(abs_dividend % abs_divisor).isZero()) {
        quotient++;
    }

    // Обновление текущего объекта
    this->negative = sign_dividend != sign_divisor;
    this->_natural_number = quotient;

    return *this;
}

LongInteger LongInteger::operator%(const LongInteger& other) const {
    LongInteger quotient = *this / other;     // находим частное от деления
    LongInteger product = other * quotient;   // вычисляем произведение divisor * quotient
    LongInteger remainder = *this - product;  // находим остаток: dividend - (divisor * quotient)
    return remainder;
}

LongInteger& LongInteger::operator%=(const LongInteger& other) {
    LongInteger quotient = *this / other;    // находим частное от деления
    LongInteger product = other * quotient;  // вычисляем произведение divisor * quotient
    *this -= product;                        // находим остаток: this - (divisor * quotient)
    return *this;
}

LongInteger::operator LongNatural() const {
    if (negative) {
        throw std::logic_error("Error: the number must not be negative");
    } else {
        return _natural_number;
    }
}