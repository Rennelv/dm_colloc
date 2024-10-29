#include "N/DIV_NN_Dk.hpp"

#include "N/COM_NN_D.hpp"
#include "N/MUL_ND_N.hpp"
#include "N/MUL_Nk_N.hpp"

LongNatural DIV_NN_Dk(LongNatural& a, LongNatural& b) {
    if ((b.getLength() == 1 && b.at(0) == 0) || (a.getLength() == 1 && a.at(0) == 0)) {
        throw std::logic_error("Division by zero is undefined.");
    }

    if (COM_NN_D(a, b) == 1) {  // если второе число больше первого, меняем их местами
        std::swap(a, b);
    }

    LongNatural scaledB = b;
    int k = 0;

    // приводим количество разрядов b к количеству разрядов а, уменьшенному на 1
    while (COM_NN_D(scaledB, a) == 1) {
        scaledB = MUL_Nk_N(b, ++k);
    }
    if (COM_NN_D(scaledB, a) == 2) {
        scaledB = MUL_Nk_N(b, --k);
    }

    // ищем макисмальную цифру d такую, что d * scaledB <= a
    uint8_t d = 0;
    for (uint8_t testDigit = 1; testDigit <= 9; testDigit++) {
        LongNatural testProduct = MUL_ND_N(scaledB, testDigit);
        if (COM_NN_D(testProduct, a) != 2) {
            d = testDigit;
        } else {
            break;
        }
    }

    // возвращаем результат в виде d * 10^k
    return MUL_Nk_N(LongNatural({d}), k);
}
