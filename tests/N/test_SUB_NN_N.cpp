#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/SUB_NN_N.hpp"

TEST(SUB_NN_N, SubtractEqualNumbers) {
    LongNatural a("1234");
    LongNatural b("1234");
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected("0");
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractSmallerFromLarger) {
    LongNatural a("2345");
    LongNatural b("1234");
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected("1111");
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractWithBorrowing) {
    LongNatural a("1000");
    LongNatural b("1");
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected("999");
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractWithLeadingZeros) {
    LongNatural a("1000");
    LongNatural b("999");
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected("1");
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractLargerFromSmallerThrows) {
    LongNatural a("123");
    LongNatural b("455");
    EXPECT_THROW(SUB_NN_N(a, b), std::logic_error);
}

TEST(SUB_NN_N, SubtractWithDifferentLengths) {
    LongNatural a("1000");
    LongNatural b("10");
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected("990");
    EXPECT_EQ(result, expected);
}
