#include "N/LCM_NN_N.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/GCF_NN_N.hpp"
#include "N/MUL_NN_N.hpp"

LongNatural LCM_NN_N(const LongNatural& a, const LongNatural& b) {
    // Для нахождения НОК чисел справедлива формула - НОК = (m*n) / (НОД(m,n))

    LongNatural GCF = GCF_NN_N(a, b);     // НОД двух чисел
    LongNatural result = MUL_NN_N(a, b);  // умножаем a на b
    result = DIV_NN_N(result, GCF);       // дедим произведение на их НОД

    return result;
}