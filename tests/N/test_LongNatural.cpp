#include <gtest/gtest.h>

#include <algorithm>

#include "N/LongNatural.hpp"

TEST(LongNaturalTest, VectorConstructor) {
    std::vector<uint8_t> vec = {5, 4, 3, 2, 1};
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
    LongNatural ln("12345");
    std::vector<uint8_t> expected = {1, 2, 3, 4, 5};
    std::reverse(expected.begin(), expected.end());
    EXPECT_EQ(ln.getArr(), expected);
}

TEST(LongNaturalTest, GetLength) {
    LongNatural ln("12345");
    EXPECT_EQ(ln.getLength(), 5);
}

TEST(LongNaturalTest, At) {
    LongNatural ln("12345");
    EXPECT_EQ(ln.at(2), 3);
}

TEST(LongNaturalTest, AtOutOfRange) {
    LongNatural ln("12345");
    EXPECT_THROW(ln.at(5), std::out_of_range);
}

TEST(LongNaturalTest, Radix) {
    LongNatural ln("12345");
    EXPECT_EQ(ln.radix(0), 5);
    EXPECT_EQ(ln.radix(1), 4);
    EXPECT_EQ(ln.radix(4), 1);
}

TEST(LongNaturalTest, RadixOutOfRange) {
    LongNatural ln("12345");
    EXPECT_EQ(ln.radix(5), 0);
}

TEST(LongNaturalTest, Equality) {
    LongNatural a("12345");
    LongNatural b("12345");
    LongNatural c("12346");
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(LongNaturalTest, LeadingZeroes) {
    LongNatural ln("00012345");
    EXPECT_EQ(ln.radix(0), 5);
    EXPECT_EQ(ln.radix(1), 4);
    EXPECT_EQ(ln.radix(4), 1);
    EXPECT_EQ(ln.radix(5), 0);  // Out of range after leading zeroes are removed
}