#include "P/MUL_Pxk_P.hpp"

#include "N/ADD_NN_N.hpp"

Polynomial MUL_Pxk_P(const Polynomial& a, const LongNatural& k) {
    const std::map<LongNatural, LongRational>& PolyMap = a.getMap();  // возвращает вектор коэффициентов
    std::map<LongNatural, LongRational> NewPolyMap;                   // Новый map для хранения результата

    // Проходим по всем элементам исходного polyMap
    for (const auto& [key, value] : PolyMap) {
        LongNatural NewKey = ADD_NN_N(key, k);  // Новый ключ
        LongRational val = value;               // Значение остается прежним
        NewPolyMap.emplace(NewKey, val);        // Используем emplace для добавления
    }

    // Возвращаем новый полином с обновленным map
    return Polynomial(NewPolyMap);
}
