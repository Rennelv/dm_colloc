#ifndef LONGINTEGER_HPP
#define LONGINTEGER_HPP

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "N/LongNatural.hpp"

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
    bool negative;                // флаг знака числа
    LongNatural _natural_number;  // модуль числа

   public:
    // Целое число 0
    static const LongInteger ZERO;
    // Целое число 1
    static const LongInteger ONE;

    // Конструктор по умолчанию (создает число 0)
    LongInteger();

    // Создает число из натурального числа и знака
    LongInteger(bool isNegative, const LongNatural& number);
    // Создает число из списка инциализации
    LongInteger(bool isNegative, std::initializer_list<uint8_t> list);
    // // Создает число из вектора
    LongInteger(bool isNegative, const std::vector<uint8_t>& vec);
    // // Создает число из строки, принимает знак и строку натурального числа
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
    // Возвращает натуральное число
    const LongNatural& getNaturalNumber() const;

    // Возвращает строку числа
    std::string toString() const;

    // Возвращает количество цифр числа
    size_t getLength() const;

    // Оператор сравнения (проверяет равенство знаков и массивов цифр)
    bool operator==(const LongInteger& other) const;
    // Оператор сравнения (обратный оператору ==)
    bool operator!=(const LongInteger& other) const;

    // Оператор сравнения (проверяет больше ли число other)
    bool operator<(const LongInteger& other) const;
    // Оператор сравнения (проверяет меньше ли число other)
    bool operator>(const LongInteger& other) const;
    // Оператор сравнения (проверяет больше или равно ли число other)
    bool operator<=(const LongInteger& other) const;
    // Оператор сравнения (проверяет меньше или равно ли число other)
    bool operator>=(const LongInteger& other) const;

    // Смена знака числа
    LongInteger operator-() const;

    LongNatural abs() const;

    // Проверка на равенство нулю
    bool isZero() const;

    // Оператор булева преобразования (проверка на неравенство нулю)
    explicit operator bool() const;

    // Оператор сложения
    LongInteger operator+(const LongInteger& other) const;
    // Оператор присваивания сложения
    LongInteger& operator+=(const LongInteger& other);

    // Оператор вычитания
    LongInteger operator-(const LongInteger& other) const;
    // Оператор присваивания вычитания
    LongInteger& operator-=(const LongInteger& other);

    // Оператор умножения
    LongInteger operator*(const LongInteger& other) const;
    // Оператор присваивания умножения
    LongInteger& operator*=(const LongInteger& other);

    // Оператор деления
    LongInteger operator/(const LongInteger& other) const;
    // Оператор присваивания деления
    LongInteger& operator/=(const LongInteger& other);

    // Оператор остатка от деления
    LongInteger operator%(const LongInteger& other) const;
    // Оператор присваивания остатка от деления
    LongInteger& operator%=(const LongInteger& other);

    // Преобразование целого неотрицательного в натуральное
    explicit operator LongNatural() const;
};

#endif  // LONGINTEGER_HPP