#ifndef MOD_NN_N_HPP
#define MOD_NN_N_HPP

#include "N/LongNatural.hpp"

/**
 * @file MOD_NN_N.hpp
 * @brief Функция для вычисления остатка от деления одного натурального числа на другое.
 */

/**
 * @brief Функция MOD_NN_N вычисляет остаток от деления первого натурального числа на второе.
 *
 * @param a Первое натуральное число.
 * @param b Второе натуральное число.
 * @return Остаток от деления в виде объекта LongNatural.
 * @author Гладилин Евгений 3381
 * @exception std::logic_error При делении на ноль.
 */

LongNatural MOD_NN_N(const LongNatural& a, const LongNatural& b);

#endif  // MOD_NN_N_HPP
