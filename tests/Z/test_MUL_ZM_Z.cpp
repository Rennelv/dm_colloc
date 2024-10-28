#include <gtest/gtest.h>

#include "Z/LongInteger.hpp"
#include "Z/MUL_ZM_Z.hpp"

TEST(test_MUL_ZM_Z, PositiveNumber) {
    LongInteger a(false, {1, 2, 3});  // 123
    EXPECT_EQ(MUL_ZM_Z(a), -123);     // положительное
}

TEST(test_MUL_ZM_Z, NegativeNumber) {
    LongInteger a(true, {4, 5, 6});  // -456
    EXPECT_EQ(MUL_ZM_Z(a), 456);     // отрицательное
}

TEST(test_MUL_ZM_Z, Zero) {
    LongInteger a(false, {0});  // 0
    EXPECT_EQ(MUL_ZM_Z(a), 0);  // нуль
}