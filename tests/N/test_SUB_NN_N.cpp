#include <gtest/gtest.h>

#include <vector>

#include "N/SUB_NN_N.hpp"
#include "N/LongNatural.hpp"

TEST(test_SUB_NN_N, SameLength) {
    //std::vector<uint8_t> arr1 = {4, 5, 4};
    //std::vector<uint8_t> arr2 = {1, 2, 3};
    LongNatural a({4, 5, 4});
    LongNatural b({1, 2, 3});
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {3, 3, 1};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}
/*
TEST(test_SUB_NN_N, DifferentLength) {
    std::vector<uint8_t> arr1 = {1, 2, 3};
    std::vector<uint8_t> arr2 = {4, 5};
    LongNatural a(arr1);
    LongNatural b(arr2);
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {1, 6, 8};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, WithCarry) {
    std::vector<uint8_t> arr1 = {9, 9, 9};
    std::vector<uint8_t> arr2 = {1};
    LongNatural a(arr1);
    LongNatural b(arr2);
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {1, 0, 0, 0};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, SUBZero) {
    std::vector<uint8_t> arr1 = {1, 2, 3};
    std::vector<uint8_t> arr2 = {0};
    LongNatural a(arr1);
    LongNatural b(arr2);
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {1, 2, 3};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}

TEST(test_SUB_NN_N, SUBTwoZeros) {
    std::vector<uint8_t> arr1 = {0};
    std::vector<uint8_t> arr2 = {0};
    LongNatural a(arr1);
    LongNatural b(arr2);
    LongNatural res = SUB_NN_N(a, b);
    std::vector<uint8_t> arr3 = {0};
    LongNatural correctRes(arr3);
    EXPECT_EQ(res.getArr(), correctRes.getArr());
}
*/