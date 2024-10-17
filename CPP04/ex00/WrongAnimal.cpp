#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal " << _type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	_type = copy._type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src) {
	if (this != &src)
		_type = src._type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

void		WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}