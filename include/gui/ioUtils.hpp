#ifndef IO_UTILS_HPP
#define IO_UTILS_HPP

#include <chrono>
#include <future>
#include <new>
#include <string>
#include <type_traits>

#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"
#include "imgui.h"

/**
 * @file ioUtils.hpp
 * @brief Набор вспомогательных функций для графического интерфейса.
 *
 * @details
 * Этот файл содержит объявления функций, которые используются для ввода и вывода данных в графическом интерфейсе,
 * а также для обработки результатов вычислений и ошибок.
 *
 * @author Журавлев Дмитрий 3381
 */

// Ввод теста в строку с автоматическим увеличением ее максимальной длины
void InputTextWithResize(const char* label, std::string& str);

// Вывод результата вычислений или ошибки
template <typename ResultType>
void DisplayResultOrError(std::future<ResultType>& result_future, bool& calculation_started, std::string& result, std::string& error_str) {
    if (calculation_started) {
        error_str.clear();
        if (!result_future.valid()) {
            error_str = "Error starting the computation";
            calculation_started = false;
        } else if (result_future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            try {
                if constexpr (std::is_same_v<ResultType, LongNatural> || std::is_same_v<ResultType, LongInteger> || std::is_same_v<ResultType, Polynomial>) {
                    result = result_future.get().toString();
                } else if constexpr (std::is_same_v<ResultType, LongRational>) {
                    LongRational res = result_future.get();
                    result = '\n' + res.getNumerator().toString() + "/\n" + res.getDenominator().toString();
                } else if constexpr (std::is_same_v<ResultType, int>) {
                    result = std::to_string(result_future.get());
                } else if constexpr (std::is_same_v<ResultType, bool>) {
                    result = result_future.get() ? "true" : "false";
                } else {
                    static_assert(std::is_same_v<ResultType, LongNatural> || std::is_same_v<ResultType, int> || std::is_same_v<ResultType, bool>,
                                  "Unsupported result type");
                    result = "Unsupported result type";
                }
                //
            } catch (const std::invalid_argument& e) {
                error_str = "Invalid input: " + std::string(e.what());
            } catch (const std::logic_error& e) {
                error_str = "Error during computations: " + std::string(e.what());
            } catch (const std::bad_alloc& e) {
                error_str = "Error allocating memory: " + std::string(e.what());
            } catch (const std::exception& e) {
                error_str = "Unknown error during computations: " + std::string(e.what());
            }
            calculation_started = false;
        } else {
            ImGui::Text("Calculating...");
        }
    } else {
        ImGui::BeginChild("Result", ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * 5), true, ImGuiWindowFlags_HorizontalScrollbar);
        if (!result.empty()) ImGui::Text("Result: %s", result.c_str());
        ImGui::EndChild();
    }
    if (!result.empty() && ImGui::Button("Copy to clipboard")) {
        ImGui::SetClipboardText(result.c_str());
    }
    if (!error_str.empty()) ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
}

// template <typename ResultType, typename Func, typename... Args>
// void Calculate(std::future<ResultType>& result_future, bool& calculation_started, std::string& result, std::string& error_str, Func func, Args... args) {
//     if (ImGui::Button("Calculate") && !calculation_started) {
//         result.clear();
//         try {
//             result_future = std::async(std::launch::async, func, args...);
//             calculation_started = true;
//         } catch (const std::invalid_argument& e) {
//             error_str = "Invalid input: " + std::string(e.what());
//         } catch (const std::logic_error& e) {
//             error_str = "Error during computations: " + std::string(e.what());
//         } catch (const std::bad_alloc& e) {
//             error_str = "Error allocating memory: " + std::string(e.what());
//         } catch (const std::exception& e) {
//             error_str = "Unknown error during computations: " + std::string(e.what());
//         }
//     }
// }

// Подсказка "(?)" в интерфейсе
void HelpMarker(const char* desc);

// Переводит строку с двумя числами, разделенными пробелом, в числитель и знаменатель
void StrToFraction(const std::string& str, std::string& numerator, std::string& denominator);

// Переводит map коэффициентов многочлена в строку
std::string MapToPolyStr(const std::map<LongNatural, LongRational>& terms);

// Блок интерфейса ввода многочлена с добавлением членов
void parsePolynomial(std::string label_no, std::map<LongNatural, LongRational>& terms, std::string& degree_str, std::string& coef_str, std::string& error_str);

#endif  // IO_UTILS_HPP