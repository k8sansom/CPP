/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:15:27 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 10:12:35 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    std::cout << "Welcome to the 80s and their unbelievable technology!" << std::endl;
    std::cout << "This is your crappy awesome phonebook." << std::endl;
    std::cout << "ADD\\n		-->will add a contact." << std::endl;
    std::cout << "SEARCH\\n	-->will search for a contact." << std::endl;
    std::cout << "EXIT\\n		-->will quit the PhoneBook." << std::endl;
}

PhoneBook::~PhoneBook() {}

int   PhoneBook::add(void) {
	static int	i;

	if (this->_contacts_arr[i % 8].add() != 0)
		return 1;
	this->_contacts_arr[i % 8].index = i + 1 % 9;
	i++;
	return 0;
}

int PhoneBook::search() const {
    int index = 0;
    std::string input = "";

    for (int i = 0; i < 8; i++)
        this->_contacts_arr[i].print(i + 1);
    while (true) {
        std::cout << "Index: ";
        std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 1;
        }
		std::istringstream iss(input);
		if (!(iss >> index))
			std::cout << "Invalid input, try again" << std::endl;
        else if (index >= 1 && index <= 8) 
			break ;
		else
            std::cout << "Invalid index, try again" << std::endl;
		std::cin.clear();
    }
    this->_contacts_arr[index - 1].print_contact();
    return 0;
}
