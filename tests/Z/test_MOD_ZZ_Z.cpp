#include <gtest/gtest.h>

#include "Z/LongInteger.hpp"
#include "Z/MOD_ZZ_Z.hpp"

TEST(test_MOD_ZZ_Z, DividentPositiveDivisorPositive) {
    LongInteger a(false, {1, 0});               // 10
    LongInteger b(false, {3});                  // 3
    EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "1");  // 10 % 3 = 1
}

TEST(test_MOD_ZZ_Z, DividentPositiveDivisorNegativee) {
    LongInteger a(false, {1, 0});               // 10
    LongInteger b(true, {3});                   // -3
    EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "1");  // 10 % -3 = 1
}

TEST(test_MOD_ZZ_Z, DividentNegativeDivisorPositive) {
    LongInteger a(true, {1, 0});                // -10
    LongInteger b(false, {3});                  // 3
    EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "1");  // -10 % 3 = 1
}

TEST(test_MOD_ZZ_Z, DividentNegativeDivisorNegative) {
    LongInteger a(true, {1, 0});                // -10
    LongInteger b(true, {3});                   // -3
    EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "1");  // -10 % -3 = 1
}

TEST(test_MOD_ZZ_Z, RemainderIsZero) {
    LongInteger a(true, {1, 5});                // 15
    LongInteger b(true, {5});                   // 5
    EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "0");  // 15 % 5 = 0
}