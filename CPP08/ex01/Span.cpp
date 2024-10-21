#include "Span.hpp"

Span::Span(unsigned int N) : _capacity(N) {}

Span::~Span() {}

Span::Span(const Span &copy) : _capacity(copy._capacity), _vec(copy._vec) {}

Span& Span::operator=(const Span &src) {
	if (this != &src) {
		_capacity = src._capacity;
		_vec = src._vec;
	}
	return *this;
}

void	Span::addNumber(int num) {
	if (_vec.size() == _capacity) {
		throw std::length_error("Cannot add number as vector is full.");
	}
	_vec.push_back(num);
}

int	Span::shortestSpan() {
	if (_vec.size() < 2) {
		throw std::logic_error("No span can be found because not enough numbers in vector.");
	}
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (int i = 1; i < sorted.size() - 1; i++) {
		int currentSpan = sorted[i + 1] - sorted[i];
		minSpan = std::min(minSpan, currentSpan);
	}
	return minSpan;
}

int	Span::longestSpan() {
	if (_vec.size() < 2) {
		throw std::logic_error("No span can be found because not enough numbers in vector.");
	}
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while (begin != end) {
		addNumber(*begin++);
	}
}