#include "N/DIV_NN_Dk.hpp"

#include <stdexcept>

#include "N/COM_NN_D.hpp"
#include "N/MUL_ND_N.hpp"
#include "N/MUL_Nk_N.hpp"
#include "N/NZER_N_B.hpp"

LongNatural DIV_NN_Dk(const LongNatural& a, const LongNatural& b) {
    if (!NZER_N_B(b)) {
        throw std::logic_error("Division by zero is undefined.");
    }

    if (COM_NN_D(a, b) == 1) {  // если второе число больше первого, возвращаем ноль
        return LongNatural::ZERO;
    }

    LongNatural scaled_b = b;
    int k = 0;

    // приводим количество разрядов b к количеству разрядов а, уменьшенному на 1
    while (COM_NN_D(scaled_b, a) == 1) {
        scaled_b = MUL_Nk_N(b, ++k);
    }
    if (COM_NN_D(scaled_b, a) == 2) {
        scaled_b = MUL_Nk_N(b, --k);
    }

    // ищем макисмальную цифру d такую, что d * scaledB <= a
    uint8_t d = 0;
    for (uint8_t test_digit = 1; test_digit <= 9; test_digit++) {
        LongNatural test_product = MUL_ND_N(scaled_b, test_digit);
        if (COM_NN_D(test_product, a) != 2) {
            d = test_digit;
        } else {
            break;
        }
    }

    // возвращаем результат в виде d * 10^k
    return MUL_Nk_N(LongNatural({d}), k);
}
