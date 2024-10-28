#include <gtest/gtest.h>
#include <vector>

#include "../include/N/LongNatural.hpp"
#include "../include/N/NZER_N_B.hpp"

using namespace std;

TEST(Test_NZER_N_B, N2) {
    LongNatural a({0});
    LongNatural b({2, 0, 3});
    EXPECT_EQ(NZER_N_B(a), true);
    EXPECT_EQ(NZER_N_B(b), false);
}