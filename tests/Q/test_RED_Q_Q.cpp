#include <gtest/gtest.h>
#include <vector>

#include "../include/N/LongNatural.hpp"
#include "../include/N/LongInteger.hpp"
#include "../include/Q/RED_Q_Q.hpp"

using namespace std;

TEST(Test_RED_Q_Q, Q1) {
    LongInteger p1(false, {3});
    LongNatural q1({6});
    LongRational a(p1, q1);

    LongInteger p2(false, {1});
    LongNatural q2({2});
    LongRational b(p2, q2);

    LongInteger p3(false, {1, 2});
    LongNatural q3({2, 4});
    LongRational c(p3, q3);

    LongInteger p4(true, {1, 2});
    LongNatural q4({2, 4});
    LongRational d(p4, q4);

    LongInteger p2_neg(true, {1});
    LongRational e(p4_neg, q2);

    LongInteger p5(false, {1, 2});
    LongNatural q({0});
    LongRational f(p4, q4);
    EXPECT_EQ(RED_Q_Q(a), b);
    EXPECT_EQ(RED_Q_Q(b), b);
    EXPECT_EQ(RED_Q_Q(c), b);
    EXPECT_EQ(RED_Q_Q(d), e);
    EXPECT_EQ(RED_Q_Q(f), logic_error);
}