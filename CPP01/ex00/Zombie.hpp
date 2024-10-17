#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie(std::string);
		~Zombie(void);
		void	announce(void) const;
};
#endif