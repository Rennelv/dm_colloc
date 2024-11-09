#ifndef MOD_PP_P_HPP
#define MOD_PP_P_HPP

#include "P/Polynomial.hpp"

/**
 * @file MOD_PP_P.hpp
 * @brief Функция для вычисления остатка от деления одного многочлена на другой.
 */

/**
 * @brief Функция MOD_PP_P выполняет вычисление остатка от деления одного многочлена на другой.
 *
 * @param p1 Делимый многочлен.
 * @param p2 Делитель многочлен.
 * @return Остаток от деления p1 на p2.
 * @author Щеглов Михаил, группа 3381
 */

Polynomial MOD_PP_P(const Polynomial& p1, const Polynomial& p2);

#endif
