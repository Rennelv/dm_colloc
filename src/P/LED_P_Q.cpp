#include "P/LED_P_Q.hpp"

LongRational LED_P_Q(const Polynomial& a) {
    const std::map<LongNatural, LongRational>& poly_map = a.getMap();  // возвращает мап коэффициентов
    if (poly_map.empty()) {
        return LongRational(LongInteger("0"), LongNatural("1"));  // возвращает 0, если мап пустой
    } else {
        auto it = poly_map.begin();
        while (it != poly_map.end()) {
            if (it->first != LongNatural("0")) {  // если ключ не равен 0
                return it->second;                // возвращает старший коэффициент
            }
            ++it;
        }
    }
    // Если не найдено ни одного ненулевого ключа
    return LongRational(LongInteger("0"), LongNatural("1"));
}
