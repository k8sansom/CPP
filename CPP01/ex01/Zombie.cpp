#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->_name << " died" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string name ) {
	this->_name = name;
}