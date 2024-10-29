#include <gtest/gtest.h>

#include "P/MUL_Pxk_P.hpp"
#include "P/Polynomial.hpp"

TEST(test_MUL_Pxk_P, NormalPolynomial) {
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    LongRational zero = LongRational(LongInteger("0"), LongNatural("1"));  // ноль для результата
    Polynomial a({num1, num2, num3, num4});
    Polynomial res({num1, num2, num3, num4, zero, zero, zero, zero});
    EXPECT_EQ(MUL_Pxk_P(a, static_cast<size_t>(4)), res);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^4 = (8/3)x^7 + 3x^6 + 6x^5 + 4x^4
}

TEST(test_MUL_Pxk_P, ZeroDegree) {
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    Polynomial a({num1, num2, num3, num4});
    EXPECT_EQ(MUL_Pxk_P(a, static_cast<size_t>(0)), a);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^0 = (8/3)x^3 + 3x^2 + 6x^1 + 4x^0
}

TEST(test_MUL_Pxk_P, FirstDegree) {
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    LongRational zero = LongRational(LongInteger("0"), LongNatural("1"));  // ноль для результата
    Polynomial a({num1, num2, num3, num4});
    Polynomial res({num1, num2, num3, num4, zero});
    EXPECT_EQ(MUL_Pxk_P(a, static_cast<size_t>(1)), res);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^1 = (8/3)x^4 + 3x^3 + 6x^2 + 4x^1
}