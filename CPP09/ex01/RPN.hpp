#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cctype>

class RPN {
public:
    RPN(std::string input);
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

	int	computeResult(void);

private:
    std::stack<int> _stack;
	std::string 	_input;
	
	int		_applyOp(int left, int right, char op);
	bool	_isOp(char c);
};

#endif