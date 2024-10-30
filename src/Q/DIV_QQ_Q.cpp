#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Q/MUL_QQ_Q.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Z/LongInteger.hpp"

using namespace std;

LongRational DIV_QQ_Q(const LongRational &a, const LongRational &b) {
    LongInteger p(b.getNumerator().isNegative(),
                  b.getDenominator().getArr());  // создаем целое число p по модулю равное знаменателю второй дроби и знака второй дроби
    LongNatural q(b.getNumerator().getArr());  // создаем натуральное число q равное по модулю числителю второй дроби
    LongRational c(p, q);  // создаем дробь с числителем p и знаменателем q ("перевернутая" вторая дробь)
    LongRational ans = MUL_QQ_Q(a, c);  // перемножаем первую дробь и "перевернутую" вторую дробь
    ans = RED_Q_Q(ans);                 // сокращаем полученную дробь
    return ans;                         // возвращаем сокращенную дробь
}