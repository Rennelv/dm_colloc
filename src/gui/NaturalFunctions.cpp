#include "gui/NaturalFunctions.hpp"

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
#include "gui/Gui.hpp"
#include "imgui.h"

void HandleNaturalFunctions::ShowNaturalFuncMenu() {
    ImGui::Begin("Natural Functions Menu");

    if (ImGui::Button("1. Сравнение натуральных чисел")) {
        HandleNaturalFunc(1);
    }
    if (ImGui::Button("2. Проверка на ноль")) {
        HandleNaturalFunc(2);
    }
    if (ImGui::Button("3. Добавление 1 к натуральному числу")) {
        HandleNaturalFunc(3);
    }
    if (ImGui::Button("4. Сложение натуральных чисел")) {
        HandleNaturalFunc(4);
    }
    if (ImGui::Button("5. Вычитание натуральных чисел")) {
        HandleNaturalFunc(5);
    }
    if (ImGui::Button("6. Умножение натурального числа на цифру")) {
        HandleNaturalFunc(6);
    }
    if (ImGui::Button("7. Умножение натурального числа на 10^k")) {
        HandleNaturalFunc(7);
    }
    if (ImGui::Button("8. Умножение натуральных чисел")) {
        HandleNaturalFunc(8);
    }
    if (ImGui::Button("9. Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом")) {
        HandleNaturalFunc(9);
    }
    if (ImGui::Button("10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k")) {
        HandleNaturalFunc(10);
    }
    if (ImGui::Button("11. Неполное частное от деления первого натурального числа на второе с остатком")) {
        HandleNaturalFunc(11);
    }
    if (ImGui::Button("12. Остаток от деления первого натурального числа на второе натуральное")) {
        HandleNaturalFunc(12);
    }
    if (ImGui::Button("13. НОД натуральных чисел")) {
        HandleNaturalFunc(13);
    }
    if (ImGui::Button("14. НОК натуральных чисел")) {
        HandleNaturalFunc(14);
    }

    ImGui::End();
}

void HandleNaturalFunctions::HandleNaturalFunc(int choice) {
    switch (choice) {
        case 1:
            Show_COM_NN_D();
            break;
        case 2:
            Show_NZER_N_B();
            break;
        case 3:
            Show_ADD_1N_N();
            break;
        case 4:
            Show_ADD_NN_N();
            break;
        case 5:
            Show_SUB_NN_N();
            break;
        case 6:
            Show_MUL_ND_N();
            break;
        case 7:
            Show_MUL_Nk_N();
            break;
        case 8:
            Show_MUL_NN_N();
            break;
        case 9:
            Show_SUB_NDN_N();
            break;
        case 10:
            Show_DIV_NN_Dk();
            break;
        case 11:
            Show_DIV_NN_N();
            break;
        case 12:
            Show_MOD_NN_N();
            break;
        case 13:
            Show_GCF_NN_N();
            break;
        case 14:
            Show_LCM_NN_N();
            break;
        default:
            break;
    }
}

void HandleNaturalFunctions::Show_COM_NN_D() {
    ImGui::Begin("Natural Functions: COM_NN_D");

    ImGui::Text("Enter two natural numbers separated by space:");
    std::vector<char> a(128);  // Buffer for input 'a'
    std::vector<char> b(128);  // Buffer for input 'b'

    ImGui::InputText("a", a.data(), a.size());
    ImGui::InputText("b", b.data(), b.size());

    if (ImGui::Button("Calculate")) {
        std::string a_str(a.data());
        std::string b_str(b.data());
        LongNatural a_n(a_str);
        LongNatural b_n(b_str);
        auto result = COM_NN_D(a_n, b_n);
        ImGui::Text("Result: %d", result);
    }

    ImGui::End();
}