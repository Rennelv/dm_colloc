#include "N/LongNatural.hpp"

#include <cstddef>
#include <stdexcept>

LongNatural::LongNatural(std::initializer_list<uint8_t> list) : arr(list) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > 9) {
            throw std::invalid_argument("LongNatural::LongNatural: passed initializer_list element is invalid");
        }
    }
}

LongNatural::LongNatural(size_t n, int* arr) {
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > 9 || arr[i] < 0) {
            throw std::invalid_argument("LongNatural::LongNatural: passed array element is invalid");
        }
    }
    this->arr.reserve(n);
    for (size_t i = 0; i < n; i++) {
        this->arr.push_back(static_cast<uint8_t>(arr[i]));
    }
}

LongNatural::LongNatural(const std::vector<uint8_t>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] > 9) {
            throw std::invalid_argument("LongNatural::LongNatural: passed vector element is invalid");
        }
    }
    arr = vec;
}

LongNatural::LongNatural(const std::string& string) {
    arr.reserve(string.size());
    for (size_t i = 0; i < string.size(); i++) {
        if (string[i] < '0' || string[i] > '9') {
            throw std::invalid_argument("LongNatural::LongNatural: passed string element is invalid");
        }
        arr.push_back(static_cast<uint8_t>(string[i] - '0'));
    }
}

std::vector<uint8_t> LongNatural::getArr() const {
    return arr;
}

std::string LongNatural::toString() const {
    std::string result;
    for (size_t i = 0; i < arr.size(); i++) {
        result += static_cast<char>(arr[i] + '0');
    }
    return result;
}

size_t LongNatural::getLength() const {
    return arr.size();
}

uint8_t LongNatural::at(size_t i) const {
    if (i >= arr.size()) {
        throw std::out_of_range("LongNatural::at: index out of range");
    }
    return arr[i];
}

uint8_t LongNatural::radix(size_t i) const {
    if (i >= arr.size()) {
        return 0;
    }
    return arr[arr.size() - i - 1];
}

bool LongNatural::operator==(const LongNatural& other) const {
    return arr == other.arr;  // Если массивы равны, то числа равны
}

bool LongNatural::operator!=(const LongNatural& other) const {
    return !(*this == other);  // Если числа не равны, то они не равны
}