#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Z/ABS_Z_N.hpp"
#include "Z/LongInteger.hpp"

TEST(test_ABS_Z_N, PositiveNumber) {
    LongInteger a(false, {1, 2, 3});          // 123
    EXPECT_EQ(ABS_Z_N(a).toString(), "123");  // 123
}

TEST(test_ABS_Z_N, NegativeNumber) {
    LongInteger a(true, {4, 5, 6});           // -456
    EXPECT_EQ(ABS_Z_N(a).toString(), "456");  // 456
}

TEST(test_ABS_Z_N, Zero) {
    LongInteger a(false, {0});              // 0
    EXPECT_EQ(ABS_Z_N(a).toString(), "0");  // 0
}
