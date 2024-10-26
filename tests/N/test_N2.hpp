#include <gtest/gtest.h>
#include <vector>

#include "../include/N/N2.hpp"

using namespace std;

TEST(Test_N2, Test1) {
    LongNatural a({0});
    LongNatural b({2, 0, 3});
    EXPECT_EQ(NZER_N_B(a), true);
    EXPECT_EQ(NZER_N_B(b), false);
}

