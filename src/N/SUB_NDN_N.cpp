#include "N/SUB_NDN_N.hpp"
#include "N/SUB_NN_N.hpp"
#include "N/MUL_ND_N.hpp"
#include "N/COM_NN_D.hpp"

#include <algorithm>  // для std::reverse
#include <cstddef>
#include <stdexcept>

#include "N/LongNatural.hpp"

LongNatural SUB_NDN_N(const LongNatural& a, const LongNatural& b, const uint8_t& k) {
    
    LongNatural nb = MUL_ND_N(b, k);    //умножаем число b на k

    if (COM_NN_D(a, nb) == 1) {         //проверяем не превышает ли произведение первое число
        throw std::logic_error("The first number is less than the product of the second number and a digit.");
    }
    
    return SUB_NN_N(a, nb);     //вычитаем из первого числа произведение
}