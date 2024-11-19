#include "N/MUL_Nk_N.hpp"

LongNatural MUL_Nk_N(const LongNatural& a, size_t k) {
    return a << k;
}
