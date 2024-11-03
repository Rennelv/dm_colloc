#include "P/DIV_PP_P.hpp"

#include "N/SUB_NN_N.hpp"
#include "P/ADD_PP_P.hpp"
#include "P/DEG_P_N.hpp"
#include "P/MUL_PQ_P.hpp"
#include "P/MUL_Pxk_P.hpp"
#include "P/SUB_PP_P.hpp"
#include "Q/DIV_QQ_Q.hpp"

Polynomial DIV_PP_P(const Polynomial& dividend, const Polynomial& divisor) {
    // Инициализируем многочлен для частного
    std::map<LongNatural, LongRational> zero_map;
    Polynomial quotient(zero_map);

    // Степень делимого и делителя
    LongNatural deg_dividend = DEG_P_N(dividend);
    LongNatural deg_divisor = DEG_P_N(divisor);

    // Tекущий остаток от деления многочленов
    Polynomial remainder = dividend;

    // Пока степень остатка >= степени делителя
    // Используем функцию сравнения
    while (COM_NN_D(DEG_P_N(remainder), deg_divisor) != 1) {
        // Вычисляем текущую степень частного как разность степеней
        // Используем функцию вычитания
        LongNatural degree_diff = SUB_NN_N(DEG_P_N(remainder), deg_divisor);

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
