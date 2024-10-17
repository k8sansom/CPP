#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << _type << " constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &src) {
	if (this != &src)
		_type = src._type;
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "meow" << std::endl;
}