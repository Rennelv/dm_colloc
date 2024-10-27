#include "N/LongNatural.hpp"
#include "gtest/gtest.h"

TEST(LongNaturalTest, InitializerListConstructor) {
    LongNatural ln = {1, 2, 3, 4, 5};
    EXPECT_EQ(ln.toString(), "12345");
}

TEST(LongNaturalTest, InitializerListConstructorInvalid) {
    EXPECT_THROW(LongNatural ln({1, 2, 10}), std::invalid_argument);
}

TEST(LongNaturalTest, ArrayConstructor) {
    int arr[] = {1, 2, 3, 4, 5};
    LongNatural ln(5, arr);
    EXPECT_EQ(ln.toString(), "12345");
}

TEST(LongNaturalTest, ArrayConstructorInvalid) {
    int arr[] = {1, 2, -1};
    EXPECT_THROW(LongNatural ln(3, arr), std::invalid_argument);
}

TEST(LongNaturalTest, VectorConstructor) {
    std::vector<uint8_t> vec = {1, 2, 3, 4, 5};
    LongNatural ln(vec);
    EXPECT_EQ(ln.toString(), "12345");
}

TEST(LongNaturalTest, VectorConstructorInvalid) {
    std::vector<uint8_t> vec = {1, 2, 10};
    EXPECT_THROW(LongNatural ln(vec), std::invalid_argument);
}

TEST(LongNaturalTest, StringConstructor) {
    LongNatural ln("12345");
    EXPECT_EQ(ln.toString(), "12345");
}

TEST(LongNaturalTest, StringConstructorInvalid) {
    EXPECT_THROW(LongNatural ln("12a45"), std::invalid_argument);
}

TEST(LongNaturalTest, GetArr) {
    LongNatural ln = {1, 2, 3, 4, 5};
    std::vector<uint8_t> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(ln.getArr(), expected);
}

TEST(LongNaturalTest, GetLength) {
    LongNatural ln = {1, 2, 3, 4, 5};
    EXPECT_EQ(ln.getLength(), 5);
}

TEST(LongNaturalTest, At) {
    LongNatural ln = {1, 2, 3, 4, 5};
    EXPECT_EQ(ln.at(2), 3);
}

TEST(LongNaturalTest, AtOutOfRange) {
    LongNatural ln = {1, 2, 3, 4, 5};
    EXPECT_THROW(ln.at(5), std::out_of_range);
}

TEST(LongNaturalTest, Radix) {
    LongNatural ln = {1, 2, 3, 4, 5};
    EXPECT_EQ(ln.radix(0), 5);
    EXPECT_EQ(ln.radix(1), 4);
    EXPECT_EQ(ln.radix(4), 1);
}

TEST(LongNaturalTest, RadixOutOfRange) {
    LongNatural ln = {1, 2, 3, 4, 5};
    EXPECT_EQ(ln.radix(5), 0);
}

TEST(LongNaturalTest, Equality) {
    LongNatural a = {1, 2, 3, 4, 5};
    LongNatural b = {1, 2, 3, 4, 5};
    LongNatural c = {1, 2, 3, 4, 6};
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(LongNaturalTest, LeadingZeroes) {
    LongNatural ln = {0, 0, 1, 2, 3, 4, 5};
    EXPECT_EQ(ln.radix(0), 5);
    EXPECT_EQ(ln.radix(1), 4);
    EXPECT_EQ(ln.radix(4), 1);
    EXPECT_EQ(ln.radix(5), 0);  // Out of range after leading zeroes are removed
}