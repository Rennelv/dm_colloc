#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Q/MUL_QQ_Q.hpp"
#include "Z/LongInteger.hpp"

using namespace std;

TEST(Test_MUL_QQ_Q, Q7_1) {
    LongInteger p1(false, {1});
    LongNatural q1({2});
    LongRational a1(p1, q1);
    LongInteger p2(false, {3});
    LongNatural q2({5});
    LongRational b1(p2, q2);
    LongNatural q3({1, 0});
    LongRational ans1(p2, q3);

    EXPECT_EQ(MUL_QQ_Q(a1, b1), ans1);
}

TEST(Test_MUL_QQ_Q, Q7_2) {
    LongInteger p1(true, {2});
    LongNatural q1({3});
    LongRational a2(p1, q1);
    LongInteger p2(false, {1, 8});
    LongNatural q2({3, 7});
    LongRational b2(p2, q2);
    LongInteger p3(true, {1, 2});
    ;
    LongRational ans2(p3, q2);

    EXPECT_EQ(MUL_QQ_Q(a2, b2), ans2);
}

TEST(Test_MUL_QQ_Q, Q7_3) {
    LongInteger p1(true, {1, 0});
    LongNatural q1({2, 1});
    LongRational a3(p1, q1);
    LongInteger p2(true, {1, 4});
    LongNatural q2({1, 5});
    LongRational b3(p2, q2);
    LongInteger p3(false, {4});
    LongNatural q3({9});
    LongRational ans3(p2, q3);

    EXPECT_EQ(MUL_QQ_Q(a3, b3), ans3);
}

TEST(Test_MUL_QQ_Q, Q7_4) {
    LongInteger p1(false, {0});
    LongNatural q1({2, 1});
    LongRational a3(p1, q1);
    LongInteger p2(true, {1, 4});
    LongNatural q2({1, 5});
    LongRational b3(p2, q2);
    LongInteger p3(false, {0});
    LongNatural q3({1});
    LongRational ans3(p2, q3);

    EXPECT_EQ(MUL_QQ_Q(a3, b3), ans3);
}