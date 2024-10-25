#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(_parse()) {}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float>	BitcoinExchange::_parse() {
	std::ifstream	file("data.csv");
	if (!file.is_open()) {
		throw CanNotOpenFileException();
	}

	std::string	firstLine;
	std::getline(file, firstLine);
	if (firstLine != "date,exchange_rate") {
		throw BadDataException();
	}

	static std::map<std::string, float> data;
	std::string	line;
	while (std::getline(file, line)) {
		std::istringstream	iss(line);
		std::string			date;
		float				val;
		if (std::getline(iss, date, ',') && iss >> val) {
			data[date] = val;
		} else {
			throw BadDataException();
		}
	}
	file.close();
	return data;
}

bool	BitcoinExchange::_isValidDate(const std::string &date) {
	std::istringstream	iss;
	char				spacer;
	int					month, day, year;

	if (!(iss >> year >> spacer >> month >> spacer >> day))
		return false;
	if (spacer != '-' || year < 0 || month < 1 || month > 12 || day < 1)
		return false;
}