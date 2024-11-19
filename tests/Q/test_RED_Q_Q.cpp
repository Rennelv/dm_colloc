#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Q/RED_Q_Q.hpp"
#include "Z/LongInteger.hpp"

TEST(Test_RED_Q_Q, Q1) {
    LongInteger p1("3");
    LongNatural q1("6");
    LongRational a(p1, q1);

    LongInteger p2("1");
    LongNatural q2("2");
    LongRational b(p2, q2);

    LongInteger p3("12");
    LongNatural q3("24");
    LongRational c(p3, q3);

    LongInteger p4("-12");
    LongNatural q4("24");
    LongRational d(p4, q4);

    LongInteger p2_neg("-1");
    LongRational e(p2_neg, q2);

    LongInteger null("0");
    LongNatural q5("1");
    LongRational f(null, q2);
    LongRational g(null, q5);

    EXPECT_EQ(RED_Q_Q(a), b);
    EXPECT_EQ(RED_Q_Q(b), b);
    EXPECT_EQ(RED_Q_Q(c), b);
    EXPECT_EQ(RED_Q_Q(d), e);
    EXPECT_EQ(RED_Q_Q(f), g);
}