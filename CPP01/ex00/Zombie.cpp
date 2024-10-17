#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	//std::cout << "Zombie " << this->_name << " was born" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "Zombie " << this->_name << " died" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}