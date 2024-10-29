#include "Q/RED_Q_Q.hpp"

#include <iostream>
#include <vector>

#include "N/GCF_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/LongInteger.hpp"

using namespace std;

LongRational RED_Q_Q(const LongRational &a) {
    uint8_t gcf = GCF_NN_N(ABS_Z_N(getNumerator()), getDenominator());  // находим НОД числителя и знаменателя
    LongInteger p = ABS_Z_N(getNumerator(), gcf);                       // делим числитель на НОД
    LongNatural q = ABS_Z_N(getDenominator(), gcf);                     // делим знаменатель на НОД
    LongRational b(p, q);                                               // создаем сокращенную дробь
    return b;                                                           // возвращаем сокращенную дробь
}