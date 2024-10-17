#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>

class ScalarConverter {
	public:
		static void convert(const std::string& literal);
		~ScalarConverter();
	private:
		//OCF
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& src);
};

#endif