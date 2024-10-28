#include <gtest/gtest.h>

#include <vector>

#include "N/LongNatural.hpp"
#include "N/NZER_N_B.hpp"

using namespace std;

TEST(Test_NZER_N_B, N2) {
    LongNatural a({0});
    LongNatural b({2, 0, 3});
    LongNatural c({1, 0});
    LongNatural d({5});
    EXPECT_EQ(NZER_N_B(a), false);
    EXPECT_EQ(NZER_N_B(b), true);
    EXPECT_EQ(NZER_N_B(c), true);
    EXPECT_EQ(NZER_N_B(d), true);
}