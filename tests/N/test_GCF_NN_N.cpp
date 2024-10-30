#include <gtest/gtest.h>

#include "N/GCF_NN_N.hpp"

TEST(test_GCF_NN_N, SameNumber) {
    LongNatural a("42");
    LongNatural b("42");
    LongNatural result = GCF_NN_N(a, b);
    EXPECT_EQ(result, a);  // НОД(42, 42) = 42
}

TEST(test_GCF_NN_N, OneDividesAnother) {
    LongNatural a("100");
    LongNatural b("25");
    LongNatural result = GCF_NN_N(a, b);
    EXPECT_EQ(result, b);  // НОД(100, 25) = 25
}

TEST(test_GCF_NN_N, PrimeNumbers) {
    LongNatural a("17");
    LongNatural b("13");
    LongNatural result = GCF_NN_N(a, b);
    EXPECT_EQ(result, LongNatural("1"));  // НОД(17, 13) = 1
}

TEST(test_GCF_NN_N, ZeroAndNumber) {
    LongNatural a("0");
    LongNatural b("56");
    LongNatural result = GCF_NN_N(a, b);
    EXPECT_EQ(result, b);  // НОД(0, 56) = 56
}

TEST(test_GCF_NN_N, LargeNumbers) {
    LongNatural a("123456789");
    LongNatural b("987654321");
    LongNatural result = GCF_NN_N(a, b);
    LongNatural expected_result("9");
    EXPECT_EQ(result, expected_result);
}

TEST(test_GCF_NN_N, RandomNumbers) {
    LongNatural a("54");
    LongNatural b("24");
    LongNatural result = GCF_NN_N(a, b);
    EXPECT_EQ(result, LongNatural("6"));  // НОД(54, 24) = 6
}
