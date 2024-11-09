#ifndef TRANS_Z_Q_HPP
#define TRANS_Z_Q_HPP

#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

/**
 * @file TRANS_Z_Q.hpp
 * @brief Функция для преобразования целого числа в дробное.
 */

/**
 * @brief Функция TRANS_Z_Q преобразовывает целое число в дробное.
 *
 * @param n Целое число.
 * @return LongRational Дробное число со знаменателем 1.
 * @author Гладилин Евгений 3381
 */

LongRational TRANS_Z_Q(const LongInteger &n);

#endif