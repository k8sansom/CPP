#include "easyFind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main() {
	try {
		std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::cout << "Checking vector and found: " << easyfind(vec, 9) << std::endl;

		std::list<int> list = {10, 20, 30, 40, 60};
		std::cout << "Checking list and found: " << easyfind(list, 30) << std::endl;

		//should throw an error because not there
		std::cout << "Checking list and found: " << easyfind(list, 50);

	} catch( const NotFoundException& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}