#include <gtest/gtest.h>

#include "P/DEG_P_N.hpp"
#include "P/Polynomial.hpp"

TEST(test_DEG_P_N, NormalPolynomial) {
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
    EXPECT_EQ(DEG_P_N(a), LongNatural("3"));  //  степень многочлена((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) = 3
}

TEST(test_LED_P_Q, ZeroCoef) {
    std::map<LongNatural, LongRational> fst_pol;
    LongRational num1 = LongRational(LongInteger("0"), LongNatural("1"));
    LongRational num2 = LongRational(LongInteger("0"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    Polynomial a(fst_pol);
    EXPECT_EQ(DEG_P_N(a), LongNatural("1"));  // степень многочлена (0x^3 + 0x^2 + 6x^1 + 4x^0) = 1
}
TEST(test_LED_P_Q, AllCoefZero) {
    std::map<LongNatural, LongRational> fst_pol;
    LongRational num1 = LongRational(LongInteger("0"), LongNatural("1"));
    LongRational num2 = LongRational(LongInteger("0"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("0"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("0"), LongNatural("1"));
    fst_pol.emplace(LongNatural("3"), num1);
    fst_pol.emplace(LongNatural("2"), num2);
    fst_pol.emplace(LongNatural("1"), num3);
    fst_pol.emplace(LongNatural("0"), num4);
    Polynomial a(fst_pol);
    EXPECT_EQ(DEG_P_N(a), LongNatural("0"));  // все коэффициенты равны нулю -> cтепень  0
}
TEST(test_DEG_P_N, EmptyPolynomial) {
    std::map<LongNatural, LongRational> fst_pol;
    Polynomial a(fst_pol);
    EXPECT_EQ(DEG_P_N(a), LongNatural("0"));  // степень пустого многочлена = 0
}
