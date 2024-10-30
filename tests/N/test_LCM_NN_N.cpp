#include <gtest/gtest.h>

#include "N/LCM_NN_N.hpp"

TEST(test_LCM_NN_N, PrimeNumbers) {
    LongNatural a("3");
    LongNatural b("7");
    LongNatural expected("21");  // 3 * 7 = 21, так как НОД(3, 7) = 1

    EXPECT_EQ(LCM_NN_N(a, b), expected);
}

TEST(test_LCM_NN_N, CommonDivisors) {
    LongNatural a("12");
    LongNatural b("18");
    LongNatural expected("36");
    EXPECT_EQ(LCM_NN_N(a, b), expected);  // НОК(12, 18) = 36
}

TEST(test_LCM_NN_N, NumberAndItself) {
    LongNatural a("25");
    LongNatural expected("25");
    EXPECT_EQ(LCM_NN_N(a, a), expected);  // НОК(25, 25) = 25
}

TEST(test_LCM_NN_N, NumberAndOne) {
    LongNatural a("17");
    LongNatural b("1");
    LongNatural expected("17");
    EXPECT_EQ(LCM_NN_N(a, b), expected);  // НОК(17, 1) = 17
}

TEST(test_LCM_NN_N, LargeNumbers) {
    LongNatural a("123456789");
    LongNatural b("987654321");
    LongNatural expected("13548070123626141");
    EXPECT_EQ(LCM_NN_N(a, b), expected); // НОК(123456789, 987654321) = 13548070123626141
}

TEST(test_LCM_NN_N, ZeroNumber) {
    LongNatural a("0");
    LongNatural b("12");
    LongNatural expected("0");  
    EXPECT_EQ(LCM_NN_N(a, b), expected); // НОК(0, 12) = 0
}
