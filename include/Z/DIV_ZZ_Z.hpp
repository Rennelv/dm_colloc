#ifndef DIV_ZZ_Z_HPP
#define DIV_ZZ_Z_HPP

#include "Z/LongInteger.hpp"

/**
 * @file DIV_ZZ_Z.hpp
 * @brief Функция для деления целого числа на целое.
 */

/**
 * @brief Функция DIV_ZZ_Z выполняет деление целого числа на целое (делитель отличен от нуля).
 *
 * @param dividend Делимое (целое число).
 * @param divisor Делитель (целое число, не равен нулю).
 * @return LongInteger Частное от деления целого на целое.
 * @author Щеглов Михаил, группа 3381
 */

LongInteger DIV_ZZ_Z(const LongInteger& dividend, const LongInteger& divisor);

#endif
