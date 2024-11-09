#ifndef TRANS_Q_Z_HPP
#define TRANS_Q_Z_HPP

#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

/**
 * @file TRANS_Q_Z.hpp
 * @brief Функция для преобразования сокращенного дробного числа в целое.
 */

/**
 * @brief Функция TRANS_Q_Z преобразовывает сокращенное дробное число в целое.
 *
 * @param n Рациональное число.
 * @return Если знаменатель равен нулю - ошибка. Если знаменатель равен единице - возвращаем числитель. Если знаменатель не равен единице - ошибка.
 * @author Киреева Асия 3381
 * @exception std::logic_error Если знаменатель равен нулю.
 * @exception std::logic_error Если знаменатель не равен единице.
 */

LongInteger TRANS_Q_Z(const LongRational &n);

#endif