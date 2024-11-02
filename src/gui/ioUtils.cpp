#include "gui/ioUtils.hpp"

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

// template <typename ResultType, typename Func, typename... Args>
// static void StartComputation(std::future<ResultType>& result_future, bool& calculation_started, std::string& error_str, Func func, Args... args) {
//     result_future = std::async(std::launch::async, func, args...);
//     calculation_started = true;
// }
