#include "P/ADD_PP_P.hpp"

#include "N/LongNatural.hpp"
#include "Q/ADD_QQ_Q.hpp"
#include "Q/LongRational.hpp"

Polynomial ADD_PP_P(const Polynomial& a, const Polynomial& b) {
    std::map<LongNatural, LongRational> result_coefficients = a.getMap();  // Копируем коэффициенты первого многочлена

    for (const auto& [degree, coef_b] : b.getMap()) {
        result_coefficients[degree] = ADD_QQ_Q(a.getCoef(degree), coef_b);
    }

    return Polynomial(result_coefficients);
}
