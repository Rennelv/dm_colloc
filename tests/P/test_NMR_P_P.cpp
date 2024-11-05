#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/NMR_P_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(NMR_P_P, SimplifyMultipleRoot) {
    // Многочлен p = x^2 + 2x + 1
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));  // x^2
    p_map.emplace(LongNatural("1"), LongRational(LongInteger("2"), LongNatural("1")));  // 2x
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));  // +1
    Polynomial p(p_map);

    // Ожидаемый результат: x + 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));  // x
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));  // +1
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}

// НЕ ПАШЕТ :(
TEST(NMR_P_P, MUNMRRtest) {
    // Многочлен p = x^2 - 1
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));   // x^2
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));  // +1
    Polynomial p(p_map);

    // Ожидаемый результат: x^2 - 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}

// НЕ ПАШЕТ :(
TEST(NMR_P_P, MultipleRootsSimplified) {
    // Многочлен p = x^3 + x^2 - x - 1
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("3"), LongRational(LongInteger("1"), LongNatural("1")));   // x^3
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));   // x^2
    p_map.emplace(LongNatural("1"), LongRational(LongInteger("-1"), LongNatural("1")));  // -x
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));  // -1
    Polynomial p(p_map);

    // Ожидаемый результат: x^2 - 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));   // x^2
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));  // -1
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}
