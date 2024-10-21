#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
	{
		sp.addNumber(14);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
    std::vector<int> numbers;
	for (size_t i = 0; i < 10000; i++)
	{
		numbers.push_back(i * 3);
	}
    Span sp2 = Span(10001);
	sp2.addNumbers(numbers.begin(), numbers.end());

	try
	{
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
    return 0;
}