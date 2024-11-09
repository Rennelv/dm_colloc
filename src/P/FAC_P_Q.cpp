#include "P/FAC_P_Q.hpp"

#include "N/DIV_NN_N.hpp"
#include "N/GCF_NN_N.hpp"
#include "N/LCM_NN_N.hpp"
#include "N/LongNatural.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/DIV_ZZ_Z.hpp"
#include "Z/LongInteger.hpp"
#include "Z/MUL_ZZ_Z.hpp"
#include "Z/TRANS_N_Z.hpp"

LongRational FAC_P_Q(Polynomial& a) {
    const std::map<LongNatural, LongRational>& map = a.getMap();  // возвращает мап коэффициентов
    std::map<LongNatural, LongRational> new_map;                  // новый map для хранения результата

    LongNatural gcf = {0};  // Для хранения НОД
    LongNatural lcm = {1};  // Для хранения НОК
    LongNatural tmp_numerator = {0};

    // Проходим по всем коэффициентам многочлена не равным нулю
    for (const auto& [key, value] : map) {
        tmp_numerator = ABS_Z_N(value.getNumerator());  // Временная переменная для получения абсолютного значения числа
        gcf = GCF_NN_N(gcf, tmp_numerator);           // Считаем НОД всех числителей
        lcm = LCM_NN_N(lcm, value.getDenominator());  // Считаем НОК всех знаменателей
    }

    LongInteger gcf_long_integer = TRANS_N_Z(gcf);  // Преобразование натурального в целое число
    LongNatural new_denominatior("1");  // Новый знаменатель будет равен 1, так как из многочлена выносится НОК всех знаменателей
    LongInteger factor("0");  // Значение, на которое домножается числитель(НОК раздёленный на знаменатель)

    for (const auto& [key, value] : map) {
        LongInteger new_numerator = DIV_ZZ_Z(value.getNumerator(), gcf_long_integer);  // "Выносим" НОД из числителя
        factor = TRANS_N_Z(DIV_NN_N(lcm, value.getDenominator()));                     // "Выносим" НОК из знаменателя
        new_numerator = MUL_ZZ_Z(new_numerator, factor);                               // Получаем новый числитель
        LongRational new_value = {new_numerator, new_denominatior};  // Новый коэффициент(числитель новый, а знаменатель равен 1)
        new_map.emplace(key, new_value);                             // Помещаем новый коэффициент в мап
    }

    // Изменяем изначальный многочлен
    Polynomial new_poly(new_map);
    a = new_poly;

    // Возвращаем вынесенный коффициент
    return RED_Q_Q(LongRational(gcf_long_integer, lcm));
}
