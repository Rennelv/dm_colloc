#include <gtest/gtest.h>

#include "N/COM_NN_D.hpp"
#include "N/LongNatural.hpp"

TEST(test_COM_NN_D, EqualNumbers) {
    LongNatural a1("123");           // 123
    LongNatural b1("123");           // 123
    EXPECT_EQ(COM_NN_D(a1, b1), 0);  // 123 == 123
}

TEST(test_COM_NN_D, FirstGreaterThanSecond) {
    LongNatural a2("124");           // 124
    LongNatural b2("123");           // 123
    EXPECT_EQ(COM_NN_D(a2, b2), 2);  // 124 > 123
}

TEST(test_COM_NN_D, FirstLessThanSecond) {
    LongNatural a3("123");           // 123
    LongNatural b3("124");           // 124
    EXPECT_EQ(COM_NN_D(a3, b3), 1);  // 123 < 124
}

TEST(test_COM_NN_D, FirstLongerThanSecond) {
    LongNatural a4("1234");          // 1234
    LongNatural b4("123");           // 123
    EXPECT_EQ(COM_NN_D(a4, b4), 2);  // 1234 > 123
}

TEST(test_COM_NN_D, SecondLongerThanFirst) {
    LongNatural a5("123");           // 123
    LongNatural b5("1234");          // 1234
    EXPECT_EQ(COM_NN_D(a5, b5), 1);  // 123 < 1234
}

TEST(test_COM_NN_D, FirstLessThanSecondWithCarry) {
    LongNatural a6("999");           // 999
    LongNatural b6("1000");          // 1000
    EXPECT_EQ(COM_NN_D(a6, b6), 1);  // 999 < 1000
}

TEST(test_COM_NN_D, FirstGreaterThanSecondWithCarry) {
    LongNatural a7("100000000");     // 100000000
    LongNatural b7("999");           // 999
    EXPECT_EQ(COM_NN_D(a7, b7), 2);  // 100000000 > 999
}
