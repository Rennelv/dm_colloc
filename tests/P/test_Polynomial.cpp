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
    Polynomial p = {LongRational(LongInteger{"-1"}, LongNatural{"1"}), LongRational(LongInteger{"-2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"-3"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"-1"}, LongNatural{"1"}), LongRational(LongInteger{"-2"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"-3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), 2);
    EXPECT_EQ(p.toString(), "(-1/1)x^2 + (-2/1)x^1 + (-3/1)");
    EXPECT_EQ(p.at(1), LongRational(LongInteger{"-2"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(2), LongRational(LongInteger{"-1"}, LongNatural{"1"}));
}

TEST(PolynomialTest, MixedCoefficients) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"-2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"-2"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), 2);
    EXPECT_EQ(p.toString(), "(1/1)x^2 + (-2/1)x^1 + (3/1)");
    EXPECT_EQ(p.at(0), LongRational(LongInteger{"1"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(1), LongRational(LongInteger{"-2"}, LongNatural{"1"}));
}

TEST(PolynomialTest, SingleTermPolynomial) {
    Polynomial p = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                    LongRational(LongInteger{"5"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"0"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"5"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), 2);
    EXPECT_EQ(p.toString(), "(5/1)");
    EXPECT_EQ(p.at(2), LongRational(LongInteger{"5"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(0), LongRational(LongInteger{"5"}, LongNatural{"1"}));
}
TEST(PolynomialTest, AtMethod) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.at(0), LongRational(LongInteger{"1"}, LongNatural{"1"}));
    EXPECT_EQ(p.at(1), LongRational(LongInteger{"2"}, LongNatural{"1"}));
    EXPECT_EQ(p.at(2), LongRational(LongInteger{"3"}, LongNatural{"1"}));
}

TEST(PolynomialTest, GetCoefMethod) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getCoef(0), LongRational(LongInteger{"3"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(1), LongRational(LongInteger{"2"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(2), LongRational(LongInteger{"1"}, LongNatural{"1"}));
}

TEST(PolynomialTest, InequalityOperator) {
    Polynomial p1 = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                     LongRational(LongInteger{"3"}, LongNatural{"1"})};
    Polynomial p2 = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                     LongRational(LongInteger{"3"}, LongNatural{"1"})};
    Polynomial p3 = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"})};

    EXPECT_FALSE(p1 != p2);
    EXPECT_TRUE(p1 != p3);
}

TEST(PolynomialTest, EmptyPolynomial) {
    Polynomial p = {};
    std::vector<LongRational> expected = {};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), static_cast<size_t>(-1));  // Degree of an empty polynomial might be considered -1
    EXPECT_EQ(p.toString(), "");
}

TEST(PolynomialTest, LargePolynomial) {
    std::vector<LongRational> vec;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(LongRational(LongInteger{std::to_string(i)}, LongNatural{"1"}));
    }
    Polynomial p(vec);
    EXPECT_EQ(p.getArr(), vec);
    EXPECT_EQ(p.getDegree(), 999);
    EXPECT_EQ(p.at(500), LongRational(LongInteger{"500"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(500), LongRational(LongInteger{std::to_string(999 - 500)}, LongNatural{"1"}));
}

TEST(PolynomialTest, PolynomialWithZeroLeadingCoefficient) {
    Polynomial p = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"1"}, LongNatural{"1"}),
                    LongRational(LongInteger{"2"}, LongNatural{"1"})};
    std::vector<LongRational> expected = {LongRational(LongInteger{"0"}, LongNatural{"1"}), LongRational(LongInteger{"1"}, LongNatural{"1"}),
                                          LongRational(LongInteger{"2"}, LongNatural{"1"})};
    EXPECT_EQ(p.getArr(), expected);
    EXPECT_EQ(p.getDegree(), 2);
    EXPECT_EQ(p.toString(), "(1/1)x^1 + (2/1)");
    EXPECT_EQ(p.at(1), LongRational(LongInteger{"1"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(1), LongRational(LongInteger{"1"}, LongNatural{"1"}));
}

TEST(PolynomialTest, GetCoefMethodOutOfRange) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getCoef(3), LongRational(LongInteger{"0"}, LongNatural{"1"}));
    EXPECT_EQ(p.getCoef(4), LongRational(LongInteger{"0"}, LongNatural{"1"}));
}