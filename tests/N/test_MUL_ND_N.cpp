#include <gtest/gtest.h>

#include <vector>

#include "N/MUL_ND_N.hpp"
#include "N/LongNatural.hpp"

TEST(test_MUL_ND_N, EasyMul) {
    LongNatural a({1, 1, 1});
    uint8_t b(2);
    LongNatural res = MUL_ND_N(a, b);
    std::vector<uint8_t> arr3 = {2, 2, 2};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_MUL_ND_N, ZeroMul) {
    LongNatural a({1, 1, 1});
    uint8_t b(0);
    LongNatural res = MUL_ND_N(a, b);
    std::vector<uint8_t> arr3 = {0};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_MUL_ND_N, CarryMul) {
    LongNatural a({9, 9, 9, 9, 9});
    uint8_t b(5);
    LongNatural res = MUL_ND_N(a, b);
    std::vector<uint8_t> arr3 = {4, 9, 9, 9, 9, 5};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}
