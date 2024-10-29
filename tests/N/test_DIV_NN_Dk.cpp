#include <gtest/gtest.h>

#include "N/DIV_NN_Dk.hpp"
#include "N/LongNatural.hpp"

TEST(test_DIV_NN_Dk, FirstDigitIsLarger) {
    LongNatural a1({1, 5, 4, 9, 8});  // 15498
    LongNatural b1({9});              // 9
    LongNatural result = DIV_NN_Dk(a1, b1);
    // 15498 / 9 = 1722, первая цифра = 1, 1 * 10^3 = 1000
    EXPECT_EQ(result.toString(), "1000");
}

TEST(test_DIV_NN_Dk, SecondDigitIsLarger) {
    LongNatural a2({9});              // 9
    LongNatural b2({1, 5, 4, 9, 8});  // 15498
    LongNatural result = DIV_NN_Dk(a2, b2);
    // 9 / 15498 = 0
    EXPECT_EQ(result.toString(), "0");
}

TEST(test_DIV_NN_Dk, EqualNumbers) {
    LongNatural a3({2, 5});  // 25
    LongNatural b3({2, 5});  // 25
    LongNatural result = DIV_NN_Dk(a3, b3);
    // 25 / 25 = 1, 1 * 10^0 = 1
    EXPECT_EQ(result.toString(), "1");
}

TEST(test_DIV_NN_Dk, DivideWithCarry) {
    LongNatural a4({6, 5});  // 65
    LongNatural b4({1});     // 1
    LongNatural result = DIV_NN_Dk(a4, b4);
    // 65 / 1 = 65, первая цифра = 6, 6 * 10^2 = 60
    EXPECT_EQ(result.toString(), "60");
}

TEST(test_DIV_NN_Dk, DivideByZero) {
    LongNatural a5({1, 2, 3});  // 123
    LongNatural b5({0});        // 0
    // деление на 0 не определено
    EXPECT_THROW(DIV_NN_Dk(a5, b5), std::logic_error);
}

TEST(test_DIV_NN_Dk, ZeroIsFirst) {
    LongNatural a5({0});               // 0
    LongNatural b5({1, 2, 3});         // 123
    EXPECT_EQ(DIV_NN_Dk(a5, b5), a5);  // 0 / 123 = 0
}
