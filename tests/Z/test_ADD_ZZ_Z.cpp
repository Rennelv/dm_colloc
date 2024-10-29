#include <gtest/gtest.h>

#include "Z/ADD_ZZ_Z.hpp"
#include "Z/LongInteger.hpp"

TEST(test_ADD_ZZ_Z, PositiveAndPositive) {
    LongInteger a(false, {1, 2, 3});         // 123
    LongInteger b(false, {4, 5, 6});         // 456
    LongInteger expected(false, {5, 7, 9});  // 123 + 456 = 579
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}

TEST(test_ADD_ZZ_Z, PositiveAndNegative) {
    LongInteger a(false, {5, 6, 7});         // 567
    LongInteger b(true, {2, 3, 4});          // -234
    LongInteger expected(false, {3, 3, 3});  // 567 + (-234) = 333
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}

TEST(test_ADD_ZZ_Z, NegativeAndPositive) {
    LongInteger a(true, {7, 8, 9});         // -789
    LongInteger b(false, {1, 2, 3});        // 123
    LongInteger expected(true, {6, 6, 6});  // -789 + 123 = -666
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}

TEST(test_ADD_ZZ_Z, NegativeAndNegative) {
    LongInteger a(true, {3, 2, 1});         // -321
    LongInteger b(true, {4, 3, 2});         // -432
    LongInteger expected(true, {7, 5, 3});  // -321 + (-432) = -753
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}

TEST(test_ADD_ZZ_Z, ZeroAndPositive) {
    LongInteger a(false, {0});               // 0
    LongInteger b(false, {4, 5, 6});         // 456
    LongInteger expected(false, {4, 5, 6});  // 0 + 456 = 456
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}

TEST(test_ADD_ZZ_Z, NegativeAndZero) {
    LongInteger a(true, {1, 2, 3});         // -123
    LongInteger b(false, {0});              // 0
    LongInteger expected(true, {1, 2, 3});  // 0 + (-123) = -123
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}

TEST(test_ADD_ZZ_Z, ZeroAndZero) {
    LongInteger a(false, {0});         // 0
    LongInteger b(false, {0});         // 0
    LongInteger expected(false, {0});  // 0 + 0 = 0
    EXPECT_EQ(ADD_ZZ_Z(a, b), expected);
}
