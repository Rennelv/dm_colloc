#include <gtest/gtest.h>
#include <vector>

#include "Z/LongInteger.hpp"
#include "Z/MUL_ZZ_Z.hpp"

using namespace std;

TEST(Test_MUL_ZZ_Z, Z8) {
    LongInteger a(false, {1, 2, 3});
    LongInteger b(false, {4, 8});
    LongInteger c(false, {0});
    LongInteger d(true, {4, 0, 5});
    LongInteger e(true, {2, 3});

    LongInteger ans1(false, {5, 9, 0, 4});
    LongInteger ans2(true, {1, 9, 4, 4, 0});
    LongInteger ans3(false, {9, 3, 1, 5});
    EXPECT_EQ(MUL_ZZ_Z(a, b), ans1);
    EXPECT_EQ(MUL_ZZ_Z(b, d), ans2);
    EXPECT_EQ(MUL_ZZ_Z(d, e), ans3);
    EXPECT_EQ(MUL_ZZ_Z(c, d), c);
}