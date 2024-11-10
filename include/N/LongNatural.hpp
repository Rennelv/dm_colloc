#ifndef LONGNATURAL_HPP
#define LONGNATURAL_HPP

#include <cstdint>
#include <initializer_list>
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
 * @details Класс предоставляет методы для создания длинных натуральных чисел из списка инициализации,
 * вектора или строки, а также методы для получения различных представлений числа.
 * Число хранится в виде вектора цифр, где 0-й элемент - старший разряд.
 *
 * @author Журавлев Дмитрий 3381
 */

class LongNatural {
    std::vector<uint8_t> arr;  // вектор цифр числа (0 - старший разряд)
    void trimLeadingZeroes();  // вспомогательный метод для удаления ведущих нулей

   public:
    // Натуральное число 0
    static const LongNatural ZERO;
    // Натуральное число 1
    static const LongNatural ONE;

    // Создает число из списка инциализации
    LongNatural(std::initializer_list<uint8_t> list);
    // Создает число из вектора
    LongNatural(const std::vector<uint8_t>& vec);
    // Создает число из строки
    LongNatural(const std::string& string);

    // Возвращает вектор числа (const&)
    const std::vector<uint8_t>& getArr() const;

    // Возвращает i-ый элемент массива числа (0 - старший разряд)
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
    // Оператор сравнения (проверяет больше ли число other) использует COM_NN_D. Нужен для использования в std::map
    bool operator<(const LongNatural& other) const;
};

#endif  // LONGNATURAL_HPP