#include "P/NMR_P_P.hpp"

#include "N/LongNatural.hpp"
#include "P/DEG_P_N.hpp"
#include "P/DER_P_P.hpp"
#include "P/DIV_PP_P.hpp"
#include "P/GCF_PP_P.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial NMR_P_P(const Polynomial& p) {
    // Если многочлен - число, возвращаем его же
    if (DEG_P_N(p) == LongNatural("0")) {
        return p;
    }

    Polynomial derivative = DER_P_P(p);        // Считаем производную многочлена
    Polynomial gcd = GCF_PP_P(p, derivative);  // Считаем НОД исходного p(x) и его производной
    Polynomial result = DIV_PP_P(p, gcd);      // Делим p(x) на НОД

    return result;
}
