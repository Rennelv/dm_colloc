#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

// Test for Polynomial constructor and getDegree method
TEST(PolynomialTest, ConstructorAndGetDegree) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.getDegree(), LongNatural("2"));
}

// Test for getCoef method
TEST(PolynomialTest, GetCoef) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.getCoef(LongNatural("2")), LongRational(LongInteger("3"), LongNatural("1")));
    EXPECT_EQ(p.getCoef(LongNatural("1")), LongRational(LongInteger("0"), LongNatural("1")));
}

// Test for toString method
TEST(PolynomialTest, ToString) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.toString(), "(3/1)x^2 + 1/1");
}

// Test for empty polynomial
TEST(PolynomialTest, EmptyPolynomial) {
    std::map<LongNatural, LongRational> coefficients;
    Polynomial p(coefficients);
    EXPECT_EQ(p.getDegree(), LongNatural("0"));
    EXPECT_EQ(p.toString(), "0");
}

// Test for polynomial with zero coefficients
TEST(PolynomialTest, ZeroCoefficients) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("0"), LongNatural("1"))},
                                                        {LongNatural("1"), LongRational(LongInteger("0"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("0"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.getDegree(), LongNatural("0"));
    EXPECT_EQ(p.toString(), "0");
}

// Test for equality operator
TEST(PolynomialTest, EqualityOperator) {
    std::map<LongNatural, LongRational> coefficients1 = {{LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                         {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    std::map<LongNatural, LongRational> coefficients2 = {{LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                         {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p1(coefficients1);
    Polynomial p2(coefficients2);
    EXPECT_TRUE(p1 == p2);
}

// Test for inequality operator
TEST(PolynomialTest, InequalityOperator) {
    std::map<LongNatural, LongRational> coefficients1 = {{LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                         {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    std::map<LongNatural, LongRational> coefficients2 = {{LongNatural("1"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                         {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p1(coefficients1);
    Polynomial p2(coefficients2);
    EXPECT_TRUE(p1 != p2);
}

// Test for polynomial with leading zero coefficients
TEST(PolynomialTest, LeadingZeroCoefficients) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("3"), LongRational(LongInteger("0"), LongNatural("1"))},
                                                        {LongNatural("2"), LongRational(LongInteger("3"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.getDegree(), LongNatural("2"));
    EXPECT_EQ(p.toString(), "(3/1)x^2 + 1/1");
}

// Test for polynomial with negative coefficients
TEST(PolynomialTest, NegativeCoefficients) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("-3"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("1"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.getDegree(), LongNatural("2"));
    EXPECT_EQ(p.toString(), "(-3/1)x^2 + 1/1");
}

// Test for polynomial with large coefficients
TEST(PolynomialTest, LargeCoefficients) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("12345678901234567890"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("98765432109876543210"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.getDegree(), LongNatural("2"));
    EXPECT_EQ(p.toString(), "(12345678901234567890/1)x^2 + 98765432109876543210/1");
}

// Test isCoefZero for polynomial with large coefficients
TEST(PolynomialTest, IsZero) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("0"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("98765432109876543210"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.isCoefZero(LongNatural({0})), false);
    EXPECT_EQ(p.isCoefZero(LongNatural({2})), true);
    EXPECT_EQ(p.isCoefZero(LongNatural({9})), true);
}