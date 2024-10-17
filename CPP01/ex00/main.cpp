/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:41:40 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/19 13:21:33 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );

void randomChump( std::string name );

int	main(void) {
	Zombie *z1 = newZombie("Kate");
	z1->announce();
	randomChump("Ben");
	delete z1;
	return 0;
}
