#include "P/Polynomial.hpp"

#include <stdexcept>

#include "Q/LongRational.hpp"

Polynomial::Polynomial(const std::map<LongNatural, LongRational>& map) : coefficients(map), degree(LongNatural("0")) {
    std::map<LongNatural, LongRational> temp_map = coefficients;
    for (const auto& [deg, coef] : temp_map) {
        if (coef.getNumerator() == LongInteger("0")) {
            coefficients.erase(deg);  // стираем нулевые степени
            continue;
        }
        if (COM_NN_D(degree, deg) == 1) {
            degree = deg;  // степень многочлена равна максимальной степени при не нулевых коэффицентах
        }
    }
}

Polynomial::Polynomial(const std::vector<LongRational>& vec) {
    coefficients = vec;
}

const std::vector<LongRational>& Polynomial::getArr() const {
    return coefficients;
}

bool Polynomial::isCoefZero(const LongNatural& degree) const {
    if (coefficients.find(degree) == coefficients.end()) {
        return true;  // если не найден - true
    }
    return false;
}

LongRational Polynomial::getCoef(const LongNatural& degree) const {
    if (coefficients.find(degree) == coefficients.end()) {
        return LongRational(LongInteger("0"), LongNatural("1"));  // если не найден вернуть 0/1
    }
    return result;
}

size_t Polynomial::getDegree() const {
    return coefficients.size() - 1;
}

std::string Polynomial::toString() const {
    std::string result = "";
    for (const auto& [deg, coef] : coefficients) {
        if (deg == LongNatural("0")) {
            result += coef.toString() + " + ";

        } else {
            result += "(" + coef.toString() + ")" + "x^" + deg.toString() + " + ";
        }
        // если строка получается больше 10000 символово обрезаем строку
        if (result.size() > 10000) return result.substr(0, result.size() - 3) + "...";
    }
    return coefficients[i];
}

LongRational Polynomial::getCoef(size_t deg) const {
    if (deg >= coefficients.size()) {
        return LongRational(LongInteger{"0"}, LongNatural{"1"});
    }
    return coefficients[coefficients.size() - deg - 1];
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients && degree == other.degree;  // если равны коэффиценты и степени
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);  // обраное к равентсву
}
