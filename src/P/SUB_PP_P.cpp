#include "P/SUB_PP_P.hpp"

#include "Q/SUB_QQ_Q.hpp"
#include "Q/TRANS_Z_Q.hpp"

Polynomial SUB_PP_P(const Polynomial& a, const Polynomial& b) {
    const std::map<LongNatural, LongRational>& coefficients_a = a.getMap();  // получаем коэффициенты первого полинома

    // создаем map для хранения коэффициентов итогового полинома и дублируем в него коэффициенты первого полинома
    std::map<LongNatural, LongRational> coefficients = coefficients_a;

    const std::map<LongNatural, LongRational>& coefficients_b = b.getMap();  // получаем коэффициенты второго полинома

    LongRational zero = TRANS_Z_Q(LongInteger(false, {0}));  // создаем рациональное число равное нулю

    // проходимся по степеням второго полинома
    for (const auto& [key, value_b] : coefficients_b) {
        auto it = coefficients.find(key);
        // если в первом полиноме была данная степень, заменяем коэффициент на разность коэффициентов первого и второго полинома
        if (it != coefficients.end()) {
            it->second = SUB_QQ_Q(it->second, value_b);
        } else {
            coefficients.emplace(key, SUB_QQ_Q(zero, value_b));  // добавляем в итоговый полином разность нуля и коэффициента второго полинома
        }
    }

    Polynomial result(coefficients);  // создаем полином с полученным map коэффициентов
    return result;
}
