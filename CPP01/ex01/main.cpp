/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:41:40 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 13:47:23 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void randomChump( std::string name );

int	main(void) {
	Zombie* horde = zombieHorde(10, "Kate");
	delete [] horde;
	return 0;
}
