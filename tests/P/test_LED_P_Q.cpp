#include <gtest/gtest.h>

#include "P/LED_P_Q.hpp"
#include "P/Polynomial.hpp"

TEST(test_LED_P_Q, NormalPolynomial) {
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
    EXPECT_EQ(LED_P_Q(a), num1);  // из многочлена (8/3)x^3 + 3x^2 + 6x^1 + 4x^0 возвращает старший коэффициент 8/3
}

TEST(test_LED_P_Q, first) {
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
    EXPECT_EQ(LED_P_Q(a), num3);  // из многочлена 0x^3 + 0x^2 + 6x^1 + 4x^0 возвращает старший коэффициент 0
}
TEST(test_LED_P_Q, second) {
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
    EXPECT_EQ(LED_P_Q(a), num1);  // из многочлена 0x^3 + 0x^2 + 0x^1 + 0x^0 возвращает старший коэффициент 0
}

TEST(test_LED_P_Q, EmptyPolynomial) {
    std::map<LongNatural, LongRational> fst_pol;
    Polynomial a(fst_pol);
    // Если многочлен пустой возвращает 0
    EXPECT_EQ(LED_P_Q(a), LongRational(LongInteger("0"), LongNatural("1")));
}
