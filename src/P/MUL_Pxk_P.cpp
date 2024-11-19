#include "P/MUL_Pxk_P.hpp"

Polynomial MUL_Pxk_P(const Polynomial& a, const LongNatural& k) {
    return a << k;
}
