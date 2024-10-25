#include <gtest/gtest.h>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

TEST(test_COM_NN_D, EqualNumbers) {
    LongNatural a1({1, 2, 3});       // 123
    LongNatural b1({1, 2, 3});       // 123
    EXPECT_EQ(COM_NN_D(a1, b1), 0);  // 123 == 123
}

TEST(test_COM_NN_D, FirstGreaterThanSecond) {
    LongNatural a2({1, 2, 4});       // 124
    LongNatural b2({1, 2, 3});       // 123
    EXPECT_EQ(COM_NN_D(a2, b2), 2);  // 124 > 123
}

TEST(test_COM_NN_D, FirstLessThanSecond) {
    LongNatural a3({1, 2, 3});       // 123
    LongNatural b3({1, 2, 4});       // 124
    EXPECT_EQ(COM_NN_D(a3, b3), 1);  // 123 < 124
}

TEST(test_COM_NN_D, FirstLongerThanSecond) {
    LongNatural a4({1, 2, 3, 4});    // 1234
    LongNatural b4({1, 2, 3});       // 123
    EXPECT_EQ(COM_NN_D(a4, b4), 2);  // 1234 > 123
}

TEST(test_COM_NN_D, SecondLongerThanFirst) {
    LongNatural a5({1, 2, 3});       // 123
    LongNatural b5({1, 2, 3, 4});    // 1234
    EXPECT_EQ(COM_NN_D(a5, b5), 1);  // 123 < 1234
}

TEST(test_COM_NN_D, FirstLessThanSecondWithCarry) {
    LongNatural a6({9, 9, 9});       // 999
    LongNatural b6({1, 0, 0, 0});    // 1000
    EXPECT_EQ(COM_NN_D(a6, b6), 1);  // 999 < 1000
}

TEST(test_COM_NN_D, FirstGreaterThanSecondWithCarry) {
    LongNatural a7({1, 0, 0, 0, 0, 0, 0, 0, 0});  // 100000000
    LongNatural b7({9, 9, 9});                    // 999
    EXPECT_EQ(COM_NN_D(a7, b7), 2);               // 1000 > 999
}
