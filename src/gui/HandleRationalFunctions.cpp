#include "gui/HandleRationalFunctions.hpp"

#include <future>
#include <new>
#include <stdexcept>
#include <string>

#include "N/LongNatural.hpp"
#include "Q/ADD_QQ_Q.hpp"
#include "Q/DIV_QQ_Q.hpp"
#include "Q/INT_Q_B.hpp"
#include "Q/LongRational.hpp"
#include "Q/MUL_QQ_Q.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Q/SUB_QQ_Q.hpp"
#include "Q/TRANS_Q_Z.hpp"
#include "Q/TRANS_Z_Q.hpp"
#include "Z/LongInteger.hpp"
#include "gui/ioUtils.hpp"
#include "imgui.h"

bool HandleRationalFunctions::RED_Q_Q_open = false;
bool HandleRationalFunctions::INT_Q_B_open = false;
bool HandleRationalFunctions::TRANS_Z_Q_open = false;
bool HandleRationalFunctions::TRANS_Q_Z_open = false;
bool HandleRationalFunctions::ADD_QQ_Q_open = false;
bool HandleRationalFunctions::SUB_QQ_Q_open = false;
bool HandleRationalFunctions::MUL_QQ_Q_open = false;
bool HandleRationalFunctions::DIV_QQ_Q_open = false;

void HandleRationalFunctions::showMenu(bool* p_open) {
    if (RED_Q_Q_open) show_RED_Q_Q(&RED_Q_Q_open);
    if (INT_Q_B_open) show_INT_Q_B(&INT_Q_B_open);
    if (TRANS_Q_Z_open) show_TRANS_Q_Z(&TRANS_Q_Z_open);
    if (TRANS_Z_Q_open) show_TRANS_Z_Q(&TRANS_Z_Q_open);
    if (ADD_QQ_Q_open) show_ADD_QQ_Q(&ADD_QQ_Q_open);
    if (SUB_QQ_Q_open) show_SUB_QQ_Q(&SUB_QQ_Q_open);
    if (MUL_QQ_Q_open) show_MUL_QQ_Q(&MUL_QQ_Q_open);
    if (DIV_QQ_Q_open) show_DIV_QQ_Q(&DIV_QQ_Q_open);

    if (!ImGui::Begin("Rational Functions Menu", p_open)) {
        ImGui::End();
        return;
    }

    if (ImGui::Button("1. Сокращение дроби")) {
        RED_Q_Q_open = !RED_Q_Q_open;
    }
    if (ImGui::Button("2. Проверка сокращенного дробного на целое")) {
        INT_Q_B_open = !INT_Q_B_open;
    }
    if (ImGui::Button("3. Преобразование целого в дробное")) {
        TRANS_Z_Q_open = !TRANS_Z_Q_open;
    }
    if (ImGui::Button("4. Преобразование сокращенного дробного в целое")) {
        TRANS_Q_Z_open = !TRANS_Q_Z_open;
    }
    if (ImGui::Button("5. Сложение дробей")) {
        ADD_QQ_Q_open = !ADD_QQ_Q_open;
    }
    if (ImGui::Button("6. Вычитание дробей")) {
        SUB_QQ_Q_open = !SUB_QQ_Q_open;
    }
    if (ImGui::Button("7. Умножение дробей")) {
        MUL_QQ_Q_open = !MUL_QQ_Q_open;
    }
    if (ImGui::Button("8. Деление дробей")) {
        DIV_QQ_Q_open = !DIV_QQ_Q_open;
    }

    ImGui::End();
}

void HandleRationalFunctions::show_RED_Q_Q(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: RED_Q_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите рациональное число");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction_str;
    InputTextWithResize("fraction", fraction_str);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num_str;
            std::string den_str;
            StrToFraction(fraction_str, num_str, den_str);

            LongRational a_n((LongInteger(num_str)), LongNatural(den_str));

            result_future = std::async(std::launch::async, RED_Q_Q, a_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Сокращение дроби");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_INT_Q_B(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: INT_Q_B", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите рациональное число");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction_str;
    InputTextWithResize("fraction", fraction_str);

    static std::future<bool> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num_str;
            std::string den_str;
            StrToFraction(fraction_str, num_str, den_str);
            LongRational a_n((LongInteger(num_str)), LongNatural(den_str));

            result_future = std::async(std::launch::async, INT_Q_B, a_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Проверка сокращенного дробного на целое, если рациональное число является целым, то «да», иначе «нет»");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_TRANS_Z_Q(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: TRANS_Z_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите целое число:");
    static std::string a_str;
    InputTextWithResize("num", a_str);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            LongInteger a_n(a_str);

            result_future = std::async(std::launch::async, TRANS_Z_Q, a_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Преобразование целого в дробное");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_TRANS_Q_Z(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: TRANS_Q_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите рациональное число");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction_str;
    InputTextWithResize("fraction", fraction_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num_str;
            std::string den_str;
            StrToFraction(fraction_str, num_str, den_str);
            LongRational a_n((LongInteger(num_str)), LongNatural(den_str));

            result_future = std::async(std::launch::async, TRANS_Q_Z, a_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Преобразование сокращенного дробного в целое (если знаменатель равен 1)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_ADD_QQ_Q(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: ADD_QQ_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два рациональных числа");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction1_str;
    InputTextWithResize("fraction1", fraction1_str);
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction2_str;
    InputTextWithResize("fraction2", fraction2_str);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num1_str;
            std::string den1_str;
            StrToFraction(fraction1_str, num1_str, den1_str);
            std::string num2_str;
            std::string den2_str;
            StrToFraction(fraction2_str, num2_str, den2_str);

            LongRational a_n((LongInteger(num1_str)), LongNatural(den1_str));
            LongRational b_n((LongInteger(num2_str)), LongNatural(den2_str));

            result_future = std::async(std::launch::async, ADD_QQ_Q, a_n, b_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Сложение дробей");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_SUB_QQ_Q(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: SUB_QQ_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два рациональных числа");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction1_str;
    InputTextWithResize("fraction1", fraction1_str);
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction2_str;
    InputTextWithResize("fraction2", fraction2_str);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num1_str;
            std::string den1_str;
            StrToFraction(fraction1_str, num1_str, den1_str);
            std::string num2_str;
            std::string den2_str;
            StrToFraction(fraction2_str, num2_str, den2_str);
            LongRational a_n((LongInteger(num1_str)), LongNatural(den1_str));
            LongRational b_n((LongInteger(num2_str)), LongNatural(den2_str));

            result_future = std::async(std::launch::async, SUB_QQ_Q, a_n, b_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Вычитание дробей");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_MUL_QQ_Q(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: MUL_QQ_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два рациональных числа");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction1_str;
    InputTextWithResize("fraction1", fraction1_str);
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction2_str;
    InputTextWithResize("fraction2", fraction2_str);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num1_str;
            std::string den1_str;
            StrToFraction(fraction1_str, num1_str, den1_str);
            std::string num2_str;
            std::string den2_str;
            StrToFraction(fraction2_str, num2_str, den2_str);

            LongRational a_n((LongInteger(num1_str)), LongNatural(den1_str));
            LongRational b_n((LongInteger(num2_str)), LongNatural(den2_str));

            result_future = std::async(std::launch::async, MUL_QQ_Q, a_n, b_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Умножение дробей");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleRationalFunctions::show_DIV_QQ_Q(bool* p_open) {
    if (!ImGui::Begin("Рациональные функции: DIV_QQ_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два рациональных числа");
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction1_str;
    InputTextWithResize("fraction1", fraction1_str);
    ImGui::Text("Введите числитель (целое число) и знаменатель (натуральное число) разделенные пробелом:");
    static std::string fraction2_str;
    InputTextWithResize("fraction2", fraction2_str);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate") && !calculation_started) {
        try {
            std::string num1_str;
            std::string den1_str;
            StrToFraction(fraction1_str, num1_str, den1_str);
            std::string num2_str;
            std::string den2_str;
            StrToFraction(fraction2_str, num2_str, den2_str);

            LongRational a_n((LongInteger(num1_str)), LongNatural(den1_str));
            LongRational b_n((LongInteger(num2_str)), LongNatural(den2_str));

            result_future = std::async(std::launch::async, DIV_QQ_Q, a_n, b_n);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    HelpMarker("Деление дробей (делитель отличен от нуля)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}