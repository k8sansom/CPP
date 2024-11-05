#include "RPN.hpp"

RPN::RPN(std::string input) {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _data(other._data) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

void RPN::push(int value) {
    _data.push_back(value);
}

int RPN::pop() {
    if (_data.empty()) {
        throw std::runtime_error("Stack underflow: no elements to pop.");
    }
    int value = _data.back();
    _data.pop_back();
    return value;
}

bool RPN::empty() const {
    return _data.empty();
}
