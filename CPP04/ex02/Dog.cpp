/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:18:55 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/21 10:02:30 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << _type << " constructor called" << std::endl;
	_brain = new Brain();
	if (!_brain) {
		std::cout << "Dog brain allocation failed" << std::endl;
		exit(1);
	}
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &copy): Animal(copy) {
	_brain = new Brain(*copy._brain);
	if (!_brain) {
		std::cout << "Dog brain copy allocation failed" << std::endl;
		exit(1);
	}
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &src) {
	if (this != &src) {
		delete _brain;
		_brain = new Brain(*src._brain);
		if (!_brain) {
			std::cout << "Dog copy assignment memory allocation failed" << std::endl;
			exit(1);
		}
		_type = src._type;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "woof" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}