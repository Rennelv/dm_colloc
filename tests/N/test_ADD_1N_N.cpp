#include <gtest/gtest.h>

#include <string>

#include "N/ADD_1N_N.hpp"


// Тест добавления единицы к числу без переноса
// Число "123" -> результат "124"
TEST(ADD_1N_N, AddOneWithoutCarry) {
    LongNatural a("123");
    LongNatural expected("124");
    EXPECT_EQ(ADD_1N_N(a).toString(), expected.toString());
}

// Тест добавления единицы с переносом внутри числа
// Число "199" -> результат "200"
TEST(ADD_1N_N, AddOneWithCarryInternal) {
    LongNatural a("199");
    LongNatural expected("200");
    EXPECT_EQ(ADD_1N_N(a).toString(), expected.toString());
}

// Тест добавления единицы с переносом на новый разряд
// Число "999" -> результат "1000"
TEST(ADD_1N_N, AddOneWithCarryNewDigit) {
    LongNatural a("999");
    LongNatural expected("1000");
    EXPECT_EQ(ADD_1N_N(a).toString(), expected.toString());
}

// Тест добавления единицы к числу 0 (если разрешено начальное значение 0)
// Число "0" -> результат "1"
TEST(ADD_1N_N, AddOneToZero) {
    LongNatural a("0");
    LongNatural expected("1");
    EXPECT_EQ(ADD_1N_N(a).toString(), expected.toString());
}
