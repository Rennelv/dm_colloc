#include "N/GCF_NN_N.hpp"

#include "N/COM_NN_D.hpp"
#include "N/MOD_NN_N.hpp"
#include "N/NZER_N_B.hpp"

LongNatural GCF_NN_N(const LongNatural& a, const LongNatural& b) {
    LongNatural a_copy = a;  // копися числа а
    LongNatural b_copy = b;  // копия числа b

    // алгоритм Евклида
    while (NZER_N_B(a_copy) && NZER_N_B(b_copy)) {  // если одно из числе станет равным нулю, то НОД найден

        // Деление с остатком большего из двух чисел на меньшее
        if (COM_NN_D(a_copy, b_copy) == 2) {
            a_copy = MOD_NN_N(a_copy, b_copy);
        } else {
            b_copy = MOD_NN_N(b_copy, a_copy);
        }
    }

    if (COM_NN_D(a_copy, b_copy) == 2) {  // возращает большее число, которое является НОД
        return a_copy;
    } else {
        return b_copy;
    }
}