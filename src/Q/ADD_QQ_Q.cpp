#include "Q/ADD_QQ_Q.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/LCM_NN_N.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Z/ADD_ZZ_Z.hpp"
#include "Z/MUL_ZZ_Z.hpp"

LongRational ADD_QQ_Q(const LongRational& a, const LongRational& b) {
    LongNatural lcm = LCM_NN_N(a.getDenominator(), b.getDenominator());  // Находим НОК знаменателей

    // Приводим числители к общему знаменателю
    LongNatural multiplier_a = DIV_NN_N(lcm, a.getDenominator());
    LongNatural multiplier_b = DIV_NN_N(lcm, b.getDenominator());

    LongInteger numerator_a = MUL_ZZ_Z(a.getNumerator(), LongInteger(false, multiplier_a.getArr()));
    LongInteger numerator_b = MUL_ZZ_Z(b.getNumerator(), LongInteger(false, multiplier_b.getArr()));

    LongInteger numerator_result = ADD_ZZ_Z(numerator_a, numerator_b);  // Складываем числители

    LongRational result(numerator_result, lcm);

    return RED_Q_Q(result);
}
