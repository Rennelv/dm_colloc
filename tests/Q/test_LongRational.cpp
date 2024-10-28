#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(LongRationalTest, Constructor_ValidInput) {
    LongInteger numerator("123");
    LongNatural denominator("456");
    LongRational rational(numerator, denominator);

    EXPECT_EQ(rational.getNumerator().toString(), "123");
    EXPECT_EQ(rational.getDenominator().toString(), "456");
}

TEST(LongRationalTest, Constructor_ZeroDenominator) {
    LongInteger numerator("123");
    LongNatural denominator("0");

    EXPECT_THROW(LongRational rational(numerator, denominator), std::invalid_argument);
}

TEST(LongRationalTest, ToString) {
    LongInteger numerator("123");
    LongNatural denominator("456");
    LongRational rational(numerator, denominator);

    EXPECT_EQ(rational.toString(), "123/456");
}

TEST(LongRationalTest, GetNumerator) {
    LongInteger numerator("789");
    LongNatural denominator("456");
    LongRational rational(numerator, denominator);

    EXPECT_EQ(rational.getNumerator().toString(), "789");
}

TEST(LongRationalTest, GetDenominator) {
    LongInteger numerator("789");
    LongNatural denominator("456");
    LongRational rational(numerator, denominator);

    EXPECT_EQ(rational.getDenominator().toString(), "456");
}
