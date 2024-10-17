#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), _name("default"){
    FragTrap::_hit_points = 100;
    ScavTrap::_energy_points = 50;
    FragTrap::_attack_damage = 30;
    std::cout << "DiamondTrap default constructor called with " << _hit_points << " hit points, " << _energy_points << " energy points, and " << _attack_damage << " attack damage" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), _name(name) {
    FragTrap::_hit_points = 100;
    ScavTrap::_energy_points = 50;
    FragTrap::_attack_damage = 30;
    std::cout << "DiamondTrap " << _name << " constructor called with " <<_hit_points << " hit points, " <<_energy_points << " energy points, and " << _attack_damage << " attack damage" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
    *this = copy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &src) {
        ClapTrap::operator=(src);
        ScavTrap::operator=(src);
        FragTrap::operator=(src);
        this->_name = src._name;
        this->_hit_points = src._hit_points;
        this->_energy_points = src._energy_points;
        this->_attack_damage = src._attack_damage;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor for " << _name << " called" << std::endl;
}

// Attack method
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

// WhoAmI method
void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is " << _name << ", but my ClapTrap name is " << ClapTrap::_name << std::endl;
}
