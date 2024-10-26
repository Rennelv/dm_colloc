#ifndef CLI_HPP
#define CLI_HPP

#include <cstddef>
#include <utility>

#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"
#include "cli/InputHandler.hpp"

enum class NaturalFunctions {
    COM_NN_D,  // Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.
    NZER_N_B,  // Проверка на ноль: если число не равно нулю, то «да» иначе «нет»
    ADD_1N_N,  // Добавление 1 к натуральному числу
    ADD_NN_N,  // Сложение натуральных чисел
    SUB_NN_N,  // Вычитание из первого большего натурального числа второго меньшего или равного
    MUL_ND_N,   // Умножение натурального числа на цифру
    MUL_Nk_N,   // Умножение натурального числа на 10^k, k-натуральное
    MUL_NN_N,   // Умножение натуральных чисел
    SUB_NDN_N,  // Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом
    DIV_NN_Dk,  // Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с
                // нуля)
    DIV_NN_N,  // Неполное частное от деления первого натурального числа на второе с остатком (делитель отличен от нуля)
    MOD_NN_N,  // Остаток от деления первого натурального числа на второе натуральное (делитель отличен от нуля)
    GCF_NN_N,  // НОД натуральных чисел
    LCM_NN_N,  // НОК натуральных чисел
};

enum class IntegerFunctions {
    ABS_Z_N,  // Абсолютная величина числа, результат - натуральное
    POZ_Z_D,  // Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
    MUL_ZM_Z,   // Умножение целого на (-1)
    TRANS_N_Z,  // Преобразование натурального в целое
    TRANS_Z_N,  // Преобразование целого неотрицательного в натуральное
    ADD_ZZ_Z,   // Сложение целых чисел
    SUB_ZZ_Z,   // Вычитание целых чисел
    MUL_ZZ_Z,   // Умножение целых чисел
    DIV_ZZ_Z,   // Частное от деления целого на целое (делитель отличен от нуля)
    MOD_ZZ_Z,   // Остаток от деления целого на целое(делитель отличен от нуля)
};

enum class RationalFunctions {
    RED_Q_Q,  // Сокращение дроби
    INT_Q_B,  // Проверка сокращенного дробного на целое, если рациональное число является целым, то «да», иначе «нет»
    TRANS_Z_Q,  // Преобразование целого в дробное
    TRANS_Q_Z,  // Преобразование сокращенного дробного в целое (если знаменатель равен 1)
    ADD_QQ_Q,   // Сложение дробей
    SUB_QQ_Q,   // Вычитание дробей
    MUL_QQ_Q,   // Умножение дробей
    DIV_QQ_Q,   // Деление дробей (делитель отличен от нуля)
};

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

class Cli {
    InputHandler inputHandler;
    std::pair<int, int> cursorPos = {1, 1};

   public:
    Cli() = default;

    void run();

    void clearScreen();
    void moveCursor(int row, int col);

    void printMenu(size_t highlighted = 0);
    void printNaturalFuncMenu(size_t highlighted = 0);
    void printIntegerFuncMenu(size_t highlighted = 0);
    void printRationalFuncMenu(size_t highlighted = 0);
    void printPolynomialFuncMenu(size_t highlighted = 0);

    void naturalFuncMenu();
    void integerFuncMenu();
    void rationalFuncMenu();
    void polynomialFuncMenu();

    void naturalFunc(NaturalFunctions func);
    void integerFunc(IntegerFunctions func);
    void rationalFunc(RationalFunctions func);
    void polynomialFunc(PolynomialFunctions func);

    void printLongNatural(const LongNatural& number);
    void printLongInteger(const LongInteger& number);
    void printPolynomial(const Polynomial& polynomial);
    void printLongRational(const LongRational& number);
};

#endif  // CLI_HPP
