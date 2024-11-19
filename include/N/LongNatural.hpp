#ifndef LONGNATURAL_HPP
#define LONGNATURAL_HPP

#include <cstdint>
#include <string>
#include <vector>

/**
 * @file LongNatural.hpp
 * @brief Класс для работы с длинными натуральными числами с нулем.
 */

/**
 * @class LongNatural
 * @brief Класс для работы с длинными натуральными числами с нулем.
 *
 * @details Класс предоставляет методы для создания длинных натуральных чисел из вектора или строки,
 * а также методы для получения различных представлений числа.
 * Число хранится в виде вектора цифр, где 0-й элемент - младший разряд.
 *
 * @author Журавлев Дмитрий 3381
 */

class LongNatural {
    std::vector<uint8_t> _arr;  // вектор цифр числа (0 - младший разряд)
    void _trimLeadingZeroes();  // вспомогательный метод для удаления ведущих нулей

   public:
    // Натуральное число 0
    static const LongNatural ZERO;
    // Натуральное число 1
    static const LongNatural ONE;

    // Конструктор по умолчанию (создает число 0)
    LongNatural();

    // Создает число из int
    LongNatural(int number);
    // Создает число из вектора
    LongNatural(const std::vector<uint8_t>& vec);
    // Создает число из вектора (move-семантика)
    LongNatural(std::vector<uint8_t>&& vec);
    // Создает число из строки
    LongNatural(const std::string& string);

    // Возвращает вектор числа (const&)
    const std::vector<uint8_t>& getArr() const;

    // Возвращает i-ый элемент числа (0 - старший разряд)
    uint8_t at(size_t i) const;

    // Возвращает i-ый разряд числа (0 - младший разряд)
    uint8_t radix(size_t i) const;

    // Возвращает количество цифр числа
    size_t getLength() const;

    // Возвращает строку числа
    std::string toString() const;

    // Оператор сравнения (проверяет равенство массивов цифр)
    bool operator==(const LongNatural& other) const;
    // Оператор сравнения (обратный оператору ==)
    bool operator!=(const LongNatural& other) const;
    // Оператор сравнения (проверяет больше ли число other)
    bool operator<(const LongNatural& other) const;
    // Оператор сравнения (проверяет меньше ли число other)
    bool operator>(const LongNatural& other) const;
    // Оператор сравнения (проверяет больше или равно ли число other)
    bool operator<=(const LongNatural& other) const;
    // Оператор сравнения (проверяет меньше или равно ли число other)
    bool operator>=(const LongNatural& other) const;

    // // Функция умножения на цифру
    // LongNatural mulByDigit(uint8_t digit) const;

    // Функция вычитания из числа other числа, умноженного на digit
    LongNatural subtractMultiplyByDigit(const LongNatural& other, uint8_t digit) const;

    // Функция поиска первой цифры частного от деления на other
    LongNatural divideForFirstDigit(const LongNatural& other) const;

    // Проверка на равенство нулю
    bool isZero() const;

    // Оператор булева преобразования (проверка на неравенство нулю)
    explicit operator bool() const;

    LongNatural& operator++();    // prefix increment
    LongNatural operator++(int);  // postfix increment

    LongNatural& operator--();    // prefix decrement
    LongNatural operator--(int);  // postfix decrement

    // Оператор сложения
    LongNatural operator+(const LongNatural& other) const;
    // Оператор присваивания сложения
    LongNatural& operator+=(const LongNatural& other);

    // Оператор вычитания
    LongNatural operator-(const LongNatural& other) const;
    // Оператор присваивания вычитания
    LongNatural& operator-=(const LongNatural& other);

    // Оператор умножения
    LongNatural operator*(const LongNatural& other) const;
    // Оператор присваивания умножения
    LongNatural& operator*=(const LongNatural& other);

    // Оператор умножения на цифру
    LongNatural operator*(uint8_t digit) const;
    // Оператор присваивания умножения на цифру
    LongNatural& operator*=(uint8_t digit);

    // Оператор деления
    LongNatural operator/(const LongNatural& other) const;
    // Оператор присваивания деления
    LongNatural& operator/=(const LongNatural& other);

    // Оператор остатка от деления
    LongNatural operator%(const LongNatural& other) const;
    // Оператор присваивания остатка от деления
    LongNatural& operator%=(const LongNatural& other);

    // Оператор умножения на степень десятки
    LongNatural operator<<(size_t k) const;
    // Оператор присваивания умножения на степень десятки
    LongNatural& operator<<=(size_t k);

    // Наибольший общий делитель
    LongNatural gcd(const LongNatural& other) const;
    // Наименьшее общее кратное
    LongNatural lcm(const LongNatural& other) const;
};

#endif  // LONGNATURAL_HPP