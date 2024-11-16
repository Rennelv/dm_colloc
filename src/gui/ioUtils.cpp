#include "gui/ioUtils.hpp"

#include <sstream>

#include "imgui.h"

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

void HelpMarker(const char* desc) {
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered()) {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void StrToFraction(const std::string& str, std::string& numerator, std::string& denominator) {
    std::istringstream iss(str);
    if (!(iss >> numerator >> denominator)) {
        throw std::invalid_argument("Invalid coefficent input format. Please enter two numbers separated by a space.");
        return;
    }
}

std::string MapToPolyStr(const std::map<LongNatural, LongRational>& terms) {
    if (terms.empty()) {
        return "0";
    }
    std::string result = "";
    // добавляем в строку коэффиценты с наибольшей степени
    for (auto it = terms.rbegin(); it != terms.rend(); ++it) {
        auto [deg, coef] = *it;
        if (deg == LongNatural::ZERO) {
            result += coef.toString() + " + ";

        } else {
            result += "(" + coef.toString() + ")" + "x^" + deg.toString() + " + ";
        }
        // // если строка получается больше 10000 символово обрезаем строку
        // if (result.size() > 10000) {
        //     return result.substr(0, result.size() - 3) + "..." + "и еще " + std::to_string(terms.size() - std::distance(terms.rbegin(), it)) +
        //            " ненулевых членов";
        // }
    }
    return result.substr(0, result.size() - 3);
}

void parsePolynomial(std::string label_no, std::map<LongNatural, LongRational>& terms, std::string& degree_str, std::string& coef_str, std::string& error_str) {
    ImGui::Text("Введите степень при x добавляемого члена (натуральное число): ");
    InputTextWithResize((std::string("degree") + label_no).c_str(), degree_str);
    ImGui::Text("Введите числитель и знаменатель добавляемого члена разделяя их пробелом (целое число и натуральное число): ");
    InputTextWithResize((std::string("num") + label_no).c_str(), coef_str);

    if (ImGui::Button((std::string("Добавить одночлен ") + label_no).c_str())) {
        error_str.clear();
        std::string num_str;
        std::string den_str;
        try {
            StrToFraction(coef_str, num_str, den_str);
            terms.emplace(LongNatural(degree_str), LongRational(num_str, den_str));
            // degree_str.clear();
            // num_str.clear();
            // den_str.clear();
        } catch (const std::invalid_argument& e) {
            error_str = "Invalid input: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str = "Unknown error during computations: " + std::string(e.what());
        }
    }
    ImGui::SameLine();
    if (ImGui::Button((std::string("Очистить многочлен ") + label_no).c_str())) {
        terms.clear();
    }
    if (!error_str.empty()) {
        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", error_str.c_str());
    }
    ImGui::Text("Текущий многочлен:");
    ImGui::BeginChild((std::string("Текущий многочлен ") + label_no + ": ").c_str(), ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * 1.5f), true);
    ImGui::Text("%s", MapToPolyStr(terms).c_str());
    ImGui::EndChild();
}