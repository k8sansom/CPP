#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		const char *what()  const throw() {
			return "Value not found in container";
		}
};

template <typename T>
int	easyfind(T container, int val) {
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return *it;
}

#endif