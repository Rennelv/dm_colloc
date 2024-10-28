#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <initializer_list>
#include <vector>

#include "Q/LongRational.hpp"
/*
    Выполнил Журавлев Дмитрий 3381

    Класс для работы с многочленами с коэффицентами из длинных рациональных чисел.

*/

class Polynomial {
    std::vector<LongRational> coefficients;  // массив коэффициентов
   public:
    Polynomial(std::initializer_list<LongRational> list);  // создает полином из списка коэффициентов
    Polynomial(size_t n, LongRational* arr);               // создает полином из массива коэффициентов
    Polynomial(const std::vector<LongRational>& vec);      // создает полином из вектора коэффициентов

    std::vector<LongRational> getArr() const;  // возвращает вектор коэффициентов
    size_t getLength() const;                  // возвращает количество коэффициентов
    size_t degree() const;                     // возвращает степень полинома
    std::string toString() const;              // возвращает строку полинома

    bool operator==(const Polynomial& other) const;  // оператор сравнения (проверяет равенство коэффициентов)
    bool operator!=(const Polynomial& other) const;  // оператор сравнения (проверяет равенство коэффициентов)
};

#endif