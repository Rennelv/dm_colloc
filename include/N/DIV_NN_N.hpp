#ifndef DIV_NN_N_HPP
#define DIV_NN_N_HPP

#include "N/LongNatural.hpp"

/**
 * @file DIV_NN_N.hpp
 * @brief Функция для вычисления неполного частного от деления первого натурального числа на второе.
 */

/**
 * @brief Функция DIV_NN_N вычисляет неполное частное от деления первого натурального числа на второе.
 *
 * @param a Первое натуральное число.
 * @param b Второе натуральное число.
 * @return Неполное частное от деления.
 * @author Гладилин Евгений 3381
 * @exception std::logic_error При делении на ноль.
 */

LongNatural DIV_NN_N(const LongNatural& a, const LongNatural& b);

#endif  // DIV_NN_N_HPP
