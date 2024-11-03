#include "P/ADD_PP_P.hpp"

#include "N/LongNatural.hpp"
#include "Q/ADD_QQ_Q.hpp"
#include "Q/LongRational.hpp"

Polynomial ADD_PP_P(const Polynomial& a, const Polynomial& b) {
    std::map<LongNatural, LongRational> resultCoefficients = a.getMap();  // Копируем коэффициенты первого многочлена

    for (const auto& [degree, coefB] : b.getMap()) {
        auto it = resultCoefficients.find(degree);
        if (it != resultCoefficients.end()) {
            // Если такая степень уже есть в первом многочлене, складываем коэффициенты
            it->second = ADD_QQ_Q(it->second, coefB);
        } else {
            // Если такая степень отсутствует, добавляем новый член с данным коэффициентом
            resultCoefficients.emplace(degree, coefB);
        }
    }

    // Убираем нулевые коэффициенты из результирующего многочлена
    for (auto it = resultCoefficients.begin(); it != resultCoefficients.end();) {
        if (it->second.getNumerator() == LongInteger(false, {0})) {
            it = resultCoefficients.erase(it);
        } else {
            ++it;
        }
    }

    return Polynomial(resultCoefficients);
}
