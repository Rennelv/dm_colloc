#include "P/DIV_PP_P.hpp"

#include "N/COM_NN_D.hpp"
#include "N/SUB_NN_N.hpp"
#include "P/DEG_P_N.hpp"
#include "P/MUL_PQ_P.hpp"
#include "P/MUL_Pxk_P.hpp"
#include "P/Polynomial.hpp"
#include "P/SUB_PP_P.hpp"
#include "Q/DIV_QQ_Q.hpp"

Polynomial DIV_PP_P(const Polynomial& dividend, const Polynomial& divisor) {
    // Проверка на единичный многочлен (если divisor == 1, возвращаем dividend)
    if (divisor.getDegree() == LongNatural::ZERO && divisor.getCoef(LongNatural::ZERO) == LongRational::ONE) {
        return dividend;
    }

    // Результат деления
    std::map<LongNatural, LongRational> res;

    // Степень делимого и делителя
    const LongNatural& deg_dividend = DEG_P_N(dividend);
    const LongNatural& deg_divisor = DEG_P_N(divisor);

    Polynomial remainder = dividend;

    // Пока степень остатка >= степени делителя
    while (COM_NN_D(DEG_P_N(remainder), deg_divisor) != 1) {  // Используем функцию сравнения
        // Получаем коэффициенты старших членов
        const LongRational& leading_coeff_dividend = remainder.getCoef(DEG_P_N(remainder));
        const LongRational& leading_coeff_divisor = divisor.getCoef(deg_divisor);

        // Делим коэффициенты
        LongRational coeff_quotient = DIV_QQ_Q(leading_coeff_dividend, leading_coeff_divisor);

        // Вычисляем текущую степень частного как разность степеней
        LongNatural degree_diff = SUB_NN_N(DEG_P_N(remainder), deg_divisor);  // Используем функцию вычитания

        // Добавляем одночлен к частному
        res.emplace(degree_diff, coeff_quotient);

        // Вычитаем произведение (divisor * одночлен) из остатка
        Polynomial product = MUL_Pxk_P(MUL_PQ_P(divisor, coeff_quotient), degree_diff);
        remainder = SUB_PP_P(remainder, product);
    }

    return Polynomial(res);
}
