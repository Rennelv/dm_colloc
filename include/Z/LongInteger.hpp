#ifndef LONGINTEGER_HPP
#define LONGINTEGER_HPP

#include <cstddef>
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
    void trimLeadingZeroes();

   public:
    LongInteger(bool isNegative, std::initializer_list<uint8_t> list);  // создает число из списка инциализации
    LongInteger(bool isNegative, size_t n, int* arr);                   // создает число из массива
    LongInteger(bool isNegative, const std::vector<uint8_t>& vec);      // создает число из вектора
    LongInteger(bool isNegative, const std::string& string);  // создает число из строки, принимает знак и строку натурального числа
    LongInteger(const std::string& string);  // создает число из строки, принимает строку целого числа(знак и натуральное число)

    bool isNegative() const;              // возвращает знак числа
    uint8_t at(size_t i) const;           // возвращает i-ый элемент массива числа (0 - старший разряд)
    uint8_t radix(size_t i) const;        // возвращает i-ый разряд числа (0 - младший разряд)
    std::vector<uint8_t> getArr() const;  // возвращает вектор числа
    std::string toString() const;         // возвращает строку числа
    size_t getLength() const;             // возвращает количество цифр числа

    bool operator==(const LongInteger& other) const;  // оператор сравнения
    bool operator!=(const LongInteger& other) const;  // оператор сравнения
};

#endif  // LONGINTEGER_HPP