#include "P/MOD_PP_P.hpp"

#include "P/DIV_PP_P.hpp"
#include "P/MUL_PP_P.hpp"
#include "P/SUB_PP_P.hpp"

Polynomial MOD_PP_P(const Polynomial& p1, const Polynomial& p2) {
    // Выполняем целочисленное деление p1 на p2
    Polynomial quotient = DIV_PP_P(p1, p2);

    // Находим произведение p2 и частного (p2 * quotient)
    Polynomial product = MUL_PP_P(p2, quotient);

    // Вычисляем остаток, вычитая произведение из p1: остаток = p1 - (p2 * (p1 / p2))
    Polynomial remainder = SUB_PP_P(p1, product);

    return remainder;
}
