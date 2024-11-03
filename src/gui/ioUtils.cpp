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
