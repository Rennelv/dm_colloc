#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Q/TRANS_Q_Z.hpp"
#include "Z/LongInteger.hpp"

TEST(test_TRANS_Q_Z, DenominatorOne) {
    LongInteger numerator(false, {1, 2, 3});    // 123
    LongNatural denominator({1});               // 1
    LongRational a(numerator, denominator);     // 123 / 0
    EXPECT_EQ(TRANS_Q_Z(a).toString(), "123");  // 123
}

TEST(test_TRANS_Q_Z, DenominatorNotOne) {
    LongInteger numerator(false, {1, 2, 3});            // 123
    LongNatural denominator({2});                       // 2
    LongRational a(numerator, denominator);             // 123 / 2
    EXPECT_THROW({ TRANS_Q_Z(a); }, std::logic_error);  // проверка на выброс ошибки
}