#include "P/GCF_PP_P.hpp"

#include "N/LongNatural.hpp"
#include "P/DEG_P_N.hpp"
#include "P/MOD_PP_P.hpp"
#include "P/MUL_PQ_P.hpp"
#include "Q/DIV_QQ_Q.hpp"
#include "Q/LongRational.hpp"

Polynomial GCF_PP_P(const Polynomial& p1, const Polynomial& p2) {
    Polynomial a = p1;
    Polynomial b = p2;

    // Проверка на нулевые многочлены
    if (DEG_P_N(a) == LongNatural::ZERO && a.getCoef(LongNatural::ZERO) == LongRational::ZERO) {
        return b;
    }
    if (DEG_P_N(b) == LongNatural::ZERO && b.getCoef(LongNatural::ZERO) == LongRational::ZERO) {
        return a;
    }

    // Алгоритм Евклида для нахождения НОД
    while (!(DEG_P_N(b) == LongNatural::ZERO && b.getCoef(LongNatural::ZERO) == LongRational::ZERO)) {
        Polynomial remainder = MOD_PP_P(a, b);

        // Если НОД равен единичному многочлену, то возвращаем его
        if (DEG_P_N(remainder) == LongNatural::ZERO && remainder.getCoef(LongNatural::ZERO) != LongRational::ZERO) {
            std::map<LongNatural, LongRational> one_map;
            one_map.emplace(LongNatural::ZERO, LongRational::ONE);
            return Polynomial(one_map);
        }

        // Обновляем значения a и b
        a = std::move(b);
        b = std::move(remainder);
    }

    // Возращаем приведенный многочлен
    LongRational a0 = a.getCoef(a.getDegree());
    a = MUL_PQ_P(a, DIV_QQ_Q(LongRational::ONE, a0));
    return a;
}
