#include <gtest/gtest.h>

#include "Q/LongRational.hpp"
#include "Q/TRANS_Z_Q.hpp"
#include "Z/LongInteger.hpp"

TEST(test_TRANS_Z_Q, ZeroConversion) {
    LongInteger zero(false, {0});
    LongRational result = TRANS_Z_Q(zero);
    EXPECT_EQ(result.getNumerator(), zero);                // Числитель должен быть 0
    EXPECT_EQ(result.getDenominator(), LongNatural({1}));  // Знаменатель должен быть 1
}

TEST(test_TRANS_Z_Q, PositiveIntegerConversion) {
    LongInteger positiveInt(false, {1, 2, 3, 4, 5});  // 123456
    LongRational result = TRANS_Z_Q(positiveInt);
    EXPECT_EQ(result.getNumerator(), positiveInt);         // Числитель должен быть 12345
    EXPECT_EQ(result.getDenominator(), LongNatural({1}));  // Знаменатель должен быть 1
}

TEST(test_TRANS_Z_Q, NegativeIntegerConversion) {
    LongInteger negativeInt(true, {5, 4, 3, 2, 1});  // -54321
    LongRational result = TRANS_Z_Q(negativeInt);
    EXPECT_EQ(result.getNumerator(), negativeInt);         // Числитель должен быть -54321
    EXPECT_EQ(result.getDenominator(), LongNatural({1}));  // Знаменатель должен быть 1
}

TEST(test_TRANS_Z_Q, LargeIntegerConversion) {
    LongInteger largeInt("123456789012345678901234567890");
    LongRational result = TRANS_Z_Q(largeInt);
    EXPECT_EQ(result.getNumerator(), largeInt);            // Числитель должен быть равен largeInt
    EXPECT_EQ(result.getDenominator(), LongNatural({1}));  // Знаменатель должен быть 1
}