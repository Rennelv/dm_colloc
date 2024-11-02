#include "Q/SUB_QQ_Q.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/LCM_NN_N.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Z/MUL_ZZ_Z.hpp"
#include "Z/SUB_ZZ_Z.hpp"
#include "Z/TRANS_N_Z.hpp"

LongRational SUB_QQ_Q(const LongRational& a, const LongRational& b) {
    const LongNatural& denominator_a = a.getDenominator();     // получаем знаменатель первого числа
    const LongNatural& denominator_b = b.getDenominator();     // получаем знаменатель второго числа
    LongNatural lcm = LCM_NN_N(denominator_a, denominator_b);  // находим НОК двух чисел
    LongInteger multiplier_a = TRANS_N_Z(DIV_NN_N(lcm, denominator_a));  // находим множитель для первого числа, деля НОК на знаменатель первого числа
    LongInteger multiplier_b = TRANS_N_Z(DIV_NN_N(lcm, denominator_b));  // находим множитель для второго числа, деля НОК на знаменатель второг числа
    LongInteger numerator = SUB_ZZ_Z(MUL_ZZ_Z(a.getNumerator(), multiplier_a), MUL_ZZ_Z(b.getNumerator(), multiplier_b));  // находим числитель
    LongRational result(numerator, lcm);  // создаем дробь с полученным числителем и знаменателем
    result = RED_Q_Q(result);             // сокращаем дробь
    return result;
}
