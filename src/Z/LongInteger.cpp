#include "Z/LongInteger.hpp"

#include <cstdint>
#include <stdexcept>

LongInteger::LongInteger(bool negative, std::initializer_list<uint8_t> list) : negative(negative), arr(list) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > 9) {
            throw std::invalid_argument("LongInteger::LongInteger: passed initializer_list element is invalid");
        }
    }
    trimLeadingZeroes();
}

LongInteger::LongInteger(bool negative, const std::vector<uint8_t>& vec) : negative(negative), arr(vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] > 9) {
            throw std::invalid_argument("LongInteger::LongInteger: passed vector element is invalid");
        }
    }
    trimLeadingZeroes();
}

LongInteger::LongInteger(bool negative, const std::string& string) : negative(negative) {
    arr.reserve(string.size());
    for (size_t i = 0; i < string.size(); i++) {
        if (string[i] < '0' || string[i] > '9') {
            throw std::invalid_argument("LongInteger::LongInteger: passed string element is invalid");
        }
        arr.push_back(static_cast<uint8_t>(string[i] - '0'));
    }
    trimLeadingZeroes();
}

LongInteger::LongInteger(const std::string& string) : LongInteger(string.at(0) == '-', string.at(0) == '-' ? string.substr(1) : string) {
}

void LongInteger::trimLeadingZeroes() {
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