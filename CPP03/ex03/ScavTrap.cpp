#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    ScavTrap::_hit_points = 100;
    ScavTrap::_energy_points = 50;
    ScavTrap::_attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    ScavTrap::_hit_points = 100;
    ScavTrap::_energy_points = 50;
    ScavTrap::_attack_damage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src) {
		_name = src._name;
		_hit_points = src._hit_points;
		_energy_points = src._energy_points;
		_attack_damage = src._attack_damage;
	}
	return *this;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor for " << _name << " called" << std::endl;
}

void    ScavTrap::attack(const std::string &target) {
	if (_energy_points > 0 && _hit_points > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
	else if (_energy_points <= 0)
		std::cout << "ScavTrap " << _name << " can't attack because they don't have energy" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " can't attack because they have no health" << std::endl;
}

void    ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is guarding the gate" << std::endl;
}