#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/MOD_NN_N.hpp"

TEST(test_MOD_NN_N, RemainderByOne) {
    LongNatural a("123456");
    LongNatural b("1");
    LongNatural expected("0");
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 123456 % 1 = 0
}

TEST(test_MOD_NN_N, RemainderWhenALessThanB) {
    LongNatural a("100");
    LongNatural b("2000");
    LongNatural expected("100");
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 100 % 2000 = 100
}

TEST(test_MOD_NN_N, StandardRemainder) {
    LongNatural a("12345");
    LongNatural b("67");
    LongNatural expected("17");  // 12345 % 67 = 11
    EXPECT_EQ(MOD_NN_N(a, b).toString(), expected.toString());
}

TEST(test_MOD_NN_N, RemainderWithMODisorLargerThanMODidend) {
    LongNatural a("9");
    LongNatural b("100");
    LongNatural expected("9");
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 9 % 100 = 9
}

TEST(test_MOD_NN_N, RemainderWhenAMultipleOfB) {
    LongNatural a("625");
    LongNatural b("25");
    LongNatural expected("0");
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 625 % 25 = 0
}

TEST(test_MOD_NN_N, MODisionByZero) {
    LongNatural a("123");
    LongNatural b("0");
    EXPECT_THROW(MOD_NN_N(a, b), std::logic_error);  // Ожидается ошибка при делении на ноль
}
