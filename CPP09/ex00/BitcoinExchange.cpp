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
	if (date.length() != 10)
		return false;
	
	std::istringstream	iss;
	char				spacer;
	int					year, month, day;
	bool				leapYear;
	bool				validDay;

	if (!(iss >> year >> spacer >> month >> spacer >> day) || !iss.eof())
		return false;
	if (spacer != '-' || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

    leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    validDay = false;
    if (month == 2) {
        validDay = (day <= 28) || (leapYear && day == 29);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        validDay = (day <= 30);
    } else {
        validDay = (day <= 31);
    }
    return validDay;
}

bool	BitcoinExchange::_isValidVal(const std::string &val) {
	
}