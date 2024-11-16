#include "P/Polynomial.hpp"

#include <string>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial::Polynomial(const std::map<LongNatural, LongRational>& map) : coefficients(map), degree({0}) {
    std::map<LongNatural, LongRational> temp_map = coefficients;
    for (const auto& [deg, coef] : temp_map) {
        if (coef.getNumerator() == LongInteger::ZERO) {
            coefficients.erase(deg);  // стираем нулевые степени
        }
    }
    if (!coefficients.empty()) {
        degree = coefficients.rbegin()->first;  // если не пустой, то степень равна последнему элементу, иначе 0
    }
}

const std::map<LongNatural, LongRational>& Polynomial::getMap() const {
    return coefficients;
}

bool Polynomial::isCoef(const LongNatural& degree) const {
    for (const auto& [deg, coef] : coefficients) {
        if (deg == degree) {
            return true;  // если найден - true
        }
    }
    return false;  // если не найден - false
}

const LongRational& Polynomial::getCoef(const LongNatural& degree) const {
    if (!isCoef(degree)) {
        return LongRational::ZERO;  // если не найден - возвращаем 0
    }
    return coefficients.at(degree);  // если найден - возвращаем
}

const LongNatural& Polynomial::getDegree() const {
    return degree;
}

std::string Polynomial::toString() const {
    if (coefficients.empty()) {
        return "0";
    }
    std::string result = "";
    // добавляем в строку коэффиценты с наибольшей степени
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
        auto [deg, coef] = *it;
        if (deg == LongNatural::ZERO) {
            result += coef.toString() + " + ";

        } else {
            result += "(" + coef.toString() + ")" + "x^" + deg.toString() + " + ";
        }
    }
    return result.substr(0, result.size() - 3);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients && degree == other.degree;  // если равны коэффиценты и степени
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);  // обраное к равентсву
}
