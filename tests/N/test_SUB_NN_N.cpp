#include <gtest/gtest.h>

#include <vector>

#include "N/SUB_NN_N.hpp"
#include "N/LongNatural.hpp"

TEST(test_SUB_NN_N, SameLength) {
    //std::vector<uint8_t> arr1 = {4, 5, 4};
    //std::vector<uint8_t> arr2 = {1, 2, 3};
    LongNatural a({3, 2, 1});
    LongNatural b({1, 1, 1});
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {2, 1, 0};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, FirstLower) {
    LongNatural a({1, 2, 1});
    LongNatural b({4, 4, 4});
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {3, 2, 3};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, DifferentLength) {
    LongNatural a({1, 2, 1});
    LongNatural b({1, 1, 4, 4, 4});
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {1, 1, 3, 2, 3};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, Carry) {
    LongNatural a({2, 0, 0, 0, 0, 0});
    LongNatural b({9});
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {1, 9, 9, 9, 9, 1};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, InsignificantZero) {
    LongNatural a({9, 9, 9, 9, 9});
    LongNatural b({9, 9, 9, 9, 8});
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {2, 1, 0};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}