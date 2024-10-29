#include <gtest/gtest.h>

#include "N/DIV_NN_N.hpp"
#include "N/LongNatural.hpp"

TEST(DivisionTests, DivisionByOne) {
    LongNatural a = {1, 2, 3, 4, 5, 6};
    LongNatural b = {1};
    LongNatural expected = a;
    EXPECT_EQ(DIV_NN_N(a, b), expected);  // 123456 div 1 = 123456
}

TEST(DivisionTests, DivisionWhenALessThanB) {
    LongNatural a = {1, 0, 0};
    LongNatural b = {2, 0, 0, 0, 0};
    LongNatural expected = {0};
    EXPECT_EQ(DIV_NN_N(a, b), expected);  // 100 div 20000 = 0
}

TEST(DivisionTests, StandardDivision) {
    LongNatural a = {1, 2, 3, 4, 5};
    LongNatural b = {6, 7};
    LongNatural expected = {1, 8, 4};
    EXPECT_EQ(DIV_NN_N(a, b), expected);  // 12345 div 67 = 184
}

TEST(DivisionTests, DivisionByZero) {
    LongNatural a = {1, 2, 3};
    LongNatural b = {0};
    EXPECT_THROW(DIV_NN_N(a, b), std::logic_error);  // деление на ноль
}

TEST(DivisionTests, DivisionWhenAMultipleOfB) {
    LongNatural a = {6, 2, 5};
    LongNatural b = {2, 5};
    LongNatural expected = {2, 5};
    EXPECT_EQ(DIV_NN_N(a, b), expected);  // 625 div 25 = 25
}
