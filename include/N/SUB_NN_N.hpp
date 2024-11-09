#ifndef SUB_NN_N_HPP
#define SUB_NN_N_HPP

#include "LongNatural.hpp"

/**
 * @file SUB_NN_N.hpp
 * @brief Функция для вычитания одного длинного натурального числа из другого.
 */

/**
 * @brief Функция SUB_NN_N принимает два числа и возвращает результат вычитания из большего меньшего.
 *
 * @param a Первое число.
 * @param b Второе число.
 * @return Разность чисел.
 * @author Гладилин Евгений 3381
 * @exception std::logic_error Если первое число меньше второго.
 */

LongNatural SUB_NN_N(const LongNatural& a, const LongNatural& b);

#endif  // SUB_NN_N_HPP
