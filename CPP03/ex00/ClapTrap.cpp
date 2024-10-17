/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:17:58 by ksansom           #+#    #+#             */
/*   Updated: 2024/06/18 11:53:15 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"),  _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src) {
		_name = src._name;
		_hit_points = src._hit_points;
		_energy_points = src._energy_points;
		_attack_damage = src._attack_damage;
	}
	std::cout << "ClapTrap copy assignment operator called for " << _name << std::endl;
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap name constructor for " << name << " called with " <<_hit_points << " hit points, " <<_energy_points << " energy points, and " << _attack_damage << " attack damage" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor for " << _name << " called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energy_points > 0 && _hit_points > 0) {
		std::cout << "ClapTrap " <<_name << " attacks " << target << ", causing " <<_attack_damage << " points of damage" << std::endl;
		_energy_points--;
	}
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " can't attack " << target << " because they have no energy" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " can't attack " << target << " because they have no health" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_points >= amount){
		std::cout << "ClapTrap " << _name << " has sustained " << amount << " points of damage" << std::endl;
		_hit_points -= amount;
	}
	else if (_hit_points > 0){
		std::cout << "ClapTrap " << _name << " has taken all the damage they can" << std::endl;
		_hit_points = 0;
	}
	else
		std::cout << "ClapTrap " << _name << " can't take any more damage" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount) {
	if ( _energy_points > 0 && _hit_points > 0) {
		std::cout << "ClapTrap " << _name << " has been repaired "  << amount << " health points" << std::endl;
		_hit_points += amount;
		_energy_points--;
	}
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " can not repair themselves because they have no energy left" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " can not repair themselves because they have no health left" << std::endl;
}