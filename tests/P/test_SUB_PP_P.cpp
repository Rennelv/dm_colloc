#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "P/SUB_PP_P.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(test_SUB_PP_P, AllDegreesAre) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> scn_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("1"), LongNatural("4"));
    LongRational num2 = LongRational(LongInteger("8"), LongNatural("7"));
    LongRational num3 = LongRational(LongInteger("2"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("3"), LongNatural("5"));
    LongRational num5 = LongRational(LongInteger("6"), LongNatural("13"));
    fst_pol.emplace(LongNatural("0"), num1);
    fst_pol.emplace(LongNatural("1"), num2);
    fst_pol.emplace(LongNatural("2"), num3);
    fst_pol.emplace(LongNatural("3"), num4);
    fst_pol.emplace(LongNatural("4"), num5);
    LongRational num6 = LongRational(LongInteger("2"), LongNatural("3"));
    LongRational num7 = LongRational(LongInteger("1"), LongNatural("7"));
    LongRational num8 = LongRational(LongInteger("11"), LongNatural("10"));
    LongRational num9 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num10 = LongRational(LongInteger("1"), LongNatural("6"));
    scn_pol.emplace(LongNatural("0"), num6);
    scn_pol.emplace(LongNatural("1"), num7);
    scn_pol.emplace(LongNatural("2"), num8);
    scn_pol.emplace(LongNatural("3"), num9);
    scn_pol.emplace(LongNatural("4"), num10);
    LongRational num11 = LongRational(LongInteger("-5"), LongNatural("12"));
    LongRational num12 = LongRational(LongInteger("1"), LongNatural("1"));
    LongRational num13 = LongRational(LongInteger("9"), LongNatural("10"));
    LongRational num14 = LongRational(LongInteger("-12"), LongNatural("5"));
    LongRational num15 = LongRational(LongInteger("23"), LongNatural("78"));
    res_pol.emplace(LongNatural("0"), num11);
    res_pol.emplace(LongNatural("1"), num12);
    res_pol.emplace(LongNatural("2"), num13);
    res_pol.emplace(LongNatural("3"), num14);
    res_pol.emplace(LongNatural("4"), num15);
    Polynomial a(fst_pol);
    Polynomial b(scn_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(SUB_PP_P(a, b), res);  // ((6/13)x^4 + (3/5)x^3 + (2/1)x^2 + (8/7)x + 1/4) - ((1/6)x^4 + (3/1)x^3 + (11/10)x^2 + (1/7)x + 2/3) = ((23/78)x^4 +
                                     // (-12/5)x^3 + (9/10)x^2 + (1/1)x + (-5/12))
}

TEST(test_SUB_PP_P, DegreesAreMissing) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> scn_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("1"), LongNatural("4"));
    LongRational num3 = LongRational(LongInteger("2"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("3"), LongNatural("5"));
    LongRational num5 = LongRational(LongInteger("6"), LongNatural("13"));
    fst_pol.emplace(LongNatural("0"), num1);
    fst_pol.emplace(LongNatural("2"), num3);
    fst_pol.emplace(LongNatural("3"), num4);
    fst_pol.emplace(LongNatural("4"), num5);
    LongRational num6 = LongRational(LongInteger("2"), LongNatural("3"));
    LongRational num7 = LongRational(LongInteger("1"), LongNatural("7"));
    LongRational num8 = LongRational(LongInteger("11"), LongNatural("10"));
    LongRational num9 = LongRational(LongInteger("3"), LongNatural("1"));
    scn_pol.emplace(LongNatural("0"), num6);
    scn_pol.emplace(LongNatural("1"), num7);
    scn_pol.emplace(LongNatural("2"), num8);
    scn_pol.emplace(LongNatural("3"), num9);
    LongRational num11 = LongRational(LongInteger("-5"), LongNatural("12"));
    LongRational num12 = LongRational(LongInteger("-1"), LongNatural("7"));
    LongRational num13 = LongRational(LongInteger("9"), LongNatural("10"));
    LongRational num14 = LongRational(LongInteger("-12"), LongNatural("5"));
    LongRational num15 = LongRational(LongInteger("6"), LongNatural("13"));
    res_pol.emplace(LongNatural("0"), num11);
    res_pol.emplace(LongNatural("1"), num12);
    res_pol.emplace(LongNatural("2"), num13);
    res_pol.emplace(LongNatural("3"), num14);
    res_pol.emplace(LongNatural("4"), num15);
    Polynomial a(fst_pol);
    Polynomial b(scn_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(
        SUB_PP_P(a, b),
        res);  // ((6/13)x^4 + (3/5)x^3 + (2/1)x^2 + 1/4) - ((3/1)x^3 + (11/10)x^2 + (1/7)x + 2/3) = ((6/13)x^4 + (-12/5)x^3 + (9/10)x^2 + (-1/7)x + (-5/12))
}

TEST(test_SUB_PP_P, Equal) {
    std::map<LongNatural, LongRational> fst_pol;
    std::map<LongNatural, LongRational> res_pol;
    LongRational num1 = LongRational(LongInteger("1"), LongNatural("4"));
    LongRational num2 = LongRational(LongInteger("8"), LongNatural("7"));
    LongRational num3 = LongRational(LongInteger("2"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("3"), LongNatural("5"));
    LongRational num5 = LongRational(LongInteger("6"), LongNatural("13"));
    fst_pol.emplace(LongNatural("0"), num1);
    fst_pol.emplace(LongNatural("1"), num2);
    fst_pol.emplace(LongNatural("2"), num3);
    fst_pol.emplace(LongNatural("3"), num4);
    fst_pol.emplace(LongNatural("4"), num5);
    Polynomial a(fst_pol);
    Polynomial b(fst_pol);
    Polynomial res(res_pol);
    EXPECT_EQ(SUB_PP_P(a, b), res);  // ((6/13)x^4 + (3/5)x^3 + (2/1)x^2 + (8/7)x + 1/4) - ((6/13)x^4 + (3/5)x^3 + (2/1)x^2 + (8/7)x + 1/4) = 0
}
