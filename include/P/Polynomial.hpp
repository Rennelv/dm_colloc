#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <map>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"

/**
 * @file Polynomial.hpp
 * @brief Класс для работы с многочленами с коэффициентами из длинных рациональных чисел.
 */

/**
 * @class Polynomial
 * @brief Класс для работы с многочленами с коэффициентами из длинных рациональных чисел.
 *
 * @details Класс предоставляет методы для создания многочлена из мапы коэффициентов, получения мапы коэффициентов,
 * проверки существования коэффициента при заданной степени, получения коэффициента при заданной степени,
 * получения степени многочлена и преобразования многочлена в строку.
 * Многочлен представлен в виде словаря коэффициентов (степень -> коэффициент) отсортированного от младшей степени к старшей.
 *
 * @author Журавлев Дмитрий 3381
 */

class Polynomial {
    // Словарь (мапа) коэффициентов (степень -> коэффициент)
    std::map<LongNatural, LongRational> coefficients;
    // Степень полинома
    LongNatural degree;

   public:
    // Создает полином из мап коэффициентов
    Polynomial(const std::map<LongNatural, LongRational>& map);

    // Возвращает мап коэффициентов (const&). Для получения коэффицента при конкретной степени лучше использовать isCoefZero и getCoef, а getMap использовать
    // для итерации по всем коэффициентам
    const std::map<LongNatural, LongRational>& getMap() const;

    // Возвращает существует ли коэффициент при степени (true - существует, false - не существует)
    bool isCoef(const LongNatural& degree) const;

    // Возвращает коэффициент при степени (const&) (если коэф=0 возвращает 0/1)
    const LongRational& getCoef(const LongNatural& degree) const;

    // Возвращает степень полинома из переменной degree (const&)
    const LongNatural& getDegree() const;

    // Возвращает строку полинома ("(-654/646)x^3 + (-654/65)x^1 + 55/1")
    std::string toString() const;

    // Оператор сравнения (проверяет равенство коэффициентов)
    bool operator==(const Polynomial& other) const;
    // Оператор сравнения (обратный оператору ==)
    bool operator!=(const Polynomial& other) const;
};

#endif