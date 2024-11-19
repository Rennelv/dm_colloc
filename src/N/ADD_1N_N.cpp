#include "N/ADD_1N_N.hpp"

#include "N/LongNatural.hpp"

LongNatural ADD_1N_N(const LongNatural& a) {
    LongNatural result = a;
    return ++result;
}
