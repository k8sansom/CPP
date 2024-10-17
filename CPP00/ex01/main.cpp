/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:16:09 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 09:58:34 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook pbook;
    std::string input = "";

    while (true) {
        std::cout << "What would you like to do?> ";
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0) {
            if (pbook.add() != 0) {
				std::cout << std::endl;
                return 1;
			}
        } 
		else if (input.compare("SEARCH") == 0) {
            if (pbook.search() != 0) {
				std::cout << std::endl;
                return 1;
        	}
		}
		else if (input.compare("EXIT") == 0)
            break;
		else if (std::cin.eof()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl;
			return 1;
		}
    }
    return 0;
}

// int main(void){
//     PhoneBook pbook;
//     std::string input= "";
//     while (input.compare("EXIT")) {
// 		std::cout << "What would you like to do?> ";
// 		std::cin >> input;
// 		if (input.compare("ADD") == 0) {
//  			if (pbook.add() != 0)
// 				return 1;
// 		}
//     	else if(input.compare("SEARCH") == 0) {
// 			if (pbook.search() != 0)
// 				return 1;
// 		}
// 		else if (std::cin.eof()) {
// 			std::cin.ignore();
// 			return 1;
// 		}
// 		std::cin.ignore();
//     }
//     return 0;
// }