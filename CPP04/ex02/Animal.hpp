/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:59:36 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/21 11:35:32 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	public:
		Animal();
		Animal( std::string type );
		Animal(const Animal &copy);
		Animal	&operator=(const Animal &src);
		virtual ~Animal();

		virtual void makeSound() const = 0; // Pure virtual function
		std::string		getType(void) const;
		
	protected:
		std::string _type;
	
};


#endif