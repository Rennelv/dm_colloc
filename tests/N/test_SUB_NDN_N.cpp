#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/SUB_NDN_N.hpp"

TEST(SUB_NDN_N, GreaterThanProduct) {
    LongNatural a({1, 0, 0, 0, 0});
    LongNatural b({1, 0, 0});
    uint8_t k(4);
    LongNatural res = SUB_NDN_N(a, b, k);
    LongNatural expected({9, 6, 0, 0});  // 10000 - 400 = 9600
    EXPECT_EQ(res.getArr(), expected.getArr());
}

TEST(SUB_NDN_N, DecimalIsZero) {
    LongNatural a({2, 3, 4, 5});
    LongNatural b({1, 2, 3, 4});
    uint8_t k(0);
    LongNatural result = SUB_NDN_N(a, b, k);
    LongNatural expected({2, 3, 4, 5});  // 2345 - 1234*0 = 2345
    EXPECT_EQ(result, expected);
}

TEST(SUB_NDN_N, SubtractWithBorrowing) {
    LongNatural a({4, 0, 0});
    LongNatural b({1, 0, 0});
    uint8_t k = 5;
    EXPECT_THROW(SUB_NDN_N(a, b, k), std::logic_error);  // 400 - 500 == -100
}

TEST(SUB_NDN_N, SubtractWithLeadingZeros) {
    LongNatural a({1, 0, 0, 0});
    LongNatural b({2, 5, 0});
    uint8_t k(4);
    LongNatural result = SUB_NDN_N(a, b, k);
    LongNatural expected({0});  // 1000 - 1000 = 0
    EXPECT_EQ(result, expected);
}
