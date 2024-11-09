#ifndef COM_NN_D_HPP
#define COM_NN_D_HPP

#include <N/LongNatural.hpp>

/**
 * @file COM_NN_D.hpp
 * @brief Функция для сравнения двух длинных натуральных чисел.
 */

/**
 * @brief Функция COM_NN_D принимает два числа и сравнивает их.
 *
 * @param a Первое число.
 * @param b Второе число.
 * @return Результат сравнения:
 *         - 0, если числа равны
 *         - 1, если второе число больше первого
 *         - 2, если первое число больше второго
 * @author Журавлев Дмитрий 3381
 */

int COM_NN_D(const LongNatural& a, const LongNatural& b);

#endif  // COM_NN_D_HPP