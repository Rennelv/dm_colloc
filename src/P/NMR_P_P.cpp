#include "P/NMR_P_P.hpp"

#include "N/LongNatural.hpp"
#include "P/DER_P_P.hpp"
#include "P/DIV_PP_P.hpp"
#include "P/GCF_PP_P.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial NMR_P_P(const Polynomial& p) {
    if (DEG_P_N(p) == LongNatural("0") && p.getCoef(LongNatural("0")) != LongRational(LongInteger("0"), LongNatural("1"))) {
        std::map<LongNatural, LongRational> one_map;
        one_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
        return Polynomial(one_map);
    }

    Polynomial derivative = DER_P_P(p);        // Считаем производную многочлена
    Polynomial gcd = GCF_PP_P(p, derivative);  // Считаем НОД исходного p(x) и его производной
    Polynomial result = DIV_PP_P(p, gcd);      // Делим p(x) на НОД

    return result;
}
