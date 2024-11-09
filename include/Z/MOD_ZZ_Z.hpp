#ifndef MOD_ZZ_Z_HPP
#define MOD_ZZ_Z_HPP

#include "Z/LongInteger.hpp"

/**
 * @file MOD_ZZ_Z.hpp
 * @brief Функция для нахождения остатка от деления одного целого числа на другое.
 */

/**
 * @brief Функция MOD_ZZ_Z ищет остаток от деления одного целого числа на другое (делитель отличен от нуля).
 *
 * @param dividend Делимое, целое число.
 * @param divisor Делитель, целое число, не равное нулю.
 * @return Остаток от деления dividend на divisor.
 * @author Киреева Асия 3381
 */

LongInteger MOD_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor);

#endif