#ifndef NATURALFUNCTIONS_HPP
#define NATURALFUNCTIONS_HPP

// enum class NaturalFunctions {
//     COM_NN_D,  // Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.
//     NZER_N_B,  // Проверка на ноль: если число не равно нулю, то «да» иначе «нет»
//     ADD_1N_N,  // Добавление 1 к натуральному числу
//     ADD_NN_N,  // Сложение натуральных чисел
//     SUB_NN_N,  // Вычитание из первого большего натурального числа второго меньшего или равного
//     MUL_ND_N,   // Умножение натурального числа на цифру
//     MUL_Nk_N,   // Умножение натурального числа на 10^k, k-натуральное
//     MUL_NN_N,   // Умножение натуральных чисел
//     SUB_NDN_N,  // Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом
//     DIV_NN_Dk,  // Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с
//                 // нуля)
//     DIV_NN_N,  // Неполное частное от деления первого натурального числа на второе с остатком (делитель отличен от нуля)
//     MOD_NN_N,  // Остаток от деления первого натурального числа на второе натуральное (делитель отличен от нуля)
//     GCF_NN_N,  // НОД натуральных чисел
//     LCM_NN_N,  // НОК натуральных чисел
// };

/**
 * @file HandleNaturalFunctions.hpp
 * @brief Класс обработчика функций натуральных чисел для графического интерфейса.
 *
 * @class HandleNaturalFunctions
 * @brief Класс для управления функциями натуральных чисел в графическом интерфейсе.
 *
 * @details Класс предоставляет методы для отображения различных функций работы с натуральными числами в графическом интерфейсе.
 *
 * @author Журавлев Дмитрий 3381
 */

class HandleNaturalFunctions {
    static bool COM_NN_D_open;
    static bool NZER_N_B_open;
    static bool ADD_1N_N_open;
    static bool ADD_NN_N_open;
    static bool SUB_NN_N_open;
    static bool MUL_ND_N_open;
    static bool MUL_Nk_N_open;
    static bool MUL_NN_N_open;
    static bool SUB_NDN_N_open;
    static bool DIV_NN_Dk_open;
    static bool DIV_NN_N_open;
    static bool MOD_NN_N_open;
    static bool GCF_NN_N_open;
    static bool LCM_NN_N_open;

   public:
    static void showMenu(bool *p_open);

    static void show_COM_NN_D(bool *p_open);
    static void show_NZER_N_B(bool *p_open);
    static void show_ADD_1N_N(bool *p_open);
    static void show_ADD_NN_N(bool *p_open);
    static void show_SUB_NN_N(bool *p_open);
    static void show_MUL_ND_N(bool *p_open);
    static void show_MUL_Nk_N(bool *p_open);
    static void show_MUL_NN_N(bool *p_open);
    static void show_SUB_NDN_N(bool *p_open);
    static void show_DIV_NN_Dk(bool *p_open);
    static void show_DIV_NN_N(bool *p_open);
    static void show_MOD_NN_N(bool *p_open);
    static void show_GCF_NN_N(bool *p_open);
    static void show_LCM_NN_N(bool *p_open);
};

#endif  // NATURALFUNCTIONS_HPP