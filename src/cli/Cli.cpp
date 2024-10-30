#include "cli/Cli.hpp"

#include <initializer_list>
#include <iostream>
#include <limits>
#include <string>
#include <utility>

#include "N/ADD_1N_N.hpp"
#include "N/ADD_NN_N.hpp"
#include "N/COM_NN_D.hpp"
#include "N/DIV_NN_Dk.hpp"
#include "N/DIV_NN_N.hpp"
#include "N/GCF_NN_N.hpp"
#include "N/MOD_NN_N.hpp"
#include "N/MUL_ND_N.hpp"
#include "N/MUL_NN_N.hpp"
#include "N/MUL_Nk_N.hpp"
#include "N/NZER_N_B.hpp"
#include "N/SUB_NDN_N.hpp"
#include "N/SUB_NN_N.hpp"
#include "Q/INT_Q_B.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Q/TRANS_Q_Z.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/ADD_ZZ_Z.hpp"
#include "Z/DIV_ZZ_Z.hpp"
#include "Z/MUL_ZM_Z.hpp"
#include "Z/MUL_ZZ_Z.hpp"
#include "Z/POZ_Z_D.hpp"
#include "Z/TRANS_N_Z.hpp"
#include "Z/TRANS_Z_N.hpp"

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
                printError("Неверный ввод");
                moveCursor(3, 1);

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::printHistory() {
    return;  // WIP
    std::pair<int, int> lastPos = cursorPos;
    size_t row = 1;
    moveCursor(row, 150);
    std::cout << color.white_bold << "История:" << color.reset;
    row += 2;
    moveCursor(row, 150);
    for (const auto& element : history) {
        if (element.command.empty()) {
            break;
        }
        std::cout << color.white << element.command << color.reset;
        row++;
        moveCursor(row, 150);
        for (const auto& arg : element.args) {
            if (arg.empty()) {
                break;
            }
            std::cout << arg << ' ';
        }
        row++;
        moveCursor(row, 150);
        std::cout << color.underline << "-> " << element.result << color.reset;
        row += 2;
        moveCursor(row, 150);
    }
    moveCursor(lastPos.first, lastPos.second);
}

void Cli::updateHistory(const std::string& command, std::initializer_list<std::string> args, const std::string& result) {
    // Shift history entries
    for (size_t i = 4; i > 0; i--) {
        history[i] = history[i - 1];
    }

    // Add the new entry at the beginning
    history[0].command = command;
    history[0].result = result;

    // Copy args to the fixed-size array
    size_t index = 0;
    for (const auto& arg : args) {
        if (index >= 10) {
            throw std::out_of_range("Too many arguments provided");
        }
        history[0].args[index++] = arg;
    }

    // Clear remaining elements in the args array
    for (; index < 10; ++index) {
        history[0].args[index].clear();
    }
}

void Cli::printError(const std::string& message) {
    std::pair<int, int> lastPos = cursorPos;
    moveCursor(20, 1);
    std::cout << color.red << message << color.reset << '\n';
    moveCursor(lastPos.first, lastPos.second);
}

void Cli::printMenu(size_t highlighted) {
    moveCursor(1, 1);
    std::cout << color.yellow << "Калькулятор блин:" << color.reset << '\n';
    std::cout << '\n';
    std::cout << (highlighted == 1 ? color.highlighted : color.yellow) << "1. Натуральные числа (N)" << color.reset << '\n';
    std::cout << (highlighted == 2 ? color.highlighted : color.yellow) << "2. Целые числа (Z)" << color.reset << '\n';
    std::cout << (highlighted == 3 ? color.highlighted : color.yellow) << "3. Рациональные числа (R)" << color.reset << '\n';
    std::cout << (highlighted == 4 ? color.highlighted : color.yellow) << "4. Многочлены (P)" << color.reset << '\n';
    std::cout << (highlighted == 5 ? color.highlighted : color.red_bold) << "5. Выход" << color.reset << '\n';  // Red for "Выход"
}

void Cli::printNaturalFuncMenu(size_t highlighted) {
    moveCursor(1, 1);
    std::cout << (highlighted == 1 ? color.highlighted : color.yellow) << "1. Сравнение натуральных чисел" << color.reset << '\n';        // White or Yellow
    std::cout << (highlighted == 2 ? color.highlighted : color.yellow) << "2. Проверка на ноль" << color.reset << '\n';                   // White or Yellow
    std::cout << (highlighted == 3 ? color.highlighted : color.yellow) << "3. Добавление 1 к натуральному числу" << color.reset << '\n';  // White or Yellow
    std::cout << (highlighted == 4 ? color.highlighted : color.yellow) << "4. Сложение натуральных чисел" << color.reset << '\n';         // White or Yellow
    std::cout << (highlighted == 5 ? color.highlighted : color.yellow) << "5. Вычитание из первого большего натурального числа второго меньшего или равного"
              << color.reset << '\n';                                                                                                         // White or Yellow
    std::cout << (highlighted == 6 ? color.highlighted : color.yellow) << "6. Умножение натурального числа на цифру" << color.reset << '\n';  // White or Yellow
    std::cout << (highlighted == 7 ? color.highlighted : color.yellow) << "7. Умножение натурального числа на 10^k" << color.reset << '\n';   // White or Yellow
    std::cout << (highlighted == 8 ? color.highlighted : color.yellow) << "8. Умножение натуральных чисел" << color.reset << '\n';            // White or Yellow
    std::cout << (highlighted == 9 ? color.highlighted : color.yellow)
              << "9. Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом" << color.reset
              << '\n';  // White or Yellow
    std::cout << (highlighted == 10 ? color.highlighted : color.yellow)
              << "10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k" << color.reset << '\n';  // White or Yellow
    std::cout << (highlighted == 11 ? color.highlighted : color.yellow) << "11. Неполное частное от деления первого натурального числа на второе с остатком"
              << color.reset << '\n';  // White or Yellow
    std::cout << (highlighted == 12 ? color.highlighted : color.yellow) << "12. Остаток от деления первого натурального числа на второе натуральное"
              << color.reset << '\n';                                                                                           // White or Yellow
    std::cout << (highlighted == 13 ? color.highlighted : color.yellow) << "13. НОД натуральных чисел" << color.reset << '\n';  // White or Yellow
    std::cout << (highlighted == 14 ? color.highlighted : color.yellow) << "14. НОК натуральных чисел" << color.reset << '\n';  // White or Yellow
    std::cout << (highlighted == 15 ? color.highlighted : color.magenta_bold) << "15. Назад" << color.reset << '\n';            // Magenta or Yellow
}

void Cli::naturalFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printHistory();
        printNaturalFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        printHistory();
        if (choice < 15 && choice > 0) {
            printNaturalFuncMenu(choice);
            moveCursor(30, 1);
            naturalFunc(static_cast<NaturalFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 15) {
            return;
        } else {
            printError("Неверный ввод");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::printIntegerFuncMenu(size_t highlighted) {
    moveCursor(1, 1);
    std::cout << (highlighted == 1 ? color.highlighted : color.yellow) << "1. Абсолютная величина числа" << color.reset << '\n';
    std::cout << (highlighted == 2 ? color.highlighted : color.yellow) << "2. Определение положительности числа" << color.reset << '\n';
    std::cout << (highlighted == 3 ? color.highlighted : color.yellow) << "3. Умножение целого на (-1)" << color.reset << '\n';
    std::cout << (highlighted == 4 ? color.highlighted : color.yellow) << "4. Преобразование натурального в целое" << color.reset << '\n';
    std::cout << (highlighted == 5 ? color.highlighted : color.yellow) << "5. Преобразование целого неотрицательного в натуральное" << color.reset << '\n';
    std::cout << (highlighted == 6 ? color.highlighted : color.yellow) << "6. Сложение целых чисел" << color.reset << '\n';
    std::cout << (highlighted == 7 ? color.highlighted : color.yellow) << "7. Вычитание целых чисел" << color.reset << '\n';
    std::cout << (highlighted == 8 ? color.highlighted : color.yellow) << "8. Умножение целых чисел" << color.reset << '\n';
    std::cout << (highlighted == 9 ? color.highlighted : color.yellow) << "9. Деление целого на целое" << color.reset << '\n';
    std::cout << (highlighted == 10 ? color.highlighted : color.yellow) << "10. Остаток от деления целого на целое" << color.reset << '\n';
    std::cout << (highlighted == 11 ? color.highlighted : color.magenta_bold) << "11. Назад" << color.reset << '\n';
}

void Cli::integerFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printHistory();
        printIntegerFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        printHistory();
        if (choice < 11 && choice > 0) {
            printIntegerFuncMenu(choice);
            moveCursor(30, 1);
            integerFunc(static_cast<IntegerFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 11) {
            return;
        } else {
            printError("Неверный ввод");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void Cli::printRationalFuncMenu(size_t highlighted) {
    moveCursor(1, 1);
    std::cout << (highlighted == 1 ? color.highlighted : color.yellow) << "1. Сокращение дроби" << color.reset << '\n';
    std::cout << (highlighted == 2 ? color.highlighted : color.yellow) << "2. Проверка сокращенного дробного на целое" << color.reset << '\n';
    std::cout << (highlighted == 3 ? color.highlighted : color.yellow) << "3. Преобразование целого в дробное" << color.reset << '\n';
    std::cout << (highlighted == 4 ? color.highlighted : color.yellow) << "4. Преобразование сокращенного дробного в целое" << color.reset << '\n';
    std::cout << (highlighted == 5 ? color.highlighted : color.yellow) << "5. Сложение дробей" << color.reset << '\n';
    std::cout << (highlighted == 6 ? color.highlighted : color.yellow) << "6. Вычитание дробей" << color.reset << '\n';
    std::cout << (highlighted == 7 ? color.highlighted : color.yellow) << "7. Умножение дробей" << color.reset << '\n';
    std::cout << (highlighted == 8 ? color.highlighted : color.yellow) << "8. Деление дробей" << color.reset << '\n';
    std::cout << (highlighted == 9 ? color.highlighted : color.magenta_bold) << "9. Назад" << color.reset << '\n';  // Magenta for "Назад"
}

void Cli::rationalFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printHistory();
        printRationalFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        printHistory();
        if (choice < 9 && choice > 0) {
            printRationalFuncMenu(choice);
            moveCursor(30, 1);
            rationalFunc(static_cast<RationalFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 9) {
            return;
        } else {
            printError("Неверный ввод");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::printPolynomialFuncMenu(size_t highlighted) {
    moveCursor(1, 1);
    std::cout << (highlighted == 1 ? color.highlighted : color.yellow) << "1. Сложение многочленов" << color.reset << '\n';
    std::cout << (highlighted == 2 ? color.highlighted : color.yellow) << "2. Вычитание многочленов" << color.reset << '\n';
    std::cout << (highlighted == 3 ? color.highlighted : color.yellow) << "3. Умножение многочлена на рациональное число" << color.reset << '\n';
    std::cout << (highlighted == 4 ? color.highlighted : color.yellow) << "4. Умножение многочлена на x^k" << color.reset << '\n';
    std::cout << (highlighted == 5 ? color.highlighted : color.yellow) << "5. Старший коэффициент многочлена" << color.reset << '\n';
    std::cout << (highlighted == 6 ? color.highlighted : color.yellow) << "6. Степень многочлена" << color.reset << '\n';
    std::cout << (highlighted == 7 ? color.highlighted : color.yellow) << "7. Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей"
              << color.reset << '\n';
    std::cout << (highlighted == 8 ? color.highlighted : color.yellow) << "8. Умножение многочленов" << color.reset << '\n';
    std::cout << (highlighted == 9 ? color.highlighted : color.yellow) << "9. Частное от деления многочлена на многочлен при делении с остатком" << color.reset
              << '\n';
    std::cout << (highlighted == 10 ? color.highlighted : color.yellow) << "10. Остаток от деления многочлена на многочлен при делении с остатком"
              << color.reset << '\n';
    std::cout << (highlighted == 11 ? color.highlighted : color.yellow) << "11. НОД многочленов" << color.reset << '\n';
    std::cout << (highlighted == 12 ? color.highlighted : color.yellow) << "12. Производная многочлена" << color.reset << '\n';
    std::cout << (highlighted == 13 ? color.highlighted : color.yellow) << "13. Преобразование многочлена — кратные корни в простые" << color.reset << '\n';
    std::cout << (highlighted == 14 ? color.highlighted : color.magenta_bold) << "14. Назад" << color.reset << '\n';  // Magenta for "Назад"
}

void Cli::polynomialFuncMenu() {
    int choice;
    clearScreen();
    while (true) {
        printHistory();
        printPolynomialFuncMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen();
        printHistory();
        if (choice < 14 && choice > 0) {
            printPolynomialFuncMenu(choice);
            moveCursor(30, 1);
            polynomialFunc(static_cast<PolynomialFunctions>(choice - 1));
            moveCursor(1, 1);
        } else if (choice == 14) {
            return;
        } else {
            printError("Неверный ввод");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Cli::naturalFunc(NaturalFunctions func) {
    try {
        switch (func) {
            case NaturalFunctions::COM_NN_D: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = COM_NN_D(a, b);
                std::cout << "Результат " << result << std::endl;
                updateHistory("COM_NN_D", {a.toString(), b.toString()}, std::to_string(result));
                break;
            }
            case NaturalFunctions::NZER_N_B: {
                std::cout << "Введите натуральное число: ";
                LongNatural a = inputHandler.scanLongNatural();
                auto result = NZER_N_B(a);
                std::cout << "Результат " << result << std::endl;
                updateHistory("NZER_N_B", {a.toString()}, std::to_string(result));
                break;
            }
            case NaturalFunctions::ADD_1N_N: {
                std::cout << "Введите натуральное число: ";
                LongNatural a = inputHandler.scanLongNatural();
                auto result = ADD_1N_N(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("ADD_1N_N", {a.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::ADD_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = ADD_NN_N(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("ADD_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::SUB_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = SUB_NN_N(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("SUB_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::MUL_ND_N: {
                std::cout << "Введите натуральное число: ";
                LongNatural a = inputHandler.scanLongNatural();
                std::cout << "Введите цифру d: ";
                int d;
                std::cin >> d;
                if (std::cin.fail() || d > 9) {
                    printError("Неверный ввод");
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                auto result = MUL_ND_N(a, d);
                std::cout << "Результат" << result.toString() << std::endl;
                updateHistory("MUL_ND_N", {a.toString(), std::to_string(d)}, result.toString());
                break;
            }
            case NaturalFunctions::MUL_Nk_N: {
                std::cout << "Введите натуральное число: ";
                LongNatural a = inputHandler.scanLongNatural();
                size_t k;
                std::cout << "Введите k: ";
                std::cin >> k;
                if (std::cin.fail()) {
                    printError("Неверный ввод");
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                auto result = MUL_Nk_N(a, k);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("MUL_Nk_N", {a.toString(), std::to_string(k)}, result.toString());
                break;
            }
            case NaturalFunctions::MUL_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = MUL_NN_N(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("MUL_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::SUB_NDN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                int d;
                std::cout << "Введите цифру d: ";
                std::cin >> d;
                if (std::cin.fail() || d > 9) {
                    printError("Неверный ввод");
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                auto result = SUB_NDN_N(a, b, d);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("SUB_NDN_N", {a.toString(), b.toString(), std::to_string(d)}, result.toString());
                break;
            }
            case NaturalFunctions::DIV_NN_Dk: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = DIV_NN_Dk(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("DIV_NN_Dk", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::DIV_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = DIV_NN_N(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("DIV_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::MOD_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = MOD_NN_N(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("MOD_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::GCF_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                auto result = GCF_NN_N(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("GCF_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case NaturalFunctions::LCM_NN_N: {
                std::cout << "Введите два натуральных числа через пробел: ";
                LongNatural a = inputHandler.scanLongNatural();
                LongNatural b = inputHandler.scanLongNatural();
                // auto result = LCM_NN_N(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("LCM_NN_N", {a.toString(), b.toString()}, result.toString());
                break;
            }
            default:
                printError("Неверный ввод");
                break;
        }
    } catch (std::invalid_argument& e) {
        printError("Неверный ввод");
    }
}

void Cli::integerFunc(IntegerFunctions func) {
    try {
        switch (func) {
            case IntegerFunctions::ABS_Z_N: {
                std::cout << "Введите целое число: ";
                LongInteger a = inputHandler.scanLongInteger();
                auto result = ABS_Z_N(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("ABS_Z_N", {a.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::POZ_Z_D: {
                std::cout << "Введите целое число: ";
                LongInteger a = inputHandler.scanLongInteger();
                auto result = POZ_Z_D(a);
                std::cout << "Результат " << result << std::endl;
                updateHistory("POZ_Z_D", {a.toString()}, std::to_string(result));
            }
            case IntegerFunctions::MUL_ZM_Z: {
                std::cout << "Введите целое число: ";
                LongInteger a = inputHandler.scanLongInteger();
                auto result = MUL_ZM_Z(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("MUL_ZM_Z", {a.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::TRANS_N_Z: {
                std::cout << "Введите натуральное число: ";
                LongNatural a = inputHandler.scanLongNatural();
                auto result = TRANS_N_Z(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("TRANS_N_Z", {a.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::TRANS_Z_N: {
                std::cout << "Введите целое число: ";
                LongInteger a = inputHandler.scanLongInteger();
                auto result = TRANS_Z_N(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("TRANS_Z_N", {a.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::ADD_ZZ_Z: {
                std::cout << "Введите два целых числа через пробел: ";
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                auto result = ADD_ZZ_Z(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("ADD_ZZ_Z", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::SUB_ZZ_Z: {
                std::cout << "Введите два целых числа через пробел: ";
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // auto result = SUB_ZZ_Z(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("SUB_ZZ_Z", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::MUL_ZZ_Z: {
                std::cout << "Введите два целых числа через пробел: ";
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                auto result = MUL_ZZ_Z(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("MUL_ZZ_Z", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::DIV_ZZ_Z: {
                std::cout << "Введите два целых числа через пробел: ";
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                auto result = DIV_ZZ_Z(a, b);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("DIV_ZZ_Z", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case IntegerFunctions::MOD_ZZ_Z: {
                std::cout << "Введите два целых числа через пробел: ";
                LongInteger a = inputHandler.scanLongInteger();
                LongInteger b = inputHandler.scanLongInteger();
                // auto result = MOD_ZZ_Z(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("MOD_ZZ_Z", {a.toString(), b.toString()}, result.toString());
                break;
            }
            default:
                printError("Неверный ввод");
                break;
        }
    } catch (std::invalid_argument& e) {
        printError("Неверный ввод");
    }
}

void Cli::rationalFunc(RationalFunctions func) {
    try {
        switch (func) {
            case RationalFunctions::RED_Q_Q: {
                std::cout << "Введите рациональное число\n";
                LongRational a = inputHandler.scanLongRational();
                auto result = RED_Q_Q(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("RED_Q_Q", {a.toString()}, result.toString());
                break;
            }
            case RationalFunctions::INT_Q_B: {
                std::cout << "Введите рациональное число\n";
                LongRational a = inputHandler.scanLongRational();
                auto result = INT_Q_B(a);
                std::cout << "Результат " << result << std::endl;
                updateHistory("INT_Q_B", {a.toString()}, std::to_string(result));
                break;
            }
            case RationalFunctions::TRANS_Z_Q: {
                std::cout << "Введите целое число\n";
                LongInteger a = inputHandler.scanLongInteger();
                // auto result = TRANS_Z_Q(a);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("TRANS_Z_Q", {a.toString()}, result.toString());
                break;
            }
            case RationalFunctions::TRANS_Q_Z: {
                std::cout << "Введите рациональное число\n";
                LongRational a = inputHandler.scanLongRational();
                auto result = TRANS_Q_Z(a);
                std::cout << "Результат " << result.toString() << std::endl;
                updateHistory("TRANS_Q_Z", {a.toString()}, result.toString());
                break;
            }
            case RationalFunctions::ADD_QQ_Q: {
                std::cout << "Введите два рациональных числа\n";
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // auto result = ADD_QQ_Q(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("ADD_QQ_Q", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case RationalFunctions::SUB_QQ_Q: {
                std::cout << "Введите два рациональных числа\n";
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // auto result = SUB_QQ_Q(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("SUB_QQ_Q", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case RationalFunctions::MUL_QQ_Q: {
                std::cout << "Введите два рациональных числа\n";
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // auto result = MUL_QQ_Q(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("MUL_QQ_Q", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case RationalFunctions::DIV_QQ_Q: {
                std::cout << "Введите два рациональных числа\n";
                LongRational a = inputHandler.scanLongRational();
                LongRational b = inputHandler.scanLongRational();
                // auto result = DIV_QQ_Q(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("DIV_QQ_Q", {a.toString(), b.toString()}, result.toString());
                break;
            }
            default:
                printError("Неверный ввод");
                break;
        }
    } catch (std::invalid_argument& e) {
        printError("Неверный ввод");
    }
}

void Cli::polynomialFunc(PolynomialFunctions func) {
    try {
        switch (func) {
            case PolynomialFunctions::ADD_PP_P: {
                std::cout << "Задайте два многочлена\n";
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // auto result = ADD_PP_P(a, b);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("ADD_PP_P", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::SUB_PP_P: {
                std::cout << "Задайте два многочлена\n";
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // auto result = SUB_PP_P(a, b);
                // std::cout << "Результат " <<  result.toString() << std::endl;
                // updateHistory("SUB_PP_P", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::MUL_PQ_P: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                std::cout << "Введите рациональное число\n";
                LongRational q = inputHandler.scanLongRational();
                // auto result = MUL_PQ_P(a, q);
                // std::cout << "Результат " <<  result.toString() << std::endl;
                // updateHistory("MUL_PQ_P", {a.toString(), q.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::MUL_Pxk_P: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                size_t k;
                std::cout << "Введите k: ";
                std::cin >> k;
                if (std::cin.fail()) {
                    printError("Неверный ввод");
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                // auto result = MUL_Pxk_P(a, k);
                // std::cout << "Результат " << result.toString() << std::endl;
                // updateHistory("MUL_Pxk_P", {a.toString(), std::to_string(k)}, result.toString());
                break;
            }
            case PolynomialFunctions::LED_P_Q: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                // auto result = LED_P_Q(a);
                // std::cout << "Результат " <<  result.toString() << std::endl;
                // updateHistory("LED_P_Q", {a.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::DEG_P_N: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                // auto result = DEG_P_N(a);
                // std::cout << "Результат " <<  result.toString() << std::endl;
                // updateHistory("DEG_P_N", {a.toString()}, std::to_string(result));
                break;
            }
            case PolynomialFunctions::FAC_P_Q: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                // auto result = FAC_P_Q(a);
                // std::cout << "Результат " <<  result.toString() << std::endl;
                // updateHistory("FAC_P_Q", {a.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::MUL_PP_P: {
                std::cout << "Задайте два многочлена\n";
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // auto result = MUL_PP_P(a, b);
                // std::cout << "Результат " << < result.toString() << std::endl;
                // updateHistory("MUL_PP_P", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::DIV_PP_P: {
                std::cout << "Задайте два многочлена\n";
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // auto result = DIV_PP_P(a, b);
                // std::cout << result.toString() << std::endl;
                // updateHistory("DIV_PP_P", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::MOD_PP_P: {
                std::cout << "Задайте два многочлена\n";
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // auto result = MOD_PP_P(a, b);
                // std::cout << result.toString() << std::endl;
                // updateHistory("MOD_PP_P", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::GCF_PP_P: {
                std::cout << "Задайте два многочлена\n";
                Polynomial a = inputHandler.scanPolynomial();
                Polynomial b = inputHandler.scanPolynomial();
                // auto result = GCF_PP_P(a, b);
                // std::cout << result.toString() << std::endl;
                // updateHistory("GCF_PP_P", {a.toString(), b.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::DER_P_P: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                // auto result = DER_P_P(a);
                // std::cout << result.toString() << std::endl;
                // updateHistory("DER_P_P", {a.toString()}, result.toString());
                break;
            }
            case PolynomialFunctions::NMR_P_P: {
                std::cout << "Задайте многочлен\n";
                Polynomial a = inputHandler.scanPolynomial();
                // auto result = NMR_P_P(a);
                // std::cout << result.toString() << std::endl;
                // updateHistory("NMR_P_P", {a.toString()}, result.toString());
                break;
            }
            default:
                printError("Неверный ввод");
                break;
        }
    } catch (std::invalid_argument& e) {
        printError("Неверный ввод");
    }
}