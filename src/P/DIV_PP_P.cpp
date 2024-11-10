#include "P/DIV_PP_P.hpp"

#include "N/COM_NN_D.hpp"
#include "N/SUB_NN_N.hpp"
#include "P/ADD_PP_P.hpp"
#include "P/DEG_P_N.hpp"
#include "P/MUL_PQ_P.hpp"
#include "P/MUL_Pxk_P.hpp"
#include "P/SUB_PP_P.hpp"
#include "Q/DIV_QQ_Q.hpp"

Polynomial DIV_PP_P(const Polynomial& dividend, const Polynomial& divisor) {
    // Проверка на единичный многочлен (если divisor == 1, возвращаем dividend)
    if (divisor.getDegree() == LongNatural::ZERO && divisor.getCoef(LongNatural::ZERO) == LongRational::ONE) {
        return dividend;
    }

    // Инициализируем нулевой многочлен для частного
    std::map<LongNatural, LongRational> zero_map;
    zero_map.emplace(LongNatural::ZERO, LongRational::ZERO);
    Polynomial quotient(zero_map);

    // Степень делимого и делителя
    LongNatural deg_dividend = DEG_P_N(dividend);
    LongNatural deg_divisor = DEG_P_N(divisor);

    Polynomial remainder = dividend;

    // Пока степень остатка >= степени делителя
    while (COM_NN_D(DEG_P_N(remainder), deg_divisor) != 1) {  // Используем функцию сравнения
        // Вычисляем текущую степень частного как разность степеней
        LongNatural degree_diff = SUB_NN_N(DEG_P_N(remainder), deg_divisor);  // Используем функцию вычитания

        // Получаем коэффициенты старших членов
        LongRational leading_coeff_dividend = remainder.getCoef(DEG_P_N(remainder));
        LongRational leading_coeff_divisor = divisor.getCoef(deg_divisor);

        // Делим коэффициенты
        LongRational coeff_quotient = DIV_QQ_Q(leading_coeff_dividend, leading_coeff_divisor);

        // Создаем одночлен с этим коэффициентом и нужной степенью
        std::map<LongNatural, LongRational> single_term_map;
        single_term_map.emplace(degree_diff, coeff_quotient);
        Polynomial single_term(single_term_map);

        // Добавляем одночлен к частному
        quotient = ADD_PP_P(quotient, single_term);

        // Вычитаем произведение (divisor * одночлен) из остатка
        Polynomial product = MUL_Pxk_P(MUL_PQ_P(divisor, coeff_quotient), degree_diff);
        remainder = SUB_PP_P(remainder, product);
    }

    return quotient;
}
