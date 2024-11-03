#include "gui/HandleNaturalFunctions.hpp"

#include <cstdint>
#include <future>
#include <new>
#include <stdexcept>
#include <string>

#include "N/ADD_1N_N.hpp"
#include "N/ADD_NN_N.hpp"
#include "N/COM_NN_D.hpp"
#include "N/DIV_NN_Dk.hpp"
#include "N/DIV_NN_N.hpp"
#include "N/GCF_NN_N.hpp"
#include "N/LCM_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "N/MOD_NN_N.hpp"
#include "N/MUL_ND_N.hpp"
#include "N/MUL_NN_N.hpp"
#include "N/MUL_Nk_N.hpp"
#include "N/NZER_N_B.hpp"
#include "N/SUB_NDN_N.hpp"
#include "N/SUB_NN_N.hpp"
#include "gui/ioUtils.hpp"
#include "imgui.h"

void HandleNaturalFunctions::showMenu(bool* p_open) {
    static bool COM_NN_D_open = false;
    static bool NZER_N_B_open = false;
    static bool ADD_1N_N_open = false;
    static bool ADD_NN_N_open = false;
    static bool SUB_NN_N_open = false;
    static bool MUL_ND_N_open = false;
    static bool MUL_Nk_N_open = false;
    static bool MUL_NN_N_open = false;
    static bool SUB_NDN_N_open = false;
    static bool DIV_NN_Dk_open = false;
    static bool DIV_NN_N_open = false;
    static bool MOD_NN_N_open = false;
    static bool GCF_NN_N_open = false;
    static bool LCM_NN_N_open = false;

    if (COM_NN_D_open) show_COM_NN_D(&COM_NN_D_open);
    if (NZER_N_B_open) show_NZER_N_B(&NZER_N_B_open);
    if (ADD_1N_N_open) show_ADD_1N_N(&ADD_1N_N_open);
    if (ADD_NN_N_open) show_ADD_NN_N(&ADD_NN_N_open);
    if (SUB_NN_N_open) show_SUB_NN_N(&SUB_NN_N_open);
    if (MUL_ND_N_open) show_MUL_ND_N(&MUL_ND_N_open);
    if (MUL_Nk_N_open) show_MUL_Nk_N(&MUL_Nk_N_open);
    if (MUL_NN_N_open) show_MUL_NN_N(&MUL_NN_N_open);
    if (SUB_NDN_N_open) show_SUB_NDN_N(&SUB_NDN_N_open);
    if (DIV_NN_Dk_open) show_DIV_NN_Dk(&DIV_NN_Dk_open);
    if (DIV_NN_N_open) show_DIV_NN_N(&DIV_NN_N_open);
    if (MOD_NN_N_open) show_MOD_NN_N(&MOD_NN_N_open);
    if (GCF_NN_N_open) show_GCF_NN_N(&GCF_NN_N_open);
    if (LCM_NN_N_open) show_LCM_NN_N(&LCM_NN_N_open);

    if (!ImGui::Begin("Natural Functions Menu", p_open)) {
        ImGui::End();
        return;
    }

    if (ImGui::Button("1. Сравнение натуральных чисел")) {
        COM_NN_D_open = !COM_NN_D_open;
    }
    if (ImGui::Button("2. Проверка на ноль")) {
        NZER_N_B_open = !NZER_N_B_open;
    }
    if (ImGui::Button("3. Добавление 1 к натуральному числу")) {
        ADD_1N_N_open = !ADD_1N_N_open;
    }
    if (ImGui::Button("4. Сложение натуральных чисел")) {
        ADD_NN_N_open = !ADD_NN_N_open;
    }
    if (ImGui::Button("5. Вычитание натуральных чисел")) {
        SUB_NN_N_open = !SUB_NN_N_open;
    }
    if (ImGui::Button("6. Умножение натурального числа на цифру")) {
        MUL_ND_N_open = !MUL_ND_N_open;
    }
    if (ImGui::Button("7. Умножение натурального числа на 10^k")) {
        MUL_Nk_N_open = !MUL_Nk_N_open;
    }
    if (ImGui::Button("8. Умножение натуральных чисел")) {
        MUL_NN_N_open = !MUL_NN_N_open;
    }
    if (ImGui::Button("9. Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом")) {
        SUB_NDN_N_open = !SUB_NDN_N_open;
    }
    if (ImGui::Button("10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k")) {
        DIV_NN_Dk_open = !DIV_NN_Dk_open;
    }
    if (ImGui::Button("11. Неполное частное от деления первого натурального числа на второе с остатком")) {
        DIV_NN_N_open = !DIV_NN_N_open;
    }
    if (ImGui::Button("12. Остаток от деления первого натурального числа на второе натуральное")) {
        MOD_NN_N_open = !MOD_NN_N_open;
    }
    if (ImGui::Button("13. НОД натуральных чисел")) {
        GCF_NN_N_open = !GCF_NN_N_open;
    }
    if (ImGui::Button("14. НОК натуральных чисел")) {
        LCM_NN_N_open = !LCM_NN_N_open;
    }

    ImGui::End();
}

void HandleNaturalFunctions::show_GCF_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: GCF_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;
    static std::string b_str;

    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Посчитать")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            result_future = std::async(std::launch::async, GCF_NN_N, a_n, b_n);
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
    HelpMarker("НОД натуральных чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_COM_NN_D(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: COM_NN_D", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");

    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'

    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<int> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, COM_NN_D, a_n, b_n);
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
    HelpMarker("Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    // if (result == "0") result = "=";
    // if (result == "1") result = "<";
    // if (result == "2") result = ">";
    ImGui::End();
}

void HandleNaturalFunctions::show_NZER_N_B(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: NZER_N_B", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите натуральное число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<bool> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, NZER_N_B, a_n);
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
    HelpMarker("Проверка на ноль: если число не равно нулю, то «да» иначе «нет»");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_ADD_1N_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: ADD_1N_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите натуральное число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result("");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, ADD_1N_N, a_n);
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
    HelpMarker("Добавление 1 к натуральному числу");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_ADD_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: ADD_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, ADD_NN_N, a_n, b_n);
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
    HelpMarker("Сложение натуральных чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_SUB_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: SUB_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, SUB_NN_N, a_n, b_n);
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
    HelpMarker("Вычитание из первого большего натурального числа второго меньшего или равного");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_MUL_ND_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MUL_ND_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите натуральное число и цифру:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string d_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("d", d_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            if (d_str.length() != 1 || !isdigit(d_str[0])) {
                throw std::invalid_argument("Invalid digit input");
            }
            uint8_t d_n = d_str[0] - '0';

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, MUL_ND_N, a_n, d_n);
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
    HelpMarker("Умножение натурального числа на цифру");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_MUL_Nk_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MUL_Nk_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите натуральное число и степень 10:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string k_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("k", k_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            if (k_str.length() == 0 || !isdigit(k_str[0])) {
                throw std::invalid_argument("Invalid power of 10 input");
            }
            uint64_t k_n = std::stoull(k_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, MUL_Nk_N, a_n, k_n);
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
    HelpMarker("Умножение натурального числа на 10^k, k-натуральное");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_MUL_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MUL_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, MUL_NN_N, a_n, b_n);
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
    HelpMarker("Умножение натуральных чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_SUB_NDN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: SUB_NDN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите три натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    static std::string d_str;  // Buffer for input 'd'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);
    InputTextWithResize("d", d_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);
            if (d_str.length() != 1 || !isdigit(d_str[0])) {
                throw std::invalid_argument("Invalid digit input");
            }
            uint8_t d_n = d_str[0] - '0';

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, SUB_NDN_N, a_n, b_n, d_n);
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
    HelpMarker("Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_DIV_NN_Dk(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: DIV_NN_Dk", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, DIV_NN_Dk, a_n, b_n);
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
    HelpMarker(
        "Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_DIV_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: DIV_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, DIV_NN_N, a_n, b_n);
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
    HelpMarker("Неполное частное от деления первого натурального числа на второе с остатком (делитель отличен от нуля)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_MOD_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MOD_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, MOD_NN_N, a_n, b_n);
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
    HelpMarker("Остаток от деления первого натурального числа на второе натуральное (делитель отличен от нуля)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::show_LCM_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: LCM_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два натуральных числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);
            LongNatural b_n(b_str);

            // Start the computation in a separate thread
            result_future = std::async(std::launch::async, LCM_NN_N, a_n, b_n);
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
    HelpMarker("НОК натуральных чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}