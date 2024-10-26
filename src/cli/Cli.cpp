#include "cli/Cli.hpp"

#include <iostream>
#include <limits>

#include "N/ADD_NN_N.hpp"
#include "N/COM_NN_D.hpp"

void Cli::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
    // moveCursor(cursorPos.first, cursorPos.second);
}

void Cli::moveCursor(int row, int col) {
    std::cout << "\033[" << row << ";" << col << "H";
    cursorPos = {row, col};
}

void Cli::run() {
    int choice;
    clearScreen();
    while (true) {
        printMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                naturalFuncMenu();
                break;
            case 2:
                integerFuncMenu();
                break;
            case 3:
                rationalFuncMenu();
                break;
            case 4:
                polynomialFuncMenu();
                break;
            case 5:
                clearScreen();
                return;
            default:
                clearScreen();
                std::cout << "Неверный ввод" << '\n';
                moveCursor(3, 1);

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void Cli::printMenu(size_t highlighted) {
    std::string highlightedColor = "\033[1;43m";  // Yellow background
    std::string defaultColor = "\033[1;37m";      // White text
    std::string resetColor = "\033[0m";           // Reset to default

    std::cout << (highlighted == 1 ? highlightedColor : defaultColor) << "1. Натуральные числа (N)" << resetColor << '\n';
    std::cout << (highlighted == 2 ? highlightedColor : defaultColor) << "2. Целые числа (Z)" << resetColor << '\n';
    std::cout << (highlighted == 3 ? highlightedColor : defaultColor) << "3. Рациональные числа (R)" << resetColor << '\n';
    std::cout << (highlighted == 4 ? highlightedColor : defaultColor) << "4. Многочлены (P)" << resetColor << '\n';
    std::cout << (highlighted == 5 ? highlightedColor : "\033[1;31m") << "5. Выход" << resetColor << '\n';  // Red for "Выход"
}

void Cli::printNaturalFuncMenu(size_t highlighted) {
    std::string highlightedColor = "\033[1;43m";
    std::string defaultColor = "\033[1;37m";
    std::string resetColor = "\033[0m";

    std::cout << (highlighted == 1 ? highlightedColor : defaultColor) << "1. Сравнение натуральных чисел" << resetColor << '\n';        // White or Yellow
    std::cout << (highlighted == 2 ? highlightedColor : defaultColor) << "2. Проверка на ноль" << resetColor << '\n';                   // White or Yellow
    std::cout << (highlighted == 3 ? highlightedColor : defaultColor) << "3. Добавление 1 к натуральному числу" << resetColor << '\n';  // White or Yellow
    std::cout << (highlighted == 4 ? highlightedColor : defaultColor) << "4. Сложение натуральных чисел" << resetColor << '\n';         // White or Yellow
    std::cout << (highlighted == 5 ? highlightedColor : defaultColor) << "5. Вычитание из первого большего натурального числа второго меньшего или равного"
              << resetColor << '\n';                                                                                                        // White or Yellow
    std::cout << (highlighted == 6 ? highlightedColor : defaultColor) << "6. Умножение натурального числа на цифру" << resetColor << '\n';  // White or Yellow
    std::cout << (highlighted == 7 ? highlightedColor : defaultColor) << "7. Умножение натурального числа на 10^k" << resetColor << '\n';   // White or Yellow
    std::cout << (highlighted == 8 ? highlightedColor : defaultColor) << "8. Умножение натуральных чисел" << resetColor << '\n';            // White or Yellow
    std::cout << (highlighted == 9 ? highlightedColor : defaultColor)
              << "9. Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом" << resetColor
              << '\n';  // White or Yellow
    std::cout << (highlighted == 10 ? highlightedColor : defaultColor)
              << "10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k" << resetColor << '\n';  // White or Yellow
    std::cout << (highlighted == 11 ? highlightedColor : defaultColor) << "11. Неполное частное от деления первого натурального числа на второе с остатком"
              << resetColor << '\n';  // White or Yellow
    std::cout << (highlighted == 12 ? highlightedColor : defaultColor) << "12. Остаток от деления первого натурального числа на второе натуральное"
              << resetColor << '\n';                                                                                          // White or Yellow
    std::cout << (highlighted == 13 ? highlightedColor : defaultColor) << "13. НОД натуральных чисел" << resetColor << '\n';  // White or Yellow
    std::cout << (highlighted == 14 ? highlightedColor : defaultColor) << "14. НОК натуральных чисел" << resetColor << '\n';  // White or Yellow
    std::cout << (highlighted == 15 ? highlightedColor : "\033[1;35m") << "15. Назад" << resetColor << '\n';                  // Magenta or Yellow
}

void Cli::naturalFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printNaturalFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        if (choice < 15 && choice > 0) {
            printNaturalFuncMenu(choice);
            moveCursor(30, 1);
            naturalFunc(static_cast<NaturalFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 15) {
            return;
        } else {
            std::cout << "Неверный ввод" << '\n';
            moveCursor(3, 1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::printIntegerFuncMenu(size_t highlighted) {
    std::string highlightedColor = "\033[1;43m";  // Yellow background
    std::string defaultColor = "\033[1;37m";      // White text
    std::string resetColor = "\033[0m";           // Reset to default

    std::cout << (highlighted == 1 ? highlightedColor : defaultColor) << "1. Абсолютная величина числа" << resetColor << '\n';
    std::cout << (highlighted == 2 ? highlightedColor : defaultColor) << "2. Определение положительности числа" << resetColor << '\n';
    std::cout << (highlighted == 3 ? highlightedColor : defaultColor) << "3. Умножение целого на (-1)" << resetColor << '\n';
    std::cout << (highlighted == 4 ? highlightedColor : defaultColor) << "4. Преобразование натурального в целое" << resetColor << '\n';
    std::cout << (highlighted == 5 ? highlightedColor : defaultColor) << "5. Преобразование целого неотрицательного в натуральное" << resetColor << '\n';
    std::cout << (highlighted == 6 ? highlightedColor : defaultColor) << "6. Сложение целых чисел" << resetColor << '\n';
    std::cout << (highlighted == 7 ? highlightedColor : defaultColor) << "7. Вычитание целых чисел" << resetColor << '\n';
    std::cout << (highlighted == 8 ? highlightedColor : defaultColor) << "8. Умножение целых чисел" << resetColor << '\n';
    std::cout << (highlighted == 9 ? highlightedColor : defaultColor) << "9. Деление целого на целое" << resetColor << '\n';
    std::cout << (highlighted == 10 ? highlightedColor : defaultColor) << "10. Остаток от деления целого на целое" << resetColor << '\n';
    std::cout << (highlighted == 11 ? highlightedColor : "\033[1;35m") << "11. Назад" << resetColor << '\n';
}

void Cli::integerFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printIntegerFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        if (choice < 11 && choice > 0) {
            printIntegerFuncMenu(choice);
            moveCursor(30, 1);
            integerFunc(static_cast<IntegerFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 11) {
            return;
        } else {
            std::cout << "Неверный ввод" << '\n';
            moveCursor(3, 1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void Cli::printRationalFuncMenu(size_t highlighted) {
    std::string highlightedColor = "\033[1;43m";  // Yellow background
    std::string defaultColor = "\033[1;37m";      // White text
    std::string resetColor = "\033[0m";           // Reset to default

    std::cout << (highlighted == 1 ? highlightedColor : defaultColor) << "1. Сокращение дроби" << resetColor << '\n';
    std::cout << (highlighted == 2 ? highlightedColor : defaultColor) << "2. Проверка сокращенного дробного на целое" << resetColor << '\n';
    std::cout << (highlighted == 3 ? highlightedColor : defaultColor) << "3. Преобразование целого в дробное" << resetColor << '\n';
    std::cout << (highlighted == 4 ? highlightedColor : defaultColor) << "4. Преобразование сокращенного дробного в целое" << resetColor << '\n';
    std::cout << (highlighted == 5 ? highlightedColor : defaultColor) << "5. Сложение дробей" << resetColor << '\n';
    std::cout << (highlighted == 6 ? highlightedColor : defaultColor) << "6. Вычитание дробей" << resetColor << '\n';
    std::cout << (highlighted == 7 ? highlightedColor : defaultColor) << "7. Умножение дробей" << resetColor << '\n';
    std::cout << (highlighted == 8 ? highlightedColor : defaultColor) << "8. Деление дробей" << resetColor << '\n';
    std::cout << (highlighted == 9 ? highlightedColor : "\033[1;35m") << "9. Назад" << resetColor << '\n';  // Magenta for "Назад"
}

void Cli::rationalFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printRationalFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        if (choice < 9 && choice > 0) {
            printRationalFuncMenu(choice);
            moveCursor(30, 1);
            rationalFunc(static_cast<RationalFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 9) {
            return;
        } else {
            std::cout << "Неверный ввод" << '\n';
            moveCursor(3, 1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::printPolynomialFuncMenu(size_t highlighted) {
    std::string highlightedColor = "\033[1;43m";  // Yellow background
    std::string defaultColor = "\033[1;37m";      // White text
    std::string resetColor = "\033[0m";           // Reset to default

    std::cout << (highlighted == 1 ? highlightedColor : defaultColor) << "1. Сложение многочленов" << resetColor << '\n';
    std::cout << (highlighted == 2 ? highlightedColor : defaultColor) << "2. Вычитание многочленов" << resetColor << '\n';
    std::cout << (highlighted == 3 ? highlightedColor : defaultColor) << "3. Умножение многочлена на рациональное число" << resetColor << '\n';
    std::cout << (highlighted == 4 ? highlightedColor : defaultColor) << "4. Умножение многочлена на x^k" << resetColor << '\n';
    std::cout << (highlighted == 5 ? highlightedColor : defaultColor) << "5. Старший коэффициент многочлена" << resetColor << '\n';
    std::cout << (highlighted == 6 ? highlightedColor : defaultColor) << "6. Степень многочлена" << resetColor << '\n';
    std::cout << (highlighted == 7 ? highlightedColor : defaultColor) << "7. Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей"
              << resetColor << '\n';
    std::cout << (highlighted == 8 ? highlightedColor : defaultColor) << "8. Умножение многочленов" << resetColor << '\n';
    std::cout << (highlighted == 9 ? highlightedColor : defaultColor) << "9. Частное от деления многочлена на многочлен при делении с остатком" << resetColor
              << '\n';
    std::cout << (highlighted == 10 ? highlightedColor : defaultColor) << "10. Остаток от деления многочлена на многочлен при делении с остатком" << resetColor
              << '\n';
    std::cout << (highlighted == 11 ? highlightedColor : defaultColor) << "11. НОД многочленов" << resetColor << '\n';
    std::cout << (highlighted == 12 ? highlightedColor : defaultColor) << "12. Производная многочлена" << resetColor << '\n';
    std::cout << (highlighted == 13 ? highlightedColor : defaultColor) << "13. Преобразование многочлена — кратные корни в простые" << resetColor << '\n';
    std::cout << (highlighted == 14 ? highlightedColor : "\033[1;35m") << "14. Назад" << resetColor << '\n';  // Magenta for "Назад"
}

void Cli::polynomialFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printPolynomialFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        if (choice < 14 && choice > 0) {
            printPolynomialFuncMenu(choice);
            moveCursor(30, 1);
            polynomialFunc(static_cast<PolynomialFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 14) {
            return;
        } else {
            std::cout << "Неверный ввод" << '\n';
            moveCursor(3, 1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::naturalFunc(NaturalFunctions func) {
    try {
        switch (func) {
            case NaturalFunctions::COM_NN_D: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                std::cout << COM_NN_D(a, b) << std::endl;
                break;
            }
            case NaturalFunctions::NZER_N_B: {
                LongNatural a = inputHandler.scanLongNatural();
                // std::cout << NZER_N_B(a) << std::endl;
                break;
            }
            case NaturalFunctions::ADD_1N_N: {
                LongNatural a = inputHandler.scanLongNatural();
                // std::cout << ADD_1N_N(a).toString() << std::endl;
                break;
            }
            case NaturalFunctions::ADD_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                std::cout << ADD_NN_N(a, b).toString() << std::endl;
                break;
            }
            case NaturalFunctions::SUB_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // std::cout << SUB_NN_N(a, b).toString() << std::endl;
                break;
            }
            case NaturalFunctions::MUL_ND_N: {
                LongNatural a = inputHandler.scanLongNatural();
                uint8_t d;
                std::cin >> d;
                if (std::cin.fail() || d > 9) {
                    std::cout << "Неверный ввод" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                // std::cout << MUL_ND_N(a, d).toString() << std::endl;
                break;
            }
            case NaturalFunctions::MUL_Nk_N: {
                LongNatural a = inputHandler.scanLongNatural();
                size_t k;
                std::cin >> k;
                if (std::cin.fail()) {
                    std::cout << "Неверный ввод" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                // std::cout << MUL_Nk_N(a, k).toString() << std::endl;
                break;
            }
            case NaturalFunctions::MUL_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // std::cout << MUL_NN_N(a, b).toString() << std::endl;
                break;
            }
            case NaturalFunctions::SUB_NDN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                uint8_t d;
                std::cin >> d;
                if (std::cin.fail() || d > 9) {
                    std::cout << "Неверный ввод" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                // std::cout << SUB_NDN_N(a, b, d).toString() << std::endl;
                break;
            }
            case NaturalFunctions::DIV_NN_Dk: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                size_t k;
                std::cin >> k;
                if (std::cin.fail()) {
                    std::cout << "Неверный ввод" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                // std::cout << DIV_NN_Dk(a, b, k).toString() << std::endl;
                break;
            }
            case NaturalFunctions::DIV_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // std::cout << DIV_NN_N(a, b).toString() << std::endl;
                break;
            }
            case NaturalFunctions::MOD_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // std::cout << MOD_NN_N(a, b).toString() << std::endl;
                break;
            }
            case NaturalFunctions::GCF_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // std::cout << GCF_NN_N(a, b).toString() << std::endl;
                break;
            }
            case NaturalFunctions::LCM_NN_N: {
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // std::cout << LCM_NN_N(a, b).toString() << std::endl;
                break;
            }
            default:
                std::cout << "Неверный ввод" << '\n';
                break;
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Неверный ввод" << '\n';
    }
}

void Cli::integerFunc(IntegerFunctions func) {
    try {
        switch (func) {
            case IntegerFunctions::ABS_Z_N: {
                LongInteger a = inputHandler.scanLongInteger();
                // std::cout << ABS_Z_N(a).toString() << std::endl;
                break;
            }
            case IntegerFunctions::POZ_Z_D: {
                LongInteger a = inputHandler.scanLongInteger();
                // std::cout << POZ_Z_D(a) << std::endl;
                break;
            }
            case IntegerFunctions::MUL_ZM_Z: {
                LongInteger a = inputHandler.scanLongInteger();
                // std::cout << MUL_ZM_Z(a).toString() << std::endl;
                break;
            }
            case IntegerFunctions::TRANS_N_Z: {
                LongNatural a = inputHandler.scanLongNatural();
                // std::cout << TRANS_N_Z(a).toString() << std::endl;
                break;
            }
            case IntegerFunctions::TRANS_Z_N: {
                LongInteger a = inputHandler.scanLongInteger();
                // std::cout << TRANS_Z_N(a).toString() << std::endl;
                break;
            }
            case IntegerFunctions::ADD_ZZ_Z: {
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // std::cout << ADD_ZZ_Z(a, b).toString() << std::endl;
                break;
            }
            case IntegerFunctions::SUB_ZZ_Z: {
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // std::cout << SUB_ZZ_Z(a, b).toString() << std::endl;
                break;
            }
            case IntegerFunctions::MUL_ZZ_Z: {
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // std::cout << MUL_ZZ_Z(a, b).toString() << std::endl;
                break;
            }
            case IntegerFunctions::DIV_ZZ_Z: {
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // std::cout << DIV_ZZ_Z(a, b).toString() << std::endl;
                break;
            }
            case IntegerFunctions::MOD_ZZ_Z: {
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // std::cout << MOD_ZZ_Z(a, b).toString() << std::endl;
                break;
            }
            default:
                std::cout << "Неверный ввод" << '\n';
                break;
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Неверный ввод" << '\n';
    }
}

void Cli::rationalFunc(RationalFunctions func) {
    try {
        switch (func) {
            case RationalFunctions::RED_Q_Q: {
                LongRational a = inputHandler.scanLongRational();
                // std::cout << RED_Q_Q(a).toString() << std::endl;
                break;
            }
            case RationalFunctions::INT_Q_B: {
                LongRational a = inputHandler.scanLongRational();
                // std::cout << INT_Q_B(a) << std::endl;
                break;
            }
            case RationalFunctions::TRANS_Z_Q: {
                LongInteger a = inputHandler.scanLongInteger();
                // std::cout << TRANS_Z_Q(a).toString() << std::endl;
                break;
            }
            case RationalFunctions::TRANS_Q_Z: {
                LongRational a = inputHandler.scanLongRational();
                // std::cout << TRANS_Q_Z(a).toString() << std::endl;
                break;
            }
            case RationalFunctions::ADD_QQ_Q: {
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // std::cout << ADD_QQ_Q(a, b).toString() << std::endl;
                break;
            }
            case RationalFunctions::SUB_QQ_Q: {
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // std::cout << SUB_QQ_Q(a, b).toString() << std::endl;
                break;
            }
            case RationalFunctions::MUL_QQ_Q: {
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // std::cout << MUL_QQ_Q(a, b).toString() << std::endl;
                break;
            }
            case RationalFunctions::DIV_QQ_Q: {
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // std::cout << DIV_QQ_Q(a, b).toString() << std::endl;
                break;
            }
            default:
                std::cout << "Неверный ввод" << '\n';
                break;
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Неверный ввод" << '\n';
    }
}

void Cli::polynomialFunc(PolynomialFunctions func) {
    try {
        switch (func) {
            case PolynomialFunctions::ADD_PP_P: {
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // std::cout << ADD_PP_P(a, b).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::SUB_PP_P: {
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // std::cout << SUB_PP_P(a, b).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::MUL_PQ_P: {
                Polynomial a = inputHandler.scanPolynomial();
                LongRational q = inputHandler.scanLongRational();
                // std::cout << MUL_PQ_P(a, q).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::MUL_Pxk_P: {
                Polynomial a = inputHandler.scanPolynomial();
                size_t k;
                std::cin >> k;
                if (std::cin.fail()) {
                    std::cout << "Неверный ввод" << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                // std::cout << MUL_Pxk_P(a, k).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::LED_P_Q: {
                Polynomial a = inputHandler.scanPolynomial();
                // std::cout << LED_P_Q(a).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::DEG_P_N: {
                Polynomial a = inputHandler.scanPolynomial();
                // std::cout << DEG_P_N(a) << std::endl;
                break;
            }
            case PolynomialFunctions::FAC_P_Q: {
                Polynomial a = inputHandler.scanPolynomial();
                // std::cout << FAC_P_Q(a).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::MUL_PP_P: {
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // std::cout << MUL_PP_P(a, b).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::DIV_PP_P: {
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // std::cout << DIV_PP_P(a, b).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::MOD_PP_P: {
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // std::cout << MOD_PP_P(a, b).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::GCF_PP_P: {
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // std::cout << GCF_PP_P(a, b).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::DER_P_P: {
                Polynomial a = inputHandler.scanPolynomial();
                // std::cout << DER_P_P(a).toString() << std::endl;
                break;
            }
            case PolynomialFunctions::NMR_P_P: {
                Polynomial a = inputHandler.scanPolynomial();
                // std::cout << NMR_P_P(a).toString() << std::endl;
                break;
            }
            default:
                std::cout << "Неверный ввод" << '\n';
                break;
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Неверный ввод" << '\n';
    }
}