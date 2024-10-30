#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <map>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"

namespace std {
template <>  // Объявление less для создания std::map коэффицентов с ключем LongNatural. map требует возможность сравнения ключей
struct less<LongNatural> {
    bool operator()(const LongNatural& lhs, const LongNatural& rhs) const {
        return COM_NN_D(lhs, rhs) == 2;
    }
};
}  // namespace std

/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с многочленами с коэффицентами из длинных рациональных чисел.

*/

class Polynomial {
    // Словарь (мапа) коэффициентов (степень -> коэффициент)
    std::map<LongNatural, LongRational> coefficients;
    // Степень полинома
    LongNatural degree;
    // Нулевое рациональное число для возврата const& при получении коэффицента
    LongRational zero;

   public:
    // Создает полином из мап коэффициентов
    Polynomial(const std::map<LongNatural, LongRational>& map);

    // Возвращает мап коэффициентов (const&). Для получения коэффицента при степени лучше использовать isCoefZero и getCoef.
    const std::map<LongNatural, LongRational>& getMap() const;

    // Возращает равен ли коэффицент при степени нулю (true - равен, false - не равен)
    bool isCoefZero(const LongNatural& degree) const;

    // Возвращает коэффициент при степени (const&) (если коэф=0 возвращает 0/1)
    const LongRational& getCoef(const LongNatural& degree) const;

    // Возвращает степень полинома (const&)
    const LongNatural& getDegree() const;

    // Возвращает строку полинома ("(-654/646)x^3 + (-654/65)x^1 + 55/1")
    std::string toString() const;

    // Оператор сравнения (проверяет равенство коэффициентов)
    bool operator==(const Polynomial& other) const;
    // Оператор сравнения (обратный оператору ==)
    bool operator!=(const Polynomial& other) const;
};

#endif