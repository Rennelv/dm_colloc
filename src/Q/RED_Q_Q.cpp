#include "../include/Q/RED_Q_Q.hpp"

#include <iostream>
#include <vector>

#include "../include/N/LongNatural.hpp"
#include "../include/Z/LongInteger.hpp"
#include "../include/Q/LongRational.hpp"
#include "../include/Z/ABS_Z_N.hpp"
#include "../include/N/GCF_NN_N.hpp"
#include "../include/Z/ABS_Z_N.hpp"

using namespace std;

LongRational RED_Q_Q(const LongRational &a) {
    if (!NZER_N_B(getDenominator())) {  // проверяем, что знаменатель не равен нулю
        throw logic_error("The denominator cannot be zero");  // выбрасываем ошибку, если знаменатель равен нулю
    }
    uint8_t gcf = GCF_NN_N(ABS_Z_N(getNumerator()), getDenominator());  // находим НОД числителя и знаменателя
    LongInteger p = ABS_Z_N(getNumerator(), gcf);  // делим числитель на НОД
    LongNatural q = ABS_Z_N(getDenominator(), gcf);  // делим знаменатель на НОД
    return LongRational(p, q);  // возвращаем сокращенную дробь
}