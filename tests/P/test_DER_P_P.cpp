#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/DER_P_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(test_DER_P_P, AllDegreesAre) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("1"), LongNatural("4"));
    LongRational num2 = LongRational(LongInteger("8"), LongNatural("7"));
    LongRational num3 = LongRational(LongInteger("2"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("3"), LongNatural("5"));
    LongRational num5 = LongRational(LongInteger("6"), LongNatural("13"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("1"), num2);
    fst_pol.emplace(LongNatural("4"), num3);
    fst_pol.emplace(LongNatural("2"), num4);
    fst_pol.emplace(LongNatural("0"), num5);
    LongRational num6 = LongRational(LongInteger("3"), LongNatural("4"));
    LongRational num7 = LongRational(LongInteger("8"), LongNatural("7"));
    LongRational num8 = LongRational(LongInteger("8"), LongNatural("1"));
    LongRational num9 = LongRational(LongInteger("6"), LongNatural("5"));
    res_pol.emplace(LongNatural("2"), num6);
    res_pol.emplace(LongNatural("0"), num7);
    res_pol.emplace(LongNatural("3"), num8);
    res_pol.emplace(LongNatural("1"), num9);
    Polynomial a(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(DER_P_P(a), res);  // (2x^4 + (1/4)x^3 + (3/5)x^2 + (8/7)x^1 + (6/13)x^0)' = 8x^3 + (3/4)x^2 + (6/5)x^1 + (8/7)x^0
}

TEST(test_ABS_Z_N, DegreesAreMissing) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num3 = LongRational(LongInteger("2"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("3"), LongNatural("5"));
    LongRational num5 = LongRational(LongInteger("6"), LongNatural("13"));
    fst_pol.emplace(LongNatural("4"), num3);
    fst_pol.emplace(LongNatural("2"), num4);
    fst_pol.emplace(LongNatural("0"), num5);
    LongRational num8 = LongRational(LongInteger("8"), LongNatural("1"));
    LongRational num9 = LongRational(LongInteger("6"), LongNatural("5"));
    res_pol.emplace(LongNatural("3"), num8);
    res_pol.emplace(LongNatural("1"), num9);
    Polynomial a(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(DER_P_P(a), res);  // (2x^4 + (3/5)x^2 + (6/13)x^0)' = 8x^3 + (6/5)x^1
}

TEST(test_ABS_Z_N, Number) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num5 = LongRational(LongInteger("6"), LongNatural("13"));
    fst_pol.emplace(LongNatural("0"), num5);
    Polynomial a(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(DER_P_P(a), res);  // ((6/13)x^0)' =
}
