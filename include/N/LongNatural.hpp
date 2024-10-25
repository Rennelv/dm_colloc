#ifndef LONGNATURAL_HPP
#define LONGNATURAL_HPP
#include <sys/types.h>

#include <cstdint>
#include <string>
#include <vector>

/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с длинными натуральными числами с нулем.

*/

class LongNatural {
    std::vector<uint8_t> arr;

   public:
    LongNatural(const std::vector<uint8_t>& vec);  // создает число из вектора
    LongNatural(const std::string& string);        // создает число из строки

    std::vector<uint8_t> getArr() const;  // возвращает вектор числа
    uint8_t at(size_t i) const;           // возвращает i-ый элемент массива числа (0 - старший разряд)
    uint8_t radix(size_t i) const;        // возвращает i-ый разряд числа (0 - младший разряд)
    size_t getLength() const;             // возвращает количество цифр числа
    std::string toString() const;         // возвращает строку числа
};

#endif  // LONGNATURAL_HPP