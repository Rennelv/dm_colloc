#include "P/NMR_P_P.hpp"

#include "P/DER_P_P.hpp"
#include "P/DIV_PP_P.hpp"
#include "P/GCF_PP_P.hpp"

Polynomial NMR_P_P(const Polynomial& p) {
    Polynomial derivative = DER_P_P(p);        // Счиатем производную многочлена
    Polynomial gcd = GCF_PP_P(p, derivative);  // Cчитаем НОД исходного p(x) и его производной
    Polynomial result = DIV_PP_P(p, gcd);      // Делим p(x) на НОД

    return result;
}
