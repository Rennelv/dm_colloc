#include "P/SUB_PP_P.hpp"

#include "Q/LongRational.hpp"
#include "Q/SUB_QQ_Q.hpp"

Polynomial SUB_PP_P(const Polynomial& a, const Polynomial& b) {
    // создаем map для хранения коэффициентов итогового полинома и дублируем в него коэффициенты первого полинома
    std::map<LongNatural, LongRational> coefficients = a.getMap();

    const std::map<LongNatural, LongRational>& coefficients_b = b.getMap();  // получаем коэффициенты второго полинома

    // проходимся по степеням второго полинома
    for (const auto& [key, value_b] : coefficients_b) {
        // вычитаем коэффиценты при одинаковых степенях, если степени нет getCoef вернет 0
        coefficients[key] = SUB_QQ_Q(a.getCoef(key), value_b);
    }

    return Polynomial(coefficients);
}
