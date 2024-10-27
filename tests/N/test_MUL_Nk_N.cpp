#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/MUL_Nk_N.hpp"

TEST(test_MUL_Nk_N, MultiplyByZeroPower) {
    LongNatural a1({1, 2, 3});  // 123
    LongNatural result = MUL_Nk_N(a1, 0);
    EXPECT_EQ(result.toString(), "123");  // 123 * 10^0 = 123
}

TEST(test_MUL_Nk_N, MultiplyByOnePower) {
    LongNatural a2({1, 2, 3});  // 123
    LongNatural result = MUL_Nk_N(a2, 1);
    EXPECT_EQ(result.toString(), "1230");  // 123 * 10^1 = 1230
}

TEST(test_MUL_Nk_N, MultiplyByTwoPowers) {
    LongNatural a3({1, 2, 3});  // 123
    LongNatural result = MUL_Nk_N(a3, 2);
    EXPECT_EQ(result.toString(), "12300");  // 123 * 10^2 = 12300
}

TEST(test_MUL_Nk_N, MultiplyByLargePower) {
    LongNatural a4({1, 2, 3});  // 123
    LongNatural result = MUL_Nk_N(a4, 5);
    EXPECT_EQ(result.toString(), "12300000");  // 123 * 10^5 = 12300000
}

TEST(test_MUL_Nk_N, MultiplyZeroByPower) {
    LongNatural a5({0});  // 0
    LongNatural result = MUL_Nk_N(a5, 4);
    EXPECT_EQ(result.toString(), "0");  // 0 * 10^4 = 0
}
