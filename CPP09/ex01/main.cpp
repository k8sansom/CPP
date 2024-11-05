#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "Format: ./RPN \"<digit> <digit> <operator> ...\"" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn(argv[1]);
		std::cout << rpn.compute() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}

	return 0;
}