#include "P/MUL_PP_P.hpp"

#include "P/ADD_PP_P.hpp"
#include "P/MUL_PQ_P.hpp"
#include "P/MUL_Pxk_P.hpp"

Polynomial MUL_PP_P(const Polynomial& p1, const Polynomial& p2) {
    // Создаем нулевой многочлен для результата
    std::map<LongNatural, LongRational> zero_pol;
    zero_pol.emplace(LongNatural("0"), LongRational(LongInteger("0"), LongNatural("1")));
    Polynomial result(zero_pol);

    // Проходим по всем степеням и коэффициентам p1
    for (const auto& [degree, coeff] : p1.getMap()) {
        Polynomial term = MUL_PQ_P(p2, coeff);  // Умножаем второй многочлен p2 на коэффициент coeff из p1

        term = MUL_Pxk_P(term, degree);  // Сдвигаем умноженный многочлен на x^degree

        result = ADD_PP_P(result, term);  // Добавляем полученное произведение к результату
    }

    return result;
}
