#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/MUL_Pxk_P.hpp"
#include "P/Polynomial.hpp"

TEST(test_MUL_Pxk_P, NormalPolynomial) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    res_pol.emplace(LongNatural("7"), num1);
    res_pol.emplace(LongNatural("6"), num2);
    res_pol.emplace(LongNatural("5"), num3);
    res_pol.emplace(LongNatural("4"), num4);
    Polynomial a(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(MUL_Pxk_P(a, LongNatural("4")), res);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^4 = (8/3)x^7 + 3x^6 + 6x^5 + 4x^4
}

TEST(test_MUL_Pxk_P, ZeroDegree) {
    std::map<LongNatural, LongRational> fst_pol;
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    Polynomial a(fst_pol);
    EXPECT_EQ(MUL_Pxk_P(a, LongNatural("0")), a);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^0 = (8/3)x^3 + 3x^2 + 6x^1 + 4x^0
}

TEST(test_MUL_Pxk_P, FirstDegree) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    res_pol.emplace(LongNatural("4"), num1);
    res_pol.emplace(LongNatural("3"), num2);
    res_pol.emplace(LongNatural("2"), num3);
    res_pol.emplace(LongNatural("1"), num4);
    Polynomial a(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(MUL_Pxk_P(a, LongNatural("1")), res);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^1 = (8/3)x^4 + 3x^3 + 6x^2 + 4x^1
}
TEST(test_MUL_Pxk_P, EmptyPolynomial) {
    std::map<LongNatural, LongRational> fst_pol;
    Polynomial a(fst_pol);
    EXPECT_EQ(MUL_Pxk_P(a, LongNatural("4")), a);  // 0 * x^4 = 0
}
