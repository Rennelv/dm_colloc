#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/MUL_NN_N.hpp"

TEST(test_MUL_NN_N, ShortNumbers) {
    LongNatural a({2});
    LongNatural b({2});
    LongNatural res = MUL_NN_N(a, b);
    LongNatural expected({4});  // 2 * 2 = 4
    EXPECT_EQ(res, expected);
}

TEST(test_MUL_NN_N, OneLongOneShort) {
    LongNatural a({1, 1, 0, 2, 5});
    LongNatural b({2});
    LongNatural res = MUL_NN_N(a, b);
    LongNatural expected({2, 2, 0, 5, 0});  // 11025 * 2 = 22050
    EXPECT_EQ(res, expected);
}

TEST(test_MUL_NN_N, OneShortOneLong) {
    LongNatural a({2});
    LongNatural b({1, 1, 0, 2, 5});
    LongNatural res = MUL_NN_N(a, b);
    LongNatural expected({2, 2, 0, 5, 0});  // 2 * 11025 = 22050
    EXPECT_EQ(res, expected);
}

TEST(test_MUL_NN_N, MulZero) {
    LongNatural a({0});
    LongNatural b({1, 1, 0, 2, 5});
    LongNatural res = MUL_NN_N(a, b);
    LongNatural expected({0});  // 0 * 11025 = 0
    EXPECT_EQ(res, expected);
}

TEST(test_MUL_NN_N, LongNumbers) {
    LongNatural a({2, 5, 0, 0});
    LongNatural b({2, 5, 0, 0});
    LongNatural res = MUL_NN_N(a, b);
    LongNatural expected({6, 2, 5, 0, 0, 0, 0});  // 250 * 250 = 6250000
    EXPECT_EQ(res, expected);
}