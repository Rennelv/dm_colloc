#include "P/Polynomial.hpp"

#include "Q/LongRational.hpp"

Polynomial::Polynomial(std::initializer_list<LongRational> list) {
    coefficients = list;
}

Polynomial::Polynomial(size_t n, LongRational* arr) {
    coefficients.reserve(n);
    for (size_t i = 0; i < n; i++) {
        coefficients.push_back(arr[i]);
    }
}

Polynomial::Polynomial(const std::vector<LongRational>& vec) {
    coefficients = vec;
}

const std::vector<LongRational>& Polynomial::getArr() const {
    return coefficients;
}

std::string Polynomial::toString() const {
    std::string result;
    for (size_t i = 0; i < coefficients.size(); i++) {
        if (coefficients[i].getNumerator().toString() == "0") {  // ЪЪЪ *заменить на NZER_N_B*
            continue;
        }
        result += "(" + coefficients[i].toString() + ")";  // ЪЪЪ
        if (i != this->getDegree()) {
            result += "x^" + std::to_string(this->getDegree() - i) + " + ";
        }
    }
    return result;
}

size_t Polynomial::getDegree() const {
    return coefficients.size() - 1;
}

bool Polynomial::operator==(const Polynomial& other) const {
    return this->coefficients == other.coefficients;
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

LongRational Polynomial::at(size_t i) const {
    return coefficients[i];
}

LongRational Polynomial::getCoef(size_t deg) const {
    if (deg >= coefficients.size()) {
        return LongRational(LongInteger{"0"}, LongNatural{"1"});
    }
    return coefficients[coefficients.size() - deg - 1];
}