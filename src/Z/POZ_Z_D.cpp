#include "Z/POZ_Z_D.hpp"

int POZ_Z_D(const LongInteger& a) {
    if (a.isZero()) {
        return 0;
    }
    return a.isNegative() ? 1 : 2;
}
