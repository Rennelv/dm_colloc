#include "Q/MUL_QQ_Q.hpp"

#include "N/LongNatural.hpp"
#include "N/MUL_NN_N.hpp"
#include "Q/LongRational.hpp"
#include "Q/RED_QQ_Q.hpp"
#include "Z/LongInteger.hpp"
#include "Z/MUL_ZZ_Z.hpp"

using namespace std;

LongRational MUL_QQ_Q(const LongRational &a, const LongRational &b) {
    LongInteger p = MUL_ZZ_Z(a.getNumerator(), b.getNumerator());      // находим произведение числителей
    LongNatural q = MUL_NN_N(a.getDenominator(), b.getDenominator());  // находим произведение знаменателей
    LongRational b(p, q);  // создаем дробь с полученными числителем и знаменателем
    b = RED_QQ_Q(b);       // сокращаем дробь
    return b;              // возвращаем сокращенную дробь
}