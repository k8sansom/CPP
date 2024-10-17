/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:13:48 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 13:58:21 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* 	horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::stringstream stream;
        stream << i + 1;
        std::string num = stream.str(); // Convert integer to string
        std::string namer = name + "_" + num; // Append index to name
		horde[i].set_name(namer);
		horde[i].announce();
	}
	return horde;
}