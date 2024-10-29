#include "P/MUL_Pxk_P.hpp"

Polynomial MUL_Pxk_P(const Polynomial& a, size_t k) {
    std::vector<LongRational> vec = a.getArr();  // возвращает вектор коэффициентов
    size_t ln = vec.size();                      // возвращает размер вектора
    // следующая строка увеличивает степень каждого элемента полинома на k
    vec.resize(ln + k, LongRational(LongInteger("0"), LongNatural("1")));
    return Polynomial(vec);  // Возвращаем новое число с инвертированным знаком
}