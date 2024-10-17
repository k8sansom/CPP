/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:34:33 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 15:34:34 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void	HumanA::attack( void ) const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}