#ifndef SED4LOSERS_HPP
#define SED4LOSERS_HPP

#include <iostream>
#include <fstream>

class Sed4Losers {
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;
public:
	Sed4Losers( std::string filename, std::string s1, std::string s2);
	~Sed4Losers();
	int	replace(void);
	
};
#endif
