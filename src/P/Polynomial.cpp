#include "P/Polynomial.hpp"

#include <string>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial::Polynomial(const std::map<LongNatural, LongRational>& map) : coefficients(map), degree({0}), zero(LongInteger(false, {0}), LongNatural({1})) {
    std::map<LongNatural, LongRational> temp_map = coefficients;
    for (const auto& [deg, coef] : temp_map) {
        if (coef.getNumerator() == zero.getNumerator()) {
            coefficients.erase(deg);  // стираем нулевые степени
        }
    }
    if (!coefficients.empty()) {
        degree = coefficients.rbegin()->first;  // если не пустой, то степень равна последней степени, иначе 0
    }
}

const std::map<LongNatural, LongRational>& Polynomial::getMap() const {
    return coefficients;
}

std::map<LongNatural, LongRational>& Polynomial::getMapRW() {
    return coefficients;
}

bool Polynomial::isCoef(const LongNatural& degree) const {
    return coefficients.find(degree) != coefficients.end();  // если найден - true
}

const LongRational& Polynomial::getCoef(const LongNatural& degree) const {
    if (coefficients.find(degree) == coefficients.end()) {
        return zero;  // если не найден вернуть 0/1
    }
    return coefficients.at(degree);
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
        if (deg == LongNatural("0")) {
            result += coef.toString() + " + ";

        } else {
            result += "(" + coef.toString() + ")" + "x^" + deg.toString() + " + ";
        }
        // если строка получается больше 10000 символово обрезаем строку
        if (result.size() > 10000) {
            return result.substr(0, result.size() - 3) + "..." + "и еще " + std::to_string(coefficients.size() - std::distance(coefficients.rbegin(), it)) +
                   " ненулевых членов";
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
