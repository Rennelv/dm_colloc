#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Q/SUB_QQ_Q.hpp"
#include "Z/LongInteger.hpp"

TEST(test_SUB_QQ_Q, SimpleSubtractionSameDenominator) {
    LongInteger numerator_a("5");
    LongNatural denominator_a("3");
    LongRational a(numerator_a, denominator_a);
    LongInteger numerator_b("2");
    LongNatural denominator_b("3");
    LongRational b(numerator_b, denominator_b);
    LongInteger numerator("1");
    LongNatural denominator("1");
    LongRational result(numerator, denominator);
    EXPECT_EQ(SUB_QQ_Q(a, b), result);  // 5/3 - 2/3 = 1/1
}

TEST(test_SUB_QQ_Q, SimpleSubtractionDifferentDenominator) {
    LongInteger numerator_a("3");
    LongNatural denominator_a("4");
    LongRational a(numerator_a, denominator_a);
    LongInteger numerator_b("1");
    LongNatural denominator_b("2");
    LongRational b(numerator_b, denominator_b);
    LongInteger numerator("1");
    LongNatural denominator("4");
    LongRational result(numerator, denominator);
    EXPECT_EQ(SUB_QQ_Q(a, b), result);  // 3/4 - 1/2 = 1/4
}

TEST(test_SUB_QQ_Q, NegativeFirst) {
    LongInteger numerator_a("-7");
    LongNatural denominator_a("5");
    LongRational a(numerator_a, denominator_a);
    LongInteger numerator_b("2");
    LongNatural denominator_b("5");
    LongRational b(numerator_b, denominator_b);
    LongInteger numerator("-9");
    LongNatural denominator("5");
    LongRational result(numerator, denominator);
    EXPECT_EQ(SUB_QQ_Q(a, b), result);  // (-7/5) - 2/5 = -9/5
}

TEST(test_SUB_QQ_Q, NegativeSecond) {
    LongInteger numerator_a("13");
    LongNatural denominator_a("4");
    LongRational a(numerator_a, denominator_a);
    LongInteger numerator_b("-6");
    LongNatural denominator_b("7");
    LongRational b(numerator_b, denominator_b);
    LongInteger numerator("115");
    LongNatural denominator("28");
    LongRational result(numerator, denominator);
    EXPECT_EQ(SUB_QQ_Q(a, b), result);  // 13/4 - (-6/7) = 115/28
}

TEST(test_SUB_QQ_Q, SubtractSelf) {
    LongInteger numerator_a("5");
    LongNatural denominator_a("12");
    LongRational a(numerator_a, denominator_a);
    LongRational b(numerator_a, denominator_a);
    LongInteger numerator("0");
    LongNatural denominator("1");
    LongRational result(numerator, denominator);
    EXPECT_EQ(SUB_QQ_Q(a, b), result);  // 5/12 - 5/12 = 0/1
}
