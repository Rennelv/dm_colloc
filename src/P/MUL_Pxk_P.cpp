#include "P/MUL_Pxk_P.hpp"

#include "N/ADD_NN_N.hpp"

Polynomial MUL_Pxk_P(const Polynomial& a, const LongNatural& k) {
    const std::map<LongNatural, LongRational>& poly_map = a.getMap();  // возвращает вектор коэффициентов
    std::map<LongNatural, LongRational> new_poly_map;                  // Новый map для хранения результата

    // Проходим по всем элементам исходного polyMap
    for (const auto& [key, value] : poly_map) {
        LongNatural new_key = ADD_NN_N(key, k);  // Новый ключ
        LongRational val = value;                // Значение остается прежним
        new_poly_map.emplace(new_key, val);      // Используем emplace для добавления
    }

    // Возвращаем новый полином с обновленным map
    return Polynomial(new_poly_map);
}
