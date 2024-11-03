#include "gui/HandlePolynomialFunctions.hpp"

#include <map>
#include <new>
#include <string>

#include "N/LongNatural.hpp"
// #include "P/ADD_PP_P.hpp"
#include "P/DEG_P_N.hpp"
// #include "P/DIV_PP_P.hpp"
#include "P/DER_P_P.hpp"
// #include "P/FAC_P_Q.hpp"
// #include "P/GCF_PP_P.hpp"
#include "P/FAC_P_Q.hpp"
#include "P/LED_P_Q.hpp"
// #include "P/MOD_PP_P.hpp"
#include "P/MUL_PQ_P.hpp"
#include "P/MUL_Pxk_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "gui/ioUtils.hpp"
#include "imgui.h"

void HandlePolynomialFunctions::showMenu(bool* p_open) {
    static bool ADD_PP_P_open = false;
    static bool SUB_PP_P_open = false;
    static bool MUL_PQ_P_open = false;
    static bool MUL_Pxk_P_open = false;
    static bool LED_P_Q_open = false;
    static bool DEG_P_N_open = false;
    static bool FAC_P_Q_open = false;
    static bool MUL_PP_P_open = false;
    static bool DIV_PP_P_open = false;
    static bool MOD_PP_P_open = false;
    static bool GCF_PP_P_open = false;
    static bool DER_P_P_open = false;
    static bool NMR_P_P_open = false;

    if (ADD_PP_P_open) show_ADD_PP_P(&ADD_PP_P_open);
    if (SUB_PP_P_open) show_SUB_PP_P(&SUB_PP_P_open);
    if (MUL_PQ_P_open) show_MUL_PQ_P(&MUL_PQ_P_open);
    if (MUL_Pxk_P_open) show_MUL_Pxk_P(&MUL_Pxk_P_open);
    if (LED_P_Q_open) show_LED_P_Q(&LED_P_Q_open);
    if (DEG_P_N_open) show_DEG_P_N(&DEG_P_N_open);
    if (FAC_P_Q_open) show_FAC_P_Q(&FAC_P_Q_open);
    if (MUL_PP_P_open) show_MUL_PP_P(&MUL_PP_P_open);
    if (DIV_PP_P_open) show_DIV_PP_P(&DIV_PP_P_open);
    if (MOD_PP_P_open) show_MOD_PP_P(&MOD_PP_P_open);
    if (GCF_PP_P_open) show_GCF_PP_P(&GCF_PP_P_open);
    if (DER_P_P_open) show_DER_P_P(&DER_P_P_open);
    if (NMR_P_P_open) show_NMR_P_P(&NMR_P_P_open);

    if (!ImGui::Begin("Polynomial Functions Menu", p_open)) {
        ImGui::End();
        return;
    }

    if (ImGui::Button("1. Сложение многочленов")) {
        ADD_PP_P_open = !ADD_PP_P_open;
    }
    if (ImGui::Button("2. Вычитание многочленов")) {
        SUB_PP_P_open = !SUB_PP_P_open;
    }
    if (ImGui::Button("3. Умножение многочлена на рациональное число")) {
        MUL_PQ_P_open = !MUL_PQ_P_open;
    }
    if (ImGui::Button("4. Умножение многочлена на x^k")) {
        MUL_Pxk_P_open = !MUL_Pxk_P_open;
    }
    if (ImGui::Button("5. Старший коэффициент многочлена")) {
        LED_P_Q_open = !LED_P_Q_open;
    }
    if (ImGui::Button("6. Степень многочлена")) {
        DEG_P_N_open = !DEG_P_N_open;
    }
    if (ImGui::Button("7. Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей")) {
        FAC_P_Q_open = !FAC_P_Q_open;
    }
    if (ImGui::Button("8. Умножение многочленов")) {
        MUL_PP_P_open = !MUL_PP_P_open;
    }
    if (ImGui::Button("9. Частное от деления многочлена на многочлен при делении с остатком")) {
        DIV_PP_P_open = !DIV_PP_P_open;
    }
    if (ImGui::Button("10. Остаток от деления многочлена на многочлен при делении с остатком")) {
        MOD_PP_P_open = !MOD_PP_P_open;
    }
    if (ImGui::Button("11. НОД многочленов")) {
        GCF_PP_P_open = !GCF_PP_P_open;
    }
    if (ImGui::Button("12. Производная многочлена")) {
        DER_P_P_open = !DER_P_P_open;
    }
    if (ImGui::Button("13. Преобразование многочлена — кратные корни в простые")) {
        NMR_P_P_open = !NMR_P_P_open;
    }

    ImGui::End();
}

std::string map_to_poly_string(const std::map<LongNatural, LongRational>& terms) {
    if (terms.empty()) {
        return "0";
    }
    std::string result = "";
    // добавляем в строку коэффиценты с наибольшей степени
    for (auto it = terms.rbegin(); it != terms.rend(); ++it) {
        auto [deg, coef] = *it;
        if (deg == LongNatural("0")) {
            result += coef.toString() + " + ";

        } else {
            result += "(" + coef.toString() + ")" + "x^" + deg.toString() + " + ";
        }
        // если строка получается больше 10000 символово обрезаем строку
        if (result.size() > 10000) {
            return result.substr(0, result.size() - 3) + "..." + "и еще " + std::to_string(terms.size() - std::distance(terms.rbegin(), it)) +
                   " ненулевых членов";
        }
    }
    return result.substr(0, result.size() - 3);
}

void parsePolynomial(std::string label_no, std::map<LongNatural, LongRational>& terms, std::string& degree_str, std::string& coef_str, std::string& error_str) {
    ImGui::Text("Введите степень при x добавляемого члена (натуральное число): ");
    InputTextWithResize((std::string("degree") + label_no).c_str(), degree_str);
    ImGui::Text("Введите числитель и знаменатель добавляемого члена разделяя их пробелом (целое число и натуральное число): ");
    InputTextWithResize((std::string("num") + label_no).c_str(), coef_str);

    if (ImGui::Button((std::string("Добавить член ") + label_no).c_str())) {
        error_str.clear();
        std::string num_str;
        std::string den_str;
        try {
            str_to_fraction(coef_str, num_str, den_str);
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
    ImGui::Text("%s", map_to_poly_string(terms).c_str());
    ImGui::EndChild();
}

void HandlePolynomialFunctions::show_ADD_PP_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: ADD_PP_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two polynomials:");
    static std::map<LongNatural, LongRational> a_terms;
    static std::map<LongNatural, LongRational> b_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;
    static std::string b_degree_str;
    static std::string b_coef_str;
    static std::string error_str1;
    static std::string error_str2;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);
    parsePolynomial("2", b_terms, b_degree_str, b_coef_str, error_str2);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);
            Polynomial b(b_terms);

            // result_future = std::async(std::launch::async, ADD_PP_P, a, b);
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

void HandlePolynomialFunctions::show_SUB_PP_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: SUB_PP_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two polynomials:");
    static std::map<LongNatural, LongRational> a_terms;
    static std::map<LongNatural, LongRational> b_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string b_degree_str;
    static std::string b_coef_str;

    static std::string error_str1;
    static std::string error_str2;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);
    parsePolynomial("2", b_terms, b_degree_str, b_coef_str, error_str2);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);
            Polynomial b(b_terms);

            // result_future = std::async(std::launch::async, SUB_PP_P, a, b);
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

void HandlePolynomialFunctions::show_MUL_PQ_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: MUL_PQ_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    ImGui::Text("Enter a rational number:");
    static std::string num_str;
    static std::string den_str;
    static std::string error_str2;

    ImGui::Text("Введите числитель (целое число): ");
    InputTextWithResize("num", num_str);
    ImGui::Text("Введите знаменатель (натуральное число): ");
    InputTextWithResize("den", den_str);
    ImGui::Text(" ");

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str2.clear();
        try {
            LongRational q(num_str, den_str);
            result_future = std::async(std::launch::async, MUL_PQ_P, Polynomial(a_terms), q);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str2 = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str2 = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str2 = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str2 = "Unknown error during computations: " + std::string(e.what());
        }
    }

    DisplayResultOrError(result_future, calculation_started, result, error_str2);
    ImGui::End();
}

void HandlePolynomialFunctions::show_MUL_Pxk_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: MUL_Pxk_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    ImGui::Text("Enter a natural number:");
    static std::string k_str;
    static std::string error_str2;

    ImGui::Text("Введите k (натуральное число): ");
    InputTextWithResize("k", k_str);
    ImGui::Text(" ");

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        error_str2.clear();
        try {
            LongNatural k(k_str);
            result_future = std::async(std::launch::async, MUL_Pxk_P, Polynomial(a_terms), k);
            calculation_started = true;
        } catch (const std::invalid_argument& e) {
            error_str2 = "Invalid input: " + std::string(e.what());
        } catch (const std::logic_error& e) {
            error_str2 = "Error during computations: " + std::string(e.what());
        } catch (const std::bad_alloc& e) {
            error_str2 = "Error allocating memory: " + std::string(e.what());
        } catch (const std::exception& e) {
            error_str2 = "Unknown error during computations: " + std::string(e.what());
        }
    }

    DisplayResultOrError(result_future, calculation_started, result, error_str2);
    ImGui::End();
}

void HandlePolynomialFunctions::show_MUL_PP_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: MUL_PP_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two polynomials:");
    static std::map<LongNatural, LongRational> a_terms;
    static std::map<LongNatural, LongRational> b_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string b_degree_str;
    static std::string b_coef_str;

    static std::string error_str1;
    static std::string error_str2;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);
    parsePolynomial("2", b_terms, b_degree_str, b_coef_str, error_str2);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);
            Polynomial b(b_terms);

            // result_future = std::async(std::launch::async, MUL_PP_P, a, b);
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

void HandlePolynomialFunctions::show_LED_P_Q(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: LED_P_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);

            result_future = std::async(std::launch::async, LED_P_Q, a);
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

void HandlePolynomialFunctions::show_DEG_P_N(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: DEG_P_N", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    static std::future<LongNatural> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);

            result_future = std::async(std::launch::async, DEG_P_N, a);
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

void HandlePolynomialFunctions::show_FAC_P_Q(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: FAC_P_Q", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    static std::future<LongRational> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;
    static Polynomial a(a_terms);

    if (ImGui::Button("Calculate")) {
        a = Polynomial(a_terms);
        try {
            // Polynomial a(a_terms);
            // kill me
            result_future = std::async(std::launch::async, FAC_P_Q, std::ref(a));  // thats ****** up
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
    ImGui::Text("Новый многочлен: %s", a.toString().c_str());
    ImGui::End();
}

void HandlePolynomialFunctions::show_DIV_PP_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: DIV_PP_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two polynomials:");
    static std::map<LongNatural, LongRational> a_terms;
    static std::map<LongNatural, LongRational> b_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string b_degree_str;
    static std::string b_coef_str;

    static std::string error_str1;
    static std::string error_str2;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);
    parsePolynomial("2", b_terms, b_degree_str, b_coef_str, error_str2);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);
            Polynomial b(b_terms);

            // result_future = std::async(std::launch::async, DIV_PP_P, a, b);
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

void HandlePolynomialFunctions::show_MOD_PP_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: MOD_PP_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two polynomials:");
    static std::map<LongNatural, LongRational> a_terms;
    static std::map<LongNatural, LongRational> b_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string b_degree_str;
    static std::string b_coef_str;

    static std::string error_str1;
    static std::string error_str2;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);
    parsePolynomial("2", b_terms, b_degree_str, b_coef_str, error_str2);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);
            Polynomial b(b_terms);

            // result_future = std::async(std::launch::async, MOD_PP_P, a, b);
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

void HandlePolynomialFunctions::show_GCF_PP_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: GCF_PP_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter two polynomials:");
    static std::map<LongNatural, LongRational> a_terms;
    static std::map<LongNatural, LongRational> b_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string b_degree_str;
    static std::string b_coef_str;

    static std::string error_str1;
    static std::string error_str2;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);
    parsePolynomial("2", b_terms, b_degree_str, b_coef_str, error_str2);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);
            Polynomial b(b_terms);

            // result_future = std::async(std::launch::async, GCF_PP_P, a, b);
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

void HandlePolynomialFunctions::show_DER_P_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: DER_P_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);

            result_future = std::async(std::launch::async, DER_P_P, a);
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

void HandlePolynomialFunctions::show_NMR_P_P(bool* p_open) {
    if (!ImGui::Begin("Polynomial Functions: NMR_P_P", p_open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Enter a polynomial:");
    static std::map<LongNatural, LongRational> a_terms;

    static std::string a_degree_str;
    static std::string a_coef_str;

    static std::string error_str1;

    parsePolynomial("1", a_terms, a_degree_str, a_coef_str, error_str1);

    static std::future<Polynomial> result_future;
    static bool calculation_started = false;
    static std::string result;
    static std::string error_str;

    if (ImGui::Button("Calculate")) {
        try {
            Polynomial a(a_terms);

            // result_future = std::async(std::launch::async, NMR_P_P, a);
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