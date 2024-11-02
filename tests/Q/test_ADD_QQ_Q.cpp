#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/ADD_QQ_Q.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(Test_ADD_QQ_Q, PositiveRationals) {
    LongInteger p1(false, {3});
    LongNatural q1({5});
    LongRational a1(p1, q1);  // 3/5

    LongInteger p2(false, {1});
    LongNatural q2({5});
    LongRational b1(p2, q2);  // 1/5

    LongInteger p3(false, {4});
    LongNatural q3({5});
    LongRational expected_result(p3, q3);  // 3/5 + 1/5 = 4/5

    EXPECT_EQ(ADD_QQ_Q(a1, b1), expected_result);
}

TEST(Test_ADD_QQ_Q, MixedSignRationals) {
    LongInteger p1(false, {7});
    LongNatural q1({1, 0});
    LongRational a2(p1, q1);  // 7/10

    LongInteger p2(true, {4});
    LongNatural q2({1, 0});
    LongRational b2(p2, q2);  // -4/10

    LongInteger p3(false, {3});
    LongNatural q3({1, 0});
    LongRational expected_result(p3, q3);  // 7/10 + (-4/10) = 3/10

    EXPECT_EQ(ADD_QQ_Q(a2, b2), expected_result);
}

TEST(Test_ADD_QQ_Q, NegativeRationals) {
    LongInteger p1(true, {1});
    LongNatural q1({4});
    LongRational a3(p1, q1);  // -1/4

    LongInteger p2(true, {2});
    LongNatural q2({4});
    LongRational b3(p2, q2);  // -2/4

    LongInteger p3(true, {3});
    LongNatural q3({4});
    LongRational expected_result(p3, q3);  // -1/4 + (-2/4) = -3/4

    EXPECT_EQ(ADD_QQ_Q(a3, b3), expected_result);
}

TEST(Test_ADD_QQ_Q, ZeroValue) {
    LongInteger p1(false, {0});
    LongNatural q1({1});
    LongRational a4(p1, q1);  // 0

    LongInteger p2(false, {5});
    LongNatural q2({3});
    LongRational b4(p2, q2);  // 5/3

    LongInteger p3(false, {5});
    LongNatural q3({3});
    LongRational expected_result(p3, q3);  // 5/3

    EXPECT_EQ(ADD_QQ_Q(a4, b4), expected_result);
}

TEST(Test_ADD_QQ_Q, DifferentDenominators) {
    LongInteger p1(false, {3});
    LongNatural q1({4});
    LongRational a5(p1, q1);  // 3/4

    LongInteger p2(false, {5});
    LongNatural q2({6});
    LongRational b5(p2, q2);  // 5/6

    LongInteger p3(false, {1, 9});
    LongNatural q3({1, 2});
    LongRational expected_result(p3, q3);  // 19/12

    EXPECT_EQ(ADD_QQ_Q(a5, b5), expected_result);
}
