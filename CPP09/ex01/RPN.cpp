#include "RPN.hpp"

RPN::RPN(std::string input) {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack), _input(other._input) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _input = other._input;
		_stack = other._stack;
    }
    return *this;
}
