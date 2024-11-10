#include "P/ADD_PP_P.hpp"

#include "N/LongNatural.hpp"
#include "Q/ADD_QQ_Q.hpp"
#include "Q/LongRational.hpp"

Polynomial ADD_PP_P(const Polynomial& a, const Polynomial& b) {
    std::map<LongNatural, LongRational> result_сoefficients = a.getMap();  // Копируем коэффициенты первого многочлена

    for (const auto& [degree, coef_b] : b.getMap()) {
        auto it = result_сoefficients.find(degree);
        if (it != result_сoefficients.end()) {
            // Если такая степень уже есть в первом многочлене, складываем коэффициенты
            it->second = ADD_QQ_Q(it->second, coef_b);
        } else {
            // Если такая степень отсутствует, добавляем новый член с данным коэффициентом
            result_сoefficients.emplace(degree, coef_b);
        }
    }

    return Polynomial(result_сoefficients);
}
