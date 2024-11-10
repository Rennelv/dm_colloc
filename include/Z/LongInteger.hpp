#ifndef LONGINTEGER_HPP
#define LONGINTEGER_HPP

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

/**
 * @file LongInteger.hpp
 * @brief Класс для работы с длинными целыми числами.
 */

/**
 * @class LongInteger
 * @brief Класс для работы с длинными целыми числами.
 *
 * @details Класс предоставляет методы для создания длинных целых чисел из списка инициализации, вектора или строки,
 * а также методы для получения знака числа, доступа к цифрам числа, получения вектора цифр, представления числа в виде строки,
 * получения количества цифр.
 * Число хранится в виде пары (знак, вектор цифр).
 *
 * @author Журавлев Дмитрий 3381
 */

class LongInteger {
    bool negative;             // флаг знака числа
    std::vector<uint8_t> arr;  // вектор цифр числа (0 - старший разряд)
    void trimLeadingZeroes();  // вспомогательный метод для удаления ведущих нулей

   public:
    // Целое число 0
    static const LongInteger ZERO;
    // Целое число 1
    static const LongInteger ONE;

    // Создает число из списка инциализации
    LongInteger(bool isNegative, std::initializer_list<uint8_t> list);
    // Создает число из вектора
    LongInteger(bool isNegative, const std::vector<uint8_t>& vec);
    // Создает число из строки, принимает знак и строку натурального числа
    LongInteger(bool isNegative, const std::string& string);
    // Создает число из строки, принимает строку целого числа(знак и натуральное число)
    LongInteger(const std::string& string);

    // Возвращает знак числа
    bool isNegative() const;

    // Возвращает i-ый элемент массива числа (0 - старший разряд)
    uint8_t at(size_t i) const;

    // Возвращает i-ый разряд числа (0 - младший разряд)
    uint8_t radix(size_t i) const;

    // Возвращает вектор числа (const&)
    const std::vector<uint8_t>& getArr() const;

    // Возвращает строку числа
    std::string toString() const;

    // Возвращает количество цифр числа
    size_t getLength() const;

    // Оператор сравнения (проверяет равенство знаков и массивов цифр)
    bool operator==(const LongInteger& other) const;
    // Оператор сравнения (обратный оператору ==)
    bool operator!=(const LongInteger& other) const;
};

#endif  // LONGINTEGER_HPP