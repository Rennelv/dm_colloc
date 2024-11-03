#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/MOD_PP_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

// Тест деления многочленов с нулевым остатком
TEST(MOD_PP_P, DivisionWithoutRemainder) {
    // Создаем многочлен p1 = x^2 - 1 и p2 = x - 1
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p1(p1_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый остаток: 0 (нулевой многочлен)
    std::map<LongNatural, LongRational> zero_map;
    zero_map.emplace(LongNatural("0"), LongRational(LongInteger("0"), LongNatural("1")));
    Polynomial expected(zero_map);

    EXPECT_EQ(MOD_PP_P(p1, p2), expected);
}

// Тест деления многочлена на единичный многочлен
TEST(MOD_PP_P, DivisionByOne) {
    // Создаем многочлен p1 = x^2 + x + 1
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(p1_map);

    // Создаем единичный многочлен p2 = 1
    std::map<LongNatural, LongRational> one_map;
    one_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p2(one_map);

    // Ожидаемый остаток: 0 (нулевой многочлен)
    std::map<LongNatural, LongRational> zero_map;
    Polynomial expected(zero_map);

    EXPECT_EQ(MOD_PP_P(p1, p2), expected);
}

// Тест деления многочлена на более высокий по степени
TEST(MOD_PP_P, DivisionByHigherDegree) {
    // Создаем многочлен p1 = x^2 + x + 1 и делитель p2 = x^3
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(p1_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("3"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый остаток: p1 (так как степень p1 < степень p2)
    EXPECT_EQ(MOD_PP_P(p1, p2), p1);
}

// Тест деления нулевого многочлена на ненулевой
TEST(MOD_PP_P, ZeroDividend) {
    // Создаем многочлен p1 и ненулевой многочлен p2
    std::map<LongNatural, LongRational> zero_map;
    Polynomial p1(zero_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый остаток: 0 (нулевой многочлен)
    Polynomial expected(zero_map);

    EXPECT_EQ(MOD_PP_P(p1, p2), expected);
}
