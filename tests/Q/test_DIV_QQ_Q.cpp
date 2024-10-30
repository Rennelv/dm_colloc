#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/DIV_QQ_Q.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

using namespace std;

TEST(Test_DIV_QQ_Q, Q8_1) {
    LongInteger p1(false, {1});
    LongNatural q1({2});
    LongRational a1(p1, q1);  // 1/2
    LongInteger p2(false, {5});
    LongNatural q2({3});
    LongRational b1(p2, q2);  // 5/3
    LongInteger p3(false, {3});
    LongNatural q3({1, 0});
    LongRational ans1(p3, q3);  // 3/10

    EXPECT_EQ(DIV_QQ_Q(a1, b1), ans1);
}

TEST(Test_DIV_QQ_Q, Q8_2) {
    LongInteger p1(true, {2});
    LongNatural q1({3});
    LongRational a2(p1, q1);  // -2/3
    LongInteger p2(false, {3, 7});
    LongNatural q2({1, 8});
    LongRational b2(p2, q2);  // 37/18
    LongInteger p3(true, {1, 2});
    LongNatural q3({3, 7});
    LongRational ans2(p3, q3);  // -12/37

    EXPECT_EQ(DIV_QQ_Q(a2, b2), ans2);
}

TEST(Test_DIV_QQ_Q, Q8_3) {
    LongInteger p1(true, {1, 0});
    LongNatural q1({2, 1});
    LongRational a3(p1, q1);  // -10/21
    LongInteger p2(true, {1, 5});
    LongNatural q2({1, 4});
    LongRational b3(p2, q2);  // -15/14
    LongInteger p3(false, {4});
    LongNatural q3({9});
    LongRational ans3(p3, q3);  // 4/9

    EXPECT_EQ(DIV_QQ_Q(a3, b3), ans3);
}

TEST(Test_DIV_QQ_Q, Q8_4) {
    LongInteger p1(true, {0});
    LongNatural q1({2, 1});
    LongRational a4(p1, q1);  // -0/21
    LongInteger p2(true, {1, 5});
    LongNatural q2({1, 4});
    LongRational b4(p2, q2);  // -15/14
    LongInteger p3(false, {0});
    LongNatural q3({1});
    LongRational ans4(p3, q3);  // 0/1

    EXPECT_EQ(DIV_QQ_Q(a4, b4), ans4);
}