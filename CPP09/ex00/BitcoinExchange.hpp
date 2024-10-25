#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stdexcept>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;
	std::ifstream					_input;
	float							_val;
	std::string						_date;

	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange& operator=(BitcoinExchange const &src);

	bool	_isValidVal(const std::string &val);
	bool	_isValidDate(const std::string &date);

	std::map<std::string, float>	_parse();

	class BadDataException: public std::exception {
		virtual const char *what() const throw();
	};

	class CanNotOpenFileException: public std::exception {
		virtual const char *what() const throw();
	};

public:
	BitcoinExchange();
	~BitcoinExchange();

	void	process(const char file);
};

#endif