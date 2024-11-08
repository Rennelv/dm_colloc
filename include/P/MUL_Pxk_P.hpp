#ifndef MUL_Pxk_P_HPP
#define MUL_Pxk_P_HPP

#include "P/Polynomial.hpp"

/**
 * @file MUL_Pxk_P.hpp
 * @brief Функция для умножения многочлена на x^k.
 */

/**
 * @brief Функция MUL_Pxk_P умножает многочлен на x^k, где k - натуральное число или 0.
 *
 * @param a Многочлен.
 * @param k Натуральное число или 0.
 * @return Результат умножения многочлена на x^k.
 * @author Салдин Даниил 3381
 */

Polynomial MUL_Pxk_P(const Polynomial& a, const LongNatural& k);

#endif