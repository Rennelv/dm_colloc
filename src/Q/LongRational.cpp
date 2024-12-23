#include "Q/LongRational.hpp"

#include <stdexcept>

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"

const LongRational LongRational::ZERO = LongRational({LongInteger(false, {0}), LongNatural({1})});
const LongRational LongRational::ONE = LongRational({LongInteger(false, {1}), LongNatural({1})});

LongRational::LongRational() : numerator(LongInteger(false, {0})), denominator(LongNatural({1})) {
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