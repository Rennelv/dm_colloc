#include "N/GCF_NN_N.hpp"

#include "N/COM_NN_D.hpp"
#include "N/MOD_NN_N.hpp"
#include "N/NZER_N_B.hpp"

LongNatural GCF_NN_N(const LongNatural& a, const LongNatural& b) {
    LongNatural a_copy = a;  // копися числа а
    LongNatural b_copy = b;  // копия числа b
    LongNatural tmp({0});

    // алгоритм Евклида(модифицированный)
    while (NZER_N_B(b_copy)) {  // выполняется пока меньшее из чисел не равно нулю
        tmp = b_copy;
        b_copy = MOD_NN_N(a_copy, b_copy);  // деление с остатком
        a_copy = tmp;
    }

    return a_copy;
}