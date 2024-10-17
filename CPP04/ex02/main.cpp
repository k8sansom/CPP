/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:34:29 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/21 11:39:20 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    int animalCount = 10;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount / 2; ++i) {
        std::cout << "Animal " << i << ": " << std::endl;
        animals[i] = new Dog();
    }

    for (int i = animalCount / 2; i < animalCount; ++i) {
        std::cout << "Animal " << i << ": " << std::endl;
        animals[i] = new Cat();
    }

	// Deep copy test
    std::cout << std::endl;
    std::cout << "*************Deep copy tests**************" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original idea");

    Dog copiedDog = originalDog;
    copiedDog.getBrain()->setIdea(0, "Copied idea");

    std::cout << "Original Dog Brain Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    //test the abstract classmake re
    std::cout << std::endl;
    std::cout << "*************Test the pure virtual function**************" << std::endl;
    // Animal test;
    // if above is uncommented it shouldn't compile 

    for (int i = 0; i < animalCount; ++i) {
        std::cout << "Animal " << i << ": " << std::endl;
        delete animals[i];
    }
    return 0;
}