#include "N/COM_NN_D.hpp"

int COM_NN_D(const LongNatural& a, const LongNatural& b) {
    if (a > b) {
        return 2;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}