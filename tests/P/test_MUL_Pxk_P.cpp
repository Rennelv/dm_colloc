#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/MUL_Pxk_P.hpp"
#include "P/Polynomial.hpp"

TEST(test_MUL_Pxk_P, NormalPolynomial) {
    std::map<LongNatural, LongRational> fstPol;
    std::map<LongNatural, LongRational> resPol;
    LongRational num1 = LongRational(LongInteger("8"), LongNatural("3"));
    LongRational num2 = LongRational(LongInteger("3"), LongNatural("1"));
    LongRational num3 = LongRational(LongInteger("6"), LongNatural("1"));
    LongRational num4 = LongRational(LongInteger("4"), LongNatural("1"));
    LongRational zero = LongRational(LongInteger("0"), LongNatural("1"));
    fstPol[LongNatural("3")] = num1;
    fstPol[LongNatural("2")] = num2;
    fstPol[LongNatural("1")] = num3;
    fstPol[LongNatural("0")] = num4;
    resPol[LongNatural("7")] = num1;
    resPol[LongNatural("6")] = num2;
    resPol[LongNatural("5")] = num3;
    resPol[LongNatural("4")] = num4;
    Polynomial a(fstPol);
    Polynomial res(resPol);
    EXPECT_EQ(MUL_Pxk_P(a, LongNatural("4")), res);  // ((8/3)x^3 + 3x^2 + 6x^1 + 4x^0) * x^4 = (8/3)x^7 + 3x^6 + 6x^5 + 4x^4
}
