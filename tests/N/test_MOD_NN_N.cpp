#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "N/MOD_NN_N.hpp"

TEST(test_MOD_NN_N, RemainderByOne) {
    LongNatural a = {1, 2, 3, 4, 5, 6};
    LongNatural b = {1};
    LongNatural expected = {0};
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 123456 % 1 = 0
}

TEST(test_MOD_NN_N, RemainderWhenALessThanB) {
    LongNatural a = {1, 0, 0};
    LongNatural b = {2, 0, 0, 0};
    LongNatural expected = a;
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 100 % 2000 = 100
}

TEST(test_MOD_NN_N, StandardRemainder) {
    LongNatural a = {1, 2, 3, 4, 5};
    LongNatural b = {6, 7};
    LongNatural expected = {1, 7};  // 12345 % 67 = 11
    EXPECT_EQ(MOD_NN_N(a, b), expected);
}

TEST(test_MOD_NN_N, RemainderWithMODisorLargerThanMODidend) {
    LongNatural a = {9};
    LongNatural b = {1, 0, 0};
    LongNatural expected = a;
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 9 % 100 = 9
}

TEST(test_MOD_NN_N, RemainderWhenAMultipleOfB) {
    LongNatural a = {6, 2, 5};
    LongNatural b = {2, 5};
    LongNatural expected = {0};
    EXPECT_EQ(MOD_NN_N(a, b), expected);  // 625 % 25 = 0
}

TEST(test_MOD_NN_N, MODisionByZero) {
    LongNatural a = {1, 2, 3};
    LongNatural b = {0};
    EXPECT_THROW(MOD_NN_N(a, b), std::logic_error);  // Ожидается ошибка при делении на ноль
}
