#include "P/LED_P_Q.hpp"

LongRational LED_P_Q(const Polynomial& a) {
    return a.lead();
}