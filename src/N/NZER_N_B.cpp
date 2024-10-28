#include "../include/N/NZER_N_B.hpp"

#include "../include/N/LongNatural.hpp"

#include <iostream>
#include <vector>

using namespace std;

bool NZER_N_B(const LongNatural &a)
{
    if (a.getLength() == 1 && a.radix(0) == 0)
    { // проверяем, что количество цифр 1 и эта цифра 0
        return false;
    }
    return true;
}