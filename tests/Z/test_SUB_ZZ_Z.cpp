#include <gtest/gtest.h>

#include "Z/LongInteger.hpp"
#include "Z/SUB_ZZ_Z.hpp"

TEST(test_SUB_ZZ_Z, PositiveNumbersFirstGreater) {
    LongInteger a(false, {1, 2, 3});             // 123
    LongInteger b(false, {5, 6});                // 56
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "67");  // 123 - 56 = 67
}

TEST(test_SUB_ZZ_Z, PositiveNumbersSecondGreater) {
    LongInteger a(false, {5, 6});                 // 56
    LongInteger b(false, {1, 2, 3});              // 123
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "-67");  // 56 - 123 = -67
}

TEST(test_SUB_ZZ_Z, NegativeNumbersFirstGreater) {
    LongInteger a(true, {1, 2, 3});               // -123
    LongInteger b(true, {5, 6});                  // -56
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "-67");  // -123 + 56 = -67
}

TEST(test_SUB_ZZ_Z, NegativeNumbersSecondGreater) {
    LongInteger a(true, {5, 6});                 //-56
    LongInteger b(true, {1, 2, 3});              //-123
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "67");  // -56 + 123 = 67
}

TEST(test_SUB_ZZ_Z, PositiveAndNegative) {
    LongInteger a(false, {1, 2, 3});              // 123
    LongInteger b(true, {5, 6});                  // -56
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "179");  // 123 + 56 = 179
}

TEST(test_SUB_ZZ_Z, NegativeAndPositive) {
    LongInteger a(true, {1, 2, 3});                // -123
    LongInteger b(false, {5, 6});                  // 56
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "-179");  // -123 -56 = -179
}

TEST(test_SUB_ZZ_Z, NumbersAreEquals) {
    LongInteger a(true, {1, 2, 3});             // 123
    LongInteger b(true, {1, 2, 3});             // 123
    EXPECT_EQ(SUB_ZZ_Z(a, b).toString(), "0");  // 123 - 123 = 0
}