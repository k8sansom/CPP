#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>

class RPN {
public:
    RPN(std::string input);
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

	int	compute(void);

private:
    std::stack<int> _stack;
	std::string 	_input;
	
	void	_parse(char &c);
	char	_getOp(char &c);
};

#endif