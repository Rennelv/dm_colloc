#include "Q/RED_Q_Q.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/GCF_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/DIV_ZZ_Z.hpp"
#include "Z/LongInteger.hpp"

LongRational RED_Q_Q(const LongRational &a) {
    LongNatural gcf = GCF_NN_N(ABS_Z_N(a.getNumerator()), a.getDenominator());  // находим НОД числителя и знаменателя
    LongInteger gcf_int(false, gcf.getArr());                                   // делаем НОД целым числом
    LongInteger p = DIV_ZZ_Z(a.getNumerator(), gcf_int);                        // делим числитель на НОД (деленеие целых)
    LongNatural q = DIV_NN_N(a.getDenominator(), gcf);  // делим знаменатель на НОД (деление натуральных)
    LongRational b(p, q);                               // создаем сокращенную дробь
    return b;                                           // возвращаем сокращенную дробь
}