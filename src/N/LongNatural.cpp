#include "N/LongNatural.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

const LongNatural LongNatural::ZERO = LongNatural("0");
const LongNatural LongNatural::ONE = LongNatural("1");

LongNatural::LongNatural() : _arr(ZERO._arr) {
}

LongNatural::LongNatural(int number) {
    if (number < 0) {
        throw std::invalid_argument("LongNatural constructor: passed number is negative");
    }
    _arr.reserve(1);
    while (number > 0) {
        _arr.push_back(number % 10);
        number /= 10;
    }
    // Если число пустое, то добавляем 0
    if (_arr.empty()) {
        _arr.push_back(0);
    }
}

LongNatural::LongNatural(const std::vector<uint8_t>& vec) : _arr(vec) {
    // Проверка на корректность ввода
    if (std::any_of(_arr.begin(), _arr.end(), [](uint8_t digit) { return digit > 9; })) {
        throw std::invalid_argument("LongNatural constructor: passed vector element is invalid");
    }
    // Удаляем ведущие нули
    _trimLeadingZeroes();
}

LongNatural::LongNatural(std::vector<uint8_t>&& vec) : _arr(std::move(vec)) {
    // Проверка на корректность ввода
    if (std::any_of(_arr.begin(), _arr.end(), [](uint8_t digit) { return digit > 9; })) {
        throw std::invalid_argument("LongNatural constructor: passed vector element is invalid");
    }
    // Удаляем ведущие нули
    _trimLeadingZeroes();
}

LongNatural::LongNatural(const std::string& string) {
    _arr.reserve(string.size());
    for (auto it = string.rbegin(); it != string.rend(); ++it) {
        if (*it < '0' || *it > '9') {
            throw std::invalid_argument("LongNatural constructor: passed string element is invalid");
        }
        _arr.push_back(static_cast<uint8_t>(*it) - '0');
    }
    // Удаляем ведущие нули
    _trimLeadingZeroes();
}

void LongNatural::_trimLeadingZeroes() {
    // Пока число не пустое и первый элемент равен 0, удаляем его
    while (_arr.size() > 1 && _arr.back() == 0) {
        _arr.pop_back();
    }
    // Если число пустое, то добавляем 0
    if (_arr.empty()) {
        _arr.push_back(0);
    }
}

// back-compatibility
const std::vector<uint8_t>& LongNatural::getArr() const {
    return _arr;
}

std::string LongNatural::toString() const {
    std::string result;
    result.reserve(_arr.size());
    for (auto it = _arr.rbegin(); it != _arr.rend(); ++it) {
        result += std::to_string(*it);
    }
    return result;
}

size_t LongNatural::getLength() const {
    return _arr.size();
}

uint8_t LongNatural::at(size_t i) const {
    if (i >= _arr.size()) {
        throw std::out_of_range("LongNatural::at: index out of range");
    }
    size_t idx = _arr.size() - i - 1;
    return _arr.at(idx);
}

uint8_t LongNatural::radix(size_t i) const {
    if (i >= _arr.size()) {
        return 0;
    }
    return _arr[i];
}

bool LongNatural::operator==(const LongNatural& other) const {
    return _arr == other._arr;  // Если массивы равны, то числа равны
}

bool LongNatural::operator!=(const LongNatural& other) const {
    return !(*this == other);  // Если числа не равны, то они не равны
}

bool LongNatural::operator<(const LongNatural& other) const {
    if (this->getLength() != other.getLength()) {
        return this->getLength() < other.getLength();
    }
    // for (size_t i = _arr.size() - 1; i > 0; i--) {
    //     if (_arr[i] < other._arr[i])
    //         return true;
    //     else if (_arr[i] > other._arr[i])
    //         return false;
    // }
    // return false;
    return std::lexicographical_compare(_arr.rbegin(), _arr.rend(), other._arr.rbegin(), other._arr.rend());
}

bool LongNatural::operator>(const LongNatural& other) const {
    if (this->getLength() != other.getLength()) {
        return this->getLength() > other.getLength();
    }
    // for (size_t i = _arr.size() - 1; i > 0; i--) {
    //     if (_arr[i] > other._arr[i])
    //         return true;
    //     else if (_arr[i] < other._arr[i])
    //         return false;
    // }
    // return false;
    return std::lexicographical_compare(other._arr.rbegin(), other._arr.rend(), _arr.rbegin(), _arr.rend());
}

bool LongNatural::operator<=(const LongNatural& other) const {
    return !(*this > other);
}

bool LongNatural::operator>=(const LongNatural& other) const {
    return !(*this < other);
}

bool LongNatural::isZero() const {
    return _arr.size() == 1 && _arr[0] == 0;
}

LongNatural::operator bool() const {
    return _arr.size() != 1 || _arr[0] != 0;
}

LongNatural& LongNatural::operator++() {
    size_t i = 0;
    while (i < _arr.size() && _arr[i] == 9) {
        _arr[i] = 0;
        ++i;
    }
    if (i == _arr.size()) {
        _arr.push_back(1);
    } else {
        ++_arr[i];
    }
    return *this;
}

LongNatural LongNatural::operator++(int) {
    LongNatural copy = *this;  // Create a copy of the current object
    ++(*this);                 // Use the prefix increment operator to increment the current object
    return copy;               // Return the copy which holds the original value
}

LongNatural LongNatural::operator+(const LongNatural& other) const {
    bool comp_res = this->getLength() >= other.getLength();                  // длина this не меньше other
    std::vector<uint8_t> a_arr = comp_res ? this->_arr : other._arr;         // копируем массив цифр большего числа
    const std::vector<uint8_t>& b_arr = comp_res ? other._arr : this->_arr;  // получаем массив цифр меньшего числа

    uint8_t carry = 0;            // перенос
    size_t a_len = a_arr.size();  // длина числа a
    size_t b_len = b_arr.size();  // длина числа b

    for (size_t i = 0; i < b_len; i++) {
        a_arr[i] += (carry + b_arr[i]);  // складываем цифру числа a и перенос и прибавляем к ней цифру числа b

        carry = a_arr[i] / 10;     // вычисляем перенос
        a_arr[i] = a_arr[i] % 10;  // добавляем остаток от деления на 10 в результат
    }
    if (carry != 0) {
        for (size_t i = b_len; i < a_len; i++) {
            a_arr[i] += carry;
            carry = a_arr[i] / 10;
            a_arr[i] %= 10;
            if (carry == 0) {
                break;
            }
        }
        if (carry != 0) {
            a_arr.push_back(carry);
        }
    }

    return LongNatural(std::move(a_arr));  // возвращаем результат
}

LongNatural& LongNatural::operator+=(const LongNatural& other) {
    if (_arr.size() < other._arr.size()) {
        _arr.resize(other._arr.size(), 0);
    }
    uint8_t carry = 0;
    size_t i = 0;
    while (i < other._arr.size()) {
        _arr[i] += (carry + other._arr[i]);
        carry = _arr[i] / 10;
        _arr[i] %= 10;
        i++;
    }
    while (carry != 0) {
        if (i < _arr.size()) {
            _arr[i] += carry;
            carry = _arr[i] / 10;
            _arr[i] %= 10;
        } else {
            _arr.push_back(carry);
            break;
        }
        i++;
    }
    _trimLeadingZeroes();
    return *this;
}

LongNatural LongNatural::operator-(const LongNatural& other) const {
    if (*this < other) {
        throw std::logic_error("LongNatural::operator-: subtraction result is negative");
    }
    std::vector<uint8_t> result(_arr.size());
    uint8_t carry = 0;
    for (size_t i = 0; i < _arr.size(); i++) {
        int diff = _arr[i] - carry;
        if (i < other._arr.size()) {
            diff -= other._arr[i];
        }
        carry = (diff < 0) ? 1 : 0;
        result[i] = (diff + 10) % 10;
    }
    return LongNatural(result);
}

LongNatural& LongNatural::operator-=(const LongNatural& other) {
    if (*this < other) {
        throw std::logic_error("LongNatural::operator-=: subtraction result is negative");
    }
    uint8_t carry = 0;
    for (size_t i = 0; i < _arr.size(); i++) {
        int diff = _arr[i] - carry;
        if (i < other._arr.size()) {
            diff -= other._arr[i];
        }
        carry = (diff < 0) ? 1 : 0;
        _arr[i] = (diff + 10) % 10;
    }
    _trimLeadingZeroes();
    return *this;
}

LongNatural LongNatural::operator*(uint8_t digit) const {
    std::vector<uint8_t> result = _arr;
    result.reserve(result.size() + 1);
    uint8_t carry = 0;
    for (size_t i = 0; i < result.size(); i++) {
        uint8_t mul = result[i] * digit + carry;
        carry = mul / 10;
        result[i] = mul % 10;
    }
    if (carry != 0) {
        result.push_back(carry);
    }
    return LongNatural(std::move(result));
}

LongNatural& LongNatural::operator*=(uint8_t digit) {
    if (digit == 0) {
        *this = LongNatural::ZERO;
        return *this;
    }
    if (digit == 1) {
        return *this;
    }
    uint8_t carry = 0;
    for (size_t i = 0; i < _arr.size(); i++) {
        uint8_t mul = _arr[i] * digit + carry;
        _arr[i] = mul % 10;
        carry = mul / 10;
    }
    if (carry != 0) {
        _arr.push_back(carry);
    }
    _trimLeadingZeroes();
    return *this;
}

LongNatural LongNatural::operator<<(size_t shift) const {
    if (shift == 0 || this->isZero()) return *this;

    if (_arr.size() + shift < _arr.size()) {
        throw std::overflow_error("LongNatural::operator<<: overflow");
    }

    std::vector<uint8_t> result;
    result.reserve(_arr.size() + shift);
    result.insert(result.end(), shift, 0);
    result.insert(result.end(), _arr.begin(), _arr.end());
    return LongNatural(std::move(result));
}

LongNatural& LongNatural::operator<<=(size_t shift) {
    _arr.insert(_arr.begin(), shift, 0);
    return *this;
}

LongNatural LongNatural::operator*(const LongNatural& other) const {
    LongNatural result;
    result._arr.reserve(_arr.size() + other._arr.size());
    for (size_t i = 0; i < _arr.size(); i++) {
        result += (other * _arr[i]) << i;
    }
    return result;
}

LongNatural& LongNatural::operator*=(const LongNatural& other) {
    *this = *this * other;
    return *this;
}

LongNatural LongNatural::subtractMultiplyByDigit(const LongNatural& other, uint8_t digit) const {
    LongNatural nb = other * digit;  // умножаем число other на digit

    if (*this < nb) {  // проверяем не превышает ли произведение первое число
        throw std::logic_error("The first number is less than the product of the second number and a digit.");
    }

    return *this - nb;  // вычитаем из первого числа произведение
}

LongNatural LongNatural::divideForFirstDigit(const LongNatural& b) const {
    if (!b) {
        throw std::logic_error("Division by zero is undefined.");
    }

    if (*this < b) {
        return LongNatural::ZERO;
    }

    size_t k = this->getLength() - b.getLength();
    LongNatural scaled_b = b << k;
    while (*this < scaled_b) {
        k -= 1;
        scaled_b = b << k;
    }

    uint8_t d = 1;
    for (uint8_t test_digit = 2; test_digit <= 9; test_digit++) {
        if (*this >= scaled_b * test_digit) {
            d = test_digit;
        } else {
            break;
        }
    }

    return LongNatural(d) << k;
}

LongNatural LongNatural::operator/(const LongNatural& other) const {
    if (other.isZero()) {
        throw std::logic_error("Divider is zero");
    }

    LongNatural a_copy = *this;              // сохраняем значение a
    LongNatural result = LongNatural::ZERO;  // число для результата
    LongNatural tmp = LongNatural::ONE;      // временная переменная

    while (tmp != LongNatural::ZERO) {  // цикл представляет собой деление в столбик без остатка
        tmp = a_copy.divideForFirstDigit(other);  // сохраняем полученную при делении первую цифру умноженную на 10^k, где k - разряд числа
        result += tmp;      // суммирует переменные, домноженные на 10^k
        tmp = tmp * other;  // умножаем делитель на получившееся частное
        a_copy -= tmp;      // вычитаем это из делимого
    }

    return result;
}

LongNatural& LongNatural::operator/=(const LongNatural& other) {
    *this = *this / other;
    return *this;
}

LongNatural LongNatural::operator%(const LongNatural& other) const {
    return *this - ((*this / other) * other);
}

LongNatural& LongNatural::operator%=(const LongNatural& other) {
    *this = *this % other;
    return *this;
}

LongNatural LongNatural::gcd(const LongNatural& other) const {
    LongNatural a = *this;
    LongNatural b = other;
    while (b != LongNatural::ZERO) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

LongNatural LongNatural::lcm(const LongNatural& other) const {
    return *this / gcd(other) * other;
}
