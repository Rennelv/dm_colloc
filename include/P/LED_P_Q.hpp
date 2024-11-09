#ifndef LED_P_Q_HPP
#define LED_P_Q_HPP

#include "P/Polynomial.hpp"

/**
 * @file LED_P_Q.hpp
 * @brief Функция для получения старшего коэффициента многочлена.
 */

/**
 * @brief Функция LED_P_Q возвращает старший коэффициент многочлена.
 *
 * @param a Многочлен.
 * @return Старший коэффициент многочлена.
 * @author Салдин Даниил 3381
 */

LongRational LED_P_Q(const Polynomial& a);

#endif