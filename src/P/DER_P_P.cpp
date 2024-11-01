#include "P/DER_P_P.hpp"

#include <N/ADD_1N_N.hpp>
#include <N/COM_NN_D.hpp>
#include <N/LongNatural.hpp>
#include <N/SUB_NN_N.hpp>
#include <Q/LongRational.hpp>
#include <Q/MUL_QQ_Q.hpp>
#include <Z/LongInteger.hpp>
#include <Z/TRANS_N_Z.hpp>

Polynomial DER_P_P(const Polynomial& a) {
    const std::map<LongNatural, LongRational>& map = a.getMap();  // получаем map числа
    LongNatural one({1});                                         //создаем натуральное число 1
    LongNatural zero({0});                                        //создаем натуральное число 0
    std::map<LongNatural, LongRational> coefficients;             // создаем map для хранения результата
    // проходимся по степеням полинома, у которых не нулевые коэффициенты
    for (const auto& [key, value] : map) {
        // проверяем, что степень не равна 0
        if (COM_NN_D(key, zero) != 0) {
            LongInteger deg = TRANS_N_Z(key);                    //преобразуем натуральное число в целое
            LongRational degree(deg, one);                       //преобразуем целое число в рациональное
            LongRational coefficient = MUL_QQ_Q(value, degree);  //перемножаем значение коэффициента и значение степени
            coefficients.emplace(SUB_NN_N(key, one),
                                 coefficient);  //добавляем в map нового полинома значение полученного полинома по ключу исходной степени уменьшенной на 1
        }
    }
    Polynomial result(coefficients);
    return result;
}
