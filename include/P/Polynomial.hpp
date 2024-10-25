#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <initializer_list>
#include <vector>

#include "Z/LongInteger.hpp"

/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с многочленами с коэффицентами из днинных целых чисел.

*/

class Polynomial {
    std::vector<LongInteger> coefficients;  // массив коэффициентов
   public:
    Polynomial(std::initializer_list<LongInteger> list);  // создает полином из списка коэффициентов
    Polynomial(size_t n, LongInteger* arr);               // создает полином из массива коэффициентов
    Polynomial(const std::vector<LongInteger>& vec);      // создает полином из вектора коэффициентов

    std::vector<LongInteger> getArr() const;  // возвращает вектор коэффициентов
    size_t getLength() const;                 // возвращает количество коэффициентов
    size_t degree() const;                    // возвращает степень полинома
    std::string toString() const;             // возвращает строку полинома
};

#endif