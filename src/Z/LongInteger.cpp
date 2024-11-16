#include "Z/LongInteger.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>

const LongInteger LongInteger::ZERO = LongInteger(false, {0});
const LongInteger LongInteger::ONE = LongInteger(false, {1});

LongInteger::LongInteger(bool negative, std::initializer_list<uint8_t> list) : negative(negative), arr(list) {
    // Проверка на корректность ввода
    if (std::any_of(arr.begin(), arr.end(), [](uint8_t digit) { return digit > 9; })) {
        throw std::invalid_argument("LongInteger constructor: passed initializer_list element is invalid");
    }
    // Если число пустое, то добавляем 0
    if (arr.empty()) {
        arr.push_back(0);
    }
    // Удаляем ведущие нули
    trimLeadingZeroes();
}

LongInteger::LongInteger(bool negative, const std::vector<uint8_t>& vec) : negative(negative), arr(vec) {
    // Проверка на корректность ввода
    if (std::any_of(arr.begin(), arr.end(), [](uint8_t digit) { return digit > 9; })) {
        throw std::invalid_argument("LongInteger constructor: passed vector element is invalid");
    }
    // Если число пустое, то добавляем 0
    if (arr.empty()) {
        arr.push_back(0);
    }
    // Удаляем ведущие нули
    trimLeadingZeroes();
}

LongInteger::LongInteger(bool negative, const std::string& string) : negative(negative) {
    arr.reserve(string.size());
    for (size_t i = 0; i < string.size(); i++) {
        if (string[i] < '0' || string[i] > '9') {
            throw std::invalid_argument("LongInteger constructor: passed string element is invalid");
        }
        arr.push_back(static_cast<uint8_t>(string[i] - '0'));
    }
    // Если число пустое, то добавляем 0
    if (arr.empty()) {
        arr.push_back(0);
    }
    // Удаляем ведущие нули
    trimLeadingZeroes();
}

LongInteger::LongInteger(const std::string& string) : LongInteger(string.at(0) == '-', string.at(0) == '-' ? string.substr(1) : string) {
}

void LongInteger::trimLeadingZeroes() {
    // Пока число не пустое и первый элемент равен 0, удаляем его
    while (arr.size() > 1 && arr.front() == 0) {
        arr.erase(arr.begin());
    }
    if (arr.size() == 1 && arr[0] == 0) {
        negative = false;  // если число равно 0 - ставим знак положительным
    }
}

const std::vector<uint8_t>& LongInteger::getArr() const {
    return arr;
}

std::string LongInteger::toString() const {
    std::string result;
    if (negative) {
        result += '-';
    }

    for (size_t i = 0; i < arr.size(); i++) {
        result += static_cast<char>(arr[i] + '0');
    }

    return result;
}

bool LongInteger::isNegative() const {
    return negative;
}

size_t LongInteger::getLength() const {
    return arr.size();
}

uint8_t LongInteger::at(size_t i) const {
    if (i >= arr.size()) {
        throw std::out_of_range("LongInteger::at: index out of range");
    }
    return arr[i];
}

uint8_t LongInteger::radix(size_t i) const {
    if (i >= arr.size()) {
        return 0;
    }
    return arr[arr.size() - i - 1];
}

bool LongInteger::operator==(const LongInteger& other) const {
    return negative == other.negative && arr == other.arr;  // Если знаки и массивы равны, то числа равны
}

bool LongInteger::operator!=(const LongInteger& other) const {
    return !(*this == other);  // Если числа не равны, то они не равны
}