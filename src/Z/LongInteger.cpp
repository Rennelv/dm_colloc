#include "Z/LongInteger.hpp"

#include <cstdint>
#include <stdexcept>

LongInteger::LongInteger(bool negative, const std::vector<uint8_t>& vec) : negative(negative) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] > 9) {
            throw std::invalid_argument("LongInteger::LongInteger: passed vector element is invalid");
        }
    }
    arr = vec;
}

LongInteger::LongInteger(bool negative, const std::string& string) : negative(negative) {
    arr.reserve(string.size());
    for (size_t i = 0; i < string.size(); i++) {
        if (string[i] < '0' || string[i] > '9') {
            throw std::invalid_argument("LongInteger::LongInteger: passed string element is invalid");
        }
        arr.push_back(static_cast<uint8_t>(string[i] - '0'));
    }
}

LongInteger::LongInteger(const std::string& string) {
    negative = false;
    if (string[0] == '-') {
        negative = true;
    }

    arr.reserve(string.size() - negative);
    for (size_t i = negative; i < string.size(); i++) {
        if (string[i] < '0' || string[i] > '9') {
            throw std::invalid_argument("LongNatural constructor error: passed string element is invalid");
        }
        arr.push_back(static_cast<uint8_t>(string[i] - '0'));
    }
}

std::vector<uint8_t> LongInteger::getArr() const {
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

// возвращает i-ый элемент массива числа (0 - старший разряд)
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