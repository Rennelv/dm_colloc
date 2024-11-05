#include "P/GCF_PP_P.hpp"

#include "N/LongNatural.hpp"
#include "P/DEG_P_N.hpp"
#include "P/FAC_P_Q.hpp"
#include "P/MOD_PP_P.hpp"
#include "P/MUL_PQ_P"
#include "Q/DIV_QQ_Q"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial GCF_PP_P(const Polynomial& p1, const Polynomial& p2) {
    Polynomial a = p1;
    Polynomial b = p2;

    // Проверка на нулевые многочлены
    if (DEG_P_N(a) == LongNatural("0") && a.getCoef(LongNatural("0")) == LongRational(LongInteger("0"), LongNatural("1"))) {
        return b;
    }
    if (DEG_P_N(b) == LongNatural("0") && b.getCoef(LongNatural("0")) == LongRational(LongInteger("0"), LongNatural("1"))) {
        return a;
    }

    // Алгоритм Евклида для нахождения НОД
    while (!(DEG_P_N(b) == LongNatural("0") && b.getCoef(LongNatural("0")) == LongRational(LongInteger("0"), LongNatural("1")))) {
        // Выносим коэффициенты из многочленов a и b
        LongRational coef_a = FAC_P_Q(a);
        LongRational coef_b = FAC_P_Q(b);

        Polynomial remainder = MOD_PP_P(a, b);

        // Если НОД равен единичному многочлену, возвращаем его
        if (DEG_P_N(remainder) == LongNatural("0") && remainder.getCoef(LongNatural("0")) == LongRational(LongInteger("1"), LongNatural("1"))) {
            std::map<LongNatural, LongRational> one_map;
            one_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
            return Polynomial(one_map);
        }

        // Обновляем значения `a` и `b`
        a = std::move(b);
        b = std::move(remainder);
    }
    // Выводим приведенный многочлен
    LongRational a0 = a.getCoef(a.getDegree());
    a = MUL_PQ_P(a, DIV_QQ_Q(LongRational(LongInteger(false, {1}), LongNatural{1}), a0));
    return a;
}
