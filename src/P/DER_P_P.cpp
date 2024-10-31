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
    const LongNatural& aDeg = a.getDegree();  //получаем степень исходного полинома
    LongNatural aDegree = ADD_1N_N(aDeg);  // увеличиваем значение степени на 1 (чтобы в цикле пройтись по всем степеням)
    LongNatural one({1});                              //создаем натуральное число 1
    std::map<LongNatural, LongRational> coefficients;  // создаем map для хранения результата
    //проходим по всем степеням исходного полинома (в том числе с нулевыми коэффициентами)
    for (LongNatural i{1}; COM_NN_D(i, aDegree) == 1; i = ADD_1N_N(i)) {
        //проверяем чтобы коэффициент не был равен 0
        if (!a.isCoefZero(i)) {
            const LongRational& coeff = a.getCoef(i);            //получаем коэффициент полинома при данной степени
            LongInteger deg = TRANS_N_Z(i);                      //преобразуем натуральное число в целое
            LongRational degree(deg, one);                       //преобразуем целое число в рациональное
            LongRational coefficient = MUL_QQ_Q(coeff, degree);  //перемножаем значение коэффициента и значение степени
            coefficients.emplace(SUB_NN_N(i, one),
                                 coefficient);  //добавляем в map нового полинома значение полученного полинома по ключу исходной степени уменьшенной на 1
        }
    }
    Polynomial result(coefficients);
    return result;
}
