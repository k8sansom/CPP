/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:04:59 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/26 10:05:18 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		Weapon club = Weapon("club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		//Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		//jim.setWeapon(club);
		jim.attack();
		//club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}