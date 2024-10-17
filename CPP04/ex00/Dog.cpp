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
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &src) {
	if (this != &src) {
		_type = src._type;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "woof" << std::endl;
}