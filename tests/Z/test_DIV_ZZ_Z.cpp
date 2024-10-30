#include <gtest/gtest.h>

#include "Z/DIV_ZZ_Z.hpp"
#include "Z/LongInteger.hpp"

// Тест деления положительного числа на положительное
// 624 : 312 == 2
TEST(DIV_ZZ_Z, PositiveDivPositive) {
    LongInteger dividend(false, {6, 2, 4});
    LongInteger divisor(false, {3, 1, 2});
    LongInteger expected(false, {2});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}

// Тест деления отрицательного числа на положительное
// (-624) : 312 == -2
TEST(DIV_ZZ_Z, NegativeDivPositive) {
    LongInteger dividend(true, {6, 2, 4});
    LongInteger divisor(false, {3, 1, 2});
    LongInteger expected(true, {2});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}

// Тест деления положительного числа на отрицательное
// 624 : (-312) == -2
TEST(DIV_ZZ_Z, PositiveDivNegativeEqual) {
    LongInteger dividend(false, {6, 2, 4});
    LongInteger divisor(true, {3, 1, 2});
    LongInteger expected(true, {2});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}

// Тест деления отрицательного числа на отрицательное
// (-624) : (-312) == 2
TEST(DIV_ZZ_Z, NegativeDivNegative) {
    LongInteger dividend(true, {6, 2, 4});
    LongInteger divisor(true, {3, 1, 2});
    LongInteger expected(false, {2});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}

// Тест деления на единицу
// 624 : (1) == 624
TEST(DIV_ZZ_Z, DivByOne) {
    LongInteger dividend(false, {6, 2, 4});
    LongInteger divisor(false, {1});
    LongInteger expected(false, {6, 2, 4});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}

// Тест деления на -1
// 624 : (-1) == -624
TEST(DIV_ZZ_Z, DivByNegativeOne) {
    LongInteger dividend(false, {6, 2, 4});
    LongInteger divisor(true, {1});
    LongInteger expected(true, {6, 2, 4});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}

// Тест деления нуля на положительное число
// 0 : (312) == 0
TEST(DIV_ZZ_Z, ZeroDivPositive) {
    LongInteger dividend(false, {0});
    LongInteger divisor(false, {3, 1, 2});
    LongInteger expected(false, {0});
    EXPECT_EQ(DIV_ZZ_Z(dividend, divisor), expected);
}