#include "P/LED_P_Q.hpp"

Polynomial LED_P_Q_P(const Polynomial& a) {
    const std::map<LongNatural, LongRational>& poly_map = a.getMap();  // возвращает мап коэффициентов
    LongNatural biggest_key = LongNatural("0");
    for (const auto& [key, value] : poly_map) {
        if (key > biggest_key) {
            biggest_key = key;
        }
    }
    // Возвращаем новый полином с обновленным map
    return poly_map.getCoef(biggest_key);
}