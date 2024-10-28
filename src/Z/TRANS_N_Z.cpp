#include "Z/TRANS_N_Z.hpp"

LongInteger TRANS_N_Z(const LongNatural &n)
{
    std::vector<uint8_t> newArr = n.getArr(); // получаем массив цифр числа n
    LongInteger result(newArr);               // создаем целое число
    return result;                            // возвращаем результат
}