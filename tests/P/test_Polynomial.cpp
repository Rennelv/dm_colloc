#include "P/Polynomial.hpp"
#include "Z/LongInteger.hpp"
#include "gtest/gtest.h"

TEST(PolynomialTest, ConstructorFromInitializerList) {
    Polynomial p = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    std::vector<LongInteger> expected = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    EXPECT_EQ(p.getArr(), expected);
}

TEST(PolynomialTest, ConstructorFromArray) {
    LongInteger arr[] = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    Polynomial p(3, arr);
    std::vector<LongInteger> expected = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    EXPECT_EQ(p.getArr(), expected);
}

TEST(PolynomialTest, ConstructorFromVector) {
    std::vector<LongInteger> vec = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    Polynomial p(vec);
    EXPECT_EQ(p.getArr(), vec);
}

TEST(PolynomialTest, ToString) {
    Polynomial p = {LongInteger{"-1"}, LongInteger{"0"}, LongInteger{"3"}};
    std::string expected = "-1x^2 + 3";
    EXPECT_EQ(p.toString(), expected);
}

TEST(PolynomialTest, GetLength) {
    Polynomial p = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    EXPECT_EQ(p.getLength(), 3);
}

TEST(PolynomialTest, Degree) {
    Polynomial p = {LongInteger{"1"}, LongInteger{"2"}, LongInteger{"3"}};
    EXPECT_EQ(p.degree(), 2);
}
