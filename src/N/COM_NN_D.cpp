#include "N/COM_NN_D.hpp"

int COM_NN_D(const LongNatural& a, const LongNatural& b) {
    const std::vector<uint8_t>& a_arr = a.getArr();  // получаем массивы цифр числа а
    const std::vector<uint8_t>& b_arr = b.getArr();  // получаем массивы цифр числа b

    /*
        если количество цифр в числе а больше, чем в числе b, то первое больше второго
        если количество цифр в числе а меньше, чем в числе b, то первое меньше второго
    */

    if (a.getLength() > b.getLength()) {
        return 2;
    } else if (a.getLength() < b.getLength()) {
        return 1;
    } else {
        /*
            если количество цифр в числе а равно количеству цифр в числе b то
            если цифра числа а больше цифры числа b, то первое больше второго
            если цифра числа а меньше цифры числа b, то первое меньше второго
        */

        for (size_t i = 0; i < a.getLength(); i++) {
            if (a_arr[i] > b_arr[i]) {
                return 2;
            } else if (a_arr[i] < b_arr[i]) {
                return 1;
            }
        }

        return 0;  // если все цифры числа а равны цифрам числа b, то числа равны
    }
}