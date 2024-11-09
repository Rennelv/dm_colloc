#ifndef INT_Q_B_HPP
#define INT_Q_B_HPP

#include "Q/LongRational.hpp"

/**
 * @file INT_Q_B.hpp
 * @brief Функция для проверки, является ли рациональное число целым.
 */

/**
 * @brief Функция INT_Q_B проверяет, является ли сокращенное дробное число целым.
 *
 * Если рациональное число является целым, то возвращает 1, иначе 0.
 *
 * @param n Рациональное число.
 * @return true, если число целое, false, если нецелое.
 * @author Киреева Асия 3381
 * @exception std::logic_error Если знаменатель равен нулю.
 */

bool INT_Q_B(const LongRational &n);

#endif