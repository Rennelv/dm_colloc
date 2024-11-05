#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/NMR_P_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

// test 1
TEST(NMR_P_P, SimplifyMultipleRoot) {
    // Многочлен p = x^2 + 2x + 1
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p_map.emplace(LongNatural("1"), LongRational(LongInteger("2"), LongNatural("1")));
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p(p_map);

    // Ожидаемый результат: x + 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}

// test 2
TEST(NMR_P_P, WithoutMultipleRoots) {
    // Многочлен p = x^2 - 1
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p(p_map);

    // Ожидаемый результат: x^2 - 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}

//
TEST(NMR_P_P, SecondDegreeRoot) {
    // Многочлен p = x^3 + x^2 - x - 1 [ что равно (x-1)(x+1)^2 ]
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("3"), LongRational(LongInteger("1"), LongNatural("1")));
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p_map.emplace(LongNatural("1"), LongRational(LongInteger("-1"), LongNatural("1")));
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p(p_map);

    // Ожидаемый результат: x^2 - 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}

TEST(NMR_P_P, JustNumber) {
    // Многочлен p = 17
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("17"), LongNatural("1")));  // 17
    Polynomial p(p_map);

    // Ожидаемый результат: 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));  // 1
    Polynomial expected(expected_map);

    EXPECT_EQ(NMR_P_P(p), expected);
}

TEST(NMR_P_P, NoRoots) {
    // Многочлен p = x^4 + x^2 + 1
    std::map<LongNatural, LongRational> p_map;
    p_map.emplace(LongNatural("4"), LongRational(LongInteger("1"), LongNatural("1")));   // x^4
    p_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));   // x^2
    p_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));  // -1
    Polynomial p(p_map);
    // Ожидаемый результат: x^4 + x^2 +1

    EXPECT_EQ(NMR_P_P(p), p);
}
