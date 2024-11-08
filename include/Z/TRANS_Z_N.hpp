#ifndef TRANS_Z_N_HPP
#define TRANS_Z_N_HPP

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"

/**
 * @file TRANS_Z_N.hpp
 * @brief Функция для преобразования целого неотрицательного числа в натуральное.
 */

/**
 * @brief Функция TRANS_Z_N преобразовывает целое неотрицательное число в натуральное.
 *
 * @param n Целое неотрицательное число.
 * @return Если n >= 0 - возвращаем натуральное число, если n < 0 - ошибка.
 * @author Киреева Асия 3381
 * @exception std::logic_error Если n < 0.
 */

LongNatural TRANS_Z_N(const LongInteger &n);

#endif