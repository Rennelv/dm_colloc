#ifndef INTEGERFUNCTIONS_HPP
#define INTEGERFUNCTIONS_HPP

// enum class IntegerFunctions {
//     ABS_Z_N,  // Абсолютная величина числа, результат - натуральное
//     POZ_Z_D,  // Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
//     MUL_ZM_Z,   // Умножение целого на (-1)
//     TRANS_N_Z,  // Преобразование натурального в целое
//     TRANS_Z_N,  // Преобразование целого неотрицательного в натуральное
//     ADD_ZZ_Z,   // Сложение целых чисел
//     SUB_ZZ_Z,   // Вычитание целых чисел
//     MUL_ZZ_Z,   // Умножение целых чисел
//     DIV_ZZ_Z,   // Частное от деления целого на целое (делитель отличен от нуля)
//     MOD_ZZ_Z,   // Остаток от деления целого на целое(делитель отличен от нуля)
// };

/**
 * @file HandleIntegerFunctions.hpp
 * @brief Класс обработчика функций целых чисел для графического интерфейса.
 *
 * @class HandleIntegerFunctions
 * @brief Класс для управления функциями целых чисел в графическом интерфейсе.
 *
 * @author Журавлев Дмитрий 3381
 */

class HandleIntegerFunctions {
    static bool ABS_Z_N_open;
    static bool POZ_Z_D_open;
    static bool MUL_ZM_Z_open;
    static bool TRANS_N_Z_open;
    static bool TRANS_Z_N_open;
    static bool ADD_ZZ_Z_open;
    static bool SUB_ZZ_Z_open;
    static bool MUL_ZZ_Z_open;
    static bool DIV_ZZ_Z_open;
    static bool MOD_ZZ_Z_open;

   public:
    static void showMenu(bool* p_open);

    static void show_ABS_Z_N(bool* p_open);
    static void show_POZ_Z_D(bool* p_open);
    static void show_MUL_ZM_Z(bool* p_open);
    static void show_TRANS_N_Z(bool* p_open);
    static void show_TRANS_Z_N(bool* p_open);
    static void show_ADD_ZZ_Z(bool* p_open);
    static void show_SUB_ZZ_Z(bool* p_open);
    static void show_MUL_ZZ_Z(bool* p_open);
    static void show_DIV_ZZ_Z(bool* p_open);
    static void show_MOD_ZZ_Z(bool* p_open);
};

#endif  // INTEGERFUNCTIONS_HPP