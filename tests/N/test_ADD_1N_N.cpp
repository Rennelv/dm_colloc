#include <gtest/gtest.h>

#include "N/ADD_1N_N.hpp"

// Тест добавления единицы к числу без переноса
// Число 123 -> результат 124
TEST(ADD_1N_N, AddOneWithoutCarry) {
    LongNatural a({1, 2, 3});
    LongNatural expected({1, 2, 4});
    EXPECT_EQ(ADD_1N_N(a).getArr(), expected.getArr());
}

// Тест добавления единицы с переносом внутри числа
// Число 199 -> результат 200
TEST(ADD_1N_N, AddOneWithCarryInternal) {
    LongNatural a({1, 9, 9});
    LongNatural expected({2, 0, 0});
    EXPECT_EQ(ADD_1N_N(a).getArr(), expected.getArr());
}

// Тест добавления единицы с переносом на новый разряд
// Число 999 -> результат 1000
TEST(ADD_1N_N, AddOneWithCarryNewDigit) {
    LongNatural a({9, 9, 9});
    LongNatural expected({1, 0, 0, 0});
    EXPECT_EQ(ADD_1N_N(a).getArr(), expected.getArr());
}

// Тест добавления единицы к числу 0 (если разрешено начальное значение 0)
// Число 0 -> результат 1
TEST(ADD_1N_N, AddOneToZero) {
    LongNatural a({0});
    LongNatural expected({1});
    EXPECT_EQ(ADD_1N_N(a).getArr(), expected.getArr());
}
