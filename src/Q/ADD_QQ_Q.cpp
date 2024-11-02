#include "Q/ADD_QQ_Q.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/LCM_NN_N.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Z/ADD_ZZ_Z.hpp"
#include "Z/MUL_ZZ_Z.hpp"

LongRational ADD_QQ_Q(const LongRational& a, const LongRational& b) {
    LongNatural lcm = LCM_NN_N(a.getDenominator(), b.getDenominator());  // Находим НОК знаменателей

    // Приводим числители к общему знаменателю
    LongNatural multiplierA = DIV_NN_N(lcm, a.getDenominator());
    LongNatural multiplierB = DIV_NN_N(lcm, b.getDenominator());

    LongInteger numeratorA = MUL_ZZ_Z(a.getNumerator(), LongInteger(false, multiplierA.getArr()));
    LongInteger numeratorB = MUL_ZZ_Z(b.getNumerator(), LongInteger(false, multiplierB.getArr()));

    LongInteger numeratorResult = ADD_ZZ_Z(numeratorA, numeratorB);  // Складываем числители

    LongRational result(numeratorResult, lcm);

    return RED_Q_Q(result);
}
