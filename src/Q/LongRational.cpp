#include "Q/LongRational.hpp"

#include <stdexcept>

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"

const LongRational LongRational::ZERO = LongRational({LongInteger(false, {0}), LongNatural::ONE});
const LongRational LongRational::ONE = LongRational({LongInteger(false, {1}), LongNatural::ONE});

LongRational::LongRational() : numerator(LongInteger::ZERO), denominator(LongNatural::ONE) {
}

LongRational::LongRational(const LongInteger& numerator) : numerator(numerator), denominator(LongNatural::ONE) {
}

LongRational::LongRational(const LongInteger& numerator, const LongNatural& denominator) : numerator(numerator), denominator(denominator) {
    if (denominator.at(0) == 0) {
        throw std::invalid_argument("LongRational constructor: denominator is zero");
    }
}

const LongInteger& LongRational::getNumerator() const {
    return numerator;
}

const LongNatural& LongRational::getDenominator() const {
    return denominator;
}

std::string LongRational::toString() const {
    return numerator.toString() + "/" + denominator.toString();
}

bool LongRational::operator==(const LongRational& other) const {
    return this->denominator == other.denominator && this->numerator == other.numerator;  // если числители равны и знаменатели равны -> true, иначе false
}

bool LongRational::operator!=(const LongRational& other) const {
    return !(*this == other);  // Если числа не равны, то они не равны
}

LongRational LongRational::red() const {
    LongNatural gcd = numerator.getNaturalNumber().gcd(denominator);
    return LongRational({numerator.isNegative(), numerator.getNaturalNumber() / gcd}, denominator / gcd);
}

LongRational& LongRational::red_inplace() {
    LongNatural gcd = numerator.getNaturalNumber().gcd(denominator);
    numerator = LongInteger(numerator.isNegative(), numerator.getNaturalNumber() / gcd);
    denominator /= gcd;
    return *this;
}

bool LongRational::isInt() const {
    return denominator == LongNatural::ONE || numerator == LongInteger::ZERO;  // Если знаменатель равен 1, то число целое
}

LongInteger LongRational::toInt() const {
    if (!isInt()) {
        throw std::logic_error("LongRational::toInt: number is not integer");
    }
    return numerator;
}

LongRational LongRational::operator+(const LongRational& other) const {
    LongNatural lcm = denominator.lcm(other.denominator);  // Находим НОК знаменателей

    // Приводим числители к общему знаменателю
    LongNatural multiplier_a = lcm / denominator;
    LongNatural multiplier_b = lcm / other.denominator;

    LongInteger numerator_a = numerator * LongInteger(false, multiplier_a);
    LongInteger numerator_b = other.numerator * LongInteger(false, multiplier_b);

    LongInteger numerator_result = numerator_a + numerator_b;  // Складываем числители

    LongRational result(numerator_result, lcm);

    return result.red();
}

LongRational& LongRational::operator+=(const LongRational& other) {
    *this = *this + other;
    return *this;
}

LongRational LongRational::operator-(const LongRational& other) const {
    LongNatural lcm = denominator.lcm(other.denominator);  // Находим НОК знаменателей

    // Приводим числители к общему знаменателю
    LongNatural multiplier_a = lcm / denominator;
    LongNatural multiplier_b = lcm / other.denominator;

    LongInteger numerator_a = numerator * LongInteger(false, multiplier_a);
    LongInteger numerator_b = other.numerator * LongInteger(false, multiplier_b);

    LongInteger numerator_result = numerator_a - numerator_b;  // Вычитаем числители

    LongRational result(numerator_result, lcm);

    return result.red();
}

LongRational& LongRational::operator-=(const LongRational& other) {
    *this = *this - other;
    return *this;
}

LongRational LongRational::operator*(const LongRational& other) const {
    LongInteger numerator_result = numerator * other.numerator;        // Умножаем числители
    LongNatural denominator_result = denominator * other.denominator;  // Умножаем знаменатели

    LongRational result(numerator_result, denominator_result);

    return result.red();
}

LongRational& LongRational::operator*=(const LongRational& other) {
    *this = *this * other;
    return *this;
}

LongRational LongRational::operator/(const LongRational& other) const {
    LongInteger numerator_result =
        numerator * LongInteger(other.getNumerator().isNegative(), other.denominator);  // Умножаем числитель на знаменатель другого числа
    LongNatural denominator_result = denominator * other.numerator.getNaturalNumber();  // Умножаем знаменатель на числитель другого числа

    LongRational result(numerator_result, denominator_result);

    return result.red();
}

LongRational& LongRational::operator/=(const LongRational& other) {
    *this = *this / other;
    return *this;
}

LongRational::operator LongInteger() const {
    return toInt();
}
