#include "gui/NaturalFunctions.hpp"

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
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "imgui.h"

void HandleNaturalFunctions::ShowNaturalFuncMenu() {
    static bool show_COM_NN_D = false;
    static bool show_NZER_N_B = false;
    static bool show_ADD_1N_N = false;
    static bool show_ADD_NN_N = false;
    static bool show_SUB_NN_N = false;
    static bool show_MUL_ND_N = false;
    static bool show_MUL_Nk_N = false;
    static bool show_MUL_NN_N = false;
    static bool show_SUB_NDN_N = false;
    static bool show_DIV_NN_Dk = false;
    static bool show_DIV_NN_N = false;
    static bool show_MOD_NN_N = false;
    static bool show_GCF_NN_N = false;
    static bool show_LCM_NN_N = false;

    if (show_COM_NN_D) Show_COM_NN_D(&show_COM_NN_D);
    if (show_NZER_N_B) Show_NZER_N_B(&show_NZER_N_B);
    if (show_ADD_1N_N) Show_ADD_1N_N(&show_ADD_1N_N);
    if (show_ADD_NN_N) Show_ADD_NN_N(&show_ADD_NN_N);
    if (show_SUB_NN_N) Show_SUB_NN_N(&show_SUB_NN_N);
    if (show_MUL_ND_N) Show_MUL_ND_N(&show_MUL_ND_N);
    if (show_MUL_Nk_N) Show_MUL_Nk_N(&show_MUL_Nk_N);
    if (show_MUL_NN_N) Show_MUL_NN_N(&show_MUL_NN_N);
    if (show_SUB_NDN_N) Show_SUB_NDN_N(&show_SUB_NDN_N);
    if (show_DIV_NN_Dk) Show_DIV_NN_Dk(&show_DIV_NN_Dk);
    if (show_DIV_NN_N) Show_DIV_NN_N(&show_DIV_NN_N);
    if (show_MOD_NN_N) Show_MOD_NN_N(&show_MOD_NN_N);
    if (show_GCF_NN_N) Show_GCF_NN_N(&show_GCF_NN_N);
    if (show_LCM_NN_N) Show_LCM_NN_N(&show_LCM_NN_N);

    ImGui::Begin("Natural Functions Menu");

    if (ImGui::Button("1. Сравнение натуральных чисел")) {
        show_COM_NN_D = !show_COM_NN_D;
    }
    if (ImGui::Button("2. Проверка на ноль")) {
        show_NZER_N_B = !show_NZER_N_B;
    }
    if (ImGui::Button("3. Добавление 1 к натуральному числу")) {
        show_ADD_1N_N = !show_ADD_1N_N;
    }
    if (ImGui::Button("4. Сложение натуральных чисел")) {
        show_ADD_NN_N = !show_ADD_NN_N;
    }
    if (ImGui::Button("5. Вычитание натуральных чисел")) {
        show_SUB_NN_N = !show_SUB_NN_N;
    }
    if (ImGui::Button("6. Умножение натурального числа на цифру")) {
        show_MUL_ND_N = !show_MUL_ND_N;
    }
    if (ImGui::Button("7. Умножение натурального числа на 10^k")) {
        show_MUL_Nk_N = !show_MUL_Nk_N;
    }
    if (ImGui::Button("8. Умножение натуральных чисел")) {
        show_MUL_NN_N = !show_MUL_NN_N;
    }
    if (ImGui::Button("9. Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом")) {
        show_SUB_NDN_N = !show_SUB_NDN_N;
    }
    if (ImGui::Button("10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k")) {
        show_DIV_NN_Dk = !show_DIV_NN_Dk;
    }
    if (ImGui::Button("11. Неполное частное от деления первого натурального числа на второе с остатком")) {
        show_DIV_NN_N = !show_DIV_NN_N;
    }
    if (ImGui::Button("12. Остаток от деления первого натурального числа на второе натуральное")) {
        show_MOD_NN_N = !show_MOD_NN_N;
    }
    if (ImGui::Button("13. НОД натуральных чисел")) {
        show_GCF_NN_N = !show_GCF_NN_N;
    }
    if (ImGui::Button("14. НОК натуральных чисел")) {
        show_LCM_NN_N = !show_LCM_NN_N;
    }

    ImGui::End();
}

void InputTextWithResize(const char* label, std::string& str) {
    ImGui::InputText(
        label, &str[0], str.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
        [](ImGuiInputTextCallbackData* data) -> int {
            if (data->EventFlag == ImGuiInputTextFlags_CallbackResize) {
                std::string* str = (std::string*)data->UserData;
                str->resize(data->BufTextLen);
                data->Buf = (char*)str->c_str();
            }
            return 0;
        },
        (void*)&str);
}

// template <typename ResultType, typename Func, typename... Args>
// static void StartComputation(std::future<ResultType>& result_future, bool& calculation_started, std::string& error_str, Func func, Args... args) {
//     error_str.clear();
//     try {
//         result_future = std::async(std::launch::async, func, args...);
//         calculation_started = true;
//     } catch (const std::logic_error& e) {
//         error_str = "Error during computations: " + std::string(e.what());
//     } catch (const std::bad_alloc& e) {
//         error_str = "Error allocating memory: " + std::string(e.what());
//     } catch (const std::exception& e) {
//         error_str = "Unknown error during computations: " + std::string(e.what());
//     }
// }

template <typename ResultType>
void DisplayResultOrError(std::future<ResultType>& result_future, bool& calculation_started, std::string& result, const std::string& error_str) {
    if (calculation_started) {
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            if constexpr (std::is_same_v<ResultType, LongNatural> || std::is_same_v<ResultType, LongRational> || std::is_same_v<ResultType, LongInteger> ||
                          std::is_same_v<ResultType, Polynomial>) {
                result = result_future.get().toString();
            } else if constexpr (std::is_same_v<ResultType, int>) {
                result = std::to_string(result_future.get());
            } else if constexpr (std::is_same_v<ResultType, bool>) {
                result = result_future.get() ? "true" : "false";
            } else {
                static_assert(std::is_same_v<ResultType, LongNatural> || std::is_same_v<ResultType, int> || std::is_same_v<ResultType, bool>,
                              "Unsupported result type");
                result = "Unsupported result type";
            }
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::BeginChild("Result", ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * 5), true, ImGuiWindowFlags_HorizontalScrollbar);
        ImGui::TextWrapped("Result: %s", result.c_str());
        ImGui::EndChild();
    }
    if (!error_str.empty()) ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
}

void HandleNaturalFunctions::Show_GCF_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: GCF_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;
    static std::string b_str;

    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    DisplayResultOrError(result_future, calculation_started, result, error_str);
    ImGui::End();
}

void HandleNaturalFunctions::Show_COM_NN_D(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: COM_NN_D", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");

    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'

    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<int> result_future;
    static bool calculation_started = false;
    static int result = 0;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %d", result);
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_NZER_N_B(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: NZER_N_B", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a natural number:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<bool> result_future;
    static bool calculation_started = false;
    static bool result = false;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result ? "true" : "false");
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_ADD_1N_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: ADD_1N_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a natural number:");
    static std::string a_str;  // Buffer for input 'a'
    InputTextWithResize("a", a_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result("");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get().toString();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        if (!result.empty()) {
            ImGui::BeginChild("Result", ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * 5), true, ImGuiWindowFlags_HorizontalScrollbar);
            ImGui::TextWrapped("Result: %s", result.c_str());
            ImGui::EndChild();
        }
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_ADD_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: ADD_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::TextWrapped("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_SUB_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: SUB_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_MUL_ND_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MUL_ND_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a natural number and a digit separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string d_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("d", d_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_MUL_Nk_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MUL_Nk_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a natural number and a power of 10 separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string k_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("k", k_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
}

void HandleNaturalFunctions::Show_MUL_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MUL_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_SUB_NDN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: SUB_NDN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter three natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    static std::string d_str;  // Buffer for input 'd'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);
    InputTextWithResize("d", d_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_DIV_NN_Dk(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: DIV_NN_Dk", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_DIV_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: DIV_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_MOD_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: MOD_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}

void HandleNaturalFunctions::Show_LCM_NN_N(bool* p_open) {
    if (!ImGui::Begin("Natural Functions: LCM_NN_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two natural numbers separated by space:");
    static std::string a_str;  // Buffer for input 'a'
    static std::string b_str;  // Buffer for input 'b'
    InputTextWithResize("a", a_str);
    InputTextWithResize("b", b_str);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static LongNatural result("0");
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str.clear();
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

    if (calculation_started) {
        // Check if the result is ready
        if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            result = result_future.get();
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::Text("Result: %s", result.toString().c_str());
    }
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    ImGui::End();
}