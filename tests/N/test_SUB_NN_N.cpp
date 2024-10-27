#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/SUB_NN_N.hpp"

TEST(SUB_NN_N, SubtractEqualNumbers) {
    LongNatural a({1, 2, 3, 4});
    LongNatural b({1, 2, 3, 4});
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected({0});
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractSmallerFromLarger) {
    LongNatural a({2, 3, 4, 5});
    LongNatural b({1, 2, 3, 4});
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected({1, 1, 1, 1});
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractWithBorrowing) {
    LongNatural a({1, 0, 0, 0});
    LongNatural b({1});
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected({9, 9, 9});
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractWithLeadingZeros) {
    LongNatural a({1, 0, 0, 0});
    LongNatural b({9, 9, 9});
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected({1});
    EXPECT_EQ(result, expected);
}

TEST(SUB_NN_N, SubtractLargerFromSmallerThrows) {
    LongNatural a({1, 2, 3});
    LongNatural b({4, 5, 5});
    EXPECT_THROW(SUB_NN_N(a, b), std::logic_error);
}

TEST(SUB_NN_N, SubtractWithDifferentLengths) {
    LongNatural a({1, 0, 0, 0});
    LongNatural b({1, 0});
    LongNatural result = SUB_NN_N(a, b);
    LongNatural expected({9, 9, 0});
    EXPECT_EQ(result, expected);
}
