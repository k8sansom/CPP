/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:43:27 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/21 10:02:55 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << _type << " constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src) 
		_type = src._type;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);		
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}
	
void	Cat::makeSound(void) const {
	std::cout << "meow" << std::endl;
}