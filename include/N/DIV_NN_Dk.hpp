#ifndef DIV_NN_DK_HPP
#define DIV_NN_DK_HPP

#include "N/LongNatural.hpp"

/**
 * @file DIV_NN_Dk.hpp
 * @brief Функция для вычисления первой цифры деления большего натурального числа на меньшее, домноженной на 10^k.
 */

/**
 * @brief Функция DIV_NN_Dk вычисляет первую цифру деления большего натурального числа на меньшее, умноженную на 10^k.
 *
 * Функция использует базовые модули COM_NN_D и MUL_Nk_N.
 *
 * @param a Натуральное число.
 * @param b Натуральное число.
 * @return Первая цифра деления первого числа на второе, умноженная на 10^k, где k - номер позиции этой цифры.
 * @author Кунакова Мария 3381
 * @exception std::logic_error При делении на ноль.
 */

LongNatural DIV_NN_Dk(const LongNatural& a, const LongNatural& b);

#endif  // DIV_NN_DK_HPP
