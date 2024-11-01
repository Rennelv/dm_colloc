#ifndef POLYNOMIALFUNCTIONS_HPP
#define POLYNOMIALFUNCTIONS_HPP

enum class PolynomialFunctions {
    ADD_PP_P,   // Сложение многочленов
    SUB_PP_P,   // Вычитание многочленов
    MUL_PQ_P,   // Умножение многочлена на рациональное число
    MUL_Pxk_P,  // Умножение многочлена на x^k, k-натуральное или 0
    LED_P_Q,    // Старший коэффициент многочлена
    DEG_P_N,    // Степень многочлена
    FAC_P_Q,    // Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
    MUL_PP_P,   // Умножение многочленов
    DIV_PP_P,   // Частное от деления многочлена на многочлен при делении с остатком
    MOD_PP_P,   // Остаток от деления многочлена на многочлен при делении с остатком
    GCF_PP_P,   // НОД многочленов
    DER_P_P,    // Производная многочлена
    NMR_P_P,    // Преобразование многочлена — кратные корни в простые
};

#endif  // POLYNOMIALFUNCTIONS_HPP