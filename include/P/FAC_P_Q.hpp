#ifndef FAC_P_Q_HPP
#define FAC_P_Q_HPP

#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"

/**
 * @file FAC_P_Q.hpp
 * @brief Функция для нахождения НОД числителей и НОК знаменателей многочлена.
 */

/**
 * @brief Функция FAC_P_Q выносит НОД числителей многочлена и НОК знаменателей многочлена.
 *
 * @param a Многочлен.
 * @return LongRational - дробь, в числителе которой находится НОД всех числителей, а в знаменателе НОК знаменателей.
 * @author Гладилин Евгений 3381
 * @warning Функция изменяет переданный многочлен.
 */

LongRational FAC_P_Q(Polynomial& a);

#endif