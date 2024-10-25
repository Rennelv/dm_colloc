#ifndef LONGINTEGER_HPP
#define LONGINTEGER_HPP

#include <cstdint>
#include <string>
#include <vector>

/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с длинными целыми числами.

*/

class LongInteger {
    bool negative;
    std::vector<uint8_t> arr;

   public:
    LongInteger(bool isNegative, const std::vector<uint8_t>& vec);  // создает число из вектора
    LongInteger(bool isNegative, const std::string& string);  // создает число из строки, принимает знак и строку натурального числа
    LongInteger(const std::string& string);  // создает число из строки, принимает строку целого числа(знак и натуральное число)

    bool isNegative() const;              // возвращает знак числа
    uint8_t at(size_t i) const;           // возвращает i-ый элемент массива числа (0 - старший разряд)
    uint8_t radix(size_t i) const;        // возвращает i-ый разряд числа (0 - младший разряд)
    std::vector<uint8_t> getArr() const;  // возвращает вектор числа
    std::string toString() const;         // возвращает строку числа
    size_t getLength() const;             // возвращает количество цифр числа
};

#endif  // LONGINTEGER_HPP