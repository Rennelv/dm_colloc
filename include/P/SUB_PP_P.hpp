#ifndef SUB_PP_P_HPP
#define SUB_PP_P_HPP

#include <N/LongNatural.hpp>
#include <P/Polynomial.hpp>
#include <Q/LongRational.hpp>
#include <Z/LongInteger.hpp>

/**
 * @file SUB_PP_P.hpp
 * @brief Функция для вычитания одного многочлена из другого.
 */

/**
 * @brief Функция SUB_PP_P вычитает один многочлен из другого.
 *
 * @param a Первый многочлен.
 * @param b Второй многочлен.
 * @return Результат вычитания.
 * @author Деревягина Александра 3381
 */

Polynomial SUB_PP_P(const Polynomial& a, const Polynomial& b);

#endif  // SUB_PP_P_HPP
