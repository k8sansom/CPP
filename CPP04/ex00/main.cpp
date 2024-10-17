/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:34:29 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/24 09:44:43 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "The Animal j type is " << j->getType() << std::endl;
	std::cout << "The Animal i type is " << i->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "*************WRONG ANIMAL***************" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	wrong->makeSound();
	wrongCat->makeSound();
	delete wrong;
	delete wrongCat; //should not output meow
	
	return 0;
}