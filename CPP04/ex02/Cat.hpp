/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:30:38 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/21 11:35:45 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);
		~Cat();
		
		Brain* 	getBrain() const;
		void	makeSound(void) const;
	private:
		Brain *_brain;
};

#endif