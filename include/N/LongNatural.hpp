#ifndef LONGNATURAL_HPP
#define LONGNATURAL_HPP

#include <cstdint>
#include <initializer_list>
#include <string>
#include <vector>

/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с длинными натуральными числами с нулем.

*/

class LongNatural {
    std::vector<uint8_t> arr;  // вектор цифр числа (0 - старший разряд)
    void trimLeadingZeroes();  // вспомогательный метод для удаления ведущих нулей

   public:
    LongNatural(std::initializer_list<uint8_t> list);  // создает число из списка инциализации
    LongNatural(size_t n, int* arr);                   // создает число из массива
    LongNatural(const std::vector<uint8_t>& vec);      // создает число из вектора
    LongNatural(const std::string& string);            // создает число из строки

    const std::vector<uint8_t>& getArr() const;  // возвращает вектор числа
    uint8_t at(size_t i) const;                  // возвращает i-ый элемент массива числа (0 - старший разряд)
    uint8_t radix(size_t i) const;               // возвращает i-ый разряд числа (0 - младший разряд)
    size_t getLength() const;                    // возвращает количество цифр числа
    std::string toString() const;                // возвращает строку числа

    bool operator==(const LongNatural& other) const;  // оператор сравнения (проверяет равенство массивов цифр)
    bool operator!=(const LongNatural& other) const;  // оператор сравнения (проверяет равенство массивов цифр)
};

#endif  // LONGNATURAL_HPP