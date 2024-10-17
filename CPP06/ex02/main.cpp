#include "Base.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

Base::~Base() {}

Base* generate(void) {
	int val = rand() % 3;
	if (val == 0) {
		return new A;
	} else if (val == 1) {
		return new B;
	} else {
		return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cerr << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast) {
				std::cerr << "Unknown type" << std::endl;
			}
		}
	}
}

int	main(void) {
	std::srand(std::time(0));

	Base* newPtr1 = generate();
	Base* newPtr2 = generate();
	Base* newPtr3 = generate();

	std::cout << "Identifying newPtr1 using pointer:" << std::endl;
	identify(newPtr1);

	std::cout << "Identifying newPtr2 using reference:" << std::endl;
	identify(newPtr2);

	std::cout << "Identifying newPtr3 using pointer:" << std::endl;
	identify(newPtr3);

	delete(newPtr1);
	delete(newPtr2);
	delete(newPtr3);
}