#include "P/Polynomial.hpp"

Polynomial::Polynomial(const std::vector<LongInteger>& vec) {
    coefficients = vec;
}

std::vector<LongInteger> Polynomial::getArr() const {
    return coefficients;
}

std::string Polynomial::toString() const {
    std::string result;
    for (size_t i = 0; i < coefficients.size(); i++) {
        if (coefficients[i].toString() == "0") {  // ЪЪЪ *заменить на NZER_N_B*
            continue;
        }
        result += coefficients[i].toString();  // ЪЪЪ
        if (i != this->degree()) {
            result += "x^" + std::to_string(this->degree() - i) + " + ";
        }
    }
    return result;
}

size_t Polynomial::getLength() const {
    return coefficients.size();
}

size_t Polynomial::degree() const {
    return coefficients.size() - 1;
}