#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "Z/LongInteger.hpp"
#include "Z/TRANS_Z_N.hpp"

TEST(test_TRANS_Z_N, PositiveNumber) {
    LongInteger a(false, {1, 2, 3});            // 123
    EXPECT_EQ(TRANS_Z_N(a).toString(), "123");  // 123
}

TEST(test_TRANS_N_Z, Zero) {
    LongInteger a(false, {0});                                     // 0
    EXPECT_THROW({ TRANS_Z_N(a).toString(); }, std::logic_error);  // проверка на выброс ошибки
}