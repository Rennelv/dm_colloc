#ifndef MUL_PQ_P_HPP
#define MUL_PQ_P_HPP

#include "P/Polynomial.hpp"

/**
 * @file MUL_PQ_P.hpp
 * @brief Функция для умножения многочлена на рациональное число.
 */

/**
 * @brief Функция MUL_PQ_P умножает многочлен на рациональное число.
 *
 * @param a Многочлен.
 * @param q Рациональное число.
 * @return Результат умножения многочлена на рациональное число.
 * @author Салдин Даниил 3381
 */

Polynomial MUL_PQ_P(const Polynomial& a, const LongRational& q);

#endif