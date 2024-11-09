#include "P/DER_P_P.hpp"

#include <N/LongNatural.hpp>
#include <N/SUB_NN_N.hpp>
#include <Q/LongRational.hpp>
#include <Q/MUL_QQ_Q.hpp>
#include <Z/LongInteger.hpp>
#include <Z/TRANS_N_Z.hpp>

Polynomial DER_P_P(const Polynomial& a) {
    const std::map<LongNatural, LongRational>& map = a.getMap();  // получаем map числа
    LongNatural one({1});                                         // создаем натуральное число 1
    LongNatural zero({0});                                        // создаем натуральное число 0
    std::map<LongNatural, LongRational> coefficients;             // создаем map для хранения результата

    bool flag = a.isCoef(LongNatural({0}));  // флаг, который показывает, есть ли свободный член
    auto map_begin = flag ? std::next(map.begin()) : map.begin();  // итератор на первый элемент; если есть свободный член, то на второй

    for (auto it = map_begin; it != map.end(); ++it) {  // проходимся по степеням полинома, у которых не нулевые коэффициенты
        const auto& [key, value] = *it;

        LongInteger deg = TRANS_N_Z(key);                    // преобразуем натуральное число в целое
        LongRational degree(deg, one);                       // преобразуем целое число в рациональное
        LongRational coefficient = MUL_QQ_Q(value, degree);  // перемножаем значение коэффициента и значение степени
        coefficients.emplace(SUB_NN_N(key, one),
                             coefficient);  // добавляем в map нового полинома значение полученного полинома по ключу исходной степени уменьшенной на 1
    }

    return Polynomial(coefficients);
}
