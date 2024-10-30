#include "P/MUL_Pxk_P.hpp"
#include "N/ADD_NN_N.hpp"

Polynomial MUL_Pxk_P(const Polynomial& a, const LongNatural& k) {
    const std::map<LongNatural, LongRational>& polyMap = a.getMap();  // возвращает вектор коэффициентов
    std::map<LongNatural, LongRational> newPolyMap;  // Новый map для хранения результата

    // Проходим по всем элементам исходного polyMap
    for (const auto& pair : polyMap) {
        LongNatural newKey = ADD_NN_N(pair.first, k);  // Новый ключ
        LongRational value = pair.second;      // Значение остается прежним
        newPolyMap[newKey] = value;           // Добавляем в новый map
    }

    // Возвращаем новый полином с обновленным map
    return Polynomial(newPolyMap);
}