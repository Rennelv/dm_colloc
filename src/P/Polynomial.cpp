#include "P/Polynomial.hpp"

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial::Polynomial(const std::map<LongNatural, LongRational>& map) : coefficients(map), degree({0}), zero(LongInteger(false, {0}), LongNatural({1})) {
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

const std::map<LongNatural, LongRational>& Polynomial::getMap() const {
    return coefficients;
}

bool Polynomial::isCoefZero(const LongNatural& degree) const {
    if (coefficients.find(degree) == coefficients.end()) {
        return true;  // если не найден - true
    }
    return false;
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
    if (result.empty()) {
        return "0";
    }
    return result.substr(0, result.size() - 3);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients && degree == other.degree;  // если равны коэффиценты и степени
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);  // обраное к равентсву
}
