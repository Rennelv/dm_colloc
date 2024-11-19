#include <gtest/gtest.h>

#include "N/DIV_NN_Dk.hpp"
#include "N/LongNatural.hpp"

TEST(test_DIV_NN_Dk, FirstDigitIsLarger) {
    LongNatural a1("15498");  // 15498
    LongNatural b1("9");      // 9
    LongNatural result = DIV_NN_Dk(a1, b1);
    // 15498 / 9 = 1722, первая цифра = 1, 1 * 10^3 = 1000
    EXPECT_EQ(result.toString(), "1000");
}

TEST(test_DIV_NN_Dk, SecondDigitIsLarger) {
    LongNatural a2("9");      // 9
    LongNatural b2("15498");  // 15498
    LongNatural result = DIV_NN_Dk(a2, b2);
    // 9 / 15498 = 0
    EXPECT_EQ(result.toString(), "0");
}

TEST(test_DIV_NN_Dk, EqualNumbers) {
    LongNatural a3("25");  // 25
    LongNatural b3("25");  // 25
    LongNatural result = DIV_NN_Dk(a3, b3);
    // 25 / 25 = 1, 1 * 10^0 = 1
    EXPECT_EQ(result.toString(), "1");
}

TEST(test_DIV_NN_Dk, DivideWithCarry) {
    LongNatural a4("65");  // 65
    LongNatural b4("1");   // 1
    LongNatural result = DIV_NN_Dk(a4, b4);
    // 65 / 1 = 65, первая цифра = 6, 6 * 10^2 = 60
    EXPECT_EQ(result.toString(), "60");
}

TEST(test_DIV_NN_Dk, DivideByZero) {
    LongNatural a5("123");  // 123
    LongNatural b5("0");    // 0
    // деление на 0 не определено
    EXPECT_THROW(DIV_NN_Dk(a5, b5), std::logic_error);
}

TEST(test_DIV_NN_Dk, ZeroIsFirst) {
    LongNatural a5("0");               // 0
    LongNatural b5("124");             // 124
    EXPECT_EQ(DIV_NN_Dk(a5, b5), a5);  // 0 / 124 = 0
}
