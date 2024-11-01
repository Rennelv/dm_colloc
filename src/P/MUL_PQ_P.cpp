#include "P/MUL_PQ_P.hpp"

#include "Q/MUL_QQ_Q.hpp"

Polynomial MUL_PQ_P(const Polynomial& a, const LongRational& q) {
    const std::map<LongNatural, LongRational>& poly_map = a.getMap();  // получаем мап коэффициентов
    std::map<LongNatural, LongRational> new_poly_map;                  // создаем мап для результатов

    for (const auto& [key, value] : poly_map) {
        new_poly_map.emplace(key, MUL_QQ_Q(value, q));  // коэффицент при каждой степени домножаем на рациональое число q
    }

    return Polynomial(new_poly_map);  // возвращаем новый полином
}