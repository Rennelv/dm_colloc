#include "N/DIV_NN_N.hpp"

#include "N/ADD_NN_N.hpp"
#include "N/DIV_NN_Dk.hpp"
#include "N/MUL_NN_N.hpp"
#include "N/NZER_N_B.hpp"
#include "N/SUB_NN_N.hpp"

LongNatural DIV_NN_N(LongNatural& a, LongNatural& b) {
    if (!NZER_N_B(b)) {
        throw std::logic_error("Divider is zero");
    }

    LongNatural a_copy = a;    // сохоаняем изначальное число
    LongNatural result = {0};  // число для результатом
    LongNatural tmp = {1};     // ЪЪЪ

    while (NZER_N_B(tmp)) {  // цикл представляет собой деление в столбик без остатка
        tmp = DIV_NN_Dk(a_copy, b);  // сохраняем полученную при делении первую цифру умноженную на 10^k, где k - разряд цисла
        result = ADD_NN_N(result, tmp);  // суммирует переменные, домноженные на 10^k
        tmp = MUL_NN_N(tmp, b);          // умножаем делитель на получившееся частное
        a_copy = SUB_NN_N(a_copy, tmp);  // вычитаем это из делимого
    }

    return result;
}