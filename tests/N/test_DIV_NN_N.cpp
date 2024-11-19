#include <gtest/gtest.h>

#include <string>

#include "N/DIV_NN_N.hpp"
#include "N/LongNatural.hpp"

TEST(DivisionTests, DivisionByOne) {
    LongNatural a("123456");
    LongNatural b("1");
    EXPECT_EQ(DIV_NN_N(a, b).toString(), std::string("123456"));  // 123456 div 1 = 123456
}

TEST(DivisionTests, DivisionWhenALessThanB) {
    LongNatural a(std::string("100"));
    LongNatural b(std::string("20000"));
    EXPECT_EQ(DIV_NN_N(a, b).toString(), std::string("0"));  // 100 div 20000 = 0
}

TEST(DivisionTests, StandardDivision) {
    LongNatural a(std::string("12345"));
    LongNatural b(std::string("67"));
    EXPECT_EQ(DIV_NN_N(a, b).toString(), std::string("184"));  // 12345 div 67 = 184
}

TEST(DivisionTests, DivisionByZero) {
    LongNatural a(std::string("123"));
    LongNatural b(std::string("0"));
    EXPECT_THROW(DIV_NN_N(a, b).toString(), std::logic_error);  // деление на ноль
}

TEST(DivisionTests, DivisionWhenAMultipleOfB) {
    LongNatural a(std::string("625"));
    LongNatural b(std::string("25"));
    EXPECT_EQ(DIV_NN_N(a, b).toString(), std::string("25"));  // 625 div 25 = 25
}
