#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/FAC_P_Q.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(test_FAC_P_Q, IntegerCoefficients) {
    std::map<LongNatural, LongRational> poly;
    poly.emplace(LongNatural("2"), LongRational(LongInteger("6"), LongNatural("1")));
    poly.emplace(LongNatural("1"), LongRational(LongInteger("9"), LongNatural("1")));
    poly.emplace(LongNatural("0"), LongRational(LongInteger("12"), LongNatural("1")));
    Polynomial a(poly);
    LongRational result = FAC_P_Q(a);

    std::map<LongNatural, LongRational> expect_poly;
    expect_poly.emplace(LongNatural("2"), LongRational(LongInteger("2"), LongNatural("1")));
    expect_poly.emplace(LongNatural("1"), LongRational(LongInteger("3"), LongNatural("1")));
    expect_poly.emplace(LongNatural("0"), LongRational(LongInteger("4"), LongNatural("1")));
    Polynomial expect(expect_poly);

    EXPECT_EQ(a.toString(), expect.toString());          // (6/1)x^2 + (9/1)x^1 + (12/1)x^0 = [(2/1)x^2 + (3/1)x^1 + (4/1)x^0] * (3/1)
    EXPECT_EQ(result.getNumerator().toString(), "3");    // Ожидаемый НОД = 3
    EXPECT_EQ(result.getDenominator().toString(), "1");  // Ожидаемый НОК 1
}

TEST(test_FAC_P_Q, FractionalCoefficients) {
    std::map<LongNatural, LongRational> poly;
    poly.emplace(LongNatural("2"), LongRational(LongInteger("4"), LongNatural("5")));
    poly.emplace(LongNatural("1"), LongRational(LongInteger("6"), LongNatural("10")));
    poly.emplace(LongNatural("0"), LongRational(LongInteger("8"), LongNatural("15")));
    Polynomial a(poly);
    LongRational result = FAC_P_Q(a);

    std::map<LongNatural, LongRational> expect_poly;
    expect_poly.emplace(LongNatural("2"), LongRational(LongInteger("12"), LongNatural("1")));
    expect_poly.emplace(LongNatural("1"), LongRational(LongInteger("9"), LongNatural("1")));
    expect_poly.emplace(LongNatural("0"), LongRational(LongInteger("8"), LongNatural("1")));
    Polynomial expect(expect_poly);

    EXPECT_EQ(a.toString(), expect.toString());           // (4/5)x^2 + (6/10)x^1 + (8/15)x^0 = [(12/1)x^2 + (9/1)x^1 + (8/1)x^0] * (2/30)
    EXPECT_EQ(result.getNumerator().toString(), "1");     // Ожидаемый НОД = 1
    EXPECT_EQ(result.getDenominator().toString(), "15");  // Ожидаемый НОК = 15
}

TEST(test_FAC_P_Q, GCFAndLCMAreOne) {
    std::map<LongNatural, LongRational> poly;
    poly.emplace(LongNatural("1"), LongRational(LongInteger("7"), LongNatural("1")));
    poly.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial a(poly);
    LongRational result = FAC_P_Q(a);

    std::map<LongNatural, LongRational> expect_poly;
    expect_poly.emplace(LongNatural("1"), LongRational(LongInteger("7"), LongNatural("1")));
    expect_poly.emplace(LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1")));
    Polynomial expect(expect_poly);

    EXPECT_EQ(a.toString(), expect.toString());          // (7/1)x^1 + (1/1)x^0 = (7/1)x^1 + (1/1)x^0
    EXPECT_EQ(result.getNumerator().toString(), "1");    // Ожидаемый НОД = 1
    EXPECT_EQ(result.getDenominator().toString(), "1");  // Ожидаемый НОК  = 1
}

TEST(test_FAC_P_Q, ZeroCoefficient) {
    std::map<LongNatural, LongRational> poly;
    poly.emplace(LongNatural("3"), LongRational(LongInteger("12"), LongNatural("1")));
    poly.emplace(LongNatural("2"), LongRational(LongInteger("0"), LongNatural("1")));
    poly.emplace(LongNatural("1"), LongRational(LongInteger("18"), LongNatural("1")));
    poly.emplace(LongNatural("0"), LongRational(LongInteger("24"), LongNatural("1")));
    Polynomial a(poly);
    LongRational result = FAC_P_Q(a);

    std::map<LongNatural, LongRational> expect_poly;
    expect_poly.emplace(LongNatural("3"), LongRational(LongInteger("2"), LongNatural("1")));
    expect_poly.emplace(LongNatural("1"), LongRational(LongInteger("3"), LongNatural("1")));
    expect_poly.emplace(LongNatural("0"), LongRational(LongInteger("4"), LongNatural("1")));
    Polynomial expect(expect_poly);

    EXPECT_EQ(a.toString(), expect.toString());          // (12/1)x^3 + (18/1)x^1 + (24/1)x^0 = [(2/1)x^3 + (3/1)x^1 + (4/1)x^0] * (6/1)
    EXPECT_EQ(result.getNumerator().toString(), "6");    // Ожидаемый НОД = 6
    EXPECT_EQ(result.getDenominator().toString(), "1");  // Ожидаемый НОК = 1
}

TEST(test_FAC_P_Q, ZeroPolynomial) {
    std::map<LongNatural, LongRational> poly;
    poly.emplace(LongNatural("0"), LongRational(LongInteger("0"), LongNatural("1")));
    Polynomial a(poly);
    LongRational result = FAC_P_Q(a);

    std::map<LongNatural, LongRational> expect_poly;
    expect_poly.emplace(LongNatural("0"), LongRational(LongInteger("0"), LongNatural("1")));
    Polynomial expect(expect_poly);

    EXPECT_EQ(a.toString(), expect.toString());          // (0/1)x^0 = (0/1)x^0
    EXPECT_EQ(result.getNumerator().toString(), "0");    // Ожидаемый НОД = 0
    EXPECT_EQ(result.getDenominator().toString(), "1");  // Ожидаемый НОК = 1
}