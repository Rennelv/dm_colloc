#include "gui/HandleIntegerFunctions.hpp"

#include <new>

#include "N/LongNatural.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/ADD_ZZ_Z.hpp"
#include "Z/DIV_ZZ_Z.hpp"
#include "Z/LongInteger.hpp"
#include "Z/MOD_ZZ_Z.hpp"
#include "Z/MUL_ZM_Z.hpp"
#include "Z/MUL_ZZ_Z.hpp"
#include "Z/POZ_Z_D.hpp"
#include "Z/SUB_ZZ_Z.hpp"
#include "Z/TRANS_N_Z.hpp"
#include "Z/TRANS_Z_N.hpp"
#include "gui/ioUtils.hpp"
#include "imgui.h"

void HandleIntegerFunctions::showMenu(bool* p_open) {
    static bool ABS_Z_N_open = false;
    static bool POZ_Z_D_open = false;
    static bool MUL_ZM_Z_open = false;
    static bool TRANS_N_Z_open = false;
    static bool TRANS_Z_N_open = false;
    static bool ADD_ZZ_Z_open = false;
    static bool SUB_ZZ_Z_open = false;
    static bool MUL_ZZ_Z_open = false;
    static bool DIV_ZZ_Z_open = false;
    static bool MOD_ZZ_Z_open = false;

    if (ABS_Z_N_open) show_ABS_Z_N(&ABS_Z_N_open);
    if (POZ_Z_D_open) show_POZ_Z_D(&POZ_Z_D_open);
    if (MUL_ZM_Z_open) show_MUL_ZM_Z(&MUL_ZM_Z_open);
    if (TRANS_N_Z_open) show_TRANS_N_Z(&TRANS_N_Z_open);
    if (TRANS_Z_N_open) show_TRANS_Z_N(&TRANS_Z_N_open);
    if (ADD_ZZ_Z_open) show_ADD_ZZ_Z(&ADD_ZZ_Z_open);
    if (SUB_ZZ_Z_open) show_SUB_ZZ_Z(&SUB_ZZ_Z_open);
    if (MUL_ZZ_Z_open) show_MUL_ZZ_Z(&MUL_ZZ_Z_open);
    if (DIV_ZZ_Z_open) show_DIV_ZZ_Z(&DIV_ZZ_Z_open);
    if (MOD_ZZ_Z_open) show_MOD_ZZ_Z(&MOD_ZZ_Z_open);

    if (!ImGui::Begin("Integer Functions Menu", p_open)) {
        ImGui::End();
        return;
    }

    if (ImGui::Button("1. Абсолютная величина числа")) {
        ABS_Z_N_open = !ABS_Z_N_open;
    }
    if (ImGui::Button("2. Определение положительности числа")) {
        POZ_Z_D_open = !POZ_Z_D_open;
    }
    if (ImGui::Button("3. Умножение целого на (-1)")) {
        MUL_ZM_Z_open = !MUL_ZM_Z_open;
    }
    if (ImGui::Button("4. Преобразование натурального в целое")) {
        TRANS_N_Z_open = !TRANS_N_Z_open;
    }
    if (ImGui::Button("5. Преобразование целого неотрицательного в натуральное")) {
        TRANS_Z_N_open = !TRANS_Z_N_open;
    }
    if (ImGui::Button("6. Сложение целых чисел")) {
        ADD_ZZ_Z_open = !ADD_ZZ_Z_open;
    }
    if (ImGui::Button("7. Вычитание целых чисел")) {
        SUB_ZZ_Z_open = !SUB_ZZ_Z_open;
    }
    if (ImGui::Button("8. Умножение целых чисел")) {
        MUL_ZZ_Z_open = !MUL_ZZ_Z_open;
    }
    if (ImGui::Button("9. Частное от деления целого на целое")) {
        DIV_ZZ_Z_open = !DIV_ZZ_Z_open;
    }
    if (ImGui::Button("10. Остаток от деления целого на целое")) {
        MOD_ZZ_Z_open = !MOD_ZZ_Z_open;
    }

    ImGui::End();
}

void HandleIntegerFunctions::show_ABS_Z_N(bool* p_open) {
    if (!ImGui::Begin("Целые числа: ABS_Z_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите целое число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);

            result_future = std::async(std::launch::async, ABS_Z_N, a_n);
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
    HelpMarker("Абсолютная величина числа, результат - натуральное");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_POZ_Z_D(bool* p_open) {
    if (!ImGui::Begin("Целые числа: POZ_Z_D", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите целое число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<int> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);

            result_future = std::async(std::launch::async, POZ_Z_D, a_n);
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
    HelpMarker("Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_MUL_ZM_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: MUL_ZM_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите целое число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);

            result_future = std::async(std::launch::async, MUL_ZM_Z, a_n);
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
    HelpMarker("Умножение целого на (-1)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_TRANS_N_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: TRANS_N_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите натуральное число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongNatural a_n(a_str);

            result_future = std::async(std::launch::async, TRANS_N_Z, a_n);
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
    HelpMarker("Преобразование натурального в целое");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_TRANS_Z_N(bool* p_open) {
    if (!ImGui::Begin("Целые числа: TRANS_N_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите натуральное число:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);

            result_future = std::async(std::launch::async, TRANS_Z_N, a_n);
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
    HelpMarker("Преобразование целого неотрицательного в натуральное");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_ADD_ZZ_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: ADD_ZZ_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два целых числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);
            LongInteger b_n(b_str);

            result_future = std::async(std::launch::async, ADD_ZZ_Z, a_n, b_n);
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
    HelpMarker("Сложение целых чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_SUB_ZZ_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: SUB_ZZ_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два целых числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);
            LongInteger b_n(b_str);

            result_future = std::async(std::launch::async, SUB_ZZ_Z, a_n, b_n);
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
    HelpMarker("Вычитание целых чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_MUL_ZZ_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: MUL_ZZ_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два целых числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);
            LongInteger b_n(b_str);

            result_future = std::async(std::launch::async, MUL_ZZ_Z, a_n, b_n);
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
    HelpMarker("Умножение целых чисел");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_DIV_ZZ_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: DIV_ZZ_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два целых числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);
            LongInteger b_n(b_str);

            result_future = std::async(std::launch::async, DIV_ZZ_Z, a_n, b_n);
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
    HelpMarker("Частное от деления целого на целое (делитель отличен от нуля)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleIntegerFunctions::show_MOD_ZZ_Z(bool* p_open) {
    if (!ImGui::Begin("Целые числа: MOD_ZZ_Z", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Введите два целых числа:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongInteger> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            LongInteger a_n(a_str);
            LongInteger b_n(b_str);

            result_future = std::async(std::launch::async, MOD_ZZ_Z, a_n, b_n);
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
    HelpMarker("Остаток от деления целого на целое(делитель отличен от нуля)");
    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}
