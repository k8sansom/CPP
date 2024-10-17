#include "Harl.hpp"

	Harl::Harl() {
		std::cout << "Do you know Harl? These are the levels of comments Harl makes: \n" 
		<< "\"DEBUG\" level: Debug messages contain contextual information\n"
		<< "\"INFO\" level: These messages contain extensive information.\n"
		<< "\"WARNING\" level: Warning messages indicate a potential issue in the system.\n"
		<< "\"ERROR\" level: These messages indicate an unrecoverable error has occurred." << std::endl;
	}

	Harl::~Harl() {}
	
	void	Harl::_debug( void ) {
		std::cout << "[DEBUG]\n" 
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		<< "I really do!" << std::endl;
	}
	void	Harl::_info( void ) {
		std::cout << "[INFO]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger!\n"
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
	}
	void	Harl::_warning( void ) {
		std::cout << "[WARNING]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
	}
	void	Harl::_error( void ) {
		std::cout << "[ERROR]\n"
		<< "This is unacceptable!\n"
		<< "I want to speak to the manager now." << std::endl;
	}
	

	void	Harl::complain( std::string level ) {
		typedef void (Harl::*FuncArr) ( void );
		FuncArr	functions[] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
		std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		int i = -1;
		while (++i < 4) {
			if (levels[i] == level)
				break ;
		}
		if (i < 4)
			(this->*functions[i])();
	}