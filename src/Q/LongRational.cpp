#include "Q/LongRational.hpp"

#include <stdexcept>

LongRational::LongRational(const LongInteger& numerator, const LongNatural& denominator) : numerator(numerator), denominator(denominator) {
    if (denominator.getLength() <= 1 && denominator.getArr()[0] == 0) {
        throw std::invalid_argument("LongRational::LongRational: denominator is zero");
    }
}

LongInteger LongRational::getNumerator() const {
    return numerator;
}

LongNatural LongRational::getDenominator() const {
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