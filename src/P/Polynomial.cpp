#include "P/Polynomial.hpp"

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial::Polynomial(const std::map<LongNatural, LongRational>& map) : coefficients(map), degree(LongNatural("0")) {
    std::map<LongNatural, LongRational> tempCoefficients = coefficients;
    for (const auto& [deg, coef] : tempCoefficients) {
        if (coef.getNumerator() == LongInteger("0")) {
            coefficients.erase(deg);
            continue;
        }
        if (COM_NN_D(degree, deg) == 1) {
            degree = deg;
        }
    }
}

LongRational Polynomial::getCoef(const LongNatural& degree) const {
    if (coefficients.find(degree) == coefficients.end()) {
        return LongRational(LongInteger("0"), LongNatural("1"));
    }
    return coefficients.at(degree);
}

LongNatural Polynomial::getDegree() const {
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
    }
    if (result.empty()) {
        return "0";
    }
    return result.substr(0, result.size() - 3);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients && degree == other.degree;
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return coefficients != other.coefficients || degree != other.degree;
}
