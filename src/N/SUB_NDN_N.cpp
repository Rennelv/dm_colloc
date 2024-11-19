#include "N/SUB_NDN_N.hpp"

LongNatural SUB_NDN_N(const LongNatural& a, const LongNatural& b, uint8_t k) {
    return a.subtractMultiplyByDigit(b, k);
}