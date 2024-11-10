#include "P/LED_P_Q.hpp"

LongRational LED_P_Q(const Polynomial& a) {
    const std::map<LongNatural, LongRational>& poly_map = a.getMap();  // возвращает мап коэффициентов
    if (poly_map.empty()) {
        return LongRational::ZERO;  // возвращает 0, если мап пустой
    } else {
        // начало мап -> наибольшая степень, старший коэффициент
        return poly_map.rbegin()->second;  // возвращает старший коэффициент
    }
}