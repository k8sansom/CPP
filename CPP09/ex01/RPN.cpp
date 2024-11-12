
#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input) {
	_validateInput();
}
RPN::RPN(const RPN& other) : _input(other._input) {}
RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_input = other._input;
	}
	return *this;
}
RPN::~RPN() {}

int RPN::computeResult() {
	std::istringstream tokens(_input);
    std::string token;

    while (tokens >> token) {
		if (std::isdigit(token[0])) {
            _stack.push(std::stoi(token));
		} else if (_isOp(token[0]) && token.size() == 1) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error: invalid numbers of operands");
			}
			int right = _stack.top(); _stack.pop();
			int left = _stack.top(); _stack.pop();
			_stack.push(_applyOp(left, right, token[0]));
		} else {
			throw std::runtime_error("Error: invalid input");
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error: failed to end with one solution");
	}
    return _stack.top();
}

void	RPN::_validateInput() {
	bool expectSpace = false;

	for (size_t i = 0; i < _input.size(); i++) {
		if (std::isdigit(_input[i]) || _isOp(_input[i])) {
			if (i + 1 < _input.size() && _input[i + 1] != ' ') {
				throw std::runtime_error("Error: missing space");
			}
			expectSpace = true;
		} else if (_input[i] == ' ' && expectSpace)
			expectSpace = false;
		else
			throw std::runtime_error("Error: invalid spacing or unknown character");
	}
}

bool RPN::_isOp(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int RPN::_applyOp(int left, int right, char op) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': 
            if (right == 0) throw std::runtime_error("Error: cannot divide by zero");
            return left / right;
        default: throw std::runtime_error("Error: invalid operator");
    }
}
