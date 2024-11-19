#include <gtest/gtest.h>

#include "N/ADD_NN_N.hpp"
#include "N/LongNatural.hpp"

TEST(test_ADD_NN_N, SameLengthNoCarry) {
    LongNatural a("123");
    LongNatural b("123");
    LongNatural res = ADD_NN_N(a, b);
    LongNatural correctRes("246");
    EXPECT_EQ(res.toString(), correctRes.toString());
}

TEST(test_ADD_NN_N, DifferentLength) {
    LongNatural a("123");
    LongNatural b("45");
    LongNatural res = ADD_NN_N(a, b);
    LongNatural correctRes("168");
    EXPECT_EQ(res.toString(), correctRes.toString());
}

TEST(test_ADD_NN_N, WithCarry) {
    LongNatural a("999");
    LongNatural b("1");
    LongNatural res = ADD_NN_N(a, b);
    LongNatural correctRes("1000");
    EXPECT_EQ(res.toString(), correctRes.toString());
}

TEST(test_ADD_NN_N, AddZero) {
    LongNatural a("123");
    LongNatural b("0");
    LongNatural res = ADD_NN_N(a, b);
    LongNatural correctRes("123");
    EXPECT_EQ(res.toString(), correctRes.toString());
}

TEST(test_ADD_NN_N, AddTwoZeros) {
    LongNatural a("0");
    LongNatural b("0");
    LongNatural res = ADD_NN_N(a, b);
    LongNatural correctRes("0");
    EXPECT_EQ(res.toString(), correctRes.toString());
}
