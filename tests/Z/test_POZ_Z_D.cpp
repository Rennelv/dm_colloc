#include <gtest/gtest.h>

#include "Z/LongInteger.hpp"
#include "Z/POZ_Z_D.hpp"

TEST(test_POZ_Z_D, PositiveNumber) {
    LongInteger a(false, {1, 2, 3});  // 123
    EXPECT_EQ(POZ_Z_D(a), 2);         // положительное
}

TEST(test_POZ_Z_D, NegativeNumber) {
    LongInteger a(true, {4, 5, 6});  // -456
    EXPECT_EQ(POZ_Z_D(a), 1);        // отрицательное
}

TEST(test_POZ_Z_D, Zero) {
    LongInteger a(false, {0});  // 0
    EXPECT_EQ(POZ_Z_D(a), 0);   // нуль
}
