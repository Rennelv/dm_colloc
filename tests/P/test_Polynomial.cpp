#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(PolynomialTest, ConstructorFromInitializerList) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
}

TEST(PolynomialTest, ConstructorFromArray) {
    LongRational arr[] = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                          LongRational(LongInteger{"3"}, LongNatural{"1"})};
    Polynomial p(3, arr);
    std::vector<LongRational> expected = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
}

TEST(PolynomialTest, ConstructorFromVector) {
    std::vector<LongRational> vec = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                                     LongRational(LongInteger{"3"}, LongNatural{"1"})};
    Polynomial p(vec);
    EXPECT_EQ(p.getArr(), vec);
}

TEST(PolynomialTest, ToString) {
    Polynomial p = {LongRational(LongInteger{"-1"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    std::string expected = "(-1/1)x^2 + (3/1)";
    EXPECT_EQ(p.toString(), expected);
}

TEST(PolynomialTest, Degree) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getDegree(), 2);
}

TEST(PolynomialTest, EqualityOperator) {
    Polynomial p1 = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                     LongRational(LongInteger{"3"}, LongNatural{"1"})};
    Polynomial p2 = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                     LongRational(LongInteger{"3"}, LongNatural{"1"})};
    Polynomial p3 = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"})};

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PolynomialTest, ZeroPolynomial) {
    Polynomial p = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                    LongRational(LongInteger{"0"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"0"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), 2);
    EXPECT_EQ(p.toString(), "");
    EXPECT_EQ(p.at(0), LongRational(LongInteger{"0"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(2), LongRational(LongInteger{"0"}, LongNatural{"1"}));
}

TEST(PolynomialTest, LeadingZeroCoefficients) {
    Polynomial p = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), 2);
    EXPECT_EQ(p.toString(), "(3/1)");
    EXPECT_EQ(p.at(2), LongRational(LongInteger{"3"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(0), LongRational(LongInteger{"3"}, LongNatural{"1"}));
}

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

// Test for polynomial with large coefficients
TEST(PolynomialTest, IsZero) {
    std::map<LongNatural, LongRational> coefficients = {{LongNatural("2"), LongRational(LongInteger("0"), LongNatural("1"))},
                                                        {LongNatural("0"), LongRational(LongInteger("98765432109876543210"), LongNatural("1"))}};
    Polynomial p(coefficients);
    EXPECT_EQ(p.isCoefZero(LongNatural({0})), false);
    EXPECT_EQ(p.isCoefZero(LongNatural({2})), true);
    EXPECT_EQ(p.isCoefZero(LongNatural({9})), true);
}