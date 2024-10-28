#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"
#include "Z/TRANS_N_Z.hpp"

TEST(test_TRANS_N_Z, PositiveNumber)
{
    LongNatural a(false, {1, 2, 3});           // 123
    EXPECT_EQ(TRANS_N_Z(a).toString(), "123"); // 123
}