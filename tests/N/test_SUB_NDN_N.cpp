#include <gtest/gtest.h>

#include <string>

#include "N/LongNatural.hpp"
#include "N/SUB_NDN_N.hpp"

TEST(SUB_NDN_N, GreaterThanProduct) {
    LongNatural a("10000");
    LongNatural b("100");
    uint8_t k(4);
    LongNatural res = SUB_NDN_N(a, b, k);
    LongNatural expected("9600");  // 10000 - 400 = 9600
    EXPECT_EQ(res.toString(), expected.toString());
}

TEST(SUB_NDN_N, DecimalIsZero) {
    LongNatural a("2345");
    LongNatural b("1234");
    uint8_t k(0);
    LongNatural result = SUB_NDN_N(a, b, k);
    LongNatural expected("2345");  // 2345 - 1234*0 = 2345
    EXPECT_EQ(result.toString(), expected.toString());
}

TEST(SUB_NDN_N, SubtractWithBorrowing) {
    LongNatural a("400");
    LongNatural b("100");
    uint8_t k = 5;
    EXPECT_THROW(SUB_NDN_N(a, b, k), std::logic_error);  // 400 - 500 == -100
}

TEST(SUB_NDN_N, SubtractWithLeadingZeros) {
    LongNatural a("1000");
    LongNatural b("250");
    uint8_t k(4);
    LongNatural result = SUB_NDN_N(a, b, k);
    LongNatural expected("0");  // 1000 - 1000 = 0
    EXPECT_EQ(result.toString(), expected.toString());
}
