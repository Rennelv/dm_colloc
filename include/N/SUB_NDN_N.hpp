#ifndef SUB_NDN_N_HPP
#define SUB_NDN_N_HPP

#include "LongNatural.hpp"

/**
 * @file SUB_NDN_N.hpp
 * @brief Функция для вычитания произведения натурального числа и цифры из другого натурального числа.
 */

/**
 * @brief Функция SUB_NDN_N принимает два натуральных числа и цифру. Возвращает разность первого и второго, умноженного на цифру.
 *
 * @param a Первое натуральное число.
 * @param b Второе натуральное число (вычитаемое).
 * @param d Цифра, на которую умножают b.
 * @return Разность первого числа и второго, умноженного на цифру.
 * @author Гладилин Евгений 3381
 * @exception std::logic_error Если первое число меньше произведения второго числа и цифры.
 */

LongNatural SUB_NDN_N(const LongNatural& a, const LongNatural& b, uint8_t k);

#endif  // SUB_NDN_N_HPP
