#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"
#include "Z/TRANS_N_Z.hpp"

TEST(test_TRANS_N_Z, PositiveNumber1) {
    LongNatural a("123");                       // 123
    EXPECT_EQ(TRANS_N_Z(a).toString(), "123");  // 123
}

TEST(test_TRANS_N_Z, PositiveNumber2) {
    LongNatural a("321");                       // 321
    EXPECT_EQ(TRANS_N_Z(a).toString(), "321");  // 321
}