#include "Q/TRANS_Z_Q.hpp"

#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

LongRational TRANS_Z_Q(const LongInteger& n) {
    LongNatural denominator = {1};  // Создаём знаменатель, который равен 1
    LongRational result(n, denominator);  // Создаём рациональное число(в числителе целое число, в знаменателе 1)
    return result;
}