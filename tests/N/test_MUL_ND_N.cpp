#include <gtest/gtest.h>

#include <string>

#include "N/LongNatural.hpp"
#include "N/MUL_ND_N.hpp"

TEST(test_MUL_ND_N, EasyMul) {
    LongNatural a("111");
    uint8_t b(2);
    LongNatural res = MUL_ND_N(a, b);
    LongNatural correctRes("222");
    EXPECT_EQ(res.toString(), correctRes.toString());
}

TEST(test_MUL_ND_N, ZeroMul) {
    LongNatural a("111");
    uint8_t b(0);
    LongNatural res = MUL_ND_N(a, b);
    LongNatural correctRes("0");
    EXPECT_EQ(res.toString(), correctRes.toString());
}

TEST(test_MUL_ND_N, CarryMul) {
    LongNatural a("99999");
    uint8_t b(5);
    LongNatural res = MUL_ND_N(a, b);
    LongNatural correctRes("499995");
    EXPECT_EQ(res.toString(), correctRes.toString());
}
