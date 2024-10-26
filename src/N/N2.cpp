#include "../include/N/N2.hpp"

#include <iostream>
#include <vector>

using namespace std;

bool NZER_N_B(LongNatural x){
    if (x.getLenght() == 1 && x.radix[0] == 0){//проверяем, что количество цифр 1 и эта цифра 0
        return true;
    }
    return false;
}

