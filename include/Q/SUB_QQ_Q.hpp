#ifndef SUB_QQ_Q_HPP
#define SUB_QQ_Q_HPP

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

/**
 * @file SUB_QQ_Q.hpp
 * @brief Функция для вычитания двух рациональных чисел.
 */

/**
 * @brief Функция SUB_QQ_Q принимает две дроби и возвращает их разность.
 *
 * @param a Первое рациональное число.
 * @param b Второе рациональное число.
 * @return Результат вычитания двух дробей (рациональное число).
 * @author Деревягина Александра 3381
 */

LongRational SUB_QQ_Q(const LongRational& a, const LongRational& b);

#endif  // SUB_QQ_Q_HPP
