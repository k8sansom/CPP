#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
	private:
		unsigned int		_capacity;
		std::vector<int>	_vec;
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span& operator=(const Span &src);

		void	addNumber(int num);
		void	shortestSpan();
		void	longestSpan();

};

#endif