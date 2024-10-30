#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/INT_Q_B.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(test_INT_Q_B, DenominatorOne) {
    LongInteger numerator(false, {1, 2, 3});  // 123
    LongNatural denominator({1});             // 1
    LongRational a(numerator, denominator);   // 123 / 1
    EXPECT_EQ(INT_Q_B(a), 1);                 // 1 - число целое
}

TEST(test_INT_Q_B, DenominatorNotOne) {
    LongInteger numerator(false, {1, 2, 3});  // 123
    LongNatural denominator({2});             // 2
    LongRational a(numerator, denominator);   // 123 / 2
    EXPECT_EQ(INT_Q_B(a), 0);                 // 0 - число нецелое
}