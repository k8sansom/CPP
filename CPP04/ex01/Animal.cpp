/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:05:38 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/21 10:04:42 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("default") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type(type) {
	std::cout << "Animal " << _type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &src) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &src) {
		_type = src._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal makeSound called" << std::endl;
}

std::string	Animal::getType(void) const {
	return (_type);
}