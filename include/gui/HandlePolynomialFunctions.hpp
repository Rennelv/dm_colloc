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

/*
    Выполнил Журавлев Дмитрий 3381

    Класс обработчика функций многочленов для графического интерфейса.

*/

class HandlePolynomialFunctions {
    // static Polynomial parsePolynomial(const std::string& str);

   public:
    static void showMenu(bool* p_open);

    // std::string MapToPolyStr(const std::map<LongNatural, LongRational>& terms);

    static void show_ADD_PP_P(bool* p_open);
    static void show_SUB_PP_P(bool* p_open);
    static void show_MUL_PQ_P(bool* p_open);
    static void show_MUL_Pxk_P(bool* p_open);
    static void show_LED_P_Q(bool* p_open);
    static void show_DEG_P_N(bool* p_open);
    static void show_FAC_P_Q(bool* p_open);
    static void show_MUL_PP_P(bool* p_open);
    static void show_DIV_PP_P(bool* p_open);
    static void show_MOD_PP_P(bool* p_open);
    static void show_GCF_PP_P(bool* p_open);
    static void show_DER_P_P(bool* p_open);
    static void show_NMR_P_P(bool* p_open);
};

#endif  // POLYNOMIALFUNCTIONS_HPP