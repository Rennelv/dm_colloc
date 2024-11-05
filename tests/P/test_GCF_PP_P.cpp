#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/GCF_PP_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

// Тест на НОД двух многочленов без остатка
TEST(GCF_PP_P, GCDWithoutRemainder) {
    // Создаем многочлен p1 = x^2 - 1 и p2 = x - 1
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p1(p1_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый НОД: x - 1
    Polynomial expected(p2_map);

    EXPECT_EQ(GCF_PP_P(p1, p2), expected);
}

// Тест на НОД многочленов с результатом x^2 + 1
TEST(GCF_PP_P, GCDWithSpecificPolynomials) {
    // Создаем многочлен p1 = x^3 + x^2 + x + 1
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("3"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(p1_map);

    // Создаем многочлен p2 = x^2 + 1
    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый НОД: x^2 + 1
    Polynomial expected(p2_map);

    EXPECT_EQ(GCF_PP_P(p1, p2), expected);
}

// Тест на НОД, когда один из многочленов нулевой
TEST(GCF_PP_P, GCDWithZeroPolynomial) {
    // Создаем многочлен p1 = x^2 + x + 1 и нулевой многочлен p2
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(p1_map);

    // Нулевой многочлен p2
    std::map<LongNatural, LongRational> zero_map;
    Polynomial p2(zero_map);

    // Ожидаемый НОД: p1
    EXPECT_EQ(GCF_PP_P(p1, p2), p1);
}

// Тест на возврыт приведенного многочлена
TEST(GCF_PP_P, MyGCDTest) {
    // Создаем многочлен p1 = x^2 + 2x + 1
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("2"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(p1_map);

    // Создаем многочлен p2 = 2x + 2
    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("1"), LongRational(LongInteger("2"), LongNatural("1")));
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("2"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый НОД: x + 1
    std::map<LongNatural, LongRational> res_map;
    res_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    res_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial expected(res_map);

    EXPECT_EQ(GCF_PP_P(p1, p2), expected);
}
