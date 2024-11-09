#include "Z/TRANS_N_Z.hpp"

LongInteger TRANS_N_Z(const LongNatural &n) {
    std::vector<uint8_t> new_arr = n.getArr();  // получаем массив цифр числа n
    LongInteger result(false, new_arr);         // создаем целое число
    return result;                              // возвращаем результат
}