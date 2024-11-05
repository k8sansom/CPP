#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(_parse()) {}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float> BitcoinExchange::_parse() {
	std::ifstream	file("data.csv");
	if (!file.is_open()) {
		throw CanNotOpenFileException();
	}

	std::string	firstLine;
	std::getline(file, firstLine);
	if (firstLine != "date,exchange_rate") {
		throw BadDataException();
	}

	std::map<std::string, float> data;
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
	std::istringstream	iss(date);
	char				spacer;
	int					year, month, day;
	bool				leapYear;
	bool				validDay;

	if (!(iss >> year >> spacer >> month >> spacer >> day)) {
		return false;
	}
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

bool	BitcoinExchange::_isValidVal(const std::string &line) {
	if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
		return false;
	}
	_date = line.substr(0, 10);
	if (!_isValidDate(_date)) {
		return false;
	}

	std::istringstream ss(line.substr(13));
	ss >> _val;
	if (ss.fail()) {
		return false;
	}
	return true;
}

const char *BitcoinExchange::CanNotOpenFileException::what() const throw() {
	return "Error: Can not open file";
}

const char *BitcoinExchange::BadDataException::what() const throw() {
	return "Error: bad data";
}

void	BitcoinExchange::process(const char *file) {
	_input.open(file);
	if (!_input.is_open()) {
		throw CanNotOpenFileException();
	}

	std::string	line;
	std::getline(_input, line);
	if (line != "date | value")
		throw BadDataException();
	while(std::getline(_input, line)) {
		if (!_isValidVal(line)) 
			std::cout << "Error: bad input => " << line << std::endl;
		else if (_val < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (_val > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else {
			std::map<std::string, float>::iterator closest = _data.upper_bound(_date);
			if (closest != _data.begin())
			{
				--closest;
				std::cout << _date << " => " << _val << " = " << _val * closest->second << std::endl;
			}
			else
				std::cout << "Error: cannot find corresponding data => " << line << std::endl;
		}
    }

    _input.close();
}