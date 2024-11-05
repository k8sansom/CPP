#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		std::cerr << "Usage: ./RPN \"<digit> <digit> <operator> ...\"" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn(av[1]);
		std::cout << rpn.compute() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}

	return 0;
}