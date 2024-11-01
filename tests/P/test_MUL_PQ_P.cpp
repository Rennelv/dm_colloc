#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/MUL_PQ_P.hpp"
#include "P/Polynomial.hpp"

TEST(test_MUL_PQ_P, NormalPolynomial) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    LongRational num5 = LongRational(LongInteger("16"), LongNatural("9"));
    LongRational num6 = LongRational(LongInteger("2"), LongNatural("1"));
    LongRational num7 = LongRational(LongInteger("4"), LongNatural("1"));
    LongRational num8 = LongRational(LongInteger("8"), LongNatural("3"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    res_pol.emplace(LongNatural("3"), num5);
    res_pol.emplace(LongNatural("2"), num6);
    res_pol.emplace(LongNatural("1"), num7);
    res_pol.emplace(LongNatural("0"), num8);
    Polynomial a(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(MUL_PQ_P(a, LongRational(LongInteger("2"), LongNatural("3"))),
              res);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * (2/3) = (16/9)x^3 + 2x^2 + 4x^1 + (8/3)x^0
}
TEST(test_MUL_PQ_P, MulZero) {
    std::map<LongNatural, LongRational> fst_pol;
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    LongRational zero = LongRational(LongInteger("0"), LongNatural("1"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    Polynomial a(fst_pol);
    EXPECT_EQ(MUL_PQ_P(a, zero), zero);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * 0 = 0
}

TEST(test_MUL_PQ_P, EmptyPolynomial) {
    std::map<LongNatural, LongRational> fst_pol;
    Polynomial a(fst_pol);
    EXPECT_EQ(MUL_PQ_P(a, LongRational(LongInteger("2"), LongNatural("3"))), a);  // 0 * 2/3 = 0
}
