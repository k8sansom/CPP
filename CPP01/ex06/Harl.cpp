#include "Harl.hpp"

	Harl::Harl() {
	}

	Harl::~Harl() {}
	
	void	Harl::_debug( void ) {
		std::cout << "[DEBUG]\n" 
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		<< "I really do!\n" << std::endl;
	}
	void	Harl::_info( void ) {
		std::cout << "[INFO]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger!\n"
		<< "If you did, I wouldn’t be asking for more!\n" << std::endl;
	}
	void	Harl::_warning( void ) {
		std::cout << "[WARNING]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	}
	void	Harl::_error( void ) {
		std::cout << "[ERROR]\n"
		<< "This is unacceptable!\n"
		<< "I want to speak to the manager now.\n" << std::endl;
	}
	

	void	Harl::complain( std::string level ) {
		std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		int i = 0;
		while (i < 4 && levels[i].compare(level))
			i++;
		switch (i) {
			case	0:
				this->_debug();
			case	1:
				this->_info();
			case	2:
				this->_warning();
			case	3:
				this->_error();
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}