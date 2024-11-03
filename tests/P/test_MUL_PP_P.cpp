#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/MUL_PP_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

// Тест умножения многочлена на нулевой многочлен
TEST(MUL_PP_P, MultiplyByZero) {
    // Создаем многочлен p1: 3x^2 + x
    std::map<LongNatural, LongRational> fst_pol;
    fst_pol.emplace(LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1")));
    fst_pol.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(fst_pol);

    // Нулевой многочлен p2
    std::map<LongNatural, LongRational> zero_pol;
    zero_pol.emplace(LongNatural("0"), LongRational(LongInteger("0"), LongNatural("1")));
    Polynomial p2(zero_pol);

    // Ожидаемый результат - нулевой многочлен
    Polynomial expected(zero_pol);

    EXPECT_EQ(MUL_PP_P(p1, p2), expected);
    EXPECT_EQ(MUL_PP_P(p2, p1), expected);
}

// Тест умножения одночленов
TEST(MUL_PP_P, MultiplyMonomials) {
    // Создаем одночлены p1 и p2: p1 = 2x, p2 = 3x
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("2"), LongNatural("1")));
    Polynomial p1(p1_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("1"), LongRational(LongInteger("3"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый результат: 6x^2
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("6"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(MUL_PP_P(p1, p2), expected);
}

// Тест умножения многочлена на константу
TEST(MUL_PP_P, MultiplyByConstant) {
    // Создаем многочлен p1: 4x^2 + 2x
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("2"), LongRational(LongInteger("4"), LongNatural("1")));
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("2"), LongNatural("1")));
    Polynomial p1(p1_map);

    // Константа p2 = 3
    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("3"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый результат: 12x^2 + 6x
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("12"), LongNatural("1")));
    expected_map.emplace(LongNatural("1"), LongRational(LongInteger("6"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(MUL_PP_P(p1, p2), expected);
}

// Тест умножения двух многочленов
TEST(MUL_PP_P, MultiplyPolynomials) {
    // Создаем многочлены p1 = x + 1 и p2 = x - 1
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial p1(p1_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("1"), LongRational(LongInteger("1"), LongNatural("1")));
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый результат: x^2 - 1
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("1"), LongNatural("1")));
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("-1"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(MUL_PP_P(p1, p2), expected);
}

// Тест умножения многочлена на многочлен с пропуском степеней
TEST(MUL_PP_P, MultiplyPolynomialsWithGaps) {
    // Создаем многочлен p1 = 5x^3 + 2 и многочлен p2 = 3x^2 + 4
    std::map<LongNatural, LongRational> p1_map;
    p1_map.emplace(LongNatural("3"), LongRational(LongInteger("5"), LongNatural("1")));
    p1_map.emplace(LongNatural("0"), LongRational(LongInteger("2"), LongNatural("1")));
    Polynomial p1(p1_map);

    std::map<LongNatural, LongRational> p2_map;
    p2_map.emplace(LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1")));
    p2_map.emplace(LongNatural("0"), LongRational(LongInteger("4"), LongNatural("1")));
    Polynomial p2(p2_map);

    // Ожидаемый результат: 15x^5 + 20x^3 + 6x^2 + 8
    std::map<LongNatural, LongRational> expected_map;
    expected_map.emplace(LongNatural("5"), LongRational(LongInteger("15"), LongNatural("1")));
    expected_map.emplace(LongNatural("3"), LongRational(LongInteger("20"), LongNatural("1")));
    expected_map.emplace(LongNatural("2"), LongRational(LongInteger("6"), LongNatural("1")));
    expected_map.emplace(LongNatural("0"), LongRational(LongInteger("8"), LongNatural("1")));
    Polynomial expected(expected_map);

    EXPECT_EQ(MUL_PP_P(p1, p2), expected);
}
