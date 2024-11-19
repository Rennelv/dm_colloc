#include <gtest/gtest.h>

#include <algorithm>

#include "Z/LongInteger.hpp"

TEST(LongIntegerTest, ConstructorFromInitializerList) {
    LongInteger li(false, {1, 2, 3, 4});
    EXPECT_EQ(li.toString(), "1234");
    EXPECT_FALSE(li.isNegative());
}

TEST(LongIntegerTest, ConstructorFromVector) {
    std::vector<uint8_t> vec = {1, 2, 3, 4};
    std::reverse(vec.begin(), vec.end());
    LongInteger li(false, vec);
    EXPECT_EQ(li.toString(), "1234");
    EXPECT_FALSE(li.isNegative());
}

TEST(LongIntegerTest, ConstructorFromString) {
    LongInteger li(false, "1234");
    EXPECT_EQ(li.toString(), "1234");
    EXPECT_FALSE(li.isNegative());
}

TEST(LongIntegerTest, ConstructorFromStringWithNegative) {
    LongInteger li("-1234");
    EXPECT_EQ(li.toString(), "-1234");
    EXPECT_TRUE(li.isNegative());
}

TEST(LongIntegerTest, GetArr) {
    LongInteger li(false, {1, 2, 3, 4});
    std::vector<uint8_t> expected = {1, 2, 3, 4};
    std::reverse(expected.begin(), expected.end());
    EXPECT_EQ(li.getArr(), expected);
}

TEST(LongIntegerTest, ToString) {
    LongInteger li(false, {1, 2, 3, 4});
    EXPECT_EQ(li.toString(), "1234");
}

TEST(LongIntegerTest, IsNegative) {
    LongInteger li1(false, {1, 2, 3, 4});
    EXPECT_FALSE(li1.isNegative());

    LongInteger li2(true, {1, 2, 3, 4});
    EXPECT_TRUE(li2.isNegative());
}

TEST(LongIntegerTest, GetLength) {
    LongInteger li(false, {1, 2, 3, 4});
    EXPECT_EQ(li.getLength(), 4);
}

TEST(LongIntegerTest, At) {
    LongInteger li(false, {1, 2, 3, 4});
    EXPECT_EQ(li.at(0), 1);
    EXPECT_EQ(li.at(1), 2);
    EXPECT_EQ(li.at(2), 3);
    EXPECT_EQ(li.at(3), 4);
    EXPECT_THROW(li.at(4), std::out_of_range);
}

TEST(LongIntegerTest, Radix) {
    LongInteger li(false, {1, 2, 3, 4});
    EXPECT_EQ(li.radix(0), 4);
    EXPECT_EQ(li.radix(1), 3);
    EXPECT_EQ(li.radix(2), 2);
    EXPECT_EQ(li.radix(3), 1);
    EXPECT_EQ(li.radix(4), 0);
}

TEST(LongIntegerTest, EqualityOperator) {
    LongInteger li1(false, {1, 2, 3, 4});
    LongInteger li2(false, {1, 2, 3, 4});
    LongInteger li3(true, {1, 2, 3, 4});
    LongInteger li4(false, {4, 3, 2, 1});

    EXPECT_TRUE(li1 == li2);
    EXPECT_FALSE(li1 == li3);
    EXPECT_FALSE(li1 == li4);
}

TEST(LongIntegerTest, LeadingZeroes) {
    LongInteger li1(false, {0, 0, 1, 2, 3, 4});
    EXPECT_EQ(li1.toString(), "1234");
    EXPECT_FALSE(li1.isNegative());

    LongInteger li2(false, {0, 0, 0});
    EXPECT_EQ(li2.toString(), "0");
    EXPECT_FALSE(li2.isNegative());

    LongInteger li3(true, {0, 0, 1, 2, 3, 4});
    EXPECT_EQ(li3.toString(), "-1234");
    EXPECT_TRUE(li3.isNegative());

    LongInteger li4(true, {0, 0, 0});
    EXPECT_EQ(li4.toString(), "0");  // Leading zeroes should be trimmed, and negative zero should be treated as zero
    EXPECT_FALSE(li4.isNegative());
}