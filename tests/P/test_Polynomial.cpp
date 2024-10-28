#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"
#include "gtest/gtest.h"

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

TEST(PolynomialTest, GetLength) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.getLength(), 3);
}

TEST(PolynomialTest, Degree) {
    Polynomial p = {LongRational(LongInteger{"1"}, LongNatural{"1"}), LongRational(LongInteger{"2"}, LongNatural{"1"}),
                    LongRational(LongInteger{"3"}, LongNatural{"1"})};
    EXPECT_EQ(p.degree(), 2);
}